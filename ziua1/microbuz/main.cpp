#include <bits/stdc++.h>
#define INF 100000

using namespace std;

ifstream fin("microbuz.in");
ofstream fout("microbuz.out");

int cer,N;
int pret[12];
int ans1=INF;
int ans2[12];
int ans3,sum3;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    fin >> cer;
    for(int i=1;i<=10;i++){
        fin >> pret[i];
    }
    fin >> N;
    if(cer==1 || cer==2) for(int subset=0;subset<(1<<20);subset++){
        int count[12]={0};
        int pos=1;
        for(int x=subset;x>0;x>>=2){
            count[pos]=(x%4);
            pos++;
        }
        int sum=0;
        int dist=0;
        for(int i=1;i<=10;i++){
            sum+=count[i]*pret[i];
            //cout << count[i]*pret[i] << "\n";
            dist+=count[i]*i;
        }
        if(dist==N){
            if(ans1>sum){
                ans1=sum;
                for(int i=1;i<=10;i++){
                    ans2[i]=count[i];
                }
            }
        }
    }else for(int subset=0;subset<(1<<20);subset++){
        int sum1,sum2;
        sum1=sum2=0;
        for(int bit=0;bit<10;bit++){
            if((subset&(1<<bit))>0 && (subset&(1<<(bit+10)))>0) continue;
            if((subset&(1<<bit))>0) sum1+=pret[bit%10+1];
            if((subset&(1<<(bit+10)))>0) sum2+=pret[bit%10+1];
        }
        if(sum3<sum1 && sum1==sum2){
            sum3=sum1;
            ans3=subset;
        }
    }
    if(cer==1){
        fout << ans1;
    }else if(cer==2){
        for(int i=1;i<=10;i++){
            for(int j=1;j<=ans2[i];j++){
                fout << i << " " << pret[i] << "\n";
            }
        }
    }else{
        fout << sum3 << "\n";
        for(int bit=0;bit<20;bit++){
            if(bit==10) fout << "\n";
            if(ans3&(1<<bit)){
                fout << (bit%10)+1 << " ";
            }
        }
    }
    return 0;
}
#include <bits/stdc++.h>
#define NMAX 15002
#define lsb(x) (x&(-x))

using namespace std;

ifstream fin("datorii.in");
ofstream fout("datorii.out");

struct AIB{
    vector <int> aib;
    AIB (int N){
        aib.resize(N+1);
    }

    void update(int pos,int val){
        for(int i=pos;i<(int)aib.size();i+=lsb(i)){
            aib[i]+=val;
        }
    }

    int query(int pos){
        int ret=0;
        for(int i=pos;i>0;i-=lsb(i)){
            ret+=aib[i];
        }
        return ret;
    }

    int find(int val){
        int ans=0;
        int sum_ans=0;
        for(int pas=(1<<18);pas>0;pas>>=1){
            if(ans+pas>=(int)aib.size()) {continue;}
            if(sum_ans+aib[ans+pas]<val){
                ans+=pas;
                sum_ans+=aib[ans];
            }
        }
        return ans;
    }
};

int N,M;
int arr[NMAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    fin >> N >> M;
    AIB aib(N+2);
    for(int i=1;i<=N;i++){
        fin >> arr[i];
        aib.update(i,arr[i]);
    }
    while(M--){
        int type,x,y;
        fin >> type >> x >> y;
        if(type==0){ aib.update(x,-y); }
        else{ fout << aib.query(y)- aib.query(x-1) << "\n";}
    }
    return 0;
}

#include <bits/stdc++.h>
#define NMAX 30002

using namespace std;

ifstream fin("abc.in");
ofstream fout("abc.out");

int N,B,C,add;
int A[NMAX];

int sum(int op)
{
    int ret=0;
    for(int i=1;i<=N;i++){
        ret+=max(min(A[i]+op,B),0);
    }
    return ret;
}

int caut_bin()
{
    int L=-65535;
    int R=65535;
    int ret=L;
    while(L<=R){
        int mij=(R+L)/2;
        if(sum(mij)<=C){
            L=mij+1;
            ret=mij;
        }else{
            R=mij-1;
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    fin >> N >> B >> C;
    int saved=C;
    for(int i=1;i<=N;i++){
        fin >> A[i];
    }
    int op=caut_bin();
    C-=sum(op);
    // cout << C;
    if(C>=0){
        for(int i=1;C && i<=N;i++){
            // cout << (max(min(A[i]+op,B),0)<B) << " ";
            if(max(min(A[i]+op,B),0) <B){
                A[i]++;
                C--;
            }
        }
    }else{
        for(int i=1;C<0 && i<=N;i++){
            if(max(min(A[i]+op,B),0) >0){
                A[i]--;
                C++;
            }
        }
    }
    assert(C==0);
    int sum=0;
    for(int i=1;i<=N;i++){
        fout << max(min(A[i]+op,B),0) << " ";
        sum+=max(min(A[i]+op,B),0);
    }
    assert(sum==saved);
}

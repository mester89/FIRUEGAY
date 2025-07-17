#include <bits/stdc++.h>
#define NMAX 100002
#define MOD 1000000007

using namespace std;

ifstream fin("bitsir.in");
ofstream fout("bitsir.out");

int N,X,Y;
int M[NMAX];
int cnt[32];
int ans=1;
int fact[NMAX],inv_fact[NMAX];

int choose(int N,int K)
{
    return 1ll*fact[N]*inv_fact[N-K]%MOD * inv_fact[K] %MOD;
}

int power(int n,int p)
{
    int ret=1;
    while(p>0){
        if(p&1){
            ret=1ll*ret*n%MOD;
        }
        n=1ll*n*n%MOD;
        p>>=1;
    }
    return ret;
}

int moduri(int x,int par)
{
    int ret=0;
    // if(par==0){
    //     par=2;
    // }
    for(int i=par;i<=x;i+=2){
        ret=(ret+choose(x,i))%MOD;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    fin >> N >> X >> Y;
    ///precalc
    fact[0]=1;
    for(int i=1;i<NMAX;i++){
        fact[i]=1ll*fact[i-1]*i%MOD;
    }
    inv_fact[NMAX-1]=power(fact[NMAX-1],MOD-2);
    for(int i=NMAX-2;i>=0;i--){
        inv_fact[i]=1ll*inv_fact[i+1]*(i+1)%MOD;
    }
    for(int i=1;i<=N;i++){
        fin >> M[i];
        for(int bit=0;bit<31;bit++){
            if((M[i]&(1<<bit))>0){
                cnt[bit]++;
            }
            if((M[i]&(1<<bit))>0 && (X&(1<<bit))==0){
                fout << "NU\n0";
                return 0;
            }
        }
    }
    for(int bit=0;bit<31;bit++){
        if((cnt[bit]==N && (N%2!=(int)((Y&(1<<bit))>0))) || ((X&(1<<bit))==0 && (Y&(1<<bit))>0)){
            fout << "NU\n0";
            return 0;
        }
    }
    fout << "DA\n";
    for(int bit=0;bit<31;bit++){
        if((X&(1<<bit))>0){
            if(cnt[bit]%2==((Y&(1<<bit))>0)){
                if(cnt[bit]>0){
                    ans=1ll*ans*moduri(N-cnt[bit],0) % MOD;
                }else{
                    ans=1ll*ans*moduri(N-cnt[bit],2) % MOD;
                    // cout << moduri(N-cnt[bit],2) << "\n";
                }
            }else{
                // cout << bit << "\n";
                ans=1ll*ans*moduri(N-cnt[bit],1) % MOD;
            }
        }
    }
    fout << ans;
    // cout << moduri(4,1) << " ";
    // cout << moduri(3,1);
    return 0;
}

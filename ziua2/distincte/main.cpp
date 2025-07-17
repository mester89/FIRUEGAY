#include <bits/stdc++.h>
#define lsb(x) (x&(-x))
#define NMAX 100002
#define MOD 666013

using namespace std;

ifstream fin("distincte.in");
ofstream fout("distincte.out");

struct AIB{
    vector <long long> aib;
    AIB (int N){
        aib.resize(N+1);
    }

    void update(int pos,long long val){
        for(int i=pos;i<(int)aib.size();i+=lsb(i)){
            aib[i]+=val;
        }
    }

    long long query(int pos){
        long long ret=0;
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

struct Query{
    int L,R,idx;
};

bool operator <(const Query &q1,const Query &q2)
{
    return q1.R < q2.R;
}

int N,K,M;
int last_seen[NMAX];
int arr[NMAX];
Query queries[NMAX];
int ans[NMAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    fin >> N >> K >> M;
    AIB aib(N+1);
    for(int i=1;i<=N;i++){
        fin >> arr[i];
    }
    for(int i=1;i<=M;i++){
        fin >> queries[i].L >> queries[i].R;
        queries[i].idx=i;
    }
    sort(queries+1,queries+M+1);
    int q=1;
    for(int i=1;i<=N;i++){
        if(last_seen[arr[i]]!=0){
            aib.update(last_seen[arr[i]],-arr[i]);
        }
        aib.update(i,arr[i]);
        last_seen[arr[i]]=i;
        for(;i==(queries[q].R);q++){
            ans[queries[q].idx]=(aib.query(i)-aib.query(queries[q].L-1))%MOD;
        }
    }
    for(int i=1;i<=M;i++){
        fout << ans[i] << "\n";
    }
    return 0;
}

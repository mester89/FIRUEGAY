#include <bits/stdc++.h>
#define lsb(x) (x&(-x))

using namespace std;

ifstream fin("aib.in");
ofstream fout("aib.out");

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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N,Q,x;
    fin >> N >> Q;
    AIB aib(N+1);
    for(int i=1;i<=N;i++){
        fin >> x;
        aib.update(i,x);
    }
    while(Q--){
        int type,a,b;
        fin >> type;
        if(type==0){
            fin >> a >> b;
            aib.update(a,b);
        }else if(type==1){
            fin >> a >> b;
            fout << aib.query(b)-aib.query(a-1) << "\n";
        }else{
            fin >> a;
            int ret=aib.find(a)+1;
            // cout << ret << "\n";
            fout << (aib.query(ret)==a?ret:-1) << "\n";
        }
    }
    return 0;
}
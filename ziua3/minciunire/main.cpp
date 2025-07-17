#include <bits/stdc++.h>
#define NMAX 250002
#define lsb(x) (x&(-x))

using namespace std;

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

int N;
int arr[NMAX];
long long sum[NMAX];
long long ans;
multiset <long long> bagate;

int main()
{
    map<long long,int> norm;
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
        sum[i]=arr[i]+sum[i-1];
    }
    if(false){
        bagate.insert(0);
        for(int i=1;i<=N;i++){
            int add=distance(bagate.begin(),bagate.upper_bound(sum[i]-1));
            ans+=add;
            bagate.insert(sum[i]);
        }
    }else{
        AIB aib(N+1);///trb sa normalizam
        norm[0];
        for(int i=1;i<=N;i++){
            norm[sum[i]];
        }
        int v=1;
        for(auto &x:norm){
            x.second=v;
            v++;
        }
        aib.update(norm[0],1);
        for(int i=1;i<=N;i++){
            ans+=aib.query(norm[sum[i]]-1);
            aib.update(norm[sum[i]],1);
        }
    }
    cout << ans;
    return 0;
}

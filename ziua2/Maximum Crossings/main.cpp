#include <bits/stdc++.h>
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

void TC()
{
    int N;
    long long ans=0;
    cin >> N;
    AIB aib(N);
    vector <int> arr(N+1);
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    for(int i=N;i>=1;i--){
        ans+=aib.query(arr[i]);
        aib.update(arr[i],1);
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        TC();
    }
    return 0;
}

#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

void TC()
{
    int N,K,ans=0;
    cin >> N >> K;
    vector <int> arr(N+2);
    vector <vector<int>> dp(N+2,vector<int>(66));
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    for(int i=1;i<=N;i++){
        dp[i][arr[i]]=(dp[i][arr[i]]+1)%MOD;
        for(int mask=0;mask<64;mask++){
            dp[i+1][mask&arr[i+1]]=(1ll*dp[i+1][mask&arr[i+1]]+dp[i][mask])%MOD;
            dp[i+1][mask]=(1ll*dp[i+1][mask]+dp[i][mask])%MOD;
        }
    }
    for(int mask=0;mask<64;mask++){
        if(__builtin_popcount(mask)==K){
            ans=(1ll*ans+dp[N][mask])%MOD;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int Q;
    cin >> Q;
    while(Q--){
        TC();
    }
    return 0;
}

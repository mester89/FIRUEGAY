#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

void TC()
{
    int N,K,ans=0;
    cin >> N >> K;
    vector <int> arr(N+2);
    vector <int> dp(66);
    vector <int> freq(66);
    for(int i=1;i<=N;i++){
        cin >> arr[i];
        freq[arr[i]]++;
        if(dp[arr[i]]==0){ dp[arr[i]]++; }
        else{ dp[arr[i]]=1ll*dp[arr[i]]*2%MOD; }
    }
    for(int x=63;x>=0;x--){
        for(int folosim=0;folosim<64;folosim++){
            dp[x&folosim]=(1ll*dp[x&folosim]*dp[folosim]%MOD*dp[x]%MOD);
        }
    }
    for(int x=0;x<64;x++){
        if(__builtin_popcount(x)==K){
            ans=(1ll*ans+dp[x])%MOD;
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

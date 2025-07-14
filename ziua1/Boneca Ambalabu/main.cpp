#include <bits/stdc++.h>

using namespace std;

inline void populate(int *freq, int x)
{
    for(int i=0;x;i++){
        freq[i]+=(x&1);
        x>>=1;
    }
    return;
}

void TC()
{
    int N;
    long long ans=0,sum=0;
    int freq[32]={0};
    cin >> N;
    vector <int> arr(N+2);
    for(int i=1;i<=N;i++){
        cin >> arr[i];
        populate(freq,arr[i]);
        sum+=arr[i];
    }
    for(int i=1;i<=N;i++){
        long long modify=0;
        for(int bit=0;bit<32;bit++){
            if((arr[i]&(1<<bit))>0){
                modify+=-(freq[bit]*(1ll<<bit))+ (N-freq[bit])*(1ll<<bit);
            }
        }
        ans=max(ans,sum+modify);
    }
    cout << ans << "\n";
    return;
}

int main()
{
    int T;
    cin >> T;
    while(T--){
        TC();
    }
}
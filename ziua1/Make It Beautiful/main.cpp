#include <bits/stdc++.h>

using namespace std;

int popcount(long long x)
{
    int ret=0;
    while(x){
        ret+=x&1;
        x>>=1;
    }
    return ret;
}


void TC()
{
    int N,ans=0;
    long long k;
    cin >> N >> k;
    vector <long long> arr(N+2);
    for(int i=1;i<=N;i++){
        cin >> arr[i];
        ans+=popcount(arr[i]);
    }
    for(int bit=0;bit<64 && k>0;bit++){
        for(int i=1;i<=N;i++){
            if((arr[i]&(1ll<<bit))!=0 || k<0) continue;
            long long adds=1ll<<bit;
            k-=adds;
            //cout << k << " , " << adds << "\n";
            if(k>=0){
                ans++;
            }else{
                k=-1;
                break;
            }
        }
    }
    cout << ans << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        TC();
    }
    return 0;
}
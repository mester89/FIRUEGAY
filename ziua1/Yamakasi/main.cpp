#include <bits/stdc++.h>

using namespace std;

int T;

void TC()
{
    int N,x,S;
    int ans=0;
    map <long long,int> curr;
    map <long long,int> before_x;
    vector <int> sums;
    cin >> N >> S >> x;
    vector <int> arr(N+2);
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    
    long long sum=0;
    curr[0]=1;
    for(int i=1;i<=N;i++){
        sum+=arr[i];
        if(arr[i]<=x){
            if(arr[i]==x){
                for(auto elm:curr){
                    before_x[elm.first]+=elm.second;
                }
                curr.clear();
            }
            //cout << i << " : " << sum << " ( "<< before_x.size() << " )\n";
            ans+=before_x[sum-x];
            curr[sum]++;
        }else{
            curr.clear();
            before_x.clear();
            curr[sum]++;
        }
    }
    cout << ans << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--){
        TC();
    }
}
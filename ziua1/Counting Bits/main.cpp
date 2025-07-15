#include <bits/stdc++.h>

using namespace std;

long long N;
long long ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> N;
    N++;
    for(int bit=0;bit<60;bit++){
        ans+=(N/(1ll<<(bit+1)))*(1ll<<bit) + max(N%(1ll<<(bit+1))-(1ll<<bit),0ll);
        // cout << bit << " : " << (N/(1ll<<(bit+1)))*(1ll<<bit) + max(N%(1ll<<(bit+1))-(1ll<<bit),0ll) << "\n";
    }
    cout << ans;
	return 0;
}



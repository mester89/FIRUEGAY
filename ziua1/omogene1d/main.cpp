#include <bits/stdc++.h>
#define NMAX 250002

using namespace std;

struct stare{
    int f0,f1,f2;
};

bool operator <(const stare &s1, const stare &s2)
{
    return make_tuple(s1.f0,s1.f1,s1.f2) < make_tuple(s2.f0,s2.f1,s2.f2);
}

int N;
map <stare, int> mp;
int freq[3];
int arr[NMAX];
int ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    mp[{0,0,0}]=1;
    for(int i=1;i<=N;i++){
        freq[arr[i]]++;
        int diff1 = freq[0]-freq[1];
        int diff2 = freq[0]-freq[2];
        int diff3 = freq[1]-freq[2];
        ans+=mp[{diff1,diff2,diff3}];
        mp[{diff1,diff2,diff3}]++;// 0-1 ; 0-2 ; 1-2
    }
    cout << ans;
}
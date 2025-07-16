#include <bits/stdc++.h>

using namespace std;

struct Sir{
    int sum;
    vector <int> arr;
};

bool operator<(const Sir &s1, const Sir &s2)
{
    return s1.sum > s2.sum;
}

void TC()
{
    int N,M;
    long long ans=0;
    cin >> N >> M;
    vector <Sir> siruri(N);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            siruri[i].arr.push_back(0);
            cin >> siruri[i].arr[j];
            siruri[i].sum+=siruri[i].arr[j];
        }
    }
    sort(siruri.begin(),siruri.end());
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            ans+=((1ll*N*M)-(1ll*M*i+j))*1ll*siruri[i].arr[j];
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

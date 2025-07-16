#include <bits/stdc++.h>
#define NMAX 200002

using namespace std;

int N;
long long arr[NMAX];
long long sum[NMAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    sort(arr+1,arr+N+1);
    if(arr[1]!=1){
        cout << 1;
        return 0;
    }
    arr[N+1]=INT64_MAX;
    for(int i=1;i<=N+1;i++){
        if(sum[i-1]<arr[i]-1){
            cout << sum[i-1]+1;
            return 0;
        }
        sum[i]=sum[i-1]+arr[i];
    }
    return 0;
}

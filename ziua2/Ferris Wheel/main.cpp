#include <bits/stdc++.h>
#define NMAX 200002

using namespace std;

int N,X,ans;
int arr[NMAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> X;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    sort(arr+1,arr+N+1);
    int small,big;
    small=1;
    big=N;
    for(;small <= big;small++){
        while(arr[small]+arr[big]>X && small <= big){
            ans++;
            big--;
        }
        if(small<=big){
            big--;
            ans++;
        }
    }
    cout << ans;
    return 0;
}

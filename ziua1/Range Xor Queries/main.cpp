#include <bits/stdc++.h>
#define NMAX 200002

using namespace std;

int N,Q;
int arr[NMAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> Q;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
        arr[i]=arr[i]^arr[i-1];
    }
    while(Q--){
        int L,R;
        cin >> L >> R;
        cout << (arr[L-1]^arr[R]) << "\n";
    }
    return 0;
}

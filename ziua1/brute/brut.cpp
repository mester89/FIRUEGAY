#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 100000;
int N;
int A[N_MAX + 5];

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        if(A[i] == 1) {
            for(int j = i; j <= N && A[i] == A[j]; j++) {
                ans = max(ans, j - i + 1);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
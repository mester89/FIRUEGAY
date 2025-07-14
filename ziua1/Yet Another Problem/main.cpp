#include <bits/stdc++.h>
#define NMAX 200002

using namespace std;

int Q,N,arr[NMAX];
int closest[NMAX];
long long sum[NMAX];
map <int,int> last[2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> Q;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
        sum[i]=sum[i-1]+arr[i];
        arr[i]=arr[i]^arr[i-1];
        // cout << arr[i] << " ";
    }
    // cout << "\n";
    for(int i=N;i>=0;i--){
        if(last[i%2][arr[i]]==0){
            closest[i]=N+5;
        }else{
            closest[i]=last[i%2][arr[i]];
        }
        last[(i+1)%2][arr[i]]=i;
    }
    while(Q--){
        int L,R;
        cin >> L >> R;
        if(sum[R]-sum[L-1]==0){
            cout << "0\n";
            continue;
        }
        if((arr[R]^arr[L-1])==0){
            if((R-L+1)%2==1){
                cout << "1\n";
                continue;
            }else if((R-L+1)%2==0){
                if(sum[L]-sum[L-1]==0 || sum[R]-sum[R-1]==0){
                    cout << "1\n";
                    continue;
                }
                if(closest[L-1]<=R ){
                    cout << "2\n";
                    continue;
                }
            }
        }
        cout << "-1\n";
    }
}
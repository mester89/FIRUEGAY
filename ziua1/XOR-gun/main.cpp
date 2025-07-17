#include <bits/stdc++.h>
#define NMAX 100002
#define INF INT_MAX

using namespace std;

int N;
int arr[NMAX];
int prefix[NMAX];
int ans=INF;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    if(N<=60){
        for(int i=1;i<=N;i++){//poate intra si nu mai trb sa mi bat capul:-)
            prefix[i]=arr[i]^prefix[i-1];
        }
        arr[N+1]=INF;
        for(int i=1;i<=N;i++){
            for(int j=i;j<=N;j++){
                for(int k=j+1;k<=N;k++){
                    if((prefix[j]^prefix[i-1])>(prefix[k]^prefix[j])){
                        ans=min(ans,(k-i-1));
                    }
                }
            }
        }
    }else{
        for(int i=3;i<=N;i++){
            if(__builtin_clz(arr[i])==__builtin_clz(arr[i-1]) && __builtin_clz(arr[i-1])==__builtin_clz(arr[i-2])){
                ans=1;
            }
        }
    }
    cout << (ans!=INF?ans:-1);
    return 0;
}

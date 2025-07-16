#include <bits/stdc++.h>
#define NMAX 100002
#define lsb(x) (x&(-x))

using namespace std;

struct AIB{
    vector <int> aib;
    AIB (int N){
        aib.resize(N+1);
    }

    void update(int pos,int val){
        for(int i=pos;i<aib.size();i+=lsb(i)){
            aib[i]+=val;
        }
    }

    int query(int pos){
        int ret=0;
        for(int i=pos;i>0;i-=lsb(i)){
            ret+=aib[i];
        }
        return ret;
    }
};

int N;
int arr[NMAX];
long long ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    AIB aib(N);
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    for(int i=N;i>=1;i--){
        ans+=aib.query(arr[i]);
        aib.update(arr[i],1);
    }
    cout << ans;
    return 0;
}

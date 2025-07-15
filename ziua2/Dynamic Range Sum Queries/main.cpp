#include <bits/stdc++.h>
#define NMAX 200002
#define lsb(x) (x&(-x))

using namespace std;

int N,Q,x;
int arr[NMAX];
long long aib[NMAX];

void update(int i,int val)
{
    int start_val=arr[i];
    arr[i]=val;
    for(;i<=N;i+=lsb(i)){
        aib[i]-=start_val;
        aib[i]+=val;
    }
    return;
}

long long query(int x)
{
    long long ret=0;
    for(int i=x;i>0;i-=lsb(i)){
        ret+=aib[i];
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> Q;
    for(int i=1;i<=N;i++){
        cin >> x;
        update(i,x);
    }
    while(Q--){
        int type,x,y;
        cin >> type >> x >> y;
        if(type==1){
            update(x,y);
        }else{
            cout << (query(y)-query(x-1)) << "\n";
        }
    }
    return 0;
}

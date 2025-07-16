#include <bits/stdc++.h>
#define lsb(x) (x&(-x))

using namespace std;

struct AIB{
    vector <long long> aib;
    AIB (int N){
        aib.resize(N+1);
    }

    void update(int pos,long long val){
        for(int i=pos;i<(int)aib.size();i+=lsb(i)){
            aib[i]+=val;
        }
    }

    long long query(int pos){
        long long ret=0;
        for(int i=pos;i>0;i-=lsb(i)){
            ret+=aib[i];
        }
        return ret;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N,Q;
    cin >> N >> Q;
    AIB aib(N + 1);
    vector <int> arr(N+2);
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    while(Q--){
        int type;
        cin >> type;
        if(type==1){
            int L,R;
            long long val;
            cin >> L >> R >> val;
            aib.update(L,val);
            aib.update(R+1,-val);
        }else{
            int pos;
            cin >> pos;
            cout << arr[pos]+aib.query(pos) << "\n";
        }
    }
    return 0;
}

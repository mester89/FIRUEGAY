#include <bits/stdc++.h>
#define NMAX 100002
#define lsb(x) (x&(-x))
#define MOD 9917

using namespace std;

ifstream fin("inv.in");
ofstream fout("inv.out");

struct AIB{
    vector <int> aib;
    AIB (int N){
        aib.resize(N+1);
    }

    void update(int pos,int val){
        for(int i=pos;i<(int)aib.size();i+=lsb(i)){
            aib[i]+=val;
        }
    }

    int query(int pos){
        int ret=0;
        for(int i=pos-1;i>0;i-=lsb(i)){
            ret+=aib[i];
        }
        return ret;
    }
};

int N;
int arr[NMAX];
pair <int,int> nor[NMAX];
long long ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    fin >> N;
    AIB aib(N);
    for(int i=1;i<=N;i++){
        fin >> nor[i].first;
        nor[i].second=i;
    }
    sort(nor+1,nor+N+1);
    int val=1;
    for(int i=1;i<=N;i++){
        arr[nor[i].second]=val;
        if(nor[i].first!=nor[i+1].first) val++;
    }
    // for(int i=1;i<=N;i++){
    //     cout << arr[i] << " ";
    // }
    for(int i=N;i>=1;i--){
        ans+=aib.query(arr[i]);
        aib.update(arr[i],1);
    }
    fout << ans%MOD;
    return 0;
}

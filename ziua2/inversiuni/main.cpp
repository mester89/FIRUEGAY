#include <bits/stdc++.h>
#define lsb(x) (x&(-x))
#define NMAX 200002

using namespace std;

ifstream fin("inversiuni.in");
ofstream fout("inversiuni.out");

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
        for(int i=pos;i>0;i-=lsb(i)){
            ret+=aib[i];
        }
        return ret;
    }

    int find(int val){
        int ans=0;
        int sum_ans=0;
        for(int pas=(1<<18);pas>0;pas>>=1){
            if(ans+pas>=(int)aib.size()) {continue;}
            if(sum_ans+aib[ans+pas]<val){
                ans+=pas;
                sum_ans+=aib[ans];
            }
        }
        return ans;
    }
};

int N;
int arr[NMAX];
long long ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    fin >> N;
    AIB aib(N);
    for(int i=1;i<=N;i++){
        fin >> arr[i];
    }
    for(int i=1;i<=N;i++){
        int smaller=aib.query(arr[i]);
        int bigger=i-smaller-1;
        aib.update(arr[i],1);
        ans+=min(smaller,bigger);
    }
    fout << ans;
    return 0;
}

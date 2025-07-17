#include <bits/stdc++.h>
#define lsb(x) (x&(-x))
#define NMAX 200002

using namespace std;

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

struct Query{
    char type;
    int x,y;
};

int N,Q;
int salary[NMAX];
Query queries[NMAX];
vector <int> v;
map <int,char> intalnit;

int norm(int val)
{
    return lower_bound(v.begin(),v.end(),val)-v.begin() +1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> Q;
    for(int i=1;i<=N;i++){
        cin >> salary[i];
        if(!intalnit[salary[i]]){
            v.push_back(salary[i]);
            intalnit[salary[i]]=1;
        }
    }
    for(int i=1;i<=Q;i++){
        cin >> queries[i].type >> queries[i].x >> queries[i].y;
        if(queries[i].type=='?' && !intalnit[queries[i].x]){
            v.push_back(queries[i].x);
            intalnit[queries[i].x]=1;
        }
        if(!intalnit[queries[i].y]){
            v.push_back(queries[i].y);
            intalnit[queries[i].y]=1;
        }
    }
    sort(v.begin(),v.end());
    AIB aib(v.size()+2);
    for(int i=1;i<=N;i++){
        // cout << norm(salary[i]) << " ";
        aib.update(norm(salary[i]),1);
    }
    // return 0;
    for(int q=1;q<=Q;q++){
        if(queries[q].type=='!'){
            aib.update(norm(salary[queries[q].x]),-1);
            aib.update(norm(queries[q].y),1);
            salary[queries[q].x]=queries[q].y;
        }else{
            cout << aib.query(norm(queries[q].y))-aib.query(norm(queries[q].x)-1) << "\n";
        }
    }
    return 0;
}

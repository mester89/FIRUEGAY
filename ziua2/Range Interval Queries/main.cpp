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
    int pos,val;
    int *ans;
};

struct Query_big{
    int a,b,c,d;
    int q_ad,q_ac,q_bd,q_bc;
};

struct Element{
    int val,pos;
};

bool operator <(const Element &e1, const Element &e2)
{
    return e1.val < e2.val;
}

bool operator < (const Query &q1, const Query &q2)
{
    return q1.val < q2.val;
}

int N,Q_big;
Element arr[NMAX];
Query_big queries_big[NMAX];
vector<Query> queries_small;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> Q_big;
    AIB aib(N+2);
    for(int i=1;i<=N;i++){
        cin >> arr[i].val;
        arr[i].pos=i;
    }
    // queries_small.resize(1);
    sort(arr+1,arr+N+1);
    for(int q=1;q<=Q_big;q++){
        cin >> queries_big[q].a >> queries_big[q].b >> queries_big[q].c >> queries_big[q].d;
        int a=queries_big[q].a;
        int b=queries_big[q].b;
        int c=queries_big[q].c;
        int d=queries_big[q].d;
        queries_small.push_back({a-1,c-1,&queries_big[q].q_ac});
        queries_small.push_back({a-1,d,&queries_big[q].q_ad});
        queries_small.push_back({b,c-1,&queries_big[q].q_bc});
        queries_small.push_back({b,d,&queries_big[q].q_bd});
    }
    sort(queries_small.begin(),queries_small.end());
    int q=0;
    for(int i=1;i<=N;i++){
        while(q <(int) queries_small.size()&& queries_small[q].val<arr[i].val){
            *queries_small[q].ans=aib.query(queries_small[q].pos);
            q++;
        }
        aib.update(arr[i].pos,1);
    }
    while(q <(int) queries_small.size()){
        // cout << 1 <<endl;
        *queries_small[q].ans=aib.query(queries_small[q].pos);
        q++;
    }
    for(int q=1;q<=Q_big;q++){
        cout << (queries_big[q].q_bd-queries_big[q].q_bc - (queries_big[q].q_ad - queries_big[q].q_ac)) << "\n";
    }
    return 0;
}

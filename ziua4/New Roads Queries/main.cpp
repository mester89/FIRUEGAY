#include <bits/stdc++.h>

using namespace std;

struct DSU{
    vector <int> T;
    vector <int> fast;
    vector <int> size;
    vector <int> depth;
    vector <int> cost;
    DSU(int N){
        T.resize(N+1);
        size.resize(N+1,1);
        depth.resize(N+1,0);
        cost.resize(N+1,0);
        fast.resize(N+1,1);
        iota(T.begin(),T.end(),0);
        iota(fast.begin(),fast.end(),0);
    }
    int find(int x){
        if(T[x]==x){
            return x;
        }
        return fast[x]=find(fast[x]);
    }

    void join(int x, int y, int c){
        x=find(x);
        y=find(y);
        if(size[x]>size[y]){
            swap(y,x);
        }
        T[x]=y;
        fast[x]=y;
        size[y]+=size[x];
        cost[x]=c;
    }

    bool query(int x,int y){
        x=find(x);
        y=find(y);
        return x==y;
    }

    int calculate_depth(int nod){
        if(depth[nod]>0){
            return depth[nod];
        }else if(T[nod]==nod){
            return depth[nod]=1;
        }else{
            return depth[nod]=calculate_depth(T[nod])+1;
        }
    }

    int max_cost(int a,int b){
        if(!query(a,b)){ return -1; }
        int ans_a=0,ans_b=0;
        // cout << depth[a] << " ; " << depth[b] << " ---- ";
        while(depth[a]<depth[b]){
            // cout << "b";
            ans_b=max(ans_b,cost[b]);
            b=T[b];
        }
        while(depth[b]<depth[a]){
            // cout << "a";
            ans_a=max(ans_a,cost[a]);
            a=T[a];
        }
        // cout << " ---- ";
        // cout << depth[a] << " ; " << depth[b] << endl;
        while(a!=b){
            ans_b=max(ans_b,cost[b]);
            b=T[b];
            ans_a=max(ans_a,cost[a]);
            a=T[a];
        }
        return max(ans_a,ans_b);
    }
};

int N,M,Q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >> Q;
    DSU dsu(N+1);
    for(int i=1;i<=M;i++){
        int x,y;
        cin >> x >> y;
        if(!dsu.query(x,y)){
            dsu.join(x,y,i);
        }
    }
    for(int i=1;i<=N;i++){
        if(dsu.depth[i]==0){
            dsu.calculate_depth(i);
        }
    }
    for(int q=1;q<=Q;q++){
        int a,b;
        cin >> a >> b;
        cout << dsu.max_cost(a,b) << "\n";
    }
    return 0;
}

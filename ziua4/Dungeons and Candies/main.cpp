#include <bits/stdc++.h>
#define KMAX 1002
#define NMAX 12

using namespace std;

struct DSU{
    vector <int> T;
    vector <int> size;
    DSU(int N){
        T.resize(N+1);
        size.resize(N+1,1);
        iota(T.begin(),T.end(),0);
    }
    int find(int x){
        if(T[x]==x){
            return x;
        }
        return T[x]=find(T[x]);
    }

    void join(int x, int y){
        x=find(x);
        y=find(y);
        if(size[y]<size[x]){
            swap(y,x);
        }
        T[x]=y;
        size[x]+=size[y];
    }

    bool query(int x,int y){
        x=find(x);
        y=find(y);
        return x==y;
    }
};


struct Edge{
    int x,y,c;
};

struct Answer{
    int x,y;
};

bool operator <(const Edge &e1, const Edge &e2){
    return e1.c < e2.c;
}

int N,M,K,W;
char a[KMAX][NMAX][NMAX];
vector <Answer> ans;
vector <int> G[KMAX];
char vis[KMAX];
int cnt;

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    cin >> N >> M >> K >> W;
    DSU dsu(K);
    vector <Edge> edges;
    for(int k=1;k<=K;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                cin >> a[k][i][j];
            }
        }
        edges.push_back({0,k,N*M});
    }
    for(int m1=1;m1<=K;m1++){
        for(int m2=m1+1;m2<=K;m2++){
            int dif=0;
            for(int i=1;i<=N;i++){
                for(int j=1;j<=M;j++){
                    dif+=(a[m1][i][j]!=a[m2][i][j]);
                }
            }
            edges.push_back({m1,m2,dif*W});
        }
    }
    sort(edges.begin(),edges.end());
    for(Edge edge:edges){
        if(!dsu.query(edge.x,edge.y)){
            dsu.join(edge.x,edge.y);
            G[edge.x].push_back(edge.y);
            G[edge.y].push_back(edge.x);
            cnt+=edge.c;
        }
    }
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int nod=q.front();
        vis[nod]=1;
        q.pop();
        // cout << nod << endl;
        for(int x:G[nod]){
            if(!vis[x]){
                q.push(x);
                ans.push_back({x,nod});
            }
        }
    }
    cout << cnt << "\n";
    for(Answer x:ans){
        cout << x.x << " " << x.y << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>
#define NMAX 1002

using namespace std;

ifstream fin("oracol.in");
ofstream fout("oracol.out");

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

bool operator <(const Edge &e1,const Edge &e2){
    return e1.c < e2.c;
}

int N,ans;
int cost[NMAX][NMAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    fin >> N;
    vector <Edge> edges;
    DSU dsu(N);
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j++){
            fin >> cost[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=i+1;j<=N;j++){
            edges.push_back({i,j,cost[i+1][j]});
        }
    }
    sort(edges.begin(),edges.end());
    for(Edge edge:edges){
        if(!dsu.query(edge.x,edge.y)){
            // cout << edge.x << " -> " << edge.y << "\n";
            dsu.join(edge.x,edge.y);
            ans+=edge.c;
        }
    }
    fout << ans;
    return 0;
}

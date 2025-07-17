#include <bits/stdc++.h>
#define NMAX 250002

using namespace std;

int N,M,ans;
vector <int> G[NMAX];
vector <int> Gt[NMAX];
vector <int> Gctc[NMAX];
vector <int> S;
vector <vector <int>>C;
int comp[NMAX];
char vis[NMAX];
int T[NMAX];

void sort_top(int nod)
{
    vis[nod]=1;
    for(int x:G[nod]){
        if(!vis[x]) sort_top(x);
    }
    S.push_back(nod);
    return;
}

void dfs(int nod, vector<int> *G,int cur)
{
    vis[nod]=1;
    comp[nod]=cur;
    // C[cur].push_back(nod);
    for(int x:G[nod]){
        if(!vis[x]){
            dfs(x,G,cur);
        }
    }
    return;
}

void dfs2(int nod,int R,vector <int> *G)
{
    // cout << (int)vis[nod] << " : " << R << endl;
    vis[nod]=1;
    if(nod==R || (int)G[nod].size()==0){ return; }
    for(int x:G[nod]){
        // cout << nod << " : " << x << "!" << endl;
        if(!vis[x] && x<=R){
            dfs2(x,R,G);
        }
    }
    return;
}

bool vecini(int x,int y,vector<int> *G)
{
    return binary_search(G[x].begin(), G[x].end(), y);
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        cin >> T[i];
    }
    int E;
    cin >> E;
    for(int i=1;i<=E;i++){
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        Gt[y].push_back(x);
    }
    for(int i=1;i<=M;i++){
        sort(G[i].begin(),G[i].end());
        if(!vis[i]) sort_top(i);
    }
    reverse(S.begin(),S.end());
    memset(vis,0,sizeof(vis));
    for(int x:S){
        if(!vis[x]){
            C.push_back({});
            dfs(x,Gt,C.size()-1);
        } 
    }
    for(int i=1;i<=M;i++){
        for(int j:G[i]){
            if(comp[i]!=comp[j]){
                Gctc[comp[i]].push_back(comp[j]);
            }
        }
    }
    memset(vis,0,sizeof(vis));
    // for(int i=1;i<=N;i++){
    //     cout << comp[T[i]] << " ";
    // }
    // cout << "\n";
    ans=2;
    for(int i=1;i<N;i++){
        if(vecini(T[i],T[i+1],G)){
            ans+=2;
            continue;
        }
        if(comp[T[i]]>comp[T[i+1]]){
            cout << ans;
            return 0;
        }
        dfs2(comp[T[i]],comp[T[i+1]],Gctc);
        if(vis[comp[T[i+1]]]){
            ans++;
        }else{
            cout << ans;
            return 0;
        }
    }
    cout << ans;
    return 0;
}

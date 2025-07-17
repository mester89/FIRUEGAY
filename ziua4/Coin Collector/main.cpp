#include <bits/stdc++.h>
#define NMAX 100002

using namespace std;

int N,M;
vector <int> G[NMAX];
vector <int> Gt[NMAX];
vector <int> Gctc_t[NMAX];
vector <long long> C;
vector <int> S;
char vis[NMAX];
int comp[NMAX];
long long dp[NMAX],ans,arr[NMAX];

void sort_top(int nod)
{
    vis[nod]=1;
    for(int x:G[nod]){
        if(!vis[x]) sort_top(x);
    }
    S.push_back(nod);
    return;
}

void dfs(int nod, vector <int> *G,int cur)
{
    C[cur]+=arr[nod];
    comp[nod]=cur;
    vis[nod]=1;
    for(int x:G[nod]){
        if(!vis[x]) dfs(x,G,cur);
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    for(int i=1;i<=M;i++){
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        Gt[y].push_back(x);
    }
    for(int i=1;i<=N;i++){
        if(!vis[i]) sort_top(i);
    }
    reverse(S.begin(),S.end());
    memset(vis,0,sizeof(vis));
    for(int i:S){
        if(!vis[i]){
            C.push_back({0});
            dfs(i,Gt,C.size()-1);
        }
    }
    for(int i=1;i<=N;i++){
        for(int j:G[i]){
            if(comp[i]!=comp[j]){
                Gctc_t[comp[j]].push_back(comp[i]);
            }
        }
    }
    for(int i=0;i<(int)C.size();i++){
        long long add=0;
        for(int x:Gctc_t[i]){
            add=max(add,dp[x]);
        }
        dp[i]=add+C[i];
        ans=max(ans,dp[i]);
    }
    cout << ans;
    return 0;
}

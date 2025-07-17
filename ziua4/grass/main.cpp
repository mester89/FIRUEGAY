#include <bits/stdc++.h>
#define NMAX 100002

using namespace std;

ifstream fin("grass.in");
ofstream fout("grass.out");

int N,M,ans;
vector <int> G[NMAX];
vector <int> Gt[NMAX];
vector <int> Gctc[NMAX];
vector <int> Gctc_t[NMAX];
vector <int> C;
int dp_to[NMAX],dp_from[NMAX];
char vizitat[NMAX];
vector <int> S;
int comp[NMAX];
char rezolvat[NMAX];

void sort_top(int nod)
{
    vizitat[nod]=1;
    for(int x:G[nod]){
        if(!vizitat[x]) sort_top(x);
    }
    S.push_back(nod);
    return;
}

void ctck(int nod, vector<int> *G,int &size,int cur)
{
    vizitat[nod]=1;
    comp[nod]=cur;
    size++;
    for(int x:G[nod]){
        if(!vizitat[x]) ctck(x,G,size,cur);
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    fin >> N >> M;
    for(int i=1;i<=M;i++){
        int x,y;
        fin >> x >> y;
        G[x].push_back(y);
        Gt[y].push_back(x);
    }
    for(int i=1;i<=N;i++){
        if(!vizitat[i]) sort_top(i);
    }
    reverse(S.begin(),S.end());
    memset(vizitat,0,sizeof(vizitat));
    for(int nod:S){
        if(!vizitat[nod]){
            C.push_back(0);
            ctck(nod,Gt,C.back(),C.size()-1);
        }
    }
    for(int i=1;i<=N;i++){
        for(int j:G[i]){
            if(comp[i]!=comp[j]){
                Gctc[comp[i]].push_back(comp[j]);
                Gctc_t[comp[j]].push_back(comp[i]);
            }
        }
    }
    dp_to[comp[1]]=C[comp[1]];
    dp_from[comp[1]]=C[comp[1]];
    for(int i=comp[1]+1;i<(int)C.size();i++){
        int add=0;
        for(int x:Gctc_t[i]){
            add=max(add,dp_to[x]);
        }
        if(add>0){
            dp_to[i]=C[i] + add;
        }
    }
    for(int i=comp[1]-1;i>=0;i--){
        int add=0;
        for(int x:Gctc[i]){
            add=max(add,dp_from[x]);
        }
        if(add>0){
            dp_from[i]=C[i] + add;
        }
    }
    for(int i=0;i<(int)C.size();i++){
        for(int j:Gctc[i]){
            if(dp_from[i] != 0 && dp_to[j] != 0) {
                ans=max(ans,dp_from[i]+dp_to[j]-C[comp[1]]);
            }
        }
    }
    fout << ans;
    return 0;
}

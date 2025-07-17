#include <bits/stdc++.h>
#define NMAX 100002

int N,M;
std::vector <int> G[NMAX];
std::vector <int> Gt[NMAX];
std::vector <int> st;
std::vector <std::vector<int>> ctc;
char vizitat[NMAX];
int comp[NMAX];

void sort_top(int node)
{
    vizitat[node]=1;
    for(int x:G[node]){
        if(!vizitat[x])
            sort_top(x);
    }
    st.push_back(node);
    return;
}

void dfs(int node, std::vector <int> *G,int curr)
{
    comp[node]=curr;
    ctc[curr-1].push_back(node);
    for(int x:G[node]){
        if(comp[x]==0){
            dfs(x,G,curr);
        }
    }
    return;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> N >> M;
    for(int i=1;i<=M;i++){
        int x,y;
        std::cin >> x >> y;
        G[x].push_back(y);
        Gt[y].push_back(x);
    }
    for(int i=1;i<=N;i++){
        if(!vizitat[i]) sort_top(i);
    }
    std::reverse(st.begin(),st.end());
    memset(vizitat,0,sizeof(vizitat));
    for(int i:st){
        if(comp[i]==0){
            ctc.push_back({});
            dfs(i,Gt,ctc.size());
        }
    }
    std::cout << ctc.size() << "\n";
    for(std::vector<int> comp:ctc){
        for(int node:comp){
            std::cout << node << " ";
        }
        std::cout<< "\n";
    }
    return 0;
}

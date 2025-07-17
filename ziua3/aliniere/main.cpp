#include <bits/stdc++.h>
#define NMAX 100002

using namespace std;

int N,M,K,P;
vector <int> facute[NMAX];

int sectiuni(int mx)
{
    int ret=0;
    int max_solved=0;
    vector <int> solved(M+2);
    vector <int> touched;
    for(int i=1;i<=N;i++){
        for(int pr:facute[i]){
            if(solved[pr]==0){
                touched.push_back(pr);
            }
            solved[pr]++;
            max_solved=max(max_solved,solved[pr]);
        }
        if(max_solved>=mx+1){
            ret++;
            max_solved=0;
            for(int cioara:touched){
                solved[cioara]=0;
            }
            touched.resize(0);
            for(int pr:facute[i]){
                if(solved[pr]==0){
                    touched.push_back(pr);
                }
                solved[pr]++;
                max_solved=max(max_solved,solved[pr]);
            }
        }
        // cout << i << " , " << max_solved << "\n";  
    }
    if(max_solved>0){
        ret++;
    }
    return ret;
}

int caut_bin()
{
    int L,R;
    L=1;
    R=P;
    int ret=P;
    while(L<=R){
        int mij=(L+R)/2;
        int x=sectiuni(mij);
        // cout << mij << " , " << x << "\n";
        if(x<=K){
            ret=mij;
            R=mij-1;
        }else{
            L=mij+1;
        }
        if(mij==0){
            return ret;
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >> K >> P;
    for(int i=1;i<=P;i++){
        int x,y;
        cin >> x >> y;
        facute[x].push_back(y);
    }
    // cout << sectiuni(1);
    cout << caut_bin();
    return 0;
}
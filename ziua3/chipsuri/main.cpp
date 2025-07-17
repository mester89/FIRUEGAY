#include <bits/stdc++.h>
#define NMAX 250002

using namespace std;

struct Magazin{
    int pret,idx;
};

bool operator <(const Magazin &m1, const Magazin &m2)
{
    return m1.pret < m2.pret;
}

int N,M;
Magazin mag[NMAX];
int pos[NMAX];
bitset <NMAX> exclus;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        cin >> mag[i].pret;
        mag[i].idx=i;
    }
    sort(mag+1,mag+N+1);
    for(int i=1;i<=N;i++){
        pos[mag[i].idx]=i;
    }
    for(int q=1;q<=M;q++){
        int K,bun=1;
        cin >> K;
        for(int i=1;i<=K;i++){
            int x;
            cin >> x;
            exclus[pos[x]]=1;
            while(exclus[bun]==1){
                bun++;
            }
        }
        cout << mag[bun].pret << "\n";
        exclus.reset();
    }
    return 0;
}

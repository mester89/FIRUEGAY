#include <bits/stdc++.h>
#define NMAX 7296

using namespace std;

ifstream fin("elimin.in");
ofstream fout("elimin.out");

int N,M,R,C;
int a[NMAX][NMAX];
int ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    fin >> N >> M >> R >> C;
    if(N<=M){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                fin >> a[i][j];
            }
        }
    }else{
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                fin >> a[j][i];
            }
        }
        swap(N,M);
        swap(R,C);
    }
    for(int subset=0;subset<(1<<N);subset++){
        vector <int> sums(M+1);
        int bits=0;
        for(int i=1;i<=N;i++){
            if((subset&(1<<(i-1)))>0) {bits++; continue;}
            for(int j=1;j<=M;j++){
                // cout << a[i][j] << " ";
                sums[j]+=a[i][j];
            }
            // cout << "\n";
        }
        if(bits==R){
            //cout << "!";
            int sum=0;
            sort(sums.begin(),sums.end());
            for(int i=C+1;i<=M;i++){
                //cout << sums[i] << " ";
                sum+=sums[i];
            }
            // cout << "\n";
            ans=max(ans,sum);
        }
        // cout << "\n";
    }
    fout << ans;
    return 0;
}

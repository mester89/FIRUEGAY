#include <bits/stdc++.h>
#define NMAX 18

using namespace std;

ifstream fin("flip.in");
ofstream fout("flip.out");

int N,M;
int A[NMAX][NMAX];
int ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    fin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            fin >> A[i][j];
        }
    }
    for(int subset=0;subset<(1<<M);subset++){
        int sum=0;
        for(int i=1;i<=N;i++){
            int sum_lin=0;
            for(int j=1;j<=M;j++){
                if((subset&(1<<(j-1)))>0){
                    sum_lin-=A[i][j];
                }else{
                    sum_lin+=A[i][j];
                }
            }

            if(sum_lin<0){
                sum_lin=-sum_lin;
            }
            sum+=sum_lin;
            // cout << sum_lin << "\n";
        }
        ans=max(ans,sum);
    }
    fout << ans;
    return 0;
}

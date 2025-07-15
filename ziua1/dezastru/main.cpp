#include <bits/stdc++.h>
#define NMAX 27

using namespace std;

ifstream fin("dezastru.in");
ofstream fout("dezastru.out");

int main()
{
    int N,K;
    long double arr[NMAX];
    pair<char,float> prod[(1<<25)+2];
    long double ans,coef;
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // fin >> N >> K;
    // for(int i=1;i<=N;i++){
    //     // fin >> arr[i];
    // }
    // coef=(long double)1;
    // for(int i=N-K+1;i<=N;i++){
    //     coef*=i;
    // }
    // for(int i=1;i<=K;i++){
    //     coef/=(long double)i;
    // }
    // prod[0]={0,0};
    // for(int i=1;i<(1<<N);i++){
    //     int from=i^(i&-i);
    //     prod[i]={prod[from].first+1,prod[from].second};
    //     if(prod[from].first==K-1){
    //         ans+=prod[i].second;
    //     }
    // }
    // fout << fixed << setprecision(6)<< ans/coef;
    return 0;
}

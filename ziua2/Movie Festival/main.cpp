#include <bits/stdc++.h>
#define NMAX 200002

using namespace std;

struct Movie{
    int L,R;
};

bool operator<(const Movie &m1, const Movie &m2)
{
    return m1.R < m2.R || 
          (m1.R == m2.R && (m1.L > m2.L));
}

int N;
Movie arr[NMAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> arr[i].L >> arr[i].R;
    }
    sort(arr+1,arr+N+1);
    int last=0;
    int ans=0;
    for(int i=1;i<=N;i++){
        if(arr[i].L >= last){
            last=arr[i].R;
            ans++;
        }
    }
    cout << ans;
    return 0;
}

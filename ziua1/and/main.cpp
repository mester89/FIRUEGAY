#include <bits/stdc++.h>
#define NMAX 100002

using namespace std;

ifstream fin("and.in");
ofstream fout("and.out");

int N;
int ans,arr[NMAX];

int main()
{
    fin >> N;
    for(int i=1;i<=N;i++){
        fin >> arr[i];
    }
    for(int bit=0;bit<32;bit++){
        int len=0;
        for(int i=1;i<=N;i++){
            if((arr[i]&(1<<bit))!=0){
                len++;
            }else{
                len=0;
            }
            ans=max(ans,len);
        }
    }
    fout << ans;
}
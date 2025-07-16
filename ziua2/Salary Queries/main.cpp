#include <bits/stdc++.h>
#define lsb(x) (x&(-x))

using namespace std;

struct AIB{
    vector <int> aib;
    AIB(int n){
        aib.reserve(n+1);
    }
    int query(int pos)
    {
        int ret=0;
        for(int i=pos;i>0;i-=lsb(i)){
            ret+=aib[i];
        }
        return ret;
    }
    void update(int pos,int val)
    {
        for(int i=pos;i<aib.size();i+=lsb(i)){
            aib[i]+=val;
        }
        return;
    }
    int find(int val)
    {
        int sum=0;
        int ans=0;
        for(int pas=(1<<18);pas>0;pas>>=1){
            if(ans+pas>aib.size()) continue;
            if(sum+aib[ans+pas]<=val){
                ans+=pas;
                sum+=aib[ans];
            }
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    return 0;
}

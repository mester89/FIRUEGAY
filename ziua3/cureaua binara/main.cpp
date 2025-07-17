#include <bits/stdc++.h>
#define NMAX 1002
#define MOD 1000000007ll

using namespace std;

int Q;

long long nr_biti(long long N,long long bit){
    N++;
    return ((N/(1ll<<(bit+1)))%MOD*((1ll<<bit)%MOD)%MOD + max(N%(1ll<<(bit+1))-(1ll<<bit),0ll)%MOD)%MOD;
}

long long query(long long N)
{
    N++;
    long long ret=0;
    for(int bit=0;bit<63;bit++){
        ret = (ret + ((1ll<<bit)%MOD*nr_biti(N,bit))%MOD)%MOD;
        assert(ret>=0);
    }
    return ret%MOD;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> Q;
    while(Q--){
        long long x1,y1,x2,y2;
        long long out=0;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int bit=0;bit<62;bit++){
            long long x_0,y_0,x_1,y_1;
            x_1=(nr_biti(x2,bit)-nr_biti(x1-1,bit)+MOD)%MOD;
            y_1=(nr_biti(y2,bit)-nr_biti(y1-1,bit)+MOD)%MOD;
            x_0=((x2-x1+1)-x_1+MOD)%MOD;
            y_0=((y2-y1+1)-y_1+MOD)%MOD;
            out =((out + (1ll<<bit)%MOD*x_1%MOD *y_0) % MOD + ((1ll<<bit)%MOD * x_0%MOD * y_1%MOD))%MOD;
        }
        cout << out  << "\n";
    }
    return 0;
}
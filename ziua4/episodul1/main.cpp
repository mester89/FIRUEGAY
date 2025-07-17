#include <bits/stdc++.h>

using namespace std;

class InParser {
    private:
        FILE *fin;
        char *buff;
        int sp;
    
        char read_ch() {
            ++sp;
            if (sp == 4096) {
                sp = 0;
                fread(buff, 1, 4096, fin);
            }
            return buff[sp];
        }
    
    public:
        InParser(const char* nume) {
            fin = fopen(nume, "r");
            buff = new char[4096]();
            sp = 4095;
        }
        
        InParser& operator >> (int &n) {
            char c;
            while (!isdigit(c = read_ch()) && c != '-');
            int sgn = 1;
            if (c == '-') {
                n = 0;
                sgn = -1;
            } else {
                n = c - '0';
            }
            while (isdigit(c = read_ch())) {
                n = 10 * n + c - '0';
            }
            n *= sgn;
            return *this;
        }
        
        InParser& operator >> (long long &n) {
            char c;
            n = 0;
            while (!isdigit(c = read_ch()) && c != '-');
            long long sgn = 1;
            if (c == '-') {
                n = 0;
                sgn = -1;
            } else {
                n = c - '0';
            }
            while (isdigit(c = read_ch())) {
                n = 10 * n + c - '0';
            }
            n *= sgn;
            return *this;
        }
};

class OutParser {
    private:
        FILE *fout;
        char *buff;
        int sp;
     
        void write_ch(char ch) {
            if (sp == 50000) {
                fwrite(buff, 1, 50000, fout);
                sp = 0;
                buff[sp++] = ch;
            } else {
                buff[sp++] = ch;
            }
        }
     
     
    public:
        OutParser(const char* name) {
            fout = fopen(name, "w");
            buff = new char[50000]();
            sp = 0;
        }
        ~OutParser() {
            fwrite(buff, 1, sp, fout);
            fclose(fout);
        }
     
        OutParser& operator << (int vu32) {
            if (vu32 <= 9) {
                write_ch(vu32 + '0');
            } else {
                (*this) << (vu32 / 10);
                write_ch(vu32 % 10 + '0');
            }
            return *this;
        }
     
        OutParser& operator << (long long vu64) {
            if (vu64 <= 9) {
                write_ch(vu64 + '0');
            } else {
                (*this) << (vu64 / 10);
                write_ch(vu64 % 10 + '0');
            }
            return *this;
        }
     
        OutParser& operator << (char ch) {
            write_ch(ch);
            return *this;
        }
        OutParser& operator << (const char *ch) {
            while (*ch) {
                write_ch(*ch);
                ++ch;
            }
            return *this;
        }
};

InParser fin("episodul1.in");
OutParser fout("episodul1.out");

struct DSU{
    vector <int> T;
    vector <int> size;
    vector <long long> sum;
    DSU(int N){
        T.resize(N+1);
        size.resize(N+1,1);
        iota(T.begin(),T.end(),0);
        sum.resize(N+1,0);
    }
    int find(int x){
        if(T[x]==x){
            return x;
        }
        return T[x]=find(T[x]);
    }

    void join(int x, int y,long long c){
        x=find(x);
        y=find(y);
        if(size[y]<size[x]){
            swap(y,x);
        }
        T[x]=y;
        size[y]+=size[x];
        sum[y]+=sum[x]+c;
        // cout << sum[y];
    }

    bool query(int x,int y){
        x=find(x);
        y=find(y);
        return x==y;
    }
};

int Q,N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    fin >> Q;
    DSU dsu(Q);
    while(Q--){
        int type;
        fin >> type;
        if(type==1){
            N++;
        }else if(type==2){
            int x,y,c;
            fin >> x >> y >> c;
            if(!dsu.query(x,y)){
                dsu.join(x,y,c);
                // cout << c << "\n";
            }
        }else{
            int x;
            fin >> x;
            fout << dsu.sum[dsu.find(x)] << "\n";
        }
    }
    return 0;
}

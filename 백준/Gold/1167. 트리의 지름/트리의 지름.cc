#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

struct FastInput{
    static const int SZ = 1 << 20;
    int idx, size;
    char buf[SZ];

    FastInput(): idx(0), size(0) {}

    inline int read(){
        if(idx >= size){
            size = (int)fread(buf, 1, SZ, stdin);
            idx = 0;
            if(size == 0) return EOF;
        }
        return buf[idx++];
    }

    template<typename T>
    inline bool readInt(T& out){
        int c = read();
        T sign = 1;
        T num = 0;

        while(c != EOF && c <= ' ') c = read();
        if(c == EOF) return false;

        if(c == '-'){
            sign = -1;
            c = read();
        }

        while(c >= '0' && c <= '9'){
            num = num * 10 + (c - '0');
            c = read();
        }

        out = num * sign;
        return true;
    }
};

typedef int i1;
typedef pair<i1, i1> i2;

template <typename T> using vec = vector<T>;
template <typename T> using vvc = vector<vector<T>>;

int n;
vvc<i2> E;
vec<i1> W;
int res;
int nod;
vector<int> st;

void dfs(int start){
    st.clear();
    st.push_back(start);

    while(!st.empty()){
        int cur = st.back();
        st.pop_back();

        if(res < W[cur]){
            res = W[cur];
            nod = cur;
        }

        for(const i2& p : E[cur]){
            int nxt = p.second;
            int wei = p.first;
            if(W[nxt] != -1) continue;
            W[nxt] = W[cur] + wei;
            st.push_back(nxt);
        }
    }
}

void solve(){
    FastInput in;
    int cur, nxt, wei;

    in.readInt(n);
    E.assign(n + 1, {});

    for(int i = 0; i < n; i++){
        in.readInt(cur);
        while(true){
            in.readInt(nxt);
            if(nxt == -1) break;
            in.readInt(wei);
            E[cur].push_back({wei, nxt});
        }
    }

    W.assign(n + 1, -1);
    W[1] = 0;
    nod = 1;
    res = 0;
    dfs(1);

    W.assign(n + 1, -1);
    W[nod] = 0;
    res = 0;
    dfs(nod);

    printf("%d\n", res);
}

int main(){
    solve();
    return 0;
}

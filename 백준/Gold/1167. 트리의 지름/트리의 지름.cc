#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef int                 i1;
typedef pair< i1, i1 >      i2;

template <typename T> using vec = std::vector<T>;
template <typename T> using vvc = std::vector<std::vector<T>>;

#define mp      std::make_pair

int n;
vvc< i2 > E;
vec< i1 > W;
int res;
int nod;

void dfs(int start){
    vector<int> st;
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

void solve(void){
    int cur, nxt, wei;
    cin >> n;
    E.resize(n+1);
    for(int i=0;i<n;i++){
        cin >> cur;
        for(;;){
            cin >> nxt;
            if(nxt == -1){ break; }
            cin >> wei;
            E[cur].push_back(mp(wei, nxt));
        }
    }

    W.clear(); W.resize(n+1, -1);
    nod = 1; res = W[1] = 0; dfs(1);
    W.clear(); W.resize(n+1, -1);
    res = W[nod] = 0; dfs(nod);
    cout << res << '\n';
    return;
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
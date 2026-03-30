#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <string>
#include <queue>
using namespace std;
typedef long long ll;

#define PQUE_ASC(a, b)  ((a) > (b))
#define PQUE_DEC(a, b)  ((a) < (b))
#define SORT_ASC(a, b)  ((a) < (b))
#define SORT_DEC(a, b)  ((a) > (b))

typedef int                 i1;
typedef pair< i1, i1 >      i2;

typedef long long           d1;
typedef pair<d1, d1>        d2;
typedef tuple<d1, d1, d1>   d3;
typedef pair< d1, d2 >      dc;

template <typename T> using pque_asc = std::priority_queue<T, vector<T>, greater<T>>;
template <typename T> using pque_dec = std::priority_queue<T, vector<T>, less<T>>;

template <typename T> using que = std::queue<T>;
template <typename T> using stk = std::queue<T>;

template <typename T> using vec = std::vector<T>;
template <typename T> using vvc = std::vector<std::vector<T>>;

#define mp      std::make_pair
#define mt      std::make_tuple
#define ALL(v)  (v).begin(), (v).end()
#define sot(v)  std::sort(ALL(v))
#define rev(v)  std::reverse(ALL(v))

int n;
vvc< i2 > E;
vec< i1 > W;
int res, nod;

void dfs(int cur){
    i1 wei, nxt;
    if(res < W[cur]){ res = W[cur]; nod = cur; }
    for(i2& edge:E[cur]){
        tie(wei, nxt) = edge;
        if(W[nxt] != -1){ continue; }
        W[nxt] = W[cur] + wei; dfs(nxt);
    }
}

void solve(void){
    int a, b, w;
    cin >> n;
    E.resize(n+1); W.resize(n+1);
    for(int i=0;i<n-1;i++){
        cin >> a >> b >> w;
        E[a].push_back({w, b});
        E[b].push_back({w, a});
    }
    W.assign(n+1, -1);
    nod = 1; W[1] = res = 0; dfs(1);
    W.assign(n+1, -1);
    W[nod] = res = 0; dfs(nod);
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
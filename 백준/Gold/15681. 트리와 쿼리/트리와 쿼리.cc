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
typedef pair< i1, i2 >      ic;

typedef double              f1;
typedef pair<f1, f1>        f2;
typedef tuple<f1, f1, f1>   f3;
typedef pair< f1, f2 >      fc;

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

i1 N, R, Q;
vvc< i1 > child;
vec< i1 > dp;

int calc(int curr){
    int res;
    dp[curr] = res = 1;
    for(i1& chd:child[curr]){
        if(dp[chd] != -1){ continue; }
        res += calc(chd);
    }
    return dp[curr] = res;
}

void solve(void){
    i1 u, v, x;
    cin >> N >> R >> Q;
    child.assign(N+1, {});
    dp.assign(N+1, -1);
    for(int i=0;i<N-1;i++){
        cin >> u >> v;
        child[u].push_back(v);
        child[v].push_back(u);
    }
    calc(R);
    for(int i=0;i<Q;i++){
        cin >> x;
        cout << dp[x] << '\n';
    }
    return;
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
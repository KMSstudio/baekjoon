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

typedef long long           i1;
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

i1 N;
vvc< pair< i1, i1 > > edge;     // weight of edge, connect to
vvc< pair< i1, i1 > > dy;       // size of node, total weight

i1 calculate(i1 cur, i1 eidx){
    i1 stt, fnn, cst;
    i1 chd_sze;
    i1 cnt, wei;
    // cout << "cai1: (" << cur << ", " << eidx << ")\n";
    if(dy[cur][eidx].first != -1){ return dy[cur][eidx].second; }
    dy[cur][eidx] = mp(0, 0);
    
    stt = cur;
    tie(cst, fnn) = edge[cur][eidx];
    chd_sze = edge[fnn].size();
    cnt = 1; wei = 0;
    for(int i = 0; i < chd_sze; i++){
        if(edge[fnn][i].second == stt){ continue; }
        calculate(fnn, i);
        cnt += dy[fnn][i].first;
        wei += dy[fnn][i].second;
    }
    wei += cnt*cst;
    dy[cur][eidx] = mp(cnt, wei);
    return wei;
}

i1 get_result(i1 cur){
    i1 chd_sze = edge[cur].size();
    i1 res = 0;
    for(int i = 0; i < chd_sze; i++){
        res += calculate(cur, i);
    }
    return res;
}

void solve(void){
    i1 u, v, d;
    cin >> N;
    edge.assign(N+1, {});
    dy.assign(N+1, {});
    for(int i = 0; i < N-1; i++){
        cin >> u >> v >> d;
        edge[u].push_back(mp(d, v)); dy[u].push_back(mp(-1, -1));
        edge[v].push_back(mp(d, u)); dy[v].push_back(mp(-1, -1));
    }
    for(int i = 1; i <= N; i++){
        cout << get_result(i) << '\n';
    }
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
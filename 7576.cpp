#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;

#define PQUE_ASC(a, b)  ((a) > (b))
#define PQUE_DEC(a, b)  ((a) < (b))
#define SORT_ASC(a, b)  ((a) < (b))
#define SORT_DEC(a, v)  ((a) > (b))

typedef long long           d1;
typedef pair<ll, ll>        d2;
typedef tuple<ll, ll, ll>   d3;
typedef pair< d1, d2 >      dc;

template <typename T> using _qu  = std::queue<T>;
template <typename T> using _stk = std::queue<T>;

template <typename T> using _vec = std::vector<T>;
template <typename T> using _vvc = std::vector<std::vector<T>>;

#define _mp     std::make_pair
#define _mt     std::make_tuple
#define _sot    std::sort
#define _rev    std::reverse

void solve(void){
    d1 N, M;
    d1 inp, cnt, res;
    d1 x, y, w;
    d2 loc;
    _vvc< int > box;
    _qu< dc > cq;
    cin >> M >> N;
    box.clear(); box.resize(N);
    for(int i=0;i<N;i++){ box[i].clear(); box[i].resize(M, 0); }
    cnt = res = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> inp; box[i][j] = inp; 
            if (!inp) { cnt++; }
            else if (inp == 1) { cnt++; box[i][j] = 0; cq.push(_mp(0, _mp(i, j))); }
        }
    }
    while(!cq.empty()) {
        tie(w, loc) = cq.front(); cq.pop();
        tie(x, y) = loc;
        if (box[x][y]){ continue; }
        box[x][y] = 1; cnt--; res = w;
        if (x > 0) { cq.push(_mp(w+1, _mp(x-1, y))); }
        if (x < N-1) { cq.push(_mp(w+1, _mp(x+1, y))); }
        if (y > 0) { cq.push(_mp(w+1, _mp(x, y-1))); }
        if (y < M-1) { cq.push(_mp(w+1, _mp(x, y+1))); }
    }
    if (cnt) { cout << "-1\n"; }
    else { cout << res << '\n'; }
    return;
}

int main(void){
    int TT = 1;
    // ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
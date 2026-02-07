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
#define SORT_DEC(a, b)  ((a) > (b))

typedef long long           d1;
typedef pair<ll, ll>        d2;
typedef tuple<ll, ll, ll>   d3;
typedef pair< d1, d2 >      dc;

template <typename T> using pque= std::priority_queue<T>;
template <typename T> using que = std::queue<T>;
template <typename T> using stk = std::queue<T>;

template <typename T> using vec = std::vector<T>;
template <typename T> using vvc = std::vector<std::vector<T>>;

#define mp      std::make_pair
#define mt      std::make_tuple
#define ALL(v)  (v).begin(), (v).end()
#define sot(v)  std::sort(ALL(v))
#define rev(v)  std::reverse(ALL(v))

d1 N, M;
vvc< int > map;
vec< vvc< bool > > vis;
que< pair< d1, d3 > > q;

void solve(void){
    string inp;
    d3 loc;
    d1 w, b, x, y;

    cin >> N >> M;
    map.clear(); map.resize(N);
    vis.clear(); vis.resize(2);
    vis[0].resize(N); vis[1].resize(N);
    for(int i=0;i<N;i++){
        map[i].resize(M);
        vis[0][i].resize(M, false); vis[1][i].resize(M, false);
        cin >> inp;
        for(int j=0;j<M;j++){
            map[i][j] = inp[j] - '0';
        }
    }
    q.push(mp(1, mt(map[0][0], 0, 0)));
    while(!q.empty()){
        tie(w, loc) = q.front(); q.pop();
        tie(b, x, y) = loc;
        if (b >= 2){ continue; }
        if (vis[b][x][y]){ continue; }

        vis[b][x][y] = 1;
        if (x == N-1 && y == M-1){ cout << w; return; }

        if (x > 0){ q.push(mp(w+1, mt(b + map[x-1][y], x-1, y))); }
        if (x < N-1){ q.push(mp(w+1, mt(b + map[x+1][y], x+1, y))); }
        if (y > 0){ q.push(mp(w+1, mt(b + map[x][y-1], x, y-1))); }
        if (y < M-1){ q.push(mp(w+1, mt(b + map[x][y+1], x, y+1))); }
    }
    cout << -1; return;
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
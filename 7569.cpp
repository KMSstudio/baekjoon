#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <tuple>
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

template <typename T> using pqu = std::priority_queue<T>;
template <typename T> using que = std::queue<T>;
template <typename T> using stk = std::queue<T>;

template <typename T> using vec = std::vector<T>;
template <typename T> using vvc = std::vector<std::vector<T>>;

#define mp      std::make_pair
#define mt      std::make_tuple
#define ALL(v)  (v).begin(), (v).end()
#define sot(v)  std::sort(ALL(v))
#define rev(v)  std::reverse(ALL(v))

d1 M, N, H;
vec< vec< vec< d1 > > > box;
vec< vec< vec< d1 > > > vis;
que< pair< d1, d3 > > q;

void solve(void){
    d1 tmp, now = 0;
    d3 loc;
    d1 x, y, z;
    cin >> M >> N >> H;
    box.resize(H); vis.resize(H);
    for( int i=0;i<H;i++) {
        box[i].resize(N); vis[i].resize(N);
        for(int j=0;j<N;j++) {
            box[i][j].resize(M); vis[i][j].resize(M, 0);
            for(int k=0;k<M;k++){
                cin >> tmp;
                if (tmp == 0){ box[i][j][k] = 0; }
                else if (tmp == 1){ box[i][j][k] = 1; q.push(mp(0, mt(i, j, k))); }
                else if (tmp == -1){ box[i][j][k] = -1; }
            }
        }
    }

    while (!q.empty()) {
        tie(tmp, loc) = q.front(); q.pop();
        tie(x, y, z) = loc;
        if (vis[x][y][z]){ continue; }
        vis[x][y][z] = 1; 
        if (box[x][y][z] == -1){ continue; }
        now = tmp;

        if (x > 0 && !vis[x-1][y][z]){ q.push(mp(now+1, mt(x-1, y, z))); }
        if (x < H-1 && !vis[x+1][y][z]){ q.push(mp(now+1, mt(x+1, y, z))); }
        if (y > 0 && !vis[x][y-1][z]){ q.push(mp(now+1, mt(x, y-1, z))); }
        if (y < N-1 && !vis[x][y+1][z]){ q.push(mp(now+1, mt(x, y+1, z))); }
        if (z > 0 && !vis[x][y][z-1]){ q.push(mp(now+1, mt(x, y, z-1))); }
        if (z < M-1 && !vis[x][y][z+1]){ q.push(mp(now+1, mt(x, y, z+1))); }
    }

    for(int i=0;i<H;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){
                if (box[i][j][k] != -1 && vis[i][j][k] != 1){
                    cout << -1; return;
                }
            }
        }
    }

    cout << now; return;
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
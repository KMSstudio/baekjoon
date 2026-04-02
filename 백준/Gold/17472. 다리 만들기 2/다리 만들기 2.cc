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

i1 land[12][12] = { 0, };
i1 island_cnt;
i1 N, M;
vec< pair< i1, i2 > > Edge;

vec< i1 > R;
vec< i1 > P;

int FIND(int x){
    if(P[x] == -1 || P[x] == x){ return x; }
    else{ return P[x] = FIND(P[x]); }
}

int UNION(int x, int y){
    x = FIND(x); y = FIND(y);
    if(x == y){ return 1; }
    if(R[y] > R[x]){ x^=y;y^=x;x^=y; }
    P[y] = x;
    if(R[y] == R[x]){ R[x]++; } return 0;
}

void ISLAND(int r, int c, int num){
    land[r][c] = num;
    if(land[r][c+1] == -1){ ISLAND(r, c+1, num); }
    if(land[r][c-1] == -1){ ISLAND(r, c-1, num); }
    if(land[r+1][c] == -1){ ISLAND(r+1, c, num); }
    if(land[r-1][c] == -1){ ISLAND(r-1, c, num); }
    return;
}

void CHECK(int r, int c, int dir){
    int _r[2] = {1, 0};
    int _c[2] = {0, 1};

    int cur = land[r][c];
    int nr = r + _r[dir];
    int nc = c + _c[dir];

    if(land[nr][nc] != 0) return;

    int len = 0;
    while(land[nr][nc] == 0 && nr <= N && nc <= M){
        nr += _r[dir];
        nc += _c[dir];
        len++;
    }

    if(land[nr][nc] == cur) return;
    if(land[nr][nc] <= 0) return;
    if(len < 2) return;

    Edge.push_back(mp(len, mp(cur, land[nr][nc])));
}

void solve(void){
    int tmp, res, cnt;
    i1 w, a, b;
    i2 con;
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> tmp; land[i][j] = -tmp;
        }
    }

    island_cnt = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(land[i][j] == -1){ ISLAND(i, j, ++island_cnt); }
        }
    }
    P.assign(island_cnt+1, -1);
    R.assign(island_cnt+1, 1);

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(land[i][j] > 0){
                CHECK(i, j, 0);
                CHECK(i, j, 1);
            }
        }
    }

    sort(ALL(Edge)); res = cnt = 0;
    for(auto& edge:Edge){
        tie(w, con) = edge; tie(a, b) = con;
        // cout << w << ' ' << a << ' ' << b << '\n';
        if(FIND(a) == FIND(b)){ continue; }

        res += w; cnt++;
        UNION(a, b);
    }
    if(cnt != island_cnt-1){ cout << -1; return; }
    cout << res; return;
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
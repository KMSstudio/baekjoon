#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>
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

i1 n, m;
vec< i2 > Coor;
vec< pair< f1, i2 > > Edge;

vec< i1 > R;
vec< i1 > P;

int FIND(int x){
    if(P[x] == -1 || P[x] == x){ return x; }
    else{ return P[x] = FIND(P[x]); }
}

int UNION(int x, int y){
    x = FIND(x); y = FIND(y);
    if(x == y){ return 1; }
    if(R[y] > R[x]){ x^=y; y^=x; x^=y; }
    P[y] = x;
    if(R[y] == R[x]){ R[x]++; } return 0;
}

f1 dist(i2 x, i2 y){
    return sqrt(pow(x.first - y.first, 2) + pow(x.second - y.second, 2));
}

void solve(void){
    i1 a, b;
    f1 res, w;
    i2 con;
    cin >> n >> m;
    R.assign(n+1, 1);
    P.assign(n+1, -1);
    Coor.assign(n+1, {0, 0});
    for(int i=1;i<=n;i++){
        cin >> a >> b;
        Coor[i] = mp(a, b);
    }
    for(int i=1;i<=m;i++){
        cin >> a >> b;
        UNION(a, b);
    }
    for(int u=1;u<=n;u++){
        for(int v=1;v<=n;v++){
            Edge.push_back(mp(
                dist(Coor[u], Coor[v]),
                mp(u, v)
            ));
        }
    }
    sot(Edge);
    res = 0;
    for(pair<f1, i2>& e: Edge){
        tie(w, con) = e; tie(a, b) = con;
        if(FIND(a) == FIND(b)){ continue; }
        res += w; UNION(a, b);
    }
    cout << fixed << setprecision(2) << res;
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
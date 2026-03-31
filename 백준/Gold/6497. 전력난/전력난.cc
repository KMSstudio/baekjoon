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

i1 n, m;
vec< i1 > P;
vec< i1 > R;
vec< pair< i1, i2 > > E;

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

void solve(void){
    i1 a, b, w;
    i2 con;
    i1 res, sum;
    P.assign(n, -1); R.assign(n, 1);
    E.clear(); E.reserve(m);
    sum = 0;
    for(int i=0;i<m;i++){
        cin >> a >> b >> w;
        E.push_back(mp(w, mp(a, b)));
        sum += w;
    }
    sot(E); res = 0;
    for(auto& e:E){
        tie(w, con) = e; tie(a, b) = con;
        if(FIND(a) == FIND(b)){ continue; }
        UNION(a, b); res += w;
    }
    cout << sum - res << '\n';    
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    for(;;){
        cin >> n >> m;
        if(n == 0 && m == 0){ return 0; }
        solve();
    }
    return 0;
}
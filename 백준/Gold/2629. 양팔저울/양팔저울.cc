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

vvc< d1 > dy;
vec< d1 > wei;
d1 N;
vec< d1 > bal;
d1 M;

bool calc(d1 num_ball, d1 q) {
    d1 x = q + 15000, w;
    bool res;
    if (x > 30000 || x < 0){ return false; }
    if (dy[num_ball][x] != -1){ return dy[num_ball][x]; }
    if (num_ball == 0){ return dy[num_ball][x] = (q == 0); }
    
    w = wei[num_ball-1];
    res = calc(num_ball-1, q-w) || calc(num_ball-1, q) || calc(num_ball-1, q+w);
    return dy[num_ball][x] = res;
}

void solve(void){
    d1 tmp;
    cin >> N; wei.resize(N);
    dy.resize(N+1, vec< d1 >(30001, -1));
    for(d1& w:wei){ cin >> w; }
    cin >> M; bal.resize(M);
    for(d1& b:bal){ cin >> b; }

    for(d1& b:bal){
        cout << (calc(N, b) ? 'Y' : 'N') << ' ';
    }
    cout << '\n';
    return;
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
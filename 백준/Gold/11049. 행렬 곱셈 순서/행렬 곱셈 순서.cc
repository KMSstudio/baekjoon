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

vec< d2 > mat;
vvc< d1 > dy;

d1 calc(int st, int fn){
    if (dy[st][fn] != -1){ return dy[st][fn]; }
    if (fn - st <= 1){ return dy[st][fn] = 0; }
    d1 res = -1, tmp;
    for(int spl = st+1; spl < fn; spl++) {
        tmp = calc(st, spl) + calc(spl, fn) + mat[st].first * mat[spl].first * mat[fn-1].second;
        if (res == -1 || res > tmp){ res = tmp; }
    }
    return dy[st][fn] = res;
}

void solve(void){
    d1 N;
    d1 w, h;
    cin >> N;
    mat.resize(N); dy.resize(N+1);
    for(int i=0;i<N;i++){
        dy[i].resize(N+1, -1);
        cin >> h >> w;
        mat[i] = mp(h, w);
    }
    dy[N].resize(N+1, -1);
    cout << calc(0, N) << '\n';
    return;
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
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

vec< d1 > m;
vec< d1 > c;
d1 N, M;

const d1 ABSOLUTE_INFTY = LLONG_MAX/5;
d1 dy[10000001] = { 0, };

void solve(void){
    d1 sm, sc;
    d1 wei, cst;
    cin >> N >> M;
    m.resize(N, 0); sm = 0;
    for(d1& inp:m){ cin >> inp; sm += inp; }
    c.resize(N, 0); sc = 0;
    for(d1& inp:c){ cin >> inp; sc += inp; }

    // dy[w]: minimum c that fill up over w. 
    for(int i=1;i<=M;i++){ dy[i] = ABSOLUTE_INFTY; }
    dy[0] = 0;
    for(int i=0;i<N;i++){
        wei = m[i]; cst = c[i];
        for(int w=M;w>=wei;w--){
            dy[w] = min(dy[w], dy[w-wei]+cst);
        }
        for(int w=wei-1;w>=0;w--){
            dy[w] = min(dy[w], cst);
        }
    }

    cout << dy[M] << '\n';
    return;
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
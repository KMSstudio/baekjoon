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

vvc< d1 > fld;
vvc< d1 > dy;
int N, M;

d1 calc(d1 row, d1 col) {
    if (dy[row][col] != -1) { return dy[row][col]; }
    if (row == 0 && col == 0) { return dy[row][col] = 1; }
    d1 res = 0, val = fld[row][col];
    if(row > 0 && fld[row-1][col] > val){ res += calc(row-1, col); }
    if(row < (N-1) && fld[row+1][col] > val){ res += calc(row+1, col); }
    if(col > 0 && fld[row][col-1] > val){ res += calc(row, col-1); }
    if(col < (M-1) && fld[row][col+1] > val){ res += calc(row, col+1); }
    return dy[row][col] = res;
}

void solve(void){
    cin >> N >> M;
    fld.resize(N); dy.resize(N);
    for(int i=0;i<N;i++){
        fld[i].resize(M); dy[i].resize(M, -1);
        for(int j=0;j<M;j++){ cin >> fld[i][j]; }
    }
    cout << calc(N-1, M-1) << '\n';
    return;
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
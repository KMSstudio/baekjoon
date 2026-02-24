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

d1 k;
vec< d1 > c;
vec< d1 > sum;
vvc< d1 > cost;

d1 calc_cost(d1 stt, d1 fin) {
    d1 res = -1, tmp;
    if(cost[stt][fin] != -1){ return cost[stt][fin]; }
    if(stt == fin){ return cost[stt][fin] = 0; }

    for(int i=stt; i<fin; i++){
        tmp = (calc_cost(stt, i) + calc_cost(i+1, fin)) + (sum[fin] - sum[stt-1]);
        if(res == -1 || res > tmp){ res = tmp; }
    }
    return cost[stt][fin] = res;
}

void solve(void){
    cin >> k;
    c.clear(); c.resize(k+1);
    sum.clear(); sum.resize(k+1);
    cost.clear(); cost.resize(k+1);

    c[0] = sum[0] = 0;
    for(int i=1;i<=k;i++){
        cost[i].resize(k+1, -1);
        cin >> c[i];
        sum[i] = sum[i-1] + c[i];
    }

    cout << calc_cost(1, k) << '\n'; return;
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
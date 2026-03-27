#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;

#define PQUE_ASC(a, b)  ((a) > (b))
#define PQUE_DEC(a, b)  ((a) < (b))
#define SORT_ASC(a, b)  ((a) < (b))
#define SORT_DEC(a, b)  ((a) > (b))

typedef int                 d1;
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

int n;
int dy[1000001];
int pv[1000001];

int calc(int cr){
    int res;
    if(dy[cr] != -1){ return dy[cr]; }
    if(cr <= 1){ return dy[cr] = 0; }
    res = calc(cr-1); pv[cr] = cr-1;
    if(cr % 2 == 0 && res > dy[cr/2]){ res = dy[cr/2]; pv[cr] = cr/2; }
    if(cr % 3 == 0 && res > dy[cr/3]){ res = dy[cr/3]; pv[cr] = cr/3; }
    return dy[cr] = res + 1;
}

void solve(void){
    int cr;
    cin >> n;
    memset(dy, -1, sizeof(dy));
    cout << calc(n) << '\n';
    for(int cr = n; cr != 1; cr = pv[cr]){
        cout << cr << ' ';
    }
    cout << "1\n";
    return;
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
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

int N;
vec< int > card;
vvc< int > dy;

int calc(int st, int fn) {
    if(dy[st][fn] != -1){ return dy[st][fn]; }
    if(fn - st <= 1){ return dy[st][fn] = max(card[st], card[fn]); }
    return dy[st][fn] = max(min(calc(st+1, fn-1), calc(st+2, fn)) + card[st], min(calc(st+1, fn-1), calc(st, fn-2)) + card[fn]);
}

void solve(void){
    cin >> N;
    card.resize(N); for(int& c:card){ cin >> c; }
    dy.clear(); dy.resize(N, vec<int>(N, -1));
    cout << calc(0, N-1) << '\n';
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
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
typedef pair<ll, ll>        d2;
typedef tuple<ll, ll, ll>   d3;
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

int N, K;
int w, cur;
pque_asc< pair< int, int > > q;
vec< bool > vis;

void solve(void){
    cin >> N >> K;
    vis.resize(100001, false);
    q.push(mp(0, N));
    while(!q.empty()){
        tie(w, cur) = q.top(); q.pop();
        if(vis[cur]){ continue; } vis[cur] = true;

        if(cur == K){ cout << w; return; }

        if(cur > 0){ q.push(mp(w+1, cur-1)); }
        if(cur < 100000){ q.push(mp(w+1, cur+1)); }
        if(cur*2 <= 100000){ q.push(mp(w, cur*2)); }
    }
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
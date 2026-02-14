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

vec< d1 > dist;
vec< d3 > edge;
d1 n, m;
const d1 INF = LONG_LONG_MAX/4;

void solve(void){
    d1 a, b, w;
    cin >> n >> m;
    dist.resize(n+1, INF);
    for(int i=0;i<m;i++){
        cin >> a >> b >> w;
        edge.push_back(mt(a, b, w));
    }
    dist[1] = 0;

    for(int i=0;i<n;i++){
        for(d3& tt:edge){
            tie(a, b, w) = tt;
            if(dist[a] == INF){ continue; }
            if(dist[a] + w < dist[b]){ dist[b] = dist[a] + w; }
        }
    }
    for(d3& tt:edge){
        tie(a, b, w) = tt;
        if(dist[a] == INF){ continue; }
        if(dist[a] + w < dist[b]){ cout << "-1\n"; return; }
    }

    for(int i=2;i<=n;i++){
        cout << ((dist[i] == INF) ? -1 : dist[i]) << '\n';
    }
    return;
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
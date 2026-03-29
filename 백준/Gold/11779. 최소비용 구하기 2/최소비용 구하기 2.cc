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

d1 n, m;
vec< d1 > dist;
vec< d1 > from;
vvc< d2 > edge;
pque_asc< dc > Q;

void solve(void){
    int a, b, w, p;
    int d;
    vec< d1 > path;
    d2  p_c;
    cin >> n >> m;
    dist.resize(n+1, -1); from.resize(n+1); edge.resize(n+1);
    for(int i=0;i<m;i++){
        cin >> a >> b >> w;
        edge[a].push_back(mp(w, b));
    }
    cin >> a >> d;
    Q.push(mp(0, mp(0, a)));
    while(!Q.empty()) {
        tie(w, p_c) = Q.top(); Q.pop();
        tie(p, a) = p_c;
        if(dist[a] != -1){ continue; }

        dist[a] = w; from[a] = p;
        for(d2& w_n:edge[a]) {
            d1 wei, nxt;
            tie(wei, nxt) = w_n;
            if(dist[nxt] != -1){ continue; }
            Q.push(mp(w+wei, mp(a, nxt)));
        }
    }
    for(d1 cur = d; cur != 0; cur = from[cur]) {
        path.push_back(cur);
    }
    reverse(ALL(path));
    cout << dist[d] << '\n';
    cout << path.size() << '\n';
    for(d1& nod:path){ cout << nod << ' '; }
    cout << '\n'; return;
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
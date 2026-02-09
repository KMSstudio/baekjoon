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

d1 N, E;
pque_asc< pair< d1, d2 > > pq;
vvc< d2 > adj;
vvc< int > dist;
vvc< bool > vis;

void solve(void){
    d1 a, b, c;
    d1 w, mask, cur, nxt;
    d1 n1, n2;
    d2 loc;
    cin >> N >> E;
    adj.resize(N+1);
    dist.resize(4); vis.resize(4);
    for(int i=0;i<4;i++){
        dist[i].resize(N+1, -1);
        vis[i].resize(N+1, false);
    }
    for(int i=0;i<E;i++){
        cin >> a >> b >> c;
        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));
    }
    cin >> n1 >> n2;
    pq.push(mp(0, mp(0b00 | (n1 == 1), 1)));
    while(!pq.empty()) {
        tie(w, loc) = pq.top(); tie(mask, cur) = loc; pq.pop();
        if(vis[mask][cur]){ continue; } vis[mask][cur] = true; dist[mask][cur] = w;
        
        for(d2& p:adj[cur]) {
            tie(b, c) = p;
            nxt = mask; if(b == n1){ nxt |= 0b01; } else if(b == n2){ nxt |= 0b10; }
            pq.push(mp(w+c, mp(nxt, b)));
        }
    }

    cout << dist[3][N];
    return;
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
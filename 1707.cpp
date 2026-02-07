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

template <typename T> using pque= std::priority_queue<T>;
template <typename T> using que = std::queue<T>;
template <typename T> using stk = std::queue<T>;

template <typename T> using vec = std::vector<T>;
template <typename T> using vvc = std::vector<std::vector<T>>;

#define mp      std::make_pair
#define mt      std::make_tuple
#define ALL(v)  (v).begin(), (v).end()
#define sot(v)  std::sort(ALL(v))
#define rev(v)  std::reverse(ALL(v))

int V, E;
vec< bool > bip;
vvc< int > adj;
vec< bool > vis;

bool trav(int cur){
    // node, set number
    que< pair< int, int > > q;
    int nod, num;
    q.push(mp(cur, 0));
    while(!q.empty()){
        tie(nod, num) = q.front(); q.pop();
        if (vis[nod] && bip[nod] != num){ return false; }
        if (vis[nod]){ continue; } vis[nod] = true; bip[nod] = num;

        for(auto& v:adj[nod]){
            q.push(mp(v, !bip[nod]));
        }
    }
    return true;
}

void solve(void){
    int a, b;
    bool safe;
    cin >> V >> E;
    adj.clear(); bip.clear(); vis.clear();
    adj.resize(V+1); bip.resize(V+1); vis.resize(V+1, false);
    for(int i=0;i<E;i++){
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    for(int cur=1;cur<=V;cur++){
        if(!vis[cur]){ safe = trav(cur); }
        if(!safe){ cout << "NO\n"; return; }
    }
    cout << "YES\n"; return;
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
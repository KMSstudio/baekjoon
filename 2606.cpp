#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;
typedef long long d1;

#define PQUE_ASC(a, b)  ((a) > (b))
#define PQUE_DEC(a, b)  ((a) < (b))
#define SORT_ASC(a, b)  ((a) < (b))
#define SORT_DEC(a, v)  ((a) > (b))

typedef pair<ll, ll> d2;
typedef tuple<ll, ll, ll> d3;

vector< vector< d1 > > adj;
vector< bool > vis;
d1 cnt;

void dfs(int cur){
    vis[cur] = true; cnt++;
    for(d1& nxt:adj[cur]){
        if(!vis[nxt]){ dfs(nxt); }
    }
}

void solve(void){
    int N, M;
    int a, b;
    cin >> N >> M;
    adj.clear(); vis.clear();
    adj.resize(N+1); vis.resize(N+1, false);
    for(int i=0;i<M;i++){
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    cnt=0; dfs(1);
    cout << cnt-1 << '\n';
    return;
}

int main(void){
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
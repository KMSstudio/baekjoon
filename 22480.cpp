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
vector< d1 > vis;
d1 cnt;

void dfs(int cur) {
    vis[cur] = cnt++;
    for(d1& nxt:adj[cur]) {
        if(!vis[nxt]){ dfs(nxt); }
    }
    return;
}

void solve(void){
    d1 N, M, R;
    d1 a, b;
    cin >> N >> M >> R;
    adj.clear(); vis.clear();
    adj.resize(N+1); vis.resize(N+1, 0);
    for(int i=0;i<M;i++){
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    for(int i=1;i<=N;i++){
        sort(adj[i].begin(), adj[i].end()); reverse(adj[i].begin(), adj[i].end());
    }
    cnt=1; dfs(R);
    for(int i=1;i<=N;i++){
        cout << vis[i] << '\n';
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
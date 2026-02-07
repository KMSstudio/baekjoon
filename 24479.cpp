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

#define SORT_THEM   0x01
template <typename T>
int get_array(vector<T>& vec, int sze = -1, int opt = 0) {
    int n = sze;
    if (sze == -1) { cin >> n; }
    vec.clear();
    vec.reserve(n);
    for (int i = 0; i < n; i++) { T x; cin >> x; vec.push_back(x); }
    if(opt & SORT_THEM) { sort(vec.begin(), vec.end()); }
    return n;
}

typedef pair<ll, ll> d2;
typedef tuple<ll, ll, ll> d3;

int V, E, R;
vector< vector<int> > adj;
vector<int> dist;
vector<bool> visit;
int cnt = 1;

void dfs(int node, int call) {
    visit[node] = true;
    dist[node] = cnt++;
    for(auto& n:adj[node]) {
        if (!visit[n]){ dfs(n, call+1); }
    }
    return;
}

void solve(void){
    int a, b;
    cin >> V >> E >> R; R--;
    dist.resize(V); adj.resize(V); visit.resize(V);
    for(int i=0;i<V;i++){ dist[i]=0; visit[i]=false; }
    for(int i=0;i<E;i++){
        cin >> a >> b; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    for(int i=0;i<V;i++){ sort(adj[i].begin(), adj[i].end()); }
    dfs(R, 1);
    for(int i=0;i<V;i++){ cout << dist[i] << '\n'; }
    return;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
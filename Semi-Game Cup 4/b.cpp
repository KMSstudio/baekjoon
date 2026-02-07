#include <bits/stdc++.h>
using namespace std;

using ll = long long;
static const ll INF = (1LL<<62);

struct Node {
    ll d;
    int r, c, dir;
    bool operator>(const Node& other) const { return d > other.d; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    int Tcost;
    cin >> N >> M >> Tcost;

    vector<string> g(N);
    for (int i = 0; i < N; i++) cin >> g[i];

    int sr=-1, sc=-1, sdir=-1;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        if ('0' <= g[i][j] && g[i][j] <= '3') {
            sr=i; sc=j; sdir=g[i][j]-'0';
            g[i][j]='.';
        }
    }

    const int dr[4] = {-1, 0, 1, 0};
    const int dc[4] = {0, -1, 0, 1};

    auto id = [&](int r, int c, int dir)->int {
        return ((r*M + c) << 2) | dir;
    };

    int V = N*M*4;

    vector<int> vis(V, 0);
    vector<char> valid(V, 0);
    vector<int> nr(V, -1), nc(V, -1), nd(V, -1);

    function<void(int,int,int)> dfs = [&](int r, int c, int dir) {
        int u = id(r,c,dir);
        if (vis[u] == 2) return;
        if (vis[u] == 1) {
            valid[u] = 0;
            nr[u] = nc[u] = nd[u] = -1;
            vis[u] = 2;
            return;
        }
        vis[u] = 1;

        if (g[r][c] != 'T') {
            valid[u] = 1;
            nr[u] = r; nc[u] = c; nd[u] = dir;
            vis[u] = 2;
            return;
        }

        int dir2 = (dir + 1) & 3;
        int r2 = r + dr[dir2];
        int c2 = c + dc[dir2];

        if (r2 < 0 || r2 >= N || c2 < 0 || c2 >= M) {
            valid[u] = 0;
            nr[u] = nc[u] = nd[u] = -1;
            vis[u] = 2;
            return;
        }

        int v = id(r2,c2,dir2);
        if (vis[v] != 2) dfs(r2,c2,dir2);

        if (!valid[v]) {
            valid[u] = 0;
            nr[u] = nc[u] = nd[u] = -1;
            vis[u] = 2;
            return;
        }

        valid[u] = 1;
        nr[u] = nr[v];
        nc[u] = nc[v];
        nd[u] = nd[v];

        vis[u] = 2;
    };

    for (int r = 0; r < N; r++) for (int c = 0; c < M; c++) for (int d = 0; d < 4; d++) {
        int u = id(r,c,d);
        if (vis[u] != 2) dfs(r,c,d);
    }

    auto normalize = [&](int r, int c, int dir, int &or_, int &oc_, int &od_)->bool {
        int u = id(r,c,dir);
        if (!valid[u]) return false;
        or_ = nr[u]; oc_ = nc[u]; od_ = nd[u];
        return true;
    };

    vector<ll> dist(V, INF);
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    int r0, c0, d0;
    if (!normalize(sr, sc, sdir, r0, c0, d0)) {
        cout << -1 << "\n";
        return 0;
    }

    dist[id(r0,c0,d0)] = 0;
    pq.push({0, r0, c0, d0});

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int r = cur.r, c = cur.c, dir = cur.dir;
        int u = id(r,c,dir);
        if (cur.d != dist[u]) continue;

        if (g[r][c] == 'S') {
            cout << cur.d << "\n";
            return 0;
        }

        {
            int ndir = (dir + 1) & 3;
            int rr, cc, dd;
            if (normalize(r, c, ndir, rr, cc, dd)) {
                int v = id(rr,cc,dd);
                ll ndist = cur.d + (ll)Tcost;
                if (ndist < dist[v]) {
                    dist[v] = ndist;
                    pq.push({ndist, rr, cc, dd});
                }
            }
        }

        if ((dir & 1) == 0) { // 0 or 2
            // left
            if (c-1 >= 0) {
                int rr, cc, dd;
                if (normalize(r, c-1, dir, rr, cc, dd)) {
                    int v = id(rr,cc,dd);
                    ll ndist = cur.d + 1;
                    if (ndist < dist[v]) {
                        dist[v] = ndist;
                        pq.push({ndist, rr, cc, dd});
                    }
                }
            }
            // right
            if (c+1 < M) {
                int rr, cc, dd;
                if (normalize(r, c+1, dir, rr, cc, dd)) {
                    int v = id(rr,cc,dd);
                    ll ndist = cur.d + 1;
                    if (ndist < dist[v]) {
                        dist[v] = ndist;
                        pq.push({ndist, rr, cc, dd});
                    }
                }
            }
        } else { // 1 or 3
            // up
            if (r-1 >= 0) {
                int rr, cc, dd;
                if (normalize(r-1, c, dir, rr, cc, dd)) {
                    int v = id(rr,cc,dd);
                    ll ndist = cur.d + 1;
                    if (ndist < dist[v]) {
                        dist[v] = ndist;
                        pq.push({ndist, rr, cc, dd});
                    }
                }
            }
            // down
            if (r+1 < N) {
                int rr, cc, dd;
                if (normalize(r+1, c, dir, rr, cc, dd)) {
                    int v = id(rr,cc,dd);
                    ll ndist = cur.d + 1;
                    if (ndist < dist[v]) {
                        dist[v] = ndist;
                        pq.push({ndist, rr, cc, dd});
                    }
                }
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}

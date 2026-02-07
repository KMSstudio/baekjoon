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

#define mp make_pair

void solve(void){
    vector< vector< bool > > vis;
    queue< pair< d1, d2 > > cq;
    d1 w, x, y;
    d1 rx, ry;
    d2 loc;
    d1 I;

    cin >> I;
    vis.clear(); vis.resize(I);
    for(int i=0;i<I;i++){ vis[i].clear(); vis[i].resize(I, false); }
    cin >> x >> y;
    cin >> rx >> ry;
    cq.push(make_pair(0, make_pair(x, y)));
    while(!cq.empty()) {
        tie(w, loc) = cq.front(); cq.pop();
        tie(x, y) = loc;
        if (vis[x][y]){ continue; } vis[x][y] = true;
        if (x == rx && y == ry) { cout << w << '\n'; return; }
        if (x >= 1 && y >= 2) { cq.push(mp(w+1, mp(x-1, y-2))); }
        if (x >= 2 && y >= 1) { cq.push(mp(w+1, mp(x-2, y-1))); }
        if (x < I-1 && y < I-2) { cq.push(mp(w+1, mp(x+1, y+2))); }
        if (x < I-2 && y < I-1) { cq.push(mp(w+1, mp(x+2, y+1))); }
        if (x < I-1 && y >= 2) { cq.push(mp(w+1, mp(x+1, y-2))); }
        if (x < I-2 && y >= 1) { cq.push(mp(w+1, mp(x+2, y-1))); }
        if (x >= 1 && y < I-2) { cq.push(mp(w+1, mp(x-1, y+2))); }
        if (x >= 2 && y < I-1) { cq.push(mp(w+1, mp(x-2, y+1))); }
    }
    return;
}

int main(void){
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
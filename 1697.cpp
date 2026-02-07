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

queue< d2 > cq;
vector< bool > vis;

void solve(void){
    d1 N, K;
    d1 w, a;
    cin >> N >> K;
    cq.push(make_pair(0, N));
    vis.resize(200001, false);
    while(!cq.empty()) {
        tie(w, a) = cq.front(); cq.pop();
        if (vis[a]){ continue; }
        vis[a] = true;
        if (K == a){ cout << w << '\n'; return; }
        if (a-1 >= 0 && !vis[a-1]){ cq.push(make_pair(w+1, a-1)); }
        if (a+1 <= 200000 && !vis[a+1]){ cq.push(make_pair(w+1, a+1)); }
        if (a*2 <= 200000 && !vis[a*2]){ cq.push(make_pair(w+1, a*2)); }
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
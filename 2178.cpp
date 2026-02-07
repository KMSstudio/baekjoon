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

vector< vector< d1 > > fld;
queue< pair< d1, d2 > > call_queue;

void solve(void){
    d1 N, M;
    string inp;
    d1 x, y, w;
    d2 front;
    cin >> N >> M;
    fld.clear(); fld.resize(N+2);
    fld[0].resize(M+2, -1); fld[N+1].resize(M+2, -1);
    for(int i=1;i<=N;i++){
        cin >> inp;
        fld[i].resize(M+2, -1);
        for(int j=0;j<M;j++){ fld[i][j+1] = inp[j] - '0' - 1; }
    }
    call_queue.push(make_pair(1, make_pair(1, 1)));
    while(!call_queue.empty()) {
        tie(w, front) = call_queue.front(); call_queue.pop();
        x = front.first; y = front.second;
        if (fld[x][y]) { continue; }
        fld[x][y] = w;
        if (!fld[x-1][y]){ call_queue.push(make_pair(w+1, make_pair(x-1, y))); }
        if (!fld[x][y-1]){ call_queue.push(make_pair(w+1, make_pair(x, y-1))); }
        if (!fld[x+1][y]){ call_queue.push(make_pair(w+1, make_pair(x+1, y))); }
        if (!fld[x][y+1]){ call_queue.push(make_pair(w+1, make_pair(x, y+1))); }
    }
    cout << fld[N][M] << '\n';
    return;
}

int main(void){
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
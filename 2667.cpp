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

d1 numbering(d1 x, d1 y, d1 num) {
    d1 cnt = 1;
    fld[x][y] = num;
    if (!fld[x-1][y]){ cnt += numbering(x-1, y, num); }
    if (!fld[x][y-1]){ cnt += numbering(x, y-1, num); }
    if (!fld[x+1][y]){ cnt += numbering(x+1, y, num); }
    if (!fld[x][y+1]){ cnt += numbering(x, y+1, num); }
    return cnt;
}

void solve(void){
    d1 N;
    string inp;
    vector< d1 > res;
    d1 sze;
    cin >> N;
    fld.clear(); fld.resize(N+2);
    fld[0].resize(N+2, -1);
    for(int i=1;i<=N;i++){
        cin >> inp;
        fld[i].resize(N+2);
        fld[i][0] = fld[i][N+1] = -1;
        for(int j=0;j<N;j++){
            fld[i][j+1] = inp[j] - '0' - 1;
        }
    }
    fld[N+1].resize(N+2, -1);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(!fld[i][j]) { res.push_back(numbering(i, j, res.size()+1)); }
        }
    }
    sort(res.begin(), res.end());
    sze = res.size();
    cout << sze << '\n';
    for(auto& v:res){
        cout << v << '\n';
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
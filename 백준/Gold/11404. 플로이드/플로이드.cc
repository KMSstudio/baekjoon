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
typedef pair<d1, d1>        d2;
typedef tuple<d1, d1, d1>   d3;
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

#define ABSOLUTE_INF    (INT_MAX / 5)

vvc< int > dist;

void solve(void){
    int n, m;
    int a, b, w;
    cin >> n >> m;
    dist.resize(n+1);
    for(int i=1;i<=n;i++){ dist[i].resize(n+1, ABSOLUTE_INF); dist[i][i] = 0; }

    for(int i=1;i<=m;i++){
        cin >> a >> b >> w;
        if (dist[a][b] > w){ dist[a][b] = w; }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if((dist[j][i] == ABSOLUTE_INF) || (dist[i][k] == ABSOLUTE_INF)){ continue; }
                if(dist[j][k] > dist[j][i] + dist[i][k]){ dist[j][k] = dist[j][i] + dist[i][k]; }
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j] == ABSOLUTE_INF){ cout << 0 << ' '; }
            else { cout << dist[i][j] << ' '; }
        }
        cout << '\n';
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
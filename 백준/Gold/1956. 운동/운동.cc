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

#define ABS_INF LLONG_MAX/8

d1 v, e;
vvc< d1 > dist;

void solve(void){
    d1 a, b, w;
    d1 res = -1;

    cin >> v >> e;
    dist.resize(v+1);
    for(int i=1;i<=v;i++){ dist[i].resize(v+1, ABS_INF); dist[i][i] = 0; }
    for(int i=1;i<=e;i++){
        cin >> a >> b >> w;
        dist[a][b] = w;
    }

    for(int mid=1;mid<=v;mid++){
        for(int lft=1;lft<=v;lft++){
            for(int rht=1;rht<=v;rht++){
                if(dist[lft][mid] == ABS_INF || dist[mid][rht] == ABS_INF){ continue; }
                if(dist[lft][rht] > dist[lft][mid] + dist[mid][rht]){ dist[lft][rht] = dist[lft][mid] + dist[mid][rht]; }
            }
        }
    }

    for(int i=1;i<=v;i++){
        for(int j=i+1;j<=v;j++){
            if(dist[i][j] == ABS_INF || dist[j][i] == ABS_INF){ continue; }
            if(res == -1 || res > dist[i][j] + dist[j][i]){ res = dist[i][j] + dist[j][i]; }
        }
    }

    cout << res << '\n'; return;
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
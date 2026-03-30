#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <string>
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

int n, m;
vvc< int > dist;
vvc< int > from;
vec< int > path;

void solve(void){
    int a, b, w;
    int sze;
    cin >> n >> m;
    dist.resize(n+1, vec<int>(n+1, -1));
    from.resize(n+1, vec<int>(n+1, -1));
    for(int i=1;i<=n;i++){ dist[i][i] = 0; from[i][i] = 0; }
    for(int i=0;i<m;i++){
        cin >> a >> b >> w;
        if(dist[a][b] == -1 || dist[a][b] > w){ dist[a][b] = w; from[a][b] = a; }
    }

    for(int mid=1;mid<=n;mid++){
        for(int lft=1;lft<=n;lft++){
            for(int rht=1;rht<=n;rht++){
                if(dist[lft][mid] == -1 || dist[mid][rht] == -1){ continue; }
                if(dist[lft][rht] == -1 || dist[lft][rht] > dist[lft][mid] + dist[mid][rht]){
                    dist[lft][rht] = dist[lft][mid] + dist[mid][rht];
                    from[lft][rht] = from[mid][rht];
                }
            }
        }
    }

    for(int stt=1;stt<=n;stt++){
        for(int fin=1;fin<=n;fin++){
            if(dist[stt][fin] == -1){ cout << 0 << ' '; }
            else{ cout << dist[stt][fin] << ' '; }
        }
        cout << '\n';
    }
    path.resize(n+1);
    for(int stt=1;stt<=n;stt++){
        for(int fin=1;fin<=n;fin++){
            if(dist[stt][fin] <= 0){ cout << 0 << '\n'; continue; }
            sze = 0;
            for(int cur = fin; cur != stt; cur = from[stt][cur]) {
                path[sze++] = cur;
            }
            if(sze != 0){ path[sze++] = stt; }
            cout << sze << ' ';
            for(int idx = sze-1; idx>=0; idx--){ cout << path[idx] << ' '; }
            cout << '\n';
        }
    }
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
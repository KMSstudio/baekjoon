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
typedef pair<ll, ll>        d2;
typedef tuple<ll, ll, ll>   d3;
typedef pair< d1, d2 >      dc;

template <typename T> using pque= std::priority_queue<T>;
template <typename T> using que = std::queue<T>;
template <typename T> using stk = std::queue<T>;

template <typename T> using vec = std::vector<T>;
template <typename T> using vvc = std::vector<std::vector<T>>;

#define mp      std::make_pair
#define mt      std::make_tuple
#define ALL(v)  (v).begin(), (v).end()
#define sot(v)  std::sort(ALL(v))
#define rev(v)  std::reverse(ALL(v))

int N, M;
vvc< int > adj;
vvc< bool > flip;
que< int > q;
vec< int > in;
vec< int > deg;
vec< int > out;

void solve(void){
    int inp, a, b;
    cin >> N;
    adj.clear(); flip.clear(); in.clear(); deg.clear(); out.clear();
    adj.resize(N+1); flip.resize(N+1); in.reserve(N+1); deg.resize(N+1, 0);
    for(int i=1;i<=N;i++){
        cin >> inp;
        in.push_back(inp);
        flip[i].resize(N+1, false);
    }
    cin >> M;
    for(int i=1;i<=M;i++){
        cin >> a >> b;
        flip[a][b] = flip[b][a] = true;
    }
    for(int ank=0;ank<N;ank++){
        for(int hok=ank+1;hok<N;hok++){
            a = in[ank]; b = in[hok];
            if (flip[a][b]) { deg[a]++; adj[b].push_back(a); }
            else { deg[b]++; adj[a].push_back(b); }
        }
    }
    for(int i=1;i<=N;i++){ if(!deg[i]){ q.push(i); } }
    while(!q.empty()) {
        a = q.front(); q.pop();
        out.push_back(a);
        for(int& v:adj[a]){ if(!(--deg[v])){ q.push(v); } }
    }
    if (out.size() != N){ cout << "IMPOSSIBLE\n"; return; }
    for(int& v:out){ cout << v << ' '; }
    cout << '\n'; return;
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
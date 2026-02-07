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
vec< int > inp;
vvc< int > adj;
que< int > q;

void solve(void){
    int a, b, cur;
    cin >> N >> M;
    inp.resize(N+1);
    adj.resize(N+1);
    for(int i=0;i<M;i++){
        cin >> a >> b;
        inp[b]++; adj[a].push_back(b);
    }
    for(int i=1;i<=N;i++){
        if (!inp[i]){ q.push(i); }
    }
    while(!q.empty()){
        cur = q.front(); q.pop();
        cout << cur << ' ';
        for(int& v:adj[cur]){
            if(!(--inp[v])){ q.push(v); }
        }
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
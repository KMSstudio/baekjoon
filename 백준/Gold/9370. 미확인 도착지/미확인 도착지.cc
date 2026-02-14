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

int n, m, t;
int s, g, h;
vvc< pair<int, int> > adj;
vec< bool > vis;
vec< int > candit;
vec< int > dist;
vec< int > res;
pque_asc< pair< int, int > > pq;

void solve(void){
    int a, b, d, w;
    bool tmp;
    cin >> n >> m >> t;
    cin >> s >> g >> h;
    adj.clear(); adj.resize(n+1);
    vis.clear(); vis.resize(n+1, false);
    dist.clear(); dist.resize(n+1, -1);
    candit.clear(); res.clear();
    
    for(int i=0;i<m;i++){
        cin >> a >> b >> d;
        tmp = (a == g && b == h) || (a == h && b == g);
        adj[a].push_back(mp(b, d*2 - tmp));
        adj[b].push_back(mp(a, d*2 - tmp));
    }
    for(int i=0;i<t;i++){
        cin >> a;
        candit.push_back(a);
    }

    pq.push(mp(0, s));
    while(!pq.empty()){
        tie(w, a) = pq.top(); pq.pop();
        if(vis[a]){ continue; } vis[a] = true;

        dist[a] = w;

        for(pair<int, int>& p:adj[a]){
            tie(b, d) = p;
            if(!vis[b]){ pq.push(mp(w+d, b)); }
        }
    }

    for(int& v:candit){
        if(dist[v] != -1 && dist[v] % 2 == 1) { res.push_back(v); }
    }
    sot(res);
    for(int& v:res){
        cout << v << ' ';
    }
    cout << '\n'; return;
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
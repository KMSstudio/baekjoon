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

int N, M;
pque_asc< int > pq;
vvc< int > adj;
vec< int > ind;

void solve(void){
    int a, b;
    cin >> N >> M;
    adj.resize(N+1); ind.resize(N+1, 0);
    for(int i=0;i<M;i++){
        cin >> a >> b;
        ind[b]++; adj[a].push_back(b);
    }
    for(int i=1;i<=N;i++){ if(!ind[i]){ pq.push(i); } }
    while(!pq.empty()){
        a = pq.top(); pq.pop();
        cout << a << ' ';
        for(int& v:adj[a]){
            if(!(--ind[v])){ pq.push(v); } }
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
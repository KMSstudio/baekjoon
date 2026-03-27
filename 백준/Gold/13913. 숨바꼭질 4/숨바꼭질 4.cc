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

int n, k;
vec< int > D;
pque_asc< pair<int, int> > Q;
vec< int > R;

void solve(void){
    vec< int > pth;
    int w, v;
    cin >> n >> k;
    D.resize(100001, -1);
    Q.push(mp(0, n));

    while(!Q.empty()){
        tie(w, v) = Q.top(); Q.pop();
        if(D[v] != -1){ continue; }

        D[v] = w;
        if(v > 0 && D[v-1] == -1){ Q.push(mp(w+1, v-1)); }
        if(v < 100000 && D[v+1] == -1){ Q.push(mp(w+1, v+1)); }
        if(v <= 50000 && D[v*2] == -1){ Q.push(mp(w+1, v*2)); }
    }

    v = k; w = D[k];
    cout << w << '\n';
    R.clear();
    for(; w; w = D[v]){
        R.push_back(v);
        if(D[v/2] + 1 == w && v%2 == 0){ v = v/2; continue; }
        if(D[v-1] + 1 == w){ v = v-1; continue; }
        if(D[v+1] + 1 == w){ v = v+1; continue; }
    }
    R.push_back(n);
    reverse(ALL(R));
    for(int& r:R){
        cout << r << ' ';
    }
    cout << '\n';
    return;
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
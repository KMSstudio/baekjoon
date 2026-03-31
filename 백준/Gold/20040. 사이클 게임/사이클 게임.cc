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

typedef int                 i1;
typedef pair< i1, i1 >      i2;

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
vec< int > P;
vec< int > R;

int FIND(int x){
    if(P[x] == -1 || P[x] == x){ return x; }
    else{ return P[x] = FIND(P[x]); }
}

int UNION(int a, int b){
    a = FIND(a); b = FIND(b);
    if(a == b){ return 1; }
    if(R[b] > R[a]){ a ^= b; b ^= a; a ^= b; }
    P[b] = a;
    if(R[b] == R[a]){ R[a]++; } return 0;
}

void solve(void){
    int res = 0;
    int a, b;
    cin >> n >> m;
    P.assign(n, -1);
    R.assign(n, 1);
    for(int i=0;i<m;i++){
        cin >> a >> b;
        if(FIND(a) == FIND(b) && res == 0){ res = i+1; }
        UNION(a, b);
    }
    cout << res;
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
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

vec< int > P;
vec< int > R;
int n, m;

int FIND(int x){
    if(P[x] == -1 || P[x] == x){ return x; }
    else{ return P[x] = FIND(P[x]); }
}

void UNION(int x, int y){
    x = FIND(x); y = FIND(y);
    if(R[y] > R[x]){ x ^= y; y ^= x; x ^= y; }
    P[y] = x;
    if(R[y] == R[x]){ R[x]++; }
}

void solve(void){
    int c, root;
    cin >> n;
    cin >> m;
    P.assign(n, -1);
    R.assign(n, 1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> c;
            if(c == 1){ UNION(i, j); }
        }
    }
    if(!m){ cout << "YES"; return; }
    cin >> c; c--; root = FIND(c);
    for(int i=1;i<m;i++){
        cin >> c; c--;
        if(FIND(c) != root){ cout << "NO"; return; }
    }
    cout << "YES"; return;
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
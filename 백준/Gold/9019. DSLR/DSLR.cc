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

typedef int         reg_num;

inline reg_num D(reg_num x){ return x*2 % 10000; }
inline reg_num S(reg_num x){ return x ? x-1 : 9999; }
inline reg_num L(reg_num x){ return (x%1000)*10 + (x/1000); }
inline reg_num R(reg_num x){ return (x%10)*1000 + (x/10); }

typedef int         res_num;

vec< res_num > dy;
vec< reg_num > pv;
que< pair< res_num, pair<reg_num, reg_num> > > Q;

void path(int x){
    reg_num p = pv[x];
    if(p == -1){ return; }
    path(p);

    if(D(p) == x){ cout << 'D'; return; }
    if(S(p) == x){ cout << 'S'; return; }
    if(L(p) == x){ cout << 'L'; return; }
    if(R(p) == x){ cout << 'R'; return; }
    return;
}

void solve(void){
    reg_num a, b, v, p;
    res_num w;
    string res;
    pair<reg_num, reg_num> rev;
    cin >> a >> b;
    dy.clear(); dy.resize(10000, -1);
    pv.clear(); pv.resize(10000, -1);
    Q.push(mp(0, mp(a, -1)));

    while(!Q.empty()) {
        tie(w, rev) = Q.front(); Q.pop();
        tie(v, p) = rev;
        if(dy[v] != -1){ continue; }

        dy[v] = w; pv[v] = p;
        if(dy[D(v)] == -1){ Q.push(mp(w+1, mp(D(v), v))); }
        if(dy[S(v)] == -1){ Q.push(mp(w+1, mp(S(v), v))); }
        if(dy[L(v)] == -1){ Q.push(mp(w+1, mp(L(v), v))); }
        if(dy[R(v)] == -1){ Q.push(mp(w+1, mp(R(v), v))); }
    }
    
    path(b);
    cout << '\n';

    return;
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
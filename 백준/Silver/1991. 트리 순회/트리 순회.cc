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

string inp;
int lft[26];
int rht[26];
int n;

void preord(int cur){
    cout << (char)('A' + cur);
    if(lft[cur] >= 0){ preord(lft[cur]); }
    if(rht[cur] >= 0){ preord(rht[cur]); }
}

void inord(int cur){
    if(lft[cur] >= 0){ inord(lft[cur]); }
    cout << (char)('A' + cur);
    if(rht[cur] >= 0){ inord(rht[cur]); }
}

void postord(int cur){
    if(lft[cur] >= 0){ postord(lft[cur]); }
    if(rht[cur] >= 0){ postord(rht[cur]); }
    cout << (char)('A' + cur);
}

void solve(void){
    int cur;
    cin >> n; cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin, inp); cur = inp[0] - 'A';
        if(inp[2] == '.'){ lft[cur] = -1; }
        else{ lft[cur] = inp[2] - 'A'; }
        if(inp[4] == '.'){ rht[cur] = -1; }
        else{ rht[cur] = inp[4] - 'A'; }
    }
    preord(0); cout << '\n';
    inord(0); cout << '\n';
    postord(0); cout << '\n';
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
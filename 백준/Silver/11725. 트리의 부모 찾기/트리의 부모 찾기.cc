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

int n;
vec< int > P;
vvc< int > E;

void DFS(int cur){
    for(int& nxt:E[cur]){
        if(P[nxt] != 0){ continue; }
        P[nxt] = cur; DFS(nxt);
    }
}

int main(void){
    int a, b;
    cin >> n;
    P.resize(n+1, 0); E.resize(n+1);
    for(int i=0;i<n-1;i++){
        cin >> a >> b;

        E[a].push_back(b); E[b].push_back(a);
    }

    P[1] = 0; DFS(1);

    for(int i=2;i<=n;i++){
        cout << P[i] << '\n';
    }
    return 0;
}

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
typedef pair< i1, i2 >      ic;

typedef double              f1;
typedef pair<f1, f1>        f2;
typedef tuple<f1, f1, f1>   f3;
typedef pair< f1, f2 >      fc;

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

i1 N;
vec< i1 > dy_iam;
vec< i1 > dy_not;
vvc< i1 > edge;

void calculate(i1 cur){
    dy_iam[cur] = 1; dy_not[cur] = 0;
    for(i1& nxt:edge[cur]){
        if(dy_iam[nxt] != -1){ continue; }
        calculate(nxt);
        dy_iam[cur] += min(dy_iam[nxt], dy_not[nxt]);
        dy_not[cur] += dy_iam[nxt];
    }
}

void solve(void){
    i1 a, b;
    cin >> N;
    dy_iam.assign(N+1, -1); dy_not.assign(N+1, -1);
    edge.assign(N+1, {});
    for(int i = 0; i < N - 1; i++){
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    calculate(1);
    cout << min(dy_iam[1], dy_not[1]) << '\n';
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
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

i1 N, K;
vvc< bool > Edge;
vec< pair<i1, i1> > res;

void solve(void){
    i1 a, b;
    cin >> N; K = 0;
    res.clear();
    Edge.assign(N+1, vec<bool>(N+1, false));
    for(int i=0; i<N-1; i++){
        cin >> a >> b;
        Edge[a][b] = Edge[b][a] = true;
    }

    if(N <= 4){
        for(int i=1; i<=N; i++){
            for(int j=i+1; j<=N;j++){
                if(!Edge[i][j]){ res.push_back(mp(i, j)); K++; }
            }
        }
        cout << K << '\n';
        cout << 1 << '\n';
    }
    else{
        for(int i=2; i<=N; i++){
            if(!Edge[1][i]){ res.push_back(mp(1, i)); K++; }
        }
        cout << K << '\n';
        cout << 2 << '\n';
    }
    for(pair<i1, i1>& val : res){
        tie(a, b) = val;
        cout << a << ' ' << b << '\n';
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
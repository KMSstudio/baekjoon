#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <string>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;

#define PQUE_ASC(a, b)  ((a) > (b))
#define PQUE_DEC(a, b)  ((a) < (b))
#define SORT_ASC(a, b)  ((a) < (b))
#define SORT_DEC(a, b)  ((a) > (b))

typedef ll                  i1;
typedef pair< i1, i1 >      i2;
typedef pair< i1, i2 >      ic;

typedef double              f1;
typedef pair<f1, f1>        f2;
typedef tuple<f1, f1, f1>   f3;
typedef pair< f1, f2 >      fc;

template <typename T> using pque_asc = std::priority_queue<T, vector<T>, greater<T>>;
template <typename T> using pque_dec = std::priority_queue<T, vector<T>, less<T>>;

template <typename T> using que = std::queue<T>;
template <typename T> using stk = std::stack<T>;

template <typename T> using vec = std::vector<T>;
template <typename T> using vvc = std::vector<std::vector<T>>;

#define mp      std::make_pair
#define mt      std::make_tuple
#define ALL(v)  (v).begin(), (v).end()
#define sot(v)  std::sort(ALL(v))
#define rev(v)  std::reverse(ALL(v))

pque_dec< pair< i1, i1 > > PQ; // w, i
vec< i1 > S;
vec< i1 > dy;
i1 N, K;

void solve(void){
    i1 inp;
    i1 w, j;
    cin >> N >> K;
    S.assign(N+1, 0); dy.assign(N+1, 0);
    cin >> dy[1]; S[1] = dy[1];
    PQ.push(mp(0, 1));
    for(int i=2; i<=N; i++){
        cin >> inp; S[i] = S[i-1] + inp;
        PQ.push(mp(-S[i-1] + dy[i-2], i));
        for(;;){
            tie(w, j) = PQ.top();
            if(j <= i-K){ PQ.pop(); continue; }
            dy[i] = max(w + S[i], dy[i-1]); break;
        }
    }
    cout << dy[N] << '\n';
    return;
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
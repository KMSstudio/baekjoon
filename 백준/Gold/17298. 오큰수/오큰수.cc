#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
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
template <typename T> using stk = std::stack<T>;

template <typename T> using vec = std::vector<T>;
template <typename T> using vvc = std::vector<std::vector<T>>;

#define mp      std::make_pair
#define mt      std::make_tuple
#define ALL(v)  (v).begin(), (v).end()
#define sot(v)  std::sort(ALL(v))
#define rev(v)  std::reverse(ALL(v))

void solve(void){
}

int N;
stk< pair< i1, i1 > > M;
vec< i1 > R;
int inp;

int main(void){ 
    int w, j;
    scanf("%d", &N);
    R.assign(N, -1);
    for(int i=0; i<N; i++){
        scanf("%d", &inp);
        while(M.size()) {
            tie(w, j) = M.top();
            if(w >= inp){ break; }
            M.pop(); R[j] = inp;
        }
        M.push(mp(inp, i));
    }
    for(i1& r:R){
        printf("%d ", r);
    }
    return 0;
}
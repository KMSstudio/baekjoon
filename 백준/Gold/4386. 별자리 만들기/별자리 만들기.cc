#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <string>
#include <queue>
#include <cmath>
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

typedef pair< double, double > dot;

int n;
vec< dot > S;
pque_asc< pair< double, int > > Q;
double res;
vec< bool > I;

double dist(dot x, dot y){
    return sqrt(pow(x.first - y.first, 2) + pow(x.second - y.second, 2));
}

void solve(void){
    double a, b;
    double w, num;
    cin >> n;
    I.assign(n, false);
    for(int i=0;i<n;i++){
        cin >> a >> b;
        S.push_back(mp(a, b));
    }
    res = 0; Q.push(mp(0, 0));
    while(!Q.empty()){
        tie(w, num) = Q.top(); Q.pop();
        if(I[num]){ continue; }

        res += w; I[num] = true;
        for(int i=0;i<n;i++){
            if(I[i]){ continue; }
            Q.push(mp(dist(S[i], S[num]), i));
        }
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
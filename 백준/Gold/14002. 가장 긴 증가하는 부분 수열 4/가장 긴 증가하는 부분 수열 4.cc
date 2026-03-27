#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <climits>
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
vec< int > A;
vec< int > PA;
vec< int > R;
vec< int > PR;

void solve(void){
    int sze;
    cin >> n;
    A.resize(n); PA.resize(n); for(int& a:A){ cin >> a; }
    R.clear(); PR.clear(); sze = 0;
    for(int i=0;i<n;i++){
        int a = A[i];
        int pos = lower_bound(ALL(R), a) - R.begin();
        if(pos == sze){ R.push_back(a); PR.push_back(i); sze++; }
        else{ R[pos] = a; PR[pos] = i; }
        PA[i] = (pos == 0) ? -1 : PR[pos-1];
    }
    cout << sze << '\n';
    for(int idx = PR[sze-1];idx != -1; idx = PA[idx]) {
        R[--sze] = A[idx];
    }
    for(int& r:R){
        cout << r << ' ';
    }
    cout << '\n';
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <queue>
#include <string>
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

vvc< int > dy;
string A, B;
int A_l, B_l;

void solve(void){
    string A, B, R;
    int fnd, pth;
    cin >> A >> B;
    A_l = A.length(); B_l = B.length();
    A.insert(0, "?"); B.insert(0, "?");
    dy.resize(A_l+1, vec<int>(B_l+1, 0));

    for(int i=1;i<=A_l;i++){
        for(int j=1;j<=B_l;j++){
            dy[i][j] = max(dy[i-1][j], dy[i][j-1]);
            if(A[i] == B[j] && dy[i][j] < dy[i-1][j-1]+1){
                dy[i][j] = dy[i-1][j-1]+1;
            }
        }
    }

    fnd = dy[A_l][B_l]; R = "";
    cout << fnd << '\n';
    for(int r = A_l, c = B_l; r != 0 && c != 0; ){
        if(dy[r][c] == dy[r-1][c]){ r--; continue; }
        if(dy[r][c] == dy[r][c-1]){ c--; continue; }
        R.push_back(A[r]); r--; c--;
    }
    reverse(ALL(R));
    cout << R << '\n';
    return;
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;

#define PQUE_ASC(a, b)  ((a) > (b))
#define PQUE_DEC(a, b)  ((a) < (b))
#define SORT_ASC(a, b)  ((a) < (b))
#define SORT_DEC(a, v)  ((a) > (b))

typedef long long           d1;
typedef pair<ll, ll>        d2;
typedef tuple<ll, ll, ll>   d3;
typedef pair< d1, d2 >      dc;

template <typename T> using qu  = std::queue<T>;
template <typename T> using stk = std::queue<T>;

template <typename T> using vec = std::vector<T>;
template <typename T> using vvc = std::vector<std::vector<T>>;

#define mp      std::make_pair
#define mt      std::make_tuple
#define ALL(v)  (v).begin(), (v).end()
#define sot(v)  std::sort((v).begin(), (v).end())
#define rev(v)  std::reverse((v).begin(), (v).end())

void solve(void){
    d1 N, M;
    d1 a, b;
    vec< bool > vis;
    vec< d2 > laddr;
    vec< d2 > snake;
    qu< d2 > cq;
    d1 w, x, y;
    cin >> N >> M;
    laddr.push_back(mp(-1, 0));
    for(int i=0;i<N;i++){
        cin >> a >> b;
        laddr.push_back(mp(a, b));
    }
    snake.push_back(mp(-1, 0));
    for(int i=0;i<M;i++){
        cin >> a >> b;
        snake.push_back(mp(a, b));
    }
    sot(laddr); sot(snake);
    vis.resize(101, false); cq.push(mp(0, 1));
    while(!cq.empty()) {
        tie(w, x) = cq.front(); cq.pop();
        if (x > 100 || vis[x]){ continue; }
        vis[x] = true;
        if (x == 100){ cout << w << '\n'; return; }
        for(int i=1;i<=6;i++){
            y = x + i;
            tie(a, b) = *lower_bound(ALL(laddr), mp(y, 0LL));
            if (a == y){ y = b; }
            else {
                tie(a, b) = *lower_bound(ALL(snake), mp(y, 0LL));
                if (a == y){ y = b; }
            }
            cq.push(mp(w+1, y));
        }
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
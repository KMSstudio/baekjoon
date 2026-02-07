#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;

#define SORT_THEM   0x01
template <typename T>
int get_array(vector<T>& vec, int sze = -1, int opt = 0) {
    int n = sze;
    if (sze == -1) { cin >> n; }
    vec.clear();
    vec.reserve(n);
    for (int i = 0; i < n; i++) { T x; cin >> x; vec.push_back(x); }
    if(opt & SORT_THEM) { sort(vec.begin(), vec.end()); }
    return n;
}

struct Cmp {
    bool operator()(ll a, ll b) {
        ll aa = abs(a), bb = abs(b);
        return (aa != bb) ? aa > bb : a > b;
    }
};

ll N;
priority_queue<ll, vector<ll>, Cmp> pq;

void solve(void){
    ll cmd;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> cmd;
        if (cmd) {
            pq.push(cmd);
        }
        else {
            if (pq.empty()) { cout << 0 << '\n'; }
            else { cout << pq.top() << '\n'; pq.pop(); }
        }
    }
    return;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
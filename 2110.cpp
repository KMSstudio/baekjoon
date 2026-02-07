#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
typedef long long lint;

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

vector<lint> x;
lint N, C;

int able(lint pad) {
    lint cnt = 1, prev=x[0];
    for (auto& loc:x) {
        if (loc >= prev + pad) { prev = loc; cnt++; }
    }
    return (cnt >= C);
}

void solve(void){
    lint lft = 1, rht = 1e+9, mid;
    cin >> N >> C;
    get_array(x, N, SORT_THEM);
    for(mid=(lft+rht+1)/2; lft<rht; mid=(lft+rht+1)/2) {
        if (able(mid)){ lft = mid; }
        else { rht = mid - 1; }
    }
    cout << lft;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
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

vector<lint> tree;
lint N, M;

int solve(void){
    lint lft = 0, res = 0;
    cin >> N >> M;
    get_array(tree, N, SORT_THEM);
    lft = M;
    for(int idx=N-1;idx>=0;idx--) {
        lint curr = tree[idx], prev = idx ? tree[idx-1] : 0;
        if (lft <= (curr - prev)*(N - idx)){ return curr - ((lft + (N-idx) - 1) / (N-idx));}
        else { lft -= (curr - prev)*(N - idx); }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << solve();
    return 0;
}
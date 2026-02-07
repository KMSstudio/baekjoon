#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
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

int N;
vector<ll> vecA;
vector<ll> lcs;

void solve(void){
    N = get_array(vecA, -1);
    for(auto& a:vecA) {
        auto loc = lower_bound(lcs.begin(), lcs.end(), a);
        if (loc == lcs.end()){ lcs.push_back(a); }
        else{ *loc = a; }
    }
    cout << lcs.size();
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
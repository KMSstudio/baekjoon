#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long lint;

#define SORT_THEM   0x01
template <typename T>
int get_array(vector<T>& vec, int opt = 0) {
    int n;
    cin >> n;
    vec.clear();
    vec.reserve(n);
    for (int i = 0; i < n; i++) { T x; cin >> x; vec.push_back(x); }
    if(opt & SORT_THEM) { sort(vec.begin(), vec.end()); }
    return n;
}

vector<lint> card;
vector<lint> q;

void solve(void){
    get_array(card, SORT_THEM);
    get_array(q);
    for (auto& f: q) {
        cout << upper_bound(card.begin(), card.end(), f) - lower_bound(card.begin(), card.end(), f) << ' ';
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
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

vector<lint> lan;

int able(int v, const int N) {
    lint cnt = 0;
    for (auto& l:lan) {
        cnt += l / v;
    }
    return (cnt >= N);
}

void solve(void){
    lint K, N;
    lint lft=0, rht=INT_MAX, mid;
    cin >> K >> N;
    get_array(lan, K, SORT_THEM);
    for(mid=(lft+rht+1)/2;lft<rht;mid=(lft+rht+1)/2){
        if (able(mid, N)){ lft = mid; }
        else{ rht = mid-1; }
    }
    cout << lft;
    return;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
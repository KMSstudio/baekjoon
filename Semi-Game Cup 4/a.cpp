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
vector<int> L;
vector<int> R;
int field[1001] = { 0, };

void solve(void){
    int l, r;
    cin >> N;
    L.reserve(N); R.reserve(N);
    for (int i = 0; i < N; i++) {
        cin >> l >> r; L.push_back(l); R.push_back(r);
    }
    const int MAXX = 1000;
    vector<char> dp0(MAXX + 1, 0), dp1(MAXX + 1, 0);
    for (int x = 1; x <= MAXX; x++) {
        if (L[0] <= x && x <= R[0]) dp0[x] = 1;
        else dp1[x] = 1;
    }
    for (int i = 1; i < N; i++) {
        vector<char> ndp0(MAXX + 1, 0), ndp1(MAXX + 1, 0);
        for (int x = 1; x <= MAXX; x++) {
            if (!dp0[x] && !dp1[x]) continue;

            for (int y = max(1, x - 1); y <= min(MAXX, x + 1); y++) {
                if (L[i] <= y && y <= R[i]) {
                    if (dp0[x]) ndp0[y] = 1;
                    if (dp1[x]) ndp1[y] = 1;
                } else {
                    if (dp0[x]) ndp1[y] = 1;
                }
            }
        }
        dp0.swap(ndp0);
        dp1.swap(ndp1);
    }
    bool ok = false;
    for (int x = 1; x <= MAXX; x++) if (dp0[x] || dp1[x]) { ok = true; break; }
    cout << (ok ? "World Champion" : "Surrender") << "\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;
typedef long long d1;

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

typedef pair<ll, ll> d2;
typedef tuple<ll, ll, ll> d3;


void solve(void){
    d1 M;
    d1 tmp;
    priority_queue< d1, vector<d1>, greater<d1> > pqM;
    priority_queue< d1, vector<d1>, less<d1> > pqm;
    cin >> M;
    cout <<(M+1)/2 << '\n';
    cin >> tmp; pqM.push(tmp); cout << tmp << ' ';
    for(int i=0;i<(M/2);i++){
        cin >> tmp; pqM.push(tmp);
        cin >> tmp; pqm.push(tmp);
        while(pqM.top() < pqm.top()) { 
            pqm.push(pqM.top()); pqM.pop(); pqM.push(pqm.top()); pqm.pop();
        }
        cout << pqM.top() << ' ';
    }
    cout << '\n';
    return;
}

int main(void){
    int T;
    ios::sync_with_stdio(false);
    cin.tie(0); cin >> T;
    for(int i=0;i<T;i++){ solve(); }
    return 0;
}
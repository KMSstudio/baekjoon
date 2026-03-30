#include <iostream>
#include <vector>
using namespace std;

typedef long long i1;
typedef pair<i1, int> i2;

int n;
vector<vector<i2>> E;
vector<i1> W;
i1 res;
int nod;

void dfs(int cur){
    if(res < W[cur]){
        res = W[cur];
        nod = cur;
    }

    for(const i2& p : E[cur]){
        i1 wei = p.first;
        int nxt = p.second;
        if(W[nxt] != -1) continue;
        W[nxt] = W[cur] + wei;
        dfs(nxt);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    E.assign(n + 1, {});

    for(int i = 0; i < n; i++){
        int cur;
        cin >> cur;
        while(true){
            int nxt;
            cin >> nxt;
            if(nxt == -1) break;
            i1 wei;
            cin >> wei;
            E[cur].emplace_back(wei, nxt);
        }
    }

    W.assign(n + 1, -1);
    W[1] = 0;
    nod = 1;
    res = 0;
    dfs(1);

    W.assign(n + 1, -1);
    W[nod] = 0;
    res = 0;
    dfs(nod);

    cout << res << '\n';
    return 0;
}

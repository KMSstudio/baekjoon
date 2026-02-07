#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long lint;

vector<lint> field;

int main(void){
    lint n, m, a;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++){ cin >> a; field.push_back(a); }
    sort(field.begin(), field.end());

    cin >> m;
    for(int i=0;i<m;i++) {
        cin >> a;
        printf("%d\n", binary_search(field.begin(), field.end(), a));
    }
    return 0;
}

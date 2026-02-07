#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n' << a - b << '\n' << a * b << '\n' << a / b << '\n' << a % b << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();

    return 0;
}
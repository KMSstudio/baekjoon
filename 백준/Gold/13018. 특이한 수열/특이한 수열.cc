#include <iostream>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	if(N == K){
		cout << "Impossible";
		return 0;
	}
	cout << N - K << " ";
	for(int i = 1;  i < N-K; i++) cout << i << " ";
	for(int i = N-K+1; i <= N; i++) cout << i << " ";
    return 0;
}
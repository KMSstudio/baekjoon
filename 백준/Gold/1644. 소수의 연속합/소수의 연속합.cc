#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;

#define PQUE_ASC(a, b)  ((a) > (b))
#define PQUE_DEC(a, b)  ((a) < (b))
#define SORT_ASC(a, b)  ((a) < (b))
#define SORT_DEC(a, b)  ((a) > (b))

typedef long long           d1;
typedef pair<d1, d1>        d2;
typedef tuple<d1, d1, d1>   d3;
typedef pair< d1, d2 >      dc;

template <typename T> using pque_asc = std::priority_queue<T, vector<T>, greater<T>>;
template <typename T> using pque_dec = std::priority_queue<T, vector<T>, less<T>>;

template <typename T> using que = std::queue<T>;
template <typename T> using stk = std::queue<T>;

template <typename T> using vec = std::vector<T>;
template <typename T> using vvc = std::vector<std::vector<T>>;

#define mp      std::make_pair
#define mt      std::make_tuple
#define ALL(v)  (v).begin(), (v).end()
#define sot(v)  std::sort(ALL(v))
#define rev(v)  std::reverse(ALL(v))

d1 n;
vec< d1 > primes;

bool is_prime(d1 num){
    d1 div, srt;
    if (~num & 1){ return false; }
    srt = sqrt(num);
    for(div=3; div <= srt; div += 2){
        if(num % div == 0){ return false; }
    }
    return true;
}

void solve(void){
    d1 stt = 0, fin = 1;
    d1 sum = 2, cnt = 0;
    d1 sze;
    cin >> n;
    primes.clear();
    
    primes.resize(1, 2);
    for(int i=2;i<=n;i++){
        if(is_prime(i)){ primes.push_back(i); }
    }
    primes.push_back(0);

    sze = primes.size();
    while(fin < sze && stt < fin){
        if(sum == n){ cnt++; sum += primes[fin++] - primes[stt++]; }
        else if(sum < n){ sum += primes[fin++]; }
        else { sum -= primes[stt++]; }
    }
    cout << cnt << '\n';
    return;
}

int main(void){ 
    int TT = 1;
    ios::sync_with_stdio(false); cin.tie(0);
    // cin >> TT;
    for(int i=0;i<TT;i++){ solve(); }
    return 0;
}
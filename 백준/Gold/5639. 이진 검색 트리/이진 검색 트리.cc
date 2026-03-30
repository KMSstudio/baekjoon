#include <stdio.h>

int pre[10001];
int post[10001];
int N;

void parse(int r_pre, int r_post, int L) {
    int K, idx;
    if(L == 1){ post[r_post] = pre[r_pre]; return; }
    if(L == 0){ return; }
    K = post[r_post+L-1] = pre[r_pre];
    for(idx=r_pre+1; (idx < r_pre + L) && (pre[idx] <= K); idx++){ ; }
    parse(r_pre+1, r_post, idx-(r_pre+1));
    parse(idx, r_post+idx-(r_pre+1), L-1-(idx-(r_pre+1)));
}

int main(void){
    for(N=0; scanf("%d", pre+N) == 1; N++){ ; }
    parse(0, 0, N);
    for(int i=0;i<N;i++){ printf("%d\n", post[i]); }
    return 0;
}
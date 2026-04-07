#include <stdio.h>

int main(void){
    int N;
    int up, dn;
    scanf("%d", &N);
    up = N; dn = (N+1)/2;
    for(int i=0; i<N/2; i++){
        printf("%d %d ", dn--, up--);
    }
    if (N&1){ printf("%d ", dn--); }
    return 0;
}
#include <stdio.h>

int main(void){
    int N;
    int up, dn;
    scanf("%d", &N);
    up = N; dn = 1;
    for(int i=0;i<N/2;i++){
        printf("%d %d ", up--, dn++);
    }
    if(N & 1){
        printf("%d ", (N+1)/2);
    }
    return 0;
}
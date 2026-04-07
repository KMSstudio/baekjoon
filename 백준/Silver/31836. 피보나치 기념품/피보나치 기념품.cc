#include <stdio.h>

int main(void){
    int N;
    int n_set, n_lft;
    int tmp, stt;
    scanf("%d", &N);
    n_set = N/3; n_lft = N%3;
    tmp = (n_lft + !n_lft) - 1;     //  0:0, 1:0, 2:1
    printf("%d\n", tmp + n_set*2);
    if(n_lft == 2){ printf("%d ", 2); }
    for(stt = n_lft + 1; stt < N; stt += 3){
        printf("%d %d ", stt, stt+1);
    }
    printf("\n");
    printf("%d\n", tmp + n_set);
    if(n_lft == 2){ printf("%d ", 1); }
    for(stt = n_lft + 1; stt < N; stt += 3){
        printf("%d ", stt+2);
    }
    printf("\n");
    return 0;
}
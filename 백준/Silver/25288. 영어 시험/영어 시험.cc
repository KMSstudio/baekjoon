#include <stdio.h>

int main(void){
    int N;
    char str[30] = { 0, };
    scanf("%d %s", &N, str);
    for(int i=0;i<N;i++){ printf("%s", str); }
    return 0;
}
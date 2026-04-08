#include <string.h>
#include <stdio.h>

char inp[1000001];
char res[1000001];
char tar[40];
int m;

int main(void){
    int cur, ptr;
    scanf("%s", inp);
    scanf("%s", tar);
    m = strlen(tar);
    for(cur = ptr = 0; inp[cur]; cur++){
        res[ptr++] = inp[cur];
        while(!(ptr < m || strcmp(tar, res+ptr-m) != 0)) {
            ptr -= m; memset(res+ptr, 0, sizeof(char)*m);
        }
    }
    if(res[0]){
        printf("%s", res);
    }
    else{
        printf("FRULA");
    }
    return 0;
}
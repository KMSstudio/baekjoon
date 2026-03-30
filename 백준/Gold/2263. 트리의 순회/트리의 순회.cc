#include <stdio.h>

typedef struct _range{
    int stt;
    int fin;
} Range;

int N;
int pre[100000];
int post[100000];
int in[100000];

void parse(Range r_pre, Range r_in, Range r_post){
    int ank, idx;
    int lft_sze, len;
    len = r_pre.fin - r_pre.stt;

    if(len == 1){ pre[r_pre.stt] = post[r_post.stt]; return; }
    if(len == 0){ return; }

    ank = post[r_post.fin-1];
    for(idx = r_in.stt; in[idx] != ank; idx++){ ; }
    lft_sze = idx - r_in.stt;
    
    pre[r_pre.stt] = ank;
    parse({r_pre.stt+1, r_pre.stt+1+lft_sze}, {r_in.stt, r_in.stt+lft_sze}, {r_post.stt, r_post.stt+lft_sze});
    parse({r_pre.stt+1+lft_sze, r_pre.fin}, {r_in.stt+1+lft_sze, r_in.fin}, {r_post.stt+lft_sze, r_post.fin-1});
}

int main(void){
    scanf("%d", &N);
    for(int i=0;i<N;i++){ scanf("%d", in+i); }
    for(int i=0;i<N;i++){ scanf("%d", post+i); }
    parse({0, N}, {0, N}, {0, N});
    for(int i=0;i<N;i++){ printf("%d ", pre[i]); }
    return 0;
}
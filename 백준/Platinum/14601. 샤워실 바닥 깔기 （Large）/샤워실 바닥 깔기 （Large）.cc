#include <bits/stdc++.h>
using namespace std;

int K, N;
int board[128][128];
int tileNum = 0;

void solveTile(int sx, int sy, int hx, int hy, int size){
    if(size == 2){
        ++tileNum;
        for(int i = sx; i < sx + 2; i++){
            for(int j = sy; j < sy + 2; j++){
                if(i == hx && j == hy) continue;
                board[i][j] = tileNum;
            }
        }
        return;
    }

    int half = size / 2;
    int mx = sx + half;
    int my = sy + half;

    int cx[4] = {mx - 1, mx - 1, mx, mx};
    int cy[4] = {my - 1, my, my - 1, my};

    int quad;
    if(hx < mx && hy < my) quad = 0;      
    else if(hx < mx && hy >= my) quad = 1; 
    else if(hx >= mx && hy < my) quad = 2; 
    else quad = 3;                         

    ++tileNum;

    for(int q = 0; q < 4; q++){
        if(q == quad) continue;
        board[cx[q]][cy[q]] = tileNum;
    }

    solveTile(sx, sy,
              quad == 0 ? hx : cx[0],
              quad == 0 ? hy : cy[0],
              half);

    solveTile(sx, sy + half,
              quad == 1 ? hx : cx[1],
              quad == 1 ? hy : cy[1],
              half);

    solveTile(sx + half, sy,
              quad == 2 ? hx : cx[2],
              quad == 2 ? hy : cy[2],
              half);

    solveTile(sx + half, sy + half,
              quad == 3 ? hx : cx[3],
              quad == 3 ? hy : cy[3],
              half);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K;
    N = 1 << K;

    int x, y;
    cin >> x >> y;

    int hx = N - y;
    int hy = x - 1;

    memset(board, 0, sizeof(board));
    board[hx][hy] = -1;

    solveTile(0, 0, hx, hy, N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
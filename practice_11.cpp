#include <stdio.h>
#include <time.h>
//チェスの盤の縦横サイズ
#define N 8
//クイーンがあることを示す定数
#define QUEEN 1
//クイーンがないことを示す定数
#define EMPTY 0
#define OK 1
#define NG 0
void printQueen(int);
int check(int, int, int, int, int);
int checkQueen(int);
void nQueen(int, int, int);
void initQueen(int);
//チェスの盤
int board[N][N];
//見つけた解の数
int resolve = 0;
//チェス盤の表示
//n１方向のマスの数
void printQueen(int n){
    int i, j;
    printf("----------------\n");
    printf("%d個目の解\n", resolve);//全マスを表示
    for (j = 0; j < n; j++){
        for (i = 0; i < n; i++){
            if (board[j][i] == QUEEN){//(i, j)マスにクイーンがある場合
                printf("Q");
            }
            else{//(i, j)マスにクイーンが無い場合
                printf("*");
            }
        }
        printf("\n");
    }
    printf("\n\n");
}
//  指定された方向に他のクイーンが無いかどうかを判断
//  n：１方向のマスの数
//  i：クイーンの位置の列番号
//  j：クイーンの位置の行番号
//  di：列番号の増加量
//  dj：行番号の増加量
int check(int n, int i, int j, int di, int dj){
    int k;
    int ii, jj;
    for (k = 1; k < n; k++){
        ii = i + di * k;
        jj = j + dj * k;
        if (ii >= n || ii < 0 || jj >= n || jj < 0){// 盤外までチェックしたらその方向にクイーンはない
            break;
        }
        if (board[j + dj * k][i + di * k] == QUEEN){
            return NG;// マス上にクイーンがあればNGを返却
        }
    }
    // その方向にクイーンが無いのでOKを返却
    return OK;
}

// Nクイーン問題を満たしているかどうかを判断
// n：１方向のマスの数

int checkQueen(int n)
{
    int i, j, k;
    int ret;

    for (j = 0; j < n; j++){ // クイーンがあるマスを探索
        for (i = 0; i < n; i++){
            if (board[j][i] == QUEEN){// クイーンのあるマスから縦横斜め方向にクイーンがあるかどうかをチェック
        
                if (!check(n, i, j, -1, 0)){//左方向を確認
                    return NG;
                }
                if (!check(n, i, j, 1, 0)){//右方向をチェック
                    return NG;
                }
                if (!check(n, i, j, 0, -1)){//下方向をチェック
                    return NG;
                }
                if (!check(n, i, j, 0, 1)){//上方向をチェック
                    return NG;
                }
                if (!check(n, i, j, -1, -1)){//左下方向をチェック
                    return NG;
                }
                if (!check(n, i, j, -1, 1)){ //左上方向をチェック
                    return NG;
                }
                if (!check(n, i, j, 1, -1)){//右下方向をチェック
                    return NG;
                }
                if (!check(n, i, j, 1, 1)){//右上方向をチェック
                    return NG;
                }
            }
        }
    }
    return OK;
}

//  クイーンの設置
//   n：１方向のマスの数
//   q：配置済みのクイーンの数
//   k：配置開始
void nQueen(int n, int q, int k){
    int i, j;
    int l;
    if (q == n){//n個クイーン設置ずみの場合
        if (checkQueen(n)){//Nクイーン問題を満たしている場合
            resolve++;//解の数をインクリメント
            printQueen(n);//チェス盤を表示
        }
        return;
    }
    for (l = k; l < n * n; l++){//配置位置の開始点から順にクイーンを配置していく
        j = l / n;//配置位置より行番号と列番号を算出
        i = l % n;
        
        board[j][i] = QUEEN;//(i, j)マスにクイーンを置く

        if (checkQueen(n)){//クイーンを置いてもまだNクイーン問題を満たしている場合
            nQueen(n, q + 1, l + 1);// 次のクイーンを置く
        }
        board[j][i] = EMPTY;//(i, j)マスからクイーンを取り除く
    }
}
//  チェス盤の初期化
//  n：１方向のマスの数

void initQueen(int n){
    int i, j;
    for (j = 0; j < n; j++){
        for (i = 0; i < n; i++){//マスを空にする
            board[j][i] = EMPTY;
        }
    }
}

int main(void){
    clock_t start, end;//チェス盤の初期化
    
    initQueen(N);

    start = clock();

    nQueen(N, 0, 0);//Nクイーン問題を解く

    end = clock();

    printf("time = %f[s]", (double)(end - start) / CLOCKS_PER_SEC);    //処理時間を表示
}

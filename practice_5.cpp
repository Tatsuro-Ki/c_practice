#include <iostream>
using namespace std;
int main(void){ /*メインのコード*/
    int n,y, i;/*変数の宣言*/
    n=0;
    scanf("%d", &n);/*x1をキー入力*/
    printf("入力した値n= %d\n", n);
    printf("--------------------\n");
    if (n<=12){
    y=1;
    i=1;
    
    for (i=1;i<=n;i++){
        y=i*y;
        }
        printf("nの階乗 %d",y);
    }
    if (n>12)
    printf("12以下の整数を入力してください");
}

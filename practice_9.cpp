#include <stdio.h>
#include <math.h>
int main(void){
    float A,psi,x,y;
    scanf("%f", &A);/*x1をキー入力*/
    printf("振幅A= %f\n", A);
    scanf("%f", &psi);/*x1をキー入力*/
    printf("位相遅れψ= %f\n", psi);
    printf("------------------------\n");
    for (x=1;x<62.8;x++){//周期10πまで計算
        y = A*sin(x-psi);
        printf("y=%f\n", y);
    }
    printf("y=%f", y);
}

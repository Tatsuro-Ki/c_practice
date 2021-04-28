#include <iostream>
using namespace std;
int main(void){ //メインのコード
    float x1, x2, y1, y2, y3, y4 ;//変数の宣言
    
    scanf("%f", &x1);//x1をキー入力
    printf("x1= %f\n", x1);
    scanf("%f", &x2);
    printf("x2= %f\n", x2);
    printf("--------------------\n");
    
    y1 = x1 + x2;
    
    y2 = x1 - x2;
    
    y3 = x1 * x2;
    
    y4 = x1 / x2;
    
    // y5 = x1 % x2;
    
    printf("和 %f\n", y1);
    printf("差 %f\n", y2);
    printf("積 %f\n", y3);
    printf("商 %f\n", y4);
    // printf("剰余 %f\n", y5);
}

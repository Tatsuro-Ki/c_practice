#include <iostream>
#include <math.h>
using namespace std;
int main(void){ /*メインのコード*/
    int x[101],i,y,z3,z5,z7,z11;/*変数の宣言*/
    for (i=1; i<=100; i++){
        x[i]=0;
        x[i]=i;
        
        y=0;
        z3=0;
        z5=0;
        z7=0;
        z11=0;
        
        y = pow(-1, x[i]);//奇数偶数の分別
        z3 = x[i]%3;//3の倍数排除
        z5 = x[i]%5;//5の倍数排除
        z7 = x[i]%7;//7の倍数排除
        z11= x[i]%11;//11の倍数排除
        
        if (i==2)
        printf("%d\n",x[i]);
        if (i==3)
        printf("%d\n",x[i]);
        if (i==5)
        printf("%d\n",x[i]);
        if (i==7)
        printf("%d\n",x[i]);
        if (i==11)
        printf("%d\n",x[i]);
        if (y==-1)//奇数だけ表示
            if (z3>0)//3の倍数排除
                if (z5>0)//5の倍数排除
                if (z7>0)//7の倍数排除
                if (z11>0)//11の倍数排除
                    printf("%d\n",x[i]);
        }
    }

#include <stdio.h>
#include <math.h>
int main(void){
    float h,v0,v,t;
    
    scanf("%f", &v0);/*x1をキー入力*/
    printf("初速度v0[m/s]= %f\n", v0);
    printf("------------------------\n");
    
    for (t=1;t<=500;t++){
    
        h = 0.1*v0*t-9.81*pow(t*0.1, 2.0)/2;
        printf("%f秒後の高さh[m]=%f\n", 0.1*t,h);
        v = v0-9.81*t*0.1;
        printf("%f秒後の速度[m/s]=%f\n",0.1*t,v);
        printf("------------------------\n");
        
        if (h<2){
        if(h>-2){
        printf("------------------------\n");
        printf("%f秒後に地面に衝突した\n",0.1*t);
        printf("------------------------\n");
        printf("------------------------\n");
        }
        }
    }
}

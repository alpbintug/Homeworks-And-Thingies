#include <stdio.h>
#include <math.h>

double fonk(double x1,int i,int j,float a[]){
    double m=0;
    for (j=0;j<i+1; j++)
    m=m + a[j] * pow(x1,j);
    return m;
}
double fonkturev(double x1,int i,int j,float a[]){
    double k=0;
    for (j=1;j<i+1; j++){
    k=k+j + j*a[j]*pow(x1,j-1);
    }
    return k;
}


int main(){
    double x1,x2,h;
    int i,j;
    float a[50];
    printf("fonksiyonun derecesini giriniz ");
    scanf("%d",&i);
    for (j=0; j<i+1; j++){
        printf("%d. dereceden terimin katsayisini giriniz", j);
        scanf("%f",&a[j]);
    }
    printf("Fonksiyonunuz= ");
    for (j=0; j<i+1; j++){
    printf("(%f*x^%d)+",a[j],j);
}

    printf("\nbaslangic degeri giriniz ");
    scanf("%f",&x1);
    printf("\nhata miktari giriniz ");
    scanf("%f",&h);
    x2= x1 - fonk(x1,i,j,a)/fonkturev(x1,i,j,a);
    while ( fabs(x2-x1) > h){
    x1=x2;
    x2= x1 - fonk(x1,i,j,a)/fonkturev(x1,i,j,a);
}
    printf("fonksiyonun koku %f\n", x2);
    system("PAUSE");
    }

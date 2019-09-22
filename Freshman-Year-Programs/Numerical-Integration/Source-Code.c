#include <math.h>
#include <stdio.h>
#define MAX 50

double fonk(float x,int i,int j,float a[]){
    double m=0;
    for (j=0;j<i+1; j++)
    m=m + a[j] * pow(x,j);
    return m;
}

int main(){
    float dx,x1,x2,area;
    int i,j;
    float a[MAX];
    printf("fonksiyonun derecesini giriniz ");
    scanf("%d",&i);
    for (j=0; j<i+1; j++){
        printf("%d. dereceden terimin katsayisini giriniz", j);
        scanf("%f",&a[j]);
    }
    printf("Fonksiyonunuz: ");
    for (j=0; j<i+1; j++){
    printf("+(%f*x^%d)",a[j],j);
}

    printf("\nbaslangic degerini giriniz ");
    scanf("%f",&x1);
    printf("\nbitis degerini giriniz");
    scanf("%f",&x2);
    printf("\ndegisim miktarini giriniz ");
    scanf("%f",&dx);
    area=0;
    while(x1<x2){
    area+=dx*(fonk(x1,i,j,a)+fonk(x1+dx,i,j,a))/2;
    x1+=dx;
}

    printf("\nArea under your function: %f\n", area);
    system("PAUSE");
    }



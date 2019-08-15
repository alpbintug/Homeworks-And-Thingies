#include <stdio.h>
#include <math.h>

double fonk(float x,int i,int j,float a[]){
    double m=0;
    for (j=0;j<i+1; j++)
    m=m + a[j] * pow(x,j);
    return m;
}

int main(){
    float x,dx,h;
    int i,j;
    float a[50];
    printf("Fonksiyonun derecesi=");
    scanf("%d",&i);
    for (j=0; j<i+1; j++){
        printf("%d. dereceden terimin katsayisini giriniz", j);
        scanf("%f",&a[j]);
    }
    printf("Fonksiyonunuz: ");
    for (j=0; j<i+1; j++){
    printf("+(%f*x^%d)",a[j],j);
}

    printf("\nbaslangic degeri giriniz ");
    scanf("%f",&x);
    printf("x'in degisim degerini giriniz ");
    scanf("%f",&dx);
    printf("hata miktari giriniz ");
    scanf("%f",&h);
    while (fabs(fonk(x,i,j,a))>h){
    if (fonk(x,i,j,a)*fonk(x+dx,i,j,a)<0){
    dx=dx/2;
}
    else{
    x=x+dx;
}
}
    printf("Fonksiyonun koku=%f\n", x);
    system("PAUSE");
    }

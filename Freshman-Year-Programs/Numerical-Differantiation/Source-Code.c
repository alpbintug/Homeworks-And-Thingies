#include <math.h>
#include <stdio.h>

double fonk(float x,int i,int j,float a[]){
    double m=0;
    for (j=0;j<i+1; j++)
    m=m + a[j] * pow(x,j);
    return m;
}

int main(){
    float dx,x,tur;
    int i,j;
    int k=0;
    float a[50];
    printf("fonksiyonun derecesini giriniz ");
    scanf("%d",&i);
    for (j=0; j<i+1; j++){
        printf("%d. dereceden terimin katsayisini giriniz", j);
        scanf("%f",&a[j]);
    }
    printf("Fonksiyonunuz: ");
    for (j=0; j<i+1; j++){
    printf("(%f*x^%d)+",a[j],j);
}

    printf("\nx degerini giriniz:");
    scanf("%f",&x);
    printf("degisim miktarini giriniz:");
    scanf("%f",&dx);
    printf("Geri Fark Turev almak isterseniz 1, Merkezi fark Turev almak isterseniz 2, Ileri fark turev almak isterseniz 3 yazin. ");
    scanf("%d",&k);

    if (k==1){
    tur=(fonk(x,i,j,a)-fonk(x-dx,i,j,a))/dx;
}
    else if (k==2){
    tur=(fonk(x+dx,i,j,a)-fonk(x-dx,i,j,a))/(2*dx);
}
    else if (k==3){
    tur=(fonk(x+dx,i,j,a)-fonk(x,i,j,a))/dx;
}


    printf("\nfonksiyonun turevi %f\n", tur);
    system("PAUSE");
    }



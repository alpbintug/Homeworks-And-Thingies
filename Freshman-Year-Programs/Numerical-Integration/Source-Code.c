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
    int power,j;
    float a[MAX];
    printf("Enter the Highest power in your function: ");
    scanf("%d",&power);
    for (j=0; j<power+1; j++){
        printf("Enter the element with power %d: ", j);
        scanf("%f",&a[j]);
    }
    printf("Fonksiyonunuz: ");
    for (j=0; j<power+1; j++){
    printf("+(%f*x^%d)",a[j],j);
}

    printf("\nEnter X1 ");
    scanf("%f",&x1);
    printf("\nEnter X2 ");
    scanf("%f",&x2);
    printf("\nEnter the step size: ");
    scanf("%f",&dx);
    area=0;
    while(x1<x2){
    area+=dx*(fonk(x1,power,j,a)+fonk(x1+dx,power,j,a))/2;
    x1+=dx;
}

    printf("\nArea under your function: %f\n", area);
    }



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
    printf("Power of your function=");
    scanf("%d",&i);
    for (j=0; j<i+1; j++){
        printf("Enter the multiplier of the element with power of %d", j);
        scanf("%f",&a[j]);
    }
    printf("Your function: ");
    for (j=0; j<i+1; j++){
    printf("+(%f*x^%d)",a[j],j);
}

    printf("\nEnter the starting value ");
    scanf("%f",&x);
    printf("\nEnter the change amount of X ");
    scanf("%f",&dx);
    printf("\nEnter the maximum amount of error/deviation ");
    scanf("%f",&h);
    while (fabs(fonk(x,i,j,a))>h){
    if (fonk(x,i,j,a)*fonk(x+dx,i,j,a)<0){
    dx=dx/2;
}
    else{
    x=x+dx;
}
}
    printf("Root of your function=%f\n", x);
    system("PAUSE");
    }

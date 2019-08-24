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
    printf("Enter the highest power of your function\n");
    scanf("%d",&i);
    for (j=0; j<i+1; j++){
        printf("Enter the multiple of element with power of %d\n", j);
        scanf("%f",&a[j]);
    }
    printf("Your function: ");
    for (j=0; j<i+1; j++){
    printf("(%f*x^%d)+",a[j],j);
}

    printf("\b\nEnter the value of X");
    scanf("%f",&x);
    printf("Enter the change amount: ");
    scanf("%f",&dx);
    printf("For bacward-differentiation enter 1, For central-differentiation enter 2, For forward-differentiation enter 3. ");
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
    else
        printf("Wrong entry");


    printf("\nDerivative of your function: %f\n", tur);
    system("PAUSE");
    }



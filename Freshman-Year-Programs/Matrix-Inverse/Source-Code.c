#include <stdio.h>
#define MAX 50

int main(){
    int i,x,y,z;
    float a[MAX][MAX],b[MAX][MAX];
    float m,k;

    printf("Your Matrix as to be a Square Matrix\nSize of your matrix=");
    scanf("%d",&i);
    for(x=0;x<i;x++){
        for(y=0;y<i;y++){
        printf("\nA[%d][%d]=",x,y);
        scanf("%f",&a[x][y]);
}
}
    for(x=0;x<i;x++){
        for(y=0;y<i;y++){
        if(y==x)
        b[x][y]=1;
        else
        b[x][y]=0;

}
}
    for(x=0;x<i;x++){
    m=a[x][x];
        for(y=0;y<i;y++){
        a[x][y]=a[x][y]/m;
        b[x][y]=b[x][y]/m;
}
    for(z=0;z<i;z++){
        if(z!=x){
        k=a[z][x];
        for(y=0;y<i;y++){
        a[z][y]=a[z][y]-(a[x][y]*k);
        b[z][y]=b[z][y]-(b[x][y]*k);
}
}
}
}
    printf("\nInverse of your matrix;\n");
    for(x=0;x<i;x++){
    printf("[");
    for(y=0;y<i;y++){
    printf(" %f ", b[x][y]);
}
    printf("]\n");
}
    system("PAUSE");
}

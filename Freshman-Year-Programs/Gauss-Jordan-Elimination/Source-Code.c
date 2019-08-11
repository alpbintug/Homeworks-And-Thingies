#include <stdio.h>
#define MAX 50

int main(){
    int matrixSize,x,y,z;
    float variables[MAX][MAX],t[MAX];
    float m,k;

    printf("Your matrix should be square\nSize of your matrix= ");
    scanf("\n %d",&matrixSize);
    //Reading the matrix in the form of
    // A1 + B1 = C1
    // A2 + B2 = C2
    // A3 + B3 = C3
    // Where A and B are stored in variables part of the matrix, C is stored in the value part of the matrix.
    for(x=0;x<matrixSize;x++){
        for(y=0;y<matrixSize;y++){
        printf("Variables[%d][%d]= ",x,y);
        scanf("%f",&variables[x][y]);
}
        printf("Values[%d]= ",x);
        scanf("%f",&variables[x][matrixSize]);
}
    //Calculating the inverse of the matrix using Gauss - Jordan algorithm - go see Readme file
    for(y=0;y<matrixSize;y++)
    {
        for(x=0;x<matrixSize+1;x++)
        {
            if(x!=y)
            {
                m=variables[x][y]/variables[y][y];
                for(z=0;z<(matrixSize+1);z++)
                {
                    variables[x][z]=variables[x][z]-m*variables[y][z];
                }
            }
        }
    }
    //Printing the results
    printf("\nResult:\n");
    for(x=0; x<matrixSize; x++)
    {
        t[x]=variables[x][matrixSize]/variables[x][x];
        printf("\n Variable%d=%f\n",x,t[x]);
    }
}

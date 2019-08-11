#include <stdio.h>
#include <math.h>
#define MAX 10

//Please read Readme file before this file, algorithm is explained there
int main(){
    int numberOfSubsets,j,m,k,q,numberOfElements;
    char set[MAX];
    printf("Enter number of elements in your Set (10 ELEMENTS IS MAXIMUM!)");
    scanf("%d",&numberOfElements);
    numberOfSubsets=pow(2,numberOfElements);
    for(j=0;j<numberOfElements;j++){
        printf("Enter your next element - You Currently entered %d elements:",j);
        scanf("\n%c",&set[j]);
    }
    //Printing the empty set
    printf("{ }\n");
    for(j=1;j<numberOfSubsets;j++){//J holds the value we need to print subsets (Explained below)
            q=j;//I have to preserve J value but at the same time I have to use its value so i create a new variable to use
    printf("{");
    //Using the truth table for subsets
    //If there are two elements truth table will be like this;
    //  There will be 2^n subsets
    //  X  0  1  0  1
    //  Y  0  0  1  1
    //Sum  0  1  2  3
    //What happens is if we have 2 elements, sum of their value will be 2^2-1, we use this to print subsets, J holds this and passes it to Q
    //At first loop J value will be 1, with value of 1 we only can print X because it has the value of one
    //At second loop, J value will be 2, so we can only print Y with that value
    //At final loop, J value will be 3, so we can both print X and Y.
    //So the value of first element will be 2^(1-1), second element will be 2^(2-1), nth element will be 2^(n-1)
        for(k=numberOfElements-1;k>=0;k--){ //Starting from the element with highest value
            m=pow(2,k);//Calculating the value of element
            if(q>=m){//Checking if we still can subtract the value of the current element from the number of subsets to find the next subset.
                printf("%c,",set[k]);//If we can, we add that element to subset
                q=q-m;//Subtract its value
            }

        }
        printf("\b}\n"); //And close that subset

    }
    system("PAUSE");
}

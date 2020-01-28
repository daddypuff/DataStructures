
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int i, j;
bool allzero=true;

int main(){

     int nonzero=0, matrix[10][10], array[26][3];
     int mrows, mcolumn, arows ;
     int x=1;

     printf("Enter number of rows in matrix: ");
     scanf("%d", &mrows);

     printf("Enter number of columns in matrix: ");
     scanf("%d", &mcolumn);
     
     if(mrows==0||mcolumn==0){
            printf("Invalid Inputs!");
            exit(0);
     }

     printf("Enter Elements of the Matrix- ");
//*Scanning Matrix And determining number of Non Zero Elements  *//
     for(i=0;i<mrows;i++){
        for(j=0;j<mcolumn;j++){
            scanf("%d", &matrix[i][j]);
            if(matrix[i][j]!=0){
                 nonzero++;
                 allzero=false;
            }
        }
            }
//*Checking if a sparse Matrix*//
     if(nonzero>mrows*mcolumn/4){
        printf("This cannot be considered and/or transformed into a scarce Matrix!!!");
        exit(0);
     }
     if(allzero=true){
          printf("As all elements of this array are 0, sparse matrix cant be formed!");
          exit(0);
     }
//*Else*//
     arows = nonzero+1;
    //*Value Assignment for the Scarce Array*//

    array[0][0]=mrows;
    array[0][1]=mcolumn;
    array[0][2]=nonzero;

    for(i=0;i<mrows;i++){
        for(j=0;j<mcolumn;j++){
            if(matrix[i][j]!=0){
                array[x][0]= i+1;
                array[x][1]=j+1;
                array[x][2]=matrix[i][j];
                x++;
            }
        }
    }

//*Resultant Array*//
    printf("\n\nThis is the Scarce Array- \n");

    for(i=0;i<arows;i++){
        for(j=0;j<3;j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
 }

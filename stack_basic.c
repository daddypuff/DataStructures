#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int i, j;

int main(){
    int stack[100], max_height, tos=-1, choice;

    printf("Enter the maximum height of the stack: ");
    scanf("%d", &max_height);
    printf("\n");

    while(true){
        //*Extreme declarations*//
        if(tos==-1)
            printf("\nEmpty Stack!\n");
        if(tos==max_height-1)
            printf("\nFull Stack!!\n");

        printf("\nOperation on stacks:\n1-Push\n2-Pop\n0-Exit\n");
        scanf("%d", &choice);



     //Menu//
        switch(choice){
        case 1:
            if(tos==max_height-1){
                    printf("\nOverflow Error!!\n");
                    break;
                }
            tos++;
            printf("Enter Number to be pushed onto the stack: ");
            scanf("%d", &stack[tos]);

        printf("\nStack:\n");
        for(i=tos;i>-1;i--){
                printf("%d\n", stack[i]);
            }
        printf("\n");
            break;

        case 2:
            if(tos==-1){
                printf("\nUnderflow Error!\n");
                break;
            }
            tos--;

        printf("\nStack:\n");
        for(i=tos;i>-1;i--){
                printf("%d\n", stack[i]);
            }
        printf("\n");

            break;
        case 0:
            exit(0);
            break;
        default:
            printf("Invalid Operator!");
            break;
            }

 }

    return 0;
}

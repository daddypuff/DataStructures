#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int array[100], i, len;

//*Function Prototypes*//
void delete_index(int arr[], int delloc);
void swap(int *, int *);
void selection_sort(int arr[]);
void traverse(int arr[]);
void insert_index(int arr[], int loc, int num);
//*#*//

int main(){
    int search, addnum, subchoice, choice, location;
    bool found=false;

    printf("Enter the number of terms you want in the array- ");
    scanf("%d", &len);

    printf("Enter the terms- ");
    for(i=0;i<len;i++){scanf("%d", &array[i]);}
    printf("\n\n");
    traverse(array);
    printf("\n\n");
//*Reusable Program Loop*//
        while(true){
        printf("\nEnter the number as per the desired operation to be performed on the given array:\n1-Inserting\n2-Delete\n3-Linear Search\n4-Selection Sort\n5-Traverse\n0-Exit\n ");
        scanf("%d", &choice);
//*Choice for Loop*//
        switch(choice){
        case 1:
            printf("Type of Insertion:\n1- Insert First Element\n2- Insert last Element\n3- Insert at a Location\n");
            scanf("%d", &subchoice);
//*Sub-Loop-1*//
            switch(subchoice)
            {
            case 1:
                printf("Enter the number to be Added:");
                scanf("%d", &addnum);
                insert_index(array, 0, addnum);
                traverse(array);
                break;
            case 2:
                printf("Enter the number to be Added:");
                scanf("%d", &addnum);
                insert_index(array, len, addnum);
                traverse(array);
                break;
            case 3:
                printf("Enter the location: ");
                scanf("%d", &location);
                if(location>len-1 || location<0){
                        printf("Element not defined!\n");
                        traverse(array);
                        printf("\n");
                        break;
                }
                printf("Enter the number to be Added: ");
                scanf("%d", &addnum);

                insert_index(array, location, addnum);
                break;

            }
            break;

        case 2:
            printf("Type of Deletion:\n1- Delete First Element\n2- Delete last Element\n3- Delete at a Location\n");
             scanf("%d", &subchoice);
//*Sub-Loop-2*//
            switch(subchoice)
            {
            case 1:
                delete_index(array, 0);
                traverse(array);
                break;
            case 2:
                len--;
                traverse(array);
                break;

            case 3:
                printf("Enter the index to be deleted: ");
                scanf("%d", &location);
                if(location>len-1 || location<0){
                        printf("Element not defined!\n");
                        traverse(array);
                        printf("\n");
                        break;
                }
                delete_index(array, location);
                traverse(array);
                break;


            }
            printf("\n");
            break;



        case 3:
            printf("Enter the number to be searched through the array linearly-" );
            scanf("%d", &search);
            for(i=0;i<len;i++){
                if(array[i]==search){
                    printf("%d Found at (index=%d)\n", search, i);
                    found= true;

                    }
                }
                if(found==false)
                    printf("Not Found!\t!!Search Failed!!\n");
                break;
        case 4:

            selection_sort(array);
            printf("Sorted Array: \n");
            traverse(array);
            break;
        case 5:
            printf("\n");
            traverse(array);
            printf("\n");
            break;

        case 0:
            exit(0);


        }
    }
        return 0;
}


//*Swapping for Sort*//
void swap(int *ax, int*bx){
    int temp;
    temp = *ax;
    *ax = *bx;
    *bx = temp;
}

//*Function for Inserting*//
void insert_index(int arr[], int loc, int num){
    len++;

    for(i=len-1;i>=loc;i--){
        arr[i+1]=arr[i];
        }
        arr[loc]=num;
        }


//*Specific function for Traversing*//
void traverse(int arr[]){
    printf("{ " );
    for(i=0;i<len;i++)
        printf("%d ", arr[i]);
    printf("}");
}


//*Function for Selection Sort*//
void selection_sort(int arr[]){
    int min, i, j;
    for(i=0;i<len-1;i++){
            min=i;
        for(j=i+1;j<len;j++){
            if(arr[j] < arr[min]){min=j;}
            }
            swap(&arr[i],&arr[min]);

    }
}
//*Function For Deletion*//
void delete_index(int arr[], int delloc){
    len--;

    for(i=delloc;i<=len-1;i++){
        arr[i]=arr[i+1];
    }


}

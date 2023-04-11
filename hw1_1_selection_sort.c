#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * create_random_array(){
    static int A[100];
    srand(time(NULL));
    int arr[1000]={0};

    for(int i = 0; i < 100; i++){
        int temp = rand()%1000;
        if(arr[temp] == 0){
            A[i] = temp;
            arr[temp] = 1;
        }
        else{
            i--;
        }

    }
    return A;
}

int * create_ascending_array(){
    static int A[100];
    for(int i = 0; i<100; i++){
        A[i] = i+1;
    }
    return A;
}

int * create_descending_array(){
    static int A[100];
    for(int i = 0; i<100; i++){
        A[i] = 100-i;
    }
    return A;
}


int selection_sort(int * A){
    int comparison = 0;
    for(int i = 0; i < 100; i++)
    {
        int max = i;

        for(int j = i + 1; j < 100; j++){
            if(A[j] > A[max]){
                max = j;
            }
            comparison++;
        }

        int temp = 0;

        temp = A[i];
        A[i] = A[max];
        A[max] = temp;

    }
    return comparison;
}

int main(){

    int * A = malloc(sizeof(*A));
    int * B = malloc(sizeof(*B));
    int * C = malloc(sizeof(*C));

// random array, already sorted array, reversely sorted array

A = create_random_array();

B= create_ascending_array();

C = create_descending_array();



    printf("\nrandom array\n");
    printf("\n");
    printf("Before sorting\n");
    
    for(int i = 0; i < 100; i++){
        printf("%d ", A[i]);
    }

    printf("\n");
    printf("\n");

    int comparison = selection_sort(A);

    printf("after sorting\n");

    for(int i = 0; i < 100; i++){
        printf("%d ", A[i]);
    }
    
    printf("\nnumber of comparison: %d", comparison);

    printf("\n");
    printf("\n");

    printf("\nalready sorted array\n");
    printf("\n");
    printf("Before sorting\n");
    
    for(int i = 0; i < 100; i++){
        printf("%d ", B[i]);
    }

    printf("\n");
    printf("\n");

    int comparison1 = selection_sort(B);

    printf("after sorting\n");

    for(int i = 0; i < 100; i++){
        printf("%d ", B[i]);
    }
    
    printf("\nnumber of comparison: %d", comparison1);

    printf("\n");
    printf("\n");

    printf("\nreversely sorted array\n");
    printf("\n");
    printf("Before sorting\n");
    
    for(int i = 0; i < 100; i++){
        printf("%d ", C[i]);
    }

    printf("\n");
    printf("\n");
    int comparison2 = selection_sort(C);

    printf("after sorting\n");

    for(int i = 0; i < 100; i++){
        printf("%d ", C[i]);
    }
    
    printf("\nnumber of comparison: %d", comparison2);

    return 0;
}
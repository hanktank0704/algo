#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int comparison = 0;

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

void merge(int * A, int l, int m, int r){
    int i = l;
    int j = m+1;
    int k = 0;
    int temp[r-l+1];

    while(i<=m && j<=r){
        if(A[i] < A[j]){
            temp[k] = A[i];
            i++;
            k++;
            comparison++;
        }
        else{
            temp[k] = A[j];
            j++;
            k++;
            comparison++;
        }

    }
    
    while(i<=m){
        temp[k] = A[i];
        k++;
        i++;
    }
    while(j<=r){
        temp[k] = A[j];
        k++;
        j++;
    }
    for(int i = l; i<r+1; i++){
        A[i] = temp[i-l];
    }
}


void merge_sort(int * A, int l, int r){
    int m=(l+r)/2;
    if(l < r){
        merge_sort(A,l,m);
        merge_sort(A,m+1,r);
        merge(A,l,m,r);
    }

}

int main(){

    int * A = malloc(sizeof(*A));
    int * B = malloc(sizeof(*B));
    int * C = malloc(sizeof(*C));

// random array, already sorted array, reversely sorted array

    A = create_random_array();

    B = create_ascending_array();

    C = create_descending_array();



    
    printf("\n");
    printf("Before sorting\n");
    
    for(int i = 0; i < 100; i++){
        printf("%d ", A[i]);
    }

    printf("\n");
    printf("\n");

    merge_sort(A,0,99);

    printf("after sorting\n");

    for(int i = 0; i < 100; i++){
        printf("%d ", A[i]);
    }
    
    printf("\nnumber of comparison: %d", comparison);

    printf("\n");
    printf("\n");
    
    printf("\n");
    printf("Before sorting\n");
    
    for(int i = 0; i < 100; i++){
        printf("%d ", B[i]);
    }

    printf("\n");
    printf("\n");

    merge_sort(B,0,99);

    printf("after sorting\n");

    for(int i = 0; i < 100; i++){
        printf("%d ", B[i]);
    }
    
    printf("\nnumber of comparison: %d", comparison);

    printf("\n");
    printf("\n");


    printf("\n");
    printf("Before sorting\n");
    
    for(int i = 0; i < 100; i++){
        printf("%d ", C[i]);
    }

    printf("\n");
    printf("\n");

    merge_sort(C,0,99);

    printf("after sorting\n");

    for(int i = 0; i < 100; i++){
        printf("%d ", C[i]);
    }
    
    printf("\nnumber of comparison: %d", comparison);

    printf("\n");
    printf("\n");
    return 0;
}
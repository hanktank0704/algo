#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * create_random_array(){
    static int A[1000];
    srand(time(NULL));
    int arr[1000]={0};

    for(int i = 0; i < 1000; i++){
        int temp = rand()%1000;
        A[i] = temp;
    }
    return A;
}

int ** standard_algo_8(int a[8][8], int b[8][8],int n){
    int computations = 0;
    int c[8][8];


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            c[i][j] = 0;
            for(int k=0; k<n; k++){
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
                computations = computations + 2;
            }            
        }

    }
    printf("\nnumber of computataions: %d\n",computations);

    printf("\n");
    printf("A 행렬 \n");
    
    for(int i=0; i<n; i++){
        printf("\n");

        for(int j=0; j<sizeof(*a)/sizeof(**a); j++){
                printf("%d ",a[i][j]);
        }

    }

    printf("\n");
    printf("\n");

    printf("B 행렬 \n");
    for(int i=0; i<n; i++){
        printf("\n");

        for(int j=0; j<sizeof(*a)/sizeof(**a); j++){
                printf("%d ",b[i][j]);
        }

    }

    printf("\n");
    printf("\n");

    printf("C 행렬 \n");

    for(int i=0; i<n; i++){
        printf("\n");

        for(int j=0; j<sizeof(*a)/sizeof(**a); j++){
                printf("%d ",c[i][j]);
        }

    }
    printf("\n");
}

int ** standard_algo_4(int a[4][4], int b[4][4],int n){
    int computations = 0;
    int c[4][4];
    printf("\n");

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            c[i][j] = 0;
            for(int k=0; k<n; k++){
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
                computations = computations + 2;
            }            
        }

    }
    printf("\nnumber of computataions: %d\n",computations);

    printf("\n");
    printf("A 행렬 \n");
    
    for(int i=0; i<n; i++){
        printf("\n");

        for(int j=0; j<sizeof(*a)/sizeof(**a); j++){
                printf("%d ",a[i][j]);
        }

    }

    printf("\n");
    printf("B 행렬 \n");
    for(int i=0; i<n; i++){
        printf("\n");

        for(int j=0; j<sizeof(*a)/sizeof(**a); j++){
                printf("%d ",b[i][j]);
        }

    }

    printf("\n");
    printf("C 행렬 \n");

    for(int i=0; i<n; i++){
        printf("\n");

        for(int j=0; j<sizeof(*a)/sizeof(**a); j++){
                printf("%d ",c[i][j]);
        }

    }
    printf("\n");
}


void divide_conquer(int n, int **A, int **B, int **C){
} 

int main(){
    // int * a = malloc(16 * sizeof(int));
    // int * b = malloc(16 * sizeof(int));
        
    // int *arr = malloc(sizeof(int));

    // 4*4 matrix

    int a[4][4];
    int b[4][4];

    int *arr = malloc(sizeof(int));
    arr = create_random_array(4);

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            a[i][j] = arr[4*i+j];
        }
    }

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            b[i][j] = arr[4*i+j+16];
        }
    }

    standard_algo_4(a,b,4);

    //8*8 matrix

    int a1[8][8];
    int b1[8][8];

    int *arr1 = malloc(sizeof(int));
    arr1 = create_random_array(8);

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            a1[i][j] = arr1[8*i+j];
        }
    }

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            b1[i][j] = arr1[8*i+j+64];
        }
    }

    standard_algo_8(a1,b1,8);

 

    return 0;
}
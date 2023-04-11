#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void fill(int **A, int **B,int N) {


    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 1000;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = rand() % 1000;
        }
    }
}

void print(int ** A){
    int n = 4;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

void addmatrix(int ** A, int ** B, int ** C, int split_index){

	for (int i = 0; i < split_index; i++)
		for (int j = 0; j < split_index; j++)
			C[i][j] = A[i][j] + B[i][j];

}

int ** mulitply_matrix(int ** A, int ** B){

    int col_1 = sizeof(*A)/sizeof(**A);

    int col_2 = sizeof(*B)/sizeof(**B);

    int ** C = malloc(sizeof(int*) * col_1);
    for(int i=0; i<col_1; i++){
        C[i] = malloc(sizeof(int) * col_1);
    }

    if(col_1 == 1){
        C[0][0] = A[0][0] * B[0][0];
    }

    // if(col_1 == 2){
    //     C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    //     C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    //     C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    //     C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
    // }
    else{
        int split_index = col_1 / 2;

        int ** C00 = malloc(sizeof(int*) * split_index);
        int ** C01 = malloc(sizeof(int*) * split_index);
        int ** C10 = malloc(sizeof(int*) * split_index);
        int ** C11 = malloc(sizeof(int*) * split_index);

        int ** A00 = malloc(sizeof(int*) * split_index);
        int ** A01 = malloc(sizeof(int*) * split_index);
        int ** A10 = malloc(sizeof(int*) * split_index);
        int ** A11 = malloc(sizeof(int*) * split_index);
        
        int ** B00 = malloc(sizeof(int*) * split_index);
        int ** B01 = malloc(sizeof(int*) * split_index);
        int ** B10 = malloc(sizeof(int*) * split_index);
        int ** B11 = malloc(sizeof(int*) * split_index);

        for(int i=0; i<split_index; i++){
            C00[i] = malloc(sizeof(int) * split_index);
            C01[i] = malloc(sizeof(int) * split_index);
            C10[i] = malloc(sizeof(int) * split_index);
            C11[i] = malloc(sizeof(int) * split_index);
            
            B00[i] = malloc(sizeof(int) * split_index);
            B01[i] = malloc(sizeof(int) * split_index);
            B10[i] = malloc(sizeof(int) * split_index);
            B11[i] = malloc(sizeof(int) * split_index);
            
            A00[i] = malloc(sizeof(int) * split_index);
            A01[i] = malloc(sizeof(int) * split_index);
            A10[i] = malloc(sizeof(int) * split_index);
            A11[i] = malloc(sizeof(int) * split_index);
        }

        for(int i=0; i<split_index; i++){
            for(int j=0; j<split_index; j++){
                A00[i][j] = A[i][j];
                A01[i][j] = A[i][j + split_index];
                A10[i][j] = A[split_index + i][j];
				A11[i][j] = A[i + split_index][j + split_index];

				B00[i][j] = B[i][j];
				B01[i][j] = B[i][j + split_index];
				B10[i][j] = B[split_index + i][j];
				B11[i][j] = B[i + split_index][j + split_index];
            }
        }

        addmatrix(mulitply_matrix(A00,B00), mulitply_matrix(A01,B10), C00, split_index);
        addmatrix(mulitply_matrix(A00,B01), mulitply_matrix(A01,B11), C01, split_index);
        addmatrix(mulitply_matrix(A10,B00), mulitply_matrix(A11,B10), C10, split_index);
        addmatrix(mulitply_matrix(A10,B01), mulitply_matrix(A11,B11), C11, split_index);

        // printf("\n");
        // print(A00);
        // printf("\n");
        // print(A01);
        // printf("\n");
        // print(A10);
        // printf("\n");
        // print(A11);

        for (int i = 0; i < split_index; i++){
			for (int j = 0; j < split_index; j++) {
				C[i][j]	= C11[i][j];
				C[i][j + split_index] = C01[i][j];
				C[split_index + i][j] = C10[i][j];
				C[i + split_index][j + split_index] = C11[i][j];
			}
        }

        for(int i=0; i<split_index; i++){
            free(A00[i]); free(A01[i]);  free(A10[i]); 
            free(A11[i]); 
            free(B00[i]); free(B01[i]);  free(B10[i]); 
            free(B11[i]); 
            free(C00[i]); free(C01[i]);  free(C10[i]); 
            free(C11[i]); 
        }
        free(A00); free(A01); free(A10); free(A11);
        free(B00); free(B01); free(B10); free(B11);
        free(C00); free(C01); free(C10); free(C11);


    }

    return C;
}

int main(){
    int ** matrix_A = malloc(sizeof(int*) * 4);
    for(int i=0; i<4; i++){
        matrix_A[i] = malloc(sizeof(int) * 4);
    }

    int ** matrix_B = malloc(sizeof(int*) * 4);
    for(int i=0; i<4; i++){
        matrix_B[i] = malloc(sizeof(int) * 4);
    }

    int ** result_matrix = malloc(sizeof(int*) * 4);
    for(int i=0; i<4; i++){
        result_matrix[i] = malloc(sizeof(int) * 4);
    }
    

    fill(matrix_A,matrix_B,4);

    printf("\n");
    print(matrix_A);

    printf("\n");
    print(matrix_B);

    printf("\n");

	result_matrix =	mulitply_matrix(matrix_A, matrix_B);

	print(result_matrix);

    printf("\n");
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            printf("%d ", result_matrix[i][j]);
        }
        printf("\n");
    }


    return 0;

}

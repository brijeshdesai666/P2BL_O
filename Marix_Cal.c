#include <stdio.h>

#define MAX_SIZE 100

void matrix_add(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void matrix_multiply(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int n, int m, int p) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < m; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_input(int A[][MAX_SIZE], int n, int m) {
    printf("Enter the elements of the matrix (%d x %d):\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
        }
    }
}

void matrix_output(int A[][MAX_SIZE], int n, int m) {
    // printf("The matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
    int n, m, p;

    printf("Enter the number of rows and columns of matrix A:\n");
    scanf("%d %d", &n, &m);
    matrix_input(A, n, m);

    printf("Enter the number of rows and columns of matrix B:\n");
    scanf("%d %d", &m, &p);
    matrix_input(B, m, p);

    printf("Matix multiply is: \n");
    matrix_multiply(A, B, C, n, m, p);
    matrix_output(C, n, p);

    printf("Matix addition is: \n");
    matrix_add(A, B, C, n, m);
    matrix_output(C, n, m);

    return 0;
}
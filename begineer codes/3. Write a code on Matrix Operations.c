#include <stdio.h>

#define MAX 10

void inputMatrix(int mat[MAX][MAX], int r, int c) {
    printf("Enter elements:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void printMatrix(int mat[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int A[MAX][MAX], int B[MAX][MAX], int r, int c) {
    int sum[MAX][MAX];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            sum[i][j] = A[i][j] + B[i][j];

    printf("\nSum of matrices:\n");
    printMatrix(sum, r, c);
}

void subMatrix(int A[MAX][MAX], int B[MAX][MAX], int r, int c) {
    int diff[MAX][MAX];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            diff[i][j] = A[i][j] - B[i][j];

    printf("\nDifference of matrices:\n");
    printMatrix(diff, r, c);
}

void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX], int r1, int c1, int r2, int c2) {
    int product[MAX][MAX] = {0};

    if (c1 != r2) {
        printf("\nMatrix multiplication not possible.\n");
        return;
    }

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                product[i][j] += A[i][k] * B[k][j];

    printf("\nProduct of matrices:\n");
    printMatrix(product, r1, c2);
}

void transposeMatrix(int A[MAX][MAX], int r, int c) {
    int trans[MAX][MAX];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            trans[j][i] = A[i][j];

    printf("\nTranspose of matrix:\n");
    printMatrix(trans, c, r);
}

int main() {
    int A[MAX][MAX], B[MAX][MAX];
    int r1, c1, r2, c2;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    printf("\nEnter Matrix A:\n");
    inputMatrix(A, r1, c1);

    printf("\nEnter Matrix B:\n");
    inputMatrix(B, r2, c2);

    if (r1 == r2 && c1 == c2) {
        addMatrix(A, B, r1, c1);
        subMatrix(A, B, r1, c1);
    } else {
        printf("\nAddition/Subtraction not possible (size mismatch).\n");
    }

    multiplyMatrix(A, B, r1, c1, r2, c2);

    printf("\nTranspose of Matrix A:\n");
    transposeMatrix(A, r1, c1);

    printf("\nTranspose of Matrix B:\n");
    transposeMatrix(B, r2, c2);

    return 0;
}

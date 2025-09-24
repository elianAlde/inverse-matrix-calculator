/*
	********** ASSIGNMENT **********
	Using the C programming language, develop a program that,
	given a 3x3 matrix as input, computes its inverse as output,
	and verifies the result by multiplying it with the original matrix (Identity).
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3
#define EPS 1e-9

typedef double Mat3[N][N];

static void read_matrix(Mat3 A);
static void print_matrix(const char *title, const Mat3 A);
static double det3(const Mat3 A);
static void cofactor3(const Mat3 A, Mat3 C);
static void transpose3(const Mat3 A, Mat3 AT);
static int inverse3(const Mat3 A, Mat3 inv);        // ritorna 0 se non invertibile
static void mul3(const Mat3 A, const Mat3 B, Mat3 R);

int main(void) {
    Mat3 A, Ainv, I;

    read_matrix(A);

    if (!inverse3(A, Ainv)) {
        puts("\nDeterminant is ~0 -> matrix is not invertible.");
        return 0;
    }

    mul3(A, Ainv, I);

    print_matrix("\nInput matrix A", A);
    print_matrix("\nInverse A^{-1}", Ainv);
    print_matrix("\nCheck A * A^{-1} (should be I)", I);

    return 0;
}

static void read_matrix(Mat3 A) {
    puts("Enter the 9 values of the 3x3 matrix (row by row):");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            while (1) {
                printf("A[%d][%d] = ", i+1, j+1);
                if (scanf("%lf", &A[i][j]) == 1) break;
                puts("Invalid number. Try again.");
                int c; while ((c = getchar()) != '\n' && c != EOF) {}
            }
        }
    }
}

static void print_matrix(const char *title, const Mat3 A) {
    puts(title);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            printf("%10.6f ", A[i][j]);
        putchar('\n');
    }
}

static double det3(const Mat3 M) {
    return
        M[0][0]*(M[1][1]*M[2][2] - M[1][2]*M[2][1]) -
        M[0][1]*(M[1][0]*M[2][2] - M[1][2]*M[2][0]) +
        M[0][2]*(M[1][0]*M[2][1] - M[1][1]*M[2][0]);
}

static void cofactor3(const Mat3 A, Mat3 C) {
    C[0][0] = +(A[1][1]*A[2][2] - A[1][2]*A[2][1]);
    C[0][1] = -(A[1][0]*A[2][2] - A[1][2]*A[2][0]);
    C[0][2] = +(A[1][0]*A[2][1] - A[1][1]*A[2][0]);

    C[1][0] = -(A[0][1]*A[2][2] - A[0][2]*A[2][1]);
    C[1][1] = +(A[0][0]*A[2][2] - A[0][2]*A[2][0]);
    C[1][2] = -(A[0][0]*A[2][1] - A[0][1]*A[2][0]);

    C[2][0] = +(A[0][1]*A[1][2] - A[0][2]*A[1][1]);
    C[2][1] = -(A[0][0]*A[1][2] - A[0][2]*A[1][0]);
    C[2][2] = +(A[0][0]*A[1][1] - A[0][1]*A[1][0]);
}

static void transpose3(const Mat3 A, Mat3 AT) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            AT[j][i] = A[i][j];
}

static int inverse3(const Mat3 A, Mat3 inv) {
    double d = det3(A);
    if (fabs(d) < EPS) return 0;

    Mat3 C, adj;
    cofactor3(A, C);
    transpose3(C, adj);      // adjugate

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            inv[i][j] = adj[i][j] / d;

    return 1;
}

static void mul3(const Mat3 A, const Mat3 B, Mat3 R) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            R[i][j] = 0.0;
            for (int k = 0; k < N; ++k) R[i][j] += A[i][k] * B[k][j];
        }
}

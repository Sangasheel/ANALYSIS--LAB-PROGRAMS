#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

// ── print ────────────────────────────────────────────────
void print(const Matrix& M, string label) {
    cout << label << ":\n";
    for (auto& row : M) {
        for (int v : row) cout << v << "\t";
        cout << "\n";
    }
    cout << "\n";
}

// ── BASE CASE: direct 2x2 multiply ──────────────────────
Matrix mul2x2(const Matrix& A, const Matrix& B) {
    Matrix C(2, vector<int>(2));
    C[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0];
    C[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1];
    C[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0];
    C[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][1];
    return C;
}

// ── ADD two n×n matrices ─────────────────────────────────
Matrix add(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// ── RECURSIVE MATRIX MULTIPLY ────────────────────────────
// n must be a power of 2 (2, 4, 8, 16, ...)
Matrix multiply(const Matrix& A, const Matrix& B) {
    int n = A.size();

    // ── BASE CASE ─────────────────────────────────────────
    if (n == 2)
        return mul2x2(A, B);

    // ── SPLIT each matrix into 4 quadrants ────────────────
    int h = n / 2;

    Matrix A11(h, vector<int>(h)),  A12(h, vector<int>(h)),
           A21(h, vector<int>(h)),  A22(h, vector<int>(h));

    Matrix B11(h, vector<int>(h)),  B12(h, vector<int>(h)),
           B21(h, vector<int>(h)),  B22(h, vector<int>(h));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < h; j++) {
            A11[i][j] = A[i][j];       A12[i][j] = A[i][j+h];
            A21[i][j] = A[i+h][j];     A22[i][j] = A[i+h][j+h];

            B11[i][j] = B[i][j];       B12[i][j] = B[i][j+h];
            B21[i][j] = B[i+h][j];     B22[i][j] = B[i+h][j+h];
        }
    }

    // ── 8 RECURSIVE MULTIPLICATIONS ──────────────────────
    //
    //   C = | A11  A12 | x | B11  B12 |
    //       | A21  A22 |   | B21  B22 |
    //
    //   C11 = A11*B11 + A12*B21   (top-left)
    //   C12 = A11*B12 + A12*B22   (top-right)
    //   C21 = A21*B11 + A22*B21   (bottom-left)
    //   C22 = A21*B12 + A22*B22   (bottom-right)
    //
    Matrix M1 = multiply(A11, B11);  // for C11
    Matrix M2 = multiply(A12, B21);  // for C11
    Matrix M3 = multiply(A11, B12);  // for C12
    Matrix M4 = multiply(A12, B22);  // for C12
    Matrix M5 = multiply(A21, B11);  // for C21
    Matrix M6 = multiply(A22, B21);  // for C21
    Matrix M7 = multiply(A21, B12);  // for C22
    Matrix M8 = multiply(A22, B22);  // for C22

    Matrix C11 = add(M1, M2);
    Matrix C12 = add(M3, M4);
    Matrix C21 = add(M5, M6);
    Matrix C22 = add(M7, M8);

    // ── COMBINE quadrants into result ─────────────────────
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < h; j++) {
            C[i][j]       = C11[i][j];
            C[i][j+h]     = C12[i][j];
            C[i+h][j]     = C21[i][j];
            C[i+h][j+h]   = C22[i][j];
        }
    }
    return C;
}

// ── MAIN ─────────────────────────────────────────────────
int main() {
    Matrix A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {1, 0, 1, 0},
        {0, 1, 0, 1}
    };
    Matrix B = {
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    print(A, "A");
    print(B, "B");
    print(multiply(A, B), "A x B");

    return 0;
}
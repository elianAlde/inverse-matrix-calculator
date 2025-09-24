# Matrix Inverse Calculator (3x3) 🧮

This project is a simple **C program** that computes the inverse of a 3x3 matrix entered by the user.  
It also performs a verification step by multiplying the original matrix by its inverse and displaying the resulting identity matrix.

---

## 📋 Features
- Input of a 3x3 matrix from the console  
- Determinant calculation and check for invertibility  
- Computation of the inverse matrix using cofactors and adjugate  
- Verification by computing `A * A⁻¹ ≈ I`  
- Clear and structured code, portable across platforms (no Windows-specific dependencies)

---

## 🛠️ Build & Run
### Compile
Using **GCC** or **Clang**:
```bash
gcc -O2 -Wall -Wextra -pedantic -std=c11 main.c -lm -o inverse3x3


/* matrix_mult.cpp
 * Top-level function cho Lab 3 — Designing With Vitis HLS (Zybo Z7).
 * Thực hiện phép nhân hai ma trận 5x5: prod = a x b
 *
 * Khi tổng hợp trong Vitis HLS 2025.2 ta sẽ chèn các directive
 * (PIPELINE, ARRAY_RESHAPE...) trong tab Directive để tối ưu hóa.
 */
#include "matrix_mult.h"

void matrix_mult(mat_a_t  a[MAT_A_ROWS][MAT_A_COLS],
                 mat_b_t  b[MAT_B_ROWS][MAT_B_COLS],
                 result_t prod[MAT_A_ROWS][MAT_B_COLS])
{
#pragma HLS ARRAY_RESHAPE variable=b dim=1 type=complete
#pragma HLS ARRAY_RESHAPE variable=a dim=2 type=complete
    /* Vòng lặp ngoài duyệt theo hàng */
    Row: for (int i = 0; i < MAT_A_ROWS; i++) {
        /* Vòng lặp giữa duyệt theo cột của ma trận B */
        Col: for (int j = 0; j < MAT_B_COLS; j++) {
#pragma HLS PIPELINE
                        prod[i][j] = 0;
            /* Vòng lặp trong tính tổng tích lũy */
            Product: for (int k = 0; k < MAT_B_ROWS; k++) {

                prod[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

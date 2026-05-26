/* matrix_mult_test.cpp
 * Testbench cho Lab 3 — Designing With Vitis HLS (Zybo Z7).
 *
 * So sánh kết quả của module HLS với kết quả tính toán software thuần
 * trên cùng dữ liệu vào. In ra "Test passed!" nếu khớp, "Test failed!"
 * nếu lệch.
 */
#include <iostream>
#include <iomanip>
#include "matrix_mult.h"

int main()
{
    /* Hai ma trận thử nghiệm cố định */
    mat_a_t in_mat_a[MAT_A_ROWS][MAT_A_COLS] = {
        { 1, 2, 3, 4, 5 },
        { 6, 7, 8, 9,10 },
        {11,12,13,14,15 },
        {16,17,18,19,20 },
        {21,22,23,24,25 }
    };

    mat_b_t in_mat_b[MAT_B_ROWS][MAT_B_COLS] = {
        { 1, 0, 0, 0, 1 },
        { 0, 1, 0, 1, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 1, 0, 1, 0 },
        { 1, 0, 0, 0, 1 }
    };

    result_t hw_result[MAT_A_ROWS][MAT_B_COLS];
    result_t sw_result[MAT_A_ROWS][MAT_B_COLS];

    /* Gọi hàm HLS (module phần cứng tương lai) */
    matrix_mult(in_mat_a, in_mat_b, hw_result);

    /* Tính kết quả tham chiếu bằng software */
    for (int i = 0; i < MAT_A_ROWS; i++) {
        for (int j = 0; j < MAT_B_COLS; j++) {
            sw_result[i][j] = 0;
            for (int k = 0; k < MAT_B_ROWS; k++) {
                sw_result[i][j] += in_mat_a[i][k] * in_mat_b[k][j];
            }
        }
    }

    /* So sánh */
    int errors = 0;
    for (int i = 0; i < MAT_A_ROWS; i++) {
        for (int j = 0; j < MAT_B_COLS; j++) {
            if (hw_result[i][j] != sw_result[i][j]) {
                errors++;
                std::cout << "Mismatch at (" << i << "," << j << ")"
                          << " hw=" << hw_result[i][j]
                          << " sw=" << sw_result[i][j] << std::endl;
            }
        }
    }

    if (errors == 0) {
        std::cout << "Test passed!" << std::endl;
        return 0;
    } else {
        std::cout << "Test failed! errors=" << errors << std::endl;
        return 1;
    }
}

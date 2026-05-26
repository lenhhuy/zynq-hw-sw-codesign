/* matrix_mult.h
 * Khai báo cho hàm nhân ma trận 5x5 dùng trong Vitis HLS 2025.2
 * Lab 3 — Designing With Vitis HLS (Zybo Z7)
 */
#ifndef MATRIX_MULT_H_
#define MATRIX_MULT_H_

#include <iostream>
#include <iomanip>

/* Kích thước ma trận */
const int MAT_A_ROWS = 5;
const int MAT_A_COLS = 5;
const int MAT_B_ROWS = 5;
const int MAT_B_COLS = 5;

/* Kiểu dữ liệu cho ngõ vào/ngõ ra
 * - Ngõ vào dùng 8-bit unsigned char để giữ port mảnh, đỡ chiếm tài nguyên
 * - Ngõ ra dùng short (16-bit) để chứa tổng tích lũy không bị overflow
 */
typedef unsigned char mat_a_t;
typedef unsigned char mat_b_t;
typedef short         result_t;

/* Prototype của top-level function */
void matrix_mult(mat_a_t  a[MAT_A_ROWS][MAT_A_COLS],
                 mat_b_t  b[MAT_B_ROWS][MAT_B_COLS],
                 result_t prod[MAT_A_ROWS][MAT_B_COLS]);

#endif /* MATRIX_MULT_H_ */

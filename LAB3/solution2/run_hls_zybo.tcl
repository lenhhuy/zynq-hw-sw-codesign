############################################################
# run_hls_zybo.tcl
# Tcl script tạo project Vitis HLS 2025.2 cho Zybo Z7-10
# Lab 3 — Designing With Vitis HLS
############################################################

open_project matrix_mult_prj
set_top matrix_mult
add_files       matrix_mult.cpp
add_files       matrix_mult.h
add_files -tb   matrix_mult_test.cpp

open_solution "solution1" -flow_target vivado
# Part của Zybo Z7-10 (Zynq-7010, package CLG400, speed -1)
set_part {xc7z010clg400-1}
create_clock -period 10 -name default

# C simulation để xác minh testbench
csim_design

# Tổng hợp (synthesis)
csynth_design

# Co-simulation RTL/C
# cosim_design

exit

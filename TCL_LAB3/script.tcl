# Khởi tạo Project (Nếu trùng tên sẽ tự động reset mới)
open_project -reset matrix_mult_automation_prj

# Khai báo các file nguồn cho project
set_top matrix_mult
add_files matrix_mult.cpp
add_files -tb matrix_mult_test.cpp

# Cấu hình chung cho tất cả các Solution
set chip_part {xc7z010clg400-1}
set clock_period 10

# SOLUTION 1: CODE GỐC (BASELINE) - Chạy tuần tự không tối ưu
open_solution -reset "Solution1" -flow_target vivado
set_part $chip_part
create_clock -period $clock_period -name default
config_compile -pipeline_loops 0

# Thực thi luồng HLS đầy đủ
csynth_design
cosim_design

# SOLUTION 2: PIPELINE VÒNG PRODUCT 
open_solution -reset "Solution2" -flow_target vivado
set_part $chip_part
create_clock -period $clock_period -name default

# Chạy lệnh pipeline với II = 1
set_directive_pipeline "matrix_mult/Product" -II 1
config_compile -pipeline_loops 0
# Thực thi luồng HLS đầy đủ
csynth_design
cosim_design

# SOLUTION 3: PIPELINE VÒNG COL 
open_solution -reset "Solution3" -flow_target vivado
set_part $chip_part
create_clock -period $clock_period -name default

# Chạy lệnh tối ưu Pipeline ở vòng Col, II = 1
set_directive_pipeline "matrix_mult/Col" -II 1
config_compile -pipeline_loops 0
# Thực thi luồng HLS đầy đủ
csynth_design
cosim_design

# SOLUTION 4: ARRAY RESHAPE + PIPELINE VÒNG COL 
open_solution -reset "Solution4" -flow_target vivado
set_part $chip_part
create_clock -period $clock_period -name default
config_compile -pipeline_loops 0
# Chạy lệnh Array Reshape
set_directive_array_reshape -type complete -dim 2 "matrix_mult" a
set_directive_array_reshape -type complete -dim 1 "matrix_mult" b

# Chạy lệnh Pipeline vòng ngoài
set_directive_pipeline "matrix_mult/Col" -II 1

# Thực thi luồng HLS đầy đủ
csynth_design
cosim_design

# SOLUTION 5: ARRAY RESHAPE + PIPELINE CẢ 3 VÒNG 
open_solution -reset "Solution5" -flow_target vivado
set_part $chip_part
create_clock -period $clock_period -name default
config_compile -pipeline_loops 0
# Chạy lệnh Array Reshape
set_directive_array_reshape -type complete -dim 2 "matrix_mult" a
set_directive_array_reshape -type complete -dim 1 "matrix_mult" b

# Chạy lệnh Pipeline vòng ngoài
set_directive_pipeline "matrix_mult" -II 1

# Thực thi luồng HLS đầy đủ
csynth_design
cosim_design

# Kết thúc quy trình, đóng Project
close_project

# Combined HW and SW Design

> **HW/SW co-design labs on Xilinx Zynq-7010 (ZyBo) using Vivado & Vitis 2025.2**

Tổng hợp các bài thực hành môn **Thiết kế kết hợp Phần cứng và Phần mềm** — phát triển song song HW (FPGA) và SW (ARM) trên cùng một SoC.

---

## Nền tảng

**Xilinx Zynq-7010** trên board **Digilent ZyBo (Rev B.3)** — kết hợp:

```
┌──────────────────────────────────────────────────┐
│                  Zynq-7010 SoC                   │
│                                                  │
│   ┌──────────────────┐      ┌──────────────────┐ │
│   │   PS (Hard)      │      │   PL (FPGA)      │ │
│   │   ARM Cortex-A9  │◄────►│   28K Logic Cells│ │
│   │   Dual Core      │ AXI  │   BRAM, DSP      │ │
│   │   650 MHz        │      │   User IP        │ │
│   └──────────────────┘      └──────────────────┘ │
└──────────────────────────────────────────────────┘
```

- **PS (Processing System):** lõi ARM Cortex-A9 cứng — chạy bare-metal C hoặc Linux
- **PL (Programmable Logic):** vùng FPGA cấu hình được — chứa logic phần cứng tùy biến
- **AXI Bus:** kênh giao tiếp giữa PS và PL

---

## Toolchain

| Công cụ | Vai trò |
|---------|---------|
| **Vivado 2025.2** | Thiết kế HW — RTL, Block Design, Synthesis, Bitstream |
| **Vitis 2025.2** | Phát triển SW — bare-metal C cho ARM Cortex-A9 |
| **Verilog / VHDL** | Ngôn ngữ mô tả phần cứng |
| **C** | Phát triển phần mềm trên PS |

---

## Danh sách Lab

| Lab | Tên | Nội dung chính | Trạng thái |
|-----|-----|----------------|------------|
| [Lab 1](./LAB_1/) | First Designs on Zynq | PS điều khiển 4 LED qua AXI GPIO | ✅ |
| [Lab 2](./LAB_2/) | *(cập nhật sau)* | — | 🔜 |
| [Lab 3](./LAB_3/) | *(cập nhật sau)* | — | 🔜 |
| [Lab 4](./LAB_4/) | *(cập nhật sau)* | — | 🔜 |
---
## Quy trình HW/SW Co-design trên Zynq

```
   ┌─────────────────┐
   │  Vivado (HW)    │  ← Thiết kế phần cứng
   │  Block Design   │
   │  + RTL          │
   └────────┬────────┘
            │ Bitstream + .xsa
            ▼
   ┌─────────────────┐
   │  Vitis (SW)     │  ← Phát triển phần mềm
   │  Platform + App │
   └────────┬────────┘
            │ .elf + .bit
            ▼
   ┌─────────────────┐
   │  ZyBo Board     │  ← Chạy thực tế
   └─────────────────┘
```

---

## Kiến thức cốt lõi

- **HDL:** mô tả phần cứng bằng Verilog/VHDL — logic tổ hợp & tuần tự
- **IP Integration:** ghép các khối IP có sẵn (Zynq PS, AXI GPIO, AXI Interconnect...) trong Vivado IP Integrator
- **AXI Protocol:** AXI4, AXI4-Lite, AXI-Stream — bus chuẩn của Xilinx
- **Bare-metal C:** lập trình không OS trên ARM, dùng driver Xilinx (`xgpio.h`, `xparameters.h`...)
- **Address Mapping:** ánh xạ thanh ghi peripheral vào không gian địa chỉ của CPU
- **Toolchain flow:** Synthesis → Implementation → Bitstream → Hardware Export → SW Build → Program & Debug

---

## Tài liệu tham khảo

- *The Zynq Book* — Louise H. Crockett et al., University of Strathclyde
- *Zynq-7000 SoC Technical Reference Manual (UG585)* — AMD/Xilinx
- *ZyBo Reference Manual* — Digilent
- *Vitis Unified Software Platform Documentation* — AMD/Xilinx

---

*Repository này được duy trì cho mục đích học tập trong khuôn khổ môn học.*

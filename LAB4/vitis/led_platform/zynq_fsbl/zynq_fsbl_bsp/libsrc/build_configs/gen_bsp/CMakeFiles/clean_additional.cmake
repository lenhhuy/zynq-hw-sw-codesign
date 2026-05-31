# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "D:\\Semester_6\\HWSW\\LAB4\\vitis\\led_platform\\zynq_fsbl\\zynq_fsbl_bsp\\include\\diskio.h"
  "D:\\Semester_6\\HWSW\\LAB4\\vitis\\led_platform\\zynq_fsbl\\zynq_fsbl_bsp\\include\\ff.h"
  "D:\\Semester_6\\HWSW\\LAB4\\vitis\\led_platform\\zynq_fsbl\\zynq_fsbl_bsp\\include\\ffconf.h"
  "D:\\Semester_6\\HWSW\\LAB4\\vitis\\led_platform\\zynq_fsbl\\zynq_fsbl_bsp\\include\\sleep.h"
  "D:\\Semester_6\\HWSW\\LAB4\\vitis\\led_platform\\zynq_fsbl\\zynq_fsbl_bsp\\include\\xilffs.h"
  "D:\\Semester_6\\HWSW\\LAB4\\vitis\\led_platform\\zynq_fsbl\\zynq_fsbl_bsp\\include\\xilffs_config.h"
  "D:\\Semester_6\\HWSW\\LAB4\\vitis\\led_platform\\zynq_fsbl\\zynq_fsbl_bsp\\include\\xilrsa.h"
  "D:\\Semester_6\\HWSW\\LAB4\\vitis\\led_platform\\zynq_fsbl\\zynq_fsbl_bsp\\include\\xiltimer.h"
  "D:\\Semester_6\\HWSW\\LAB4\\vitis\\led_platform\\zynq_fsbl\\zynq_fsbl_bsp\\include\\xtimer_config.h"
  "D:\\Semester_6\\HWSW\\LAB4\\vitis\\led_platform\\zynq_fsbl\\zynq_fsbl_bsp\\lib\\libxilffs.a"
  "D:\\Semester_6\\HWSW\\LAB4\\vitis\\led_platform\\zynq_fsbl\\zynq_fsbl_bsp\\lib\\libxilrsa.a"
  "D:\\Semester_6\\HWSW\\LAB4\\vitis\\led_platform\\zynq_fsbl\\zynq_fsbl_bsp\\lib\\libxiltimer.a"
  )
endif()

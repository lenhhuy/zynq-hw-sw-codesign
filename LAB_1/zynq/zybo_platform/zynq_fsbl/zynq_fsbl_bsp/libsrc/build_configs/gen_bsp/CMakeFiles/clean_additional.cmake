# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "C:\\zynq\\zybo_platform\\zynq_fsbl\\zynq_fsbl_bsp\\include\\diskio.h"
  "C:\\zynq\\zybo_platform\\zynq_fsbl\\zynq_fsbl_bsp\\include\\ff.h"
  "C:\\zynq\\zybo_platform\\zynq_fsbl\\zynq_fsbl_bsp\\include\\ffconf.h"
  "C:\\zynq\\zybo_platform\\zynq_fsbl\\zynq_fsbl_bsp\\include\\sleep.h"
  "C:\\zynq\\zybo_platform\\zynq_fsbl\\zynq_fsbl_bsp\\include\\xilffs.h"
  "C:\\zynq\\zybo_platform\\zynq_fsbl\\zynq_fsbl_bsp\\include\\xilffs_config.h"
  "C:\\zynq\\zybo_platform\\zynq_fsbl\\zynq_fsbl_bsp\\include\\xilrsa.h"
  "C:\\zynq\\zybo_platform\\zynq_fsbl\\zynq_fsbl_bsp\\include\\xiltimer.h"
  "C:\\zynq\\zybo_platform\\zynq_fsbl\\zynq_fsbl_bsp\\include\\xtimer_config.h"
  "C:\\zynq\\zybo_platform\\zynq_fsbl\\zynq_fsbl_bsp\\lib\\libxilffs.a"
  "C:\\zynq\\zybo_platform\\zynq_fsbl\\zynq_fsbl_bsp\\lib\\libxilrsa.a"
  "C:\\zynq\\zybo_platform\\zynq_fsbl\\zynq_fsbl_bsp\\lib\\libxiltimer.a"
  )
endif()

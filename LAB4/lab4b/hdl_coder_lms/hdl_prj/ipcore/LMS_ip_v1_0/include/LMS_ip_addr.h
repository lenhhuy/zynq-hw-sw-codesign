/*
 * File Name:         hdl_prj\ipcore\LMS_ip_v1_0\include\LMS_ip_addr.h
 * Description:       C Header File
 * Created:           2026-06-01 08:09:03
*/

#ifndef LMS_IP_H_
#define LMS_IP_H_

#define  IPCore_Reset_LMS_ip       0x0  //write 0x1 to bit 0 to reset IP core
#define  IPCore_Enable_LMS_ip      0x4  //enabled (by default) when bit 0 is 0x1
#define  IPCore_Strobe_LMS_ip      0x8  //write 1 to bit 0 after write all input data
#define  IPCore_Ready_LMS_ip       0xC  //wait until bit 0 is 1 before read output data
#define  IPCore_Timestamp_LMS_ip   0x10  //contains unique IP timestamp (yymmddHHMM): 2606010809
#define  x_k__Data_LMS_ip          0x100  //data register for Inport x(k)
#define  d_k__Data_LMS_ip          0x104  //data register for Inport d(k)
#define  e_k__Data_LMS_ip          0x108  //data register for Outport e(k)

#endif /* LMS_IP_H_ */

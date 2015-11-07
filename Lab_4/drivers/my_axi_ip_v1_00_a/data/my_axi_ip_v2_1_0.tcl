##############################################################################
## Filename:          D:\Study\first\prj_ZYNQ_PS\Lab_4/drivers/my_axi_ip_v1_00_a/data/my_axi_ip_v2_1_0.tcl
## Description:       Microprocess Driver Command (tcl)
## Date:              Sat Jul 25 08:50:04 2015 (by Create and Import Peripheral Wizard)
##############################################################################

#uses "xillib.tcl"

proc generate {drv_handle} {
  xdefine_include_file $drv_handle "xparameters.h" "my_axi_ip" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" 
}

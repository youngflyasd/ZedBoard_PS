#include <stdio.h>
#include "xparameters.h"
#include "xil_types.h"
#include "xstatus.h"
#include "xil_testmem.h"
#include "xgpio.h"
#include "platform.h"

void print(char *ptr);

int main()
{
	static XGpio LED_Ptr;//定义GPIO指针
	int XStatus;//函数返回状态

    init_platform();

    print("ZedBoard LAB3: PS_AXI_LED\n\r");
    print("超群天晴 2012年10月7日22:12:31\n\r");

    XStatus = XGpio_Initialize(&LED_Ptr,XPAR_AXI_LDS_DEVICE_ID);
    if(XST_SUCCESS != XStatus)
    	print("GPIO INIT FAILED\n\r");

    XGpio_SetDataDirection(&LED_Ptr, 1,0x00);//通道1；设置方向 0 输出 1输入

    XGpio_DiscreteWrite(&LED_Ptr, 1,0xaa);

    cleanup_platform();

}

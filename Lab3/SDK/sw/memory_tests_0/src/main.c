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
	static XGpio LED_Ptr;//����GPIOָ��
	int XStatus;//��������״̬

    init_platform();

    print("ZedBoard LAB3: PS_AXI_LED\n\r");
    print("��Ⱥ���� 2012��10��7��22:12:31\n\r");

    XStatus = XGpio_Initialize(&LED_Ptr,XPAR_AXI_LDS_DEVICE_ID);
    if(XST_SUCCESS != XStatus)
    	print("GPIO INIT FAILED\n\r");

    XGpio_SetDataDirection(&LED_Ptr, 1,0x00);//ͨ��1�����÷��� 0 ��� 1����

    XGpio_DiscreteWrite(&LED_Ptr, 1,0xaa);

    cleanup_platform();

}

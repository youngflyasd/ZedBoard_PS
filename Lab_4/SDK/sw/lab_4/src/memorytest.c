/*
 * Copyright (c) 2009 Xilinx, Inc.  All rights reserved.
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A 
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR 
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION 
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE 
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO 
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO 
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE 
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY 
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#include <stdio.h>
#include "xparameters.h"
#include "xil_types.h"
#include "xstatus.h"
#include "xil_testmem.h"

#include "xil_io.h"		//包含xil_io头文件，完成对绝对地址的访问

#include "platform.h"
#include "memory_config.h"

#define LED_DATA_REG 0x6d200000			//自定义IP的基地址（起始地址）

void putnum(unsigned int num);
//void print(char *ptr);

void delay(unsigned int delaytime);		//延时函数，不是用的定时器做的，循环做的，不开心
void LED_Play(unsigned char led);		//流水灯执行函数

void test_memory_range(struct memory_range_s *range) {
    XStatus status;

    /* This application uses print statements instead of xil_printf/printf
     * to reduce the text size.
     *
     * The default linker script generated for this application does not have
     * heap memory allocated. This implies that this program cannot use any
     * routines that allocate memory on heap (printf is one such function).
     * If you'd like to add such functions, then please generate a linker script
     * that does allocate sufficient heap memory.
     */

    print("Testing memory region: "); print(range->name);  print("\n\r");
    print("    Memory Controller: "); print(range->ip);  print("\n\r");
    print("         Base Address: 0x"); putnum(range->base); print("\n\r");
    print("                 Size: 0x"); putnum(range->size); print (" bytes \n\r");

    status = Xil_TestMem32((u32*)range->base, 1024, 0xAAAA5555, XIL_TESTMEM_ALLMEMTESTS);
    print("          32-bit test: "); print(status == XST_SUCCESS? "PASSED!":"FAILED!"); print("\n\r");

    status = Xil_TestMem16((u16*)range->base, 2048, 0xAA55, XIL_TESTMEM_ALLMEMTESTS);
    print("          16-bit test: "); print(status == XST_SUCCESS? "PASSED!":"FAILED!"); print("\n\r");

    status = Xil_TestMem8((u8*)range->base, 4096, 0xA5, XIL_TESTMEM_ALLMEMTESTS);
    print("           8-bit test: "); print(status == XST_SUCCESS? "PASSED!":"FAILED!"); print("\n\r");

}

int main()
{
    int i;

    init_platform();

    print("--Starting Memory Test Application--\n\r");
    print("NOTE: This application runs with D-Cache disabled.");
    print("As a result, cacheline requests will not be generated\n\r");

    for (i = 0; i < n_memory_ranges; i++) {
        test_memory_range(&memory_ranges[i]);
    }

    print("--Memory Test Application Complete--\n\r");

    LED_Play(0x03);
    while(1);
    cleanup_platform();
    return 0;
}

void delay(unsigned int delaytime)
{
	int i;
	for(i=0;i<delaytime;i++);
}

void LED_Play(unsigned char led)
{
	for(;;)
	{
		led=(led<<1)|(led>>7);
		Xil_Out32(LED_DATA_REG,led);	//将led的值输出到LED_DATA_REG地址（可能对应端口，可能对应寄存器，）
		delay(5000000);					//这个地方对应的my_axi_ip_0的基地址，也就是LD输出端口
	}
}

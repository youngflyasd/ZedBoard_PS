/* This file is automatically generated based on your hardware design. */
#include "memory_config.h"

struct memory_range_s memory_ranges[] = {
	{
		"ps7_ddr_0",
		"ps7_ddr",
		0x00100000,
		1072693248,
	},
	/* ps7_ram_0 memory will not be tested since application resides in the same memory */
	{
		"ps7_ram_1",
		"ps7_ram",
		0xffff0000,
		65024,
	},
};

int n_memory_ranges = 2;

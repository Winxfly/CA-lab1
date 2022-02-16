#pragma once
#include <Windows.h>
#include <iostream>

class MemoryInfo {
private:

	MEMORYSTATUSEX memory;

	unsigned int total;
	unsigned int free;
	unsigned int used;
	unsigned int percentUsed;
	unsigned int percentFree;

public:

	MemoryInfo();
	void getMemoryInfo();
};
#include <iostream>
#include <Windows.h>

#include "MemoryInfo.h"
#include "DiskInfo.h"

int main() {
	setlocale(LC_ALL, "ru");

	MemoryInfo m;
	m.getMemoryInfo();

	DiskInfo d;
	d.getDiskInfo();

	return 0;
}
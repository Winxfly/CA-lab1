#include "MemoryInfo.h"

MemoryInfo::MemoryInfo() {
	memory.dwLength = sizeof(memory);
	GlobalMemoryStatusEx(&memory);

	total = memory.ullTotalPhys / (1024 * 1024);
	free = memory.ullAvailPhys / (1024 * 1024);
	used = total - free;
	percentUsed = memory.dwMemoryLoad;
	percentFree = 100 - percentUsed;
}

void MemoryInfo::getMemoryInfo() {
	std::cout << "\t������\n\n";
	std::cout << "�����:\t\t" << total << " ��\n";
	std::cout << "������������:\t" << used << " �� (" << percentUsed << " %)\n";
	std::cout << "��������:\t" << free << " �� (" << percentFree << " %)\n\n";
}
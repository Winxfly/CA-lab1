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
	std::cout << "\tÏÀÌßÒÜ\n\n";
	std::cout << "Îáúåì:\t\t" << total << " ÌÁ\n";
	std::cout << "Èñïîëüçóåòñÿ:\t" << used << " ÌÁ (" << percentUsed << " %)\n";
	std::cout << "Äîñòóïíî:\t" << free << " ÌÁ (" << percentFree << " %)\n\n";
}
#include "DiskInfo.h"

DiskInfo::DiskInfo() {

}

void DiskInfo::getDiskInfo() {
	szLogicalDrives = new char[sz];
	GetLogicalDriveStrings(sz, szLogicalDrives);

	std::cout << "\tÄÈÑÊÈ\n\n";
	while (*szLogicalDrives)
	{
		char szDisk[80];
		lstrcpy(szDisk, szLogicalDrives);

		GetDiskFreeSpaceEx(szDisk, NULL, (PULARGE_INTEGER)&uliTotalBytes, (PULARGE_INTEGER)&uliFreeBytes);
		uliUsedBytes = uliTotalBytes - uliFreeBytes;

		std::cout << szDisk << "\n";
		std::cout << "Îáúåì äèñêà:\t" << uliTotalBytes / (1024 * 1024) << " ÌÁ\n";
		std::cout << "Äîñòóïíî:\t" << uliFreeBytes / (1024 * 1024) << " ÌÁ\n";
		std::cout << "Çàíÿòî:\t\t" << uliUsedBytes / (1024 * 1024) << " ÌÁ\n\n";

		while (*szLogicalDrives) szLogicalDrives++;
		szLogicalDrives++;
	}
}
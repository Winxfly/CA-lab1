#include "DiskInfo.h"

DiskInfo::DiskInfo() {

}

void DiskInfo::getDiskInfo() {
	szLogicalDrives = new char[sz];
	GetLogicalDriveStrings(sz, szLogicalDrives);

	std::cout << "\t�����\n\n";
	while (*szLogicalDrives)
	{
		char szDisk[80];
		lstrcpy(szDisk, szLogicalDrives);

		GetDiskFreeSpaceEx(szDisk, NULL, (PULARGE_INTEGER)&uliTotalBytes, (PULARGE_INTEGER)&uliFreeBytes);
		uliUsedBytes = uliTotalBytes - uliFreeBytes;

		std::cout << szDisk << "\n";
		std::cout << "����� �����:\t" << uliTotalBytes / (1024 * 1024) << " ��\n";
		std::cout << "��������:\t" << uliFreeBytes / (1024 * 1024) << " ��\n";
		std::cout << "������:\t\t" << uliUsedBytes / (1024 * 1024) << " ��\n\n";

		while (*szLogicalDrives) szLogicalDrives++;
		szLogicalDrives++;
	}
}
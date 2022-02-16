#pragma once
#include <Windows.h>
#include <iostream>

class DiskInfo {
private:

	int sz = GetLogicalDriveStrings(NULL, 0);
	char* szLogicalDrives;

	__int64 uliTotalBytes;
	__int64 uliFreeBytes;
	__int64 uliUsedBytes;

public:

	DiskInfo();
	void getDiskInfo();
};
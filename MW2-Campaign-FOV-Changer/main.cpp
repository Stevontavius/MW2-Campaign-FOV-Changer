#include <iostream>
#include <windows.h>
#include <tlhelp32.h>
#include <stdlib.h>
#include "CoDMemory.h"
#include "procid.h"

int main(int argc, char** argv) {

	float desiredFOV;
	
	std::cout << "Enter the desired FOV: ";
	std::cin >> desiredFOV;
	
	Sleep(1000);

	std::wstring mw2 = L"iw4sp.exe";
	DWORD pID = GetProcessIdByName(mw2);
	HWND hwnd = FindWindowA(NULL, "Modern Warfare 2");
	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);

	system("cls");
	Sleep(500);

	if (hwnd == NULL) 
	{
		system("Color 0C");
		std::cout << "Failed to find Call of Duty: Modern Warfare 2 (iw4sp.exe)\n\n";
		Sleep(1000);
		std::cout << "Please start Modern Warfare 2 (2009) from Steam & reopen utility.\n";
		Sleep(1000);
	}
	else
	{
		system("Color 0A");
		std::cout << "Found Call of Duty: Modern Warfare 2! Setting FOV to " << desiredFOV << "\n\n";

		WriteProcessMemory(handle, LPVOID(0x01978B50), &desiredFOV, sizeof(desiredFOV), 0);

		Sleep(1000);
		std::cout << "Successfully set FOV to " << desiredFOV << "!\n";
		Sleep(1000);
		std::cout << "You may close the software!\n";
		Sleep(100);
	}
}
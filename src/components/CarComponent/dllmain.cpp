// dllmain.cpp : Implementation of DllMain.

#include "dllmain.h"
#include "CarComponent_h.h"

CarComponentModule _AtlModule;

// DLL Entry Point
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	return _AtlModule.DllMain(dwReason, lpReserved);
}

#include <initguid.h>
#include <Windows.h>
#include "CoCarClassFactory.h"

ULONG _lockCount = 0;
ULONG _objCount = 0;

// {97B98437-966B-4F72-9527-363603BD8572}
DEFINE_GUID(CLSID_CoCar,
	0x97b98437, 0x966b, 0x4f72, 0x95, 0x27, 0x36, 0x36, 0x3, 0xbd, 0x85, 0x72);

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, void** ppv)
{
	if (rclsid != CLSID_CoCar)
	{
		return CLASS_E_CLASSNOTAVAILABLE;
	}

	auto* pCFact = new CoCarClassFactory();
	const auto hr = pCFact->QueryInterface(riid, ppv);

	if (FAILED(hr))
	{
		delete pCFact;
	}

	return hr;
}

STDAPI DllCanUnloadNow()
{
	return _lockCount == 0 && _objCount == 0 ? S_OK : S_FALSE;
}

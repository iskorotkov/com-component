#include <initguid.h>
#include <Windows.h>
#include "CoCarClassFactory.h"
#include "iid.h"

ULONG _lockCount = 0;
ULONG _objCount = 0;

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

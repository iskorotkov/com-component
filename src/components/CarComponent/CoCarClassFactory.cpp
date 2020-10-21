#include "CoCarClassFactory.h"
#include "CoCar.h"

extern DWORD _lockCount;
extern DWORD _objCount;

CoCarClassFactory::CoCarClassFactory()
{
	_refCount = 0;
	++_objCount;
}

CoCarClassFactory::~CoCarClassFactory()
{
	--_objCount;
}

STDMETHODIMP CoCarClassFactory::QueryInterface(const IID& riid, void** pIFace)
{
	if (riid == IID_IUnknown)
	{
		*pIFace = static_cast<IUnknown*>(this);
	}
	else if (riid == IID_IClassFactory)
	{
		*pIFace = static_cast<IClassFactory*>(this);
	}
	else
	{
		*pIFace = nullptr;
		return E_NOINTERFACE;
	}

	static_cast<IUnknown*>(*pIFace)->AddRef();
	return S_OK;
}

STDMETHODIMP_(DWORD) CoCarClassFactory::AddRef()
{
	++_refCount;
	return _refCount;
}

STDMETHODIMP_(DWORD) CoCarClassFactory::Release()
{
	--_refCount;
	if (_refCount == 0)
	{
		delete this;
	}

	return _refCount;
}

HRESULT CoCarClassFactory::LockServer(BOOL fLock)
{
	if (fLock)
	{
		++_lockCount;
	}
	else
	{
		--_lockCount;
	}

	return S_OK;
}

HRESULT CoCarClassFactory::CreateInstance(LPUNKNOWN pUnkOuter, const IID& riid, void** ppv)
{
	if (pUnkOuter)
	{
		return CLASS_E_NOAGGREGATION;
	}

	auto* pCarObj = new CoCar();
	if (pCarObj == nullptr)
	{
		return E_OUTOFMEMORY;
	}

	const auto hr = pCarObj->QueryInterface(riid, ppv);

	if (FAILED(hr))
	{
		delete pCarObj;
	}

	return hr;
}

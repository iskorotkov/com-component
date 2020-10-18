#pragma once
#include <Windows.h>

class CoCarClassFactory: public IClassFactory
{
public:
	CoCarClassFactory();
	virtual ~CoCarClassFactory();

	// IUnknown
	STDMETHODIMP QueryInterface(REFIID riid, void** pIFace) override;
	STDMETHODIMP_(DWORD) AddRef() override;
	STDMETHODIMP_(DWORD) Release() override;

	// IClassFactory
	STDMETHODIMP LockServer(BOOL fLock) override;
	STDMETHODIMP CreateInstance(LPUNKNOWN pUnkOuter, REFIID riid, void** ppv) override;

private:
	DWORD _refCount;
};

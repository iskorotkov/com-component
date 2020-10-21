#pragma once
#include <atlbase.h>
#include <atlctl.h>
#include "interfaces.h"

const int MAX_SPEED = 1000;
const int MAX_NAME_LENGTH = 256;

class CoCar : public IEngine, public ICreateCar, public IStats
{
public:
	CoCar();
	virtual ~CoCar();

	DECLARE_REGISTRY_RESOURCEID(101)

BEGIN_COM_MAP(CoCar)
	COM_INTERFACE_ENTRY(IEngine)
	COM_INTERFACE_ENTRY(ICreateCar)
	COM_INTERFACE_ENTRY(IStats)
END_COM_MAP()

	HRESULT Init();

	// IUnknown
	STDMETHODIMP QueryInterface(REFIID riid, void** pIFace) override;
	STDMETHODIMP_(DWORD) AddRef() override;
	STDMETHODIMP_(DWORD) Release() override;

	// IEngine
	STDMETHODIMP SpeedUp() override;
	STDMETHODIMP GetMaxSpeed(int* maxSpeed) override;
	STDMETHODIMP GetCurSpeed(int* curSpeed) override;

	// IStats
	STDMETHODIMP DisplayStats() override;
	STDMETHODIMP GetPetName(BSTR* petName) override;

	// ICreateCar
	STDMETHODIMP SetPetName(BSTR petName) override;
	STDMETHODIMP SetMaxSpeed(int maxSp) override;

	// IDispatch
	STDMETHODIMP GetTypeInfoCount(UINT* pctinfo) override;
	STDMETHODIMP GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo) override;
	STDMETHODIMP GetIDsOfNames(const IID& riid, LPOLESTR* rgszNames, UINT cNames, LCID lcid, DISPID* rgDispId) override;
	STDMETHODIMP Invoke(DISPID dispIdMember, const IID& riid, LCID lcid, WORD wFlags, DISPPARAMS* pDispParams,
		VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr) override;

private:
	DWORD _refCount = 0;
	BSTR _petName;
	int _maxSpeed = 0;
	int _curSpeed = 0;

	ITypeInfo* _typeInfo{};
};

#pragma once
#include <atlbase.h>
#include <atlctl.h>
#include <OAIdl.h>
#include <OCIdl.h>
#include <Ole2.h>
#include <rpc.h>
#include <rpcndr.h>
#include <Windows.h>
#include "iid.h"
#include "carinprocserver_h.h"

using namespace ATL;

const int MAX_SPEED = 1000;
const int MAX_NAME_LENGTH = 256;

class CoCar :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CoCar, &CLSID_CoCar>,
	public IDispatchImpl<ICoCar, &IID_IEngine, &LIBID_CarComponent>,
	public IEngine,
	public IStats,
	public ICreateCar
{
public:
	CoCar();
	virtual ~CoCar();

	DECLARE_REGISTRY_RESOURCEID(101)

	BEGIN_COM_MAP(CoCar)
		COM_INTERFACE_ENTRY(ICoCar)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(IEngine)
		COM_INTERFACE_ENTRY(ICreateCar)
		COM_INTERFACE_ENTRY(IStats)
	END_COM_MAP()

	/*BEGIN_MSG_MAP(CoCar)
		DEFAULT_REFLECTION_HANDLER()
	END_MSG_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()*/

	HRESULT Init();

	// IEngine
	STDMETHODIMP SpeedUp();
	STDMETHODIMP GetMaxSpeed(int* maxSpeed);
	STDMETHODIMP GetCurSpeed(int* curSpeed);

	// IStats
	STDMETHODIMP DisplayStats();
	STDMETHODIMP GetPetName(BSTR* petName);

	// ICreateCar
	STDMETHODIMP SetPetName(BSTR petName);
	STDMETHODIMP SetMaxSpeed(int maxSp);

private:
	DWORD _refCount = 0;
	BSTR _petName;
	int _maxSpeed = 0;
	int _curSpeed = 0;

	ITypeInfo* _typeInfo{};
};

OBJECT_ENTRY_AUTO(__uuidof(CoCar), CoCar)

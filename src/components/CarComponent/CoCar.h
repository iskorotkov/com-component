#pragma once
#include <atlbase.h>
#include <atlctl.h>
#include "CarComponent_h.h"
#include "Resource.h"

using namespace ATL;

const int MAX_SPEED = 1000;
const int MAX_NAME_LENGTH = 256;

class ATL_NO_VTABLE CoCar :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CoCar, &CLSID_Car>,
	public IDispatchImpl<ICar, &IID_ICar, &LIBID_CarComponent, 1, 0>,
	public IDispatchImpl<IEngine, &IID_IEngine, &LIBID_CarComponent, 1, 0>,
	public IDispatchImpl<IStats, &IID_IStats, &LIBID_CarComponent, 1, 0>,
	public IDispatchImpl<ICreateCar, &IID_ICreateCar, &LIBID_CarComponent, 1, 0>
{
public:
	CoCar();
	virtual ~CoCar();

	DECLARE_REGISTRY_RESOURCEID(IDR_CAR)

BEGIN_COM_MAP(CoCar)
		COM_INTERFACE_ENTRY(ICar)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(IEngine)
		COM_INTERFACE_ENTRY(ICreateCar)
		COM_INTERFACE_ENTRY(IStats)
		END_COM_MAP()

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
	BSTR _petName;
	int _maxSpeed = 0;
	int _curSpeed = 0;
};

OBJECT_ENTRY_AUTO(__uuidof(Car), CoCar)

#pragma once
#include <Windows.h>

DECLARE_INTERFACE_(IStats, IDispatch)
{
	STDMETHOD(DisplayStats)() PURE;
	STDMETHOD(GetPetName)(BSTR* petName) PURE;
};

DECLARE_INTERFACE_(IEngine, IDispatch)
{
	STDMETHOD(SpeedUp)() PURE;
	STDMETHOD(GetMaxSpeed)(int* maxSpeed) PURE;
	STDMETHOD(GetCurSpeed)(int* curSpeed) PURE;
};

DECLARE_INTERFACE_(ICreateCar, IDispatch)
{
	STDMETHOD(SetPetName)(BSTR petName) PURE;
	STDMETHOD(SetMaxSpeed)(int maxSp) PURE;
};

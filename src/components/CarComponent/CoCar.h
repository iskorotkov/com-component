#pragma once
#include "interfaces.h"

const int MAX_SPEED = 1000;
const int MAX_NAME_LENGTH = 256;

class CoCar : public IEngine, public ICreateCar, public IStats
{
public:
	CoCar();
	virtual ~CoCar();

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

private:
	DWORD _refCount;
	BSTR _petName;
	int _maxSpeed;
	int _curSpeed;
};

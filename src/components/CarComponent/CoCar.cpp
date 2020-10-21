#include "CoCar.h"
#include <cstdio>
#include "iid.h"

extern DWORD _objCount;

CoCar::CoCar()
{
	_petName = SysAllocString(L"Default Pet Name");
	++_objCount;
}

CoCar::~CoCar()
{
	if (_petName)
	{
		SysFreeString(_petName);
	}
	--_objCount;
}

STDMETHODIMP CoCar::SpeedUp()
{
	_curSpeed += 10;
	return S_OK;
}

STDMETHODIMP CoCar::GetMaxSpeed(int* maxSpeed)
{
	*maxSpeed = _maxSpeed;
	return S_OK;
}

STDMETHODIMP CoCar::GetCurSpeed(int* curSpeed)
{
	*curSpeed = _curSpeed;
	return S_OK;
}

HRESULT CoCar::DisplayStats()
{
	char buff[MAX_NAME_LENGTH];
	WideCharToMultiByte(CP_ACP, 0, _petName, -1, buff, MAX_NAME_LENGTH, nullptr, nullptr);
	MessageBoxA(nullptr, buff, "Pet name", MB_OK | MB_SETFOREGROUND);
	memset(buff, 0, sizeof buff);

	sprintf_s(buff, "%d", _maxSpeed);
	MessageBoxA(nullptr, buff, "Max speed", MB_OK | MB_SETFOREGROUND);

	return S_OK;
}

STDMETHODIMP CoCar::GetPetName(BSTR* petName)
{
	*petName = SysAllocString(_petName);
	return S_OK;
}

STDMETHODIMP CoCar::SetPetName(BSTR petName)
{
	SysReAllocString(&_petName, petName);
	return S_OK;
}

STDMETHODIMP CoCar::SetMaxSpeed(int maxSp)
{
	if (maxSp < MAX_SPEED)
	{
		_maxSpeed = maxSp;
		return S_OK;
	}

	return E_INVALIDARG;
}

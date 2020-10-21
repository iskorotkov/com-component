// dllmain.h : Declaration of module class.

#pragma once
#include <atlbase.h>
#include "CarComponent_h.h"
#include "Resource.h"

class CarComponentModule : public ATL::CAtlDllModuleT< CarComponentModule >
{
public :
	DECLARE_LIBID(LIBID_CarComponent)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLPROJECT1, "{F13E8FBA-40FF-4F09-9101-314FB9C8C1DD}")
};

extern class CarComponentModule _AtlModule;

#include <Windows.h>
#include <string>
#include "../../API/RainmeterAPI.h"

struct Measure
{
	std::wstring strValue;
	void* rm;
	Measure():
		strValue(),
		rm()
	{}
};

PLUGIN_EXPORT void Initialize(void** data, void* rm)
{
	Measure* measure = new Measure;
	measure->rm = rm;
	*data = measure;
}

PLUGIN_EXPORT void Reload(void* data, void* rm, double* maxValue)
{
	Measure* measure = (Measure*)data;
}

PLUGIN_EXPORT double Update(void* data)
{
	Measure* measure = (Measure*)data;

	HWND hwnd = GetForegroundWindow(); // get handle of currently active window

	const int length = GetWindowTextLength(hwnd);
	std::wstring wndTitle;
	wndTitle.resize(length + 1);
	GetWindowText(hwnd, &wndTitle[0], (int)wndTitle.size());
	measure->strValue = wndTitle;
	// RmLog(measure->rm, LOG_NOTICE, L"I am a 'notice'");
	return length;
}

PLUGIN_EXPORT LPCWSTR GetString(void* data)
{
	Measure* measure = (Measure*)data;
	return measure->strValue.c_str();
}

//PLUGIN_EXPORT void ExecuteBang(void* data, LPCWSTR args)
//{
//	Measure* measure = (Measure*)data;
//}

//PLUGIN_EXPORT LPCWSTR (void* data, const int argc, const WCHAR* argv[])
//{
//	Measure* measure = (Measure*)data;
//	return nullptr;
//}

PLUGIN_EXPORT void Finalize(void* data)
{
	Measure* measure = (Measure*)data;
	delete measure;
}

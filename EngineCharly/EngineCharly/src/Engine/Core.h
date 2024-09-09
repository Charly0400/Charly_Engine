#pragma once


#ifdef CHARLY_PLATFORM_WINDOWS
	#ifdef CHARLY_BUILD_DLL
		#define CHARLY_API __declspec(dllexport)
	#else
		#define CHARLY_API __declspec(dllimport)
	#endif
#else
	#error Only support windows
#endif

#ifdef CHARLY_ENABLE_ASSERTS
	#defiene CHARLY_ASSERT(x, ...) {if(!(x)){GLE_ERROR ("Assertion Failed {0]", __VA_ARGS__); __debugbreak();}}
	#defiene CHARLY_CORE_ASSERT(x, ...) {if(!(x)){GLE_ERROR ("Assertion Failed {0]", __VA_ARGS__); __debugbreak();}}
#else
	#define CHARLY_ASSERT(x, ...)
	#define CHARLY_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

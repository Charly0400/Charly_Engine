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

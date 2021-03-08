#pragma once

#ifdef GLRE_PLATFORM_WINDOWS
	#ifdef GLRE_BUILD_DLL
		#define GLRE_API __declspec(dllexport)
	#else
		#define GLRE_API __declspec(dllimport)
	#endif
#else
	#error GLRE only supports Windows.
#endif
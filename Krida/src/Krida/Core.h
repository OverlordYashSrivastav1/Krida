#pragma once

#ifdef KD_PLATFORM_WINDOWS
	#ifdef KD_BUILD_DLL
		#define KRIDA_API __declspec(dllexport)
	#else
		#define KRIDA_API __declspec(dllimport)
	#endif
#else
	#error Krdia only supports windows!
#endif

#define BIT(x) (1<<x)
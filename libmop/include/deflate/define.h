#pragma once

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

#ifdef MOP_LOG_SHOW
#define DEBUG_LOG(A)	printf(A)
#else
#define DEBUG_LOG(...)
#endif

#ifndef MIN
#define MIN(a, b)  ((a) > (b) ? (b) : (a))
#endif

#ifndef MAX
#define MAX(a, b)  ((a) < (b) ? (b) : (a))
#endif

#ifndef RANGE
#define RANGE(min, max, value)	((value) < (min) ? (min) : (max) < (value) ? (max) : (value))
#endif

#ifndef DLL_EXPORT
#define DLL_EXPORT __declspec(dllexport)
#endif

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(_A) ( sizeof(_A) / sizeof(_A[0]) )
#endif

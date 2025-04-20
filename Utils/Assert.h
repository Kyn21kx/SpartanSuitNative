#pragma once

#include <cstdio>

#ifdef _WIN32
#include <windows.h>
#if defined(_MSC_VER) || defined(__INTEL_COMPILER)
#define SP_DEBUG_BREAK __debugbreak()
#elif defined(__ARMCC_VERSION)
#define __breakpoint(42)
#endif
#else
#include <signal.h>
#ifdef SIGTRAP
#define SP_DEBUG_BREAK raise(SIGTRAP)
#else
#define SP_DEBUG_BREAK raise(SIGABRT)
#endif
#endif

#define SP_ASSERT(cond, fmt, ...)                                              \
  if (!(cond)) {                                                          \
    printf("Assertion error! " fmt, ##__VA_ARGS__);                      \
    SP_DEBUG_BREAK;                                                            \
  }

#pragma once

// Largely from https://stackoverflow.com/questions/295120/c-mark-as-deprecated

#if (defined(__cplusplus) && __cplusplus > 201402L) || defined(__CUDACC__) || defined(__HIPCC__)
// NB: We preferentially use [[deprecated]] for nvcc because
// nvcc doesn't understand __attribute__((deprecated)) syntax
// for 'using' declarations (even though the host compiler does.)
#define C10_DEPRECATED [[deprecated]]
#else
#if defined(__GNUC__)
#define C10_DEPRECATED __attribute__((deprecated))
#elif defined(_MSC_VER)
#define C10_DEPRECATED __declspec(deprecated)
#else
#warning "You need to implement C10_DEPRECATED for this compiler"
#define C10_DEPRECATED
#endif // defined(__GNUC__)
#endif // defined(__cplusplus) && __cplusplus > 201402L

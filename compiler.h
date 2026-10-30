#pragma once

#if !defined(_WIN32) && !defined(__linux__) && \
    !(defined(__APPLE__) && defined(__MACH__))
    #error "Only Windows, Linux, and macOS are supported"
#endif

#if defined(_MSC_VER)
    #define FORCE_INLINE __forceinline
#elif __has_cpp_attribute(gnu::always_inline)
    #define FORCE_INLINE [[gnu::always_inline]] inline
#else
    #define FORCE_INLINE
#endif

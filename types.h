// types.h
// Standard type definitions for freestanding embedded development
// (When newlib is not available)

#ifndef TYPES_H
#define TYPES_H

// Standard integer types
typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef unsigned short uint16_t;
typedef signed short int16_t;
typedef unsigned int uint32_t;
typedef signed int int32_t;
typedef unsigned long long uint64_t;
typedef signed long long int64_t;

// Size types
typedef uint32_t size_t;

// NULL pointer
#ifndef NULL
#define NULL ((void *)0)
#endif

// EOF for stdio compatibility
#ifndef EOF
#define EOF (-1)
#endif

// Dummy FILE type for printf compatibility
typedef struct {
  int dummy;
} FILE;

#endif // TYPES_H

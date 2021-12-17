# Count Leading Zeroes

This header-only library implements "count leading zeroes" and
closely related operations, in a way that

1. a good modern compiler like the latest `clang` can automatically
   turn into the raw "count leading zeroes" instruction when
   optimizations are turned up high enough,
2. has reasonable well-defined behavior for all inputs (does not
   rely on unportable extensions, intrinsics, or any behavior
   left implementation-defined or undefined by any C standard), and
3. is easy for a human to read, fully understand, and verify.

Try `clang -march=native -Os -S` on a modern CPU target that has
a count leading zeroes instruction and look at the assembly code!

The `clz.h` header provides:

1. The `static` functions

    * `int count_leading_zeroes(unsigned int)`
    * `int count_trailing_zeroes(unsigned int)`
    * `int find_first_set(unsigned int)`
    * `int find_last_set(unsigned int)`
    * `int count_leading_zeroes_l(unsigned long)`
    * `int count_trailing_zeroes_l(unsigned long)`
    * `int find_first_set_l(unsigned long)`
    * `int find_last_set_l(unsigned long)`
    * `int count_leading_zeroes_ll(unsigned long long)`
      (if compiling as C99 or higher)
    * `int count_trailing_zeroes_ll(unsigned long long)`
      (if compiling as C99 or higher)
    * `int find_first_set_ll(unsigned long long)`
      (if compiling as C99 or higher)
    * `int find_last_set_ll(unsigned long long)`
      (if compiling as C99 or higher)

    (which of course work on the corresponding signed integer types).

2. A `DEFINE_CLZ_FUNCTIONS` macro to define these functions for other
   unsigned integer types if needed. (Trying to define these functions
   for signed integer types is likely to hit unportable or undefined
   or undesirable behavior. If you need these functions for a signed
   type, just define the functions for the corresponding unsigned type,
   and pass the signed values into the unsigned functions. This will
   get well-defined behavior on all standard C implementations.)

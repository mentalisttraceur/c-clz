/* SPDX-License-Identifier: 0BSD */
/* Copyright 2021 Alexander Kozhevnikov <mentalisttraceur@gmail.com> */

#ifndef CLZ_H
#define CLZ_H

#define DEFINE_CLZ_FUNCTIONS( \
    unsigned_integer_type, \
    count_leading_zeroes, \
    count_trailing_zeroes, \
    find_first_set, \
    find_last_set \
) \
static \
int find_last_set(unsigned_integer_type value) \
{ \
    int position = 0; \
    while(value) \
    { \
        value >>= 1; \
        position += 1; \
    } \
    return position; \
} \
\
static \
int count_leading_zeroes(unsigned_integer_type value) \
{ \
    return find_last_set(-1) - find_last_set(value); \
} \
\
static \
int count_trailing_zeroes(unsigned_integer_type value) \
{ \
    return find_last_set(-1) - count_leading_zeroes(value & -value); \
} \
\
static \
int find_first_set(unsigned_integer_type value) \
{ \
    if(!value) \
        return 0; \
    return count_trailing_zeroes(value) + 1; \
}

DEFINE_CLZ_FUNCTIONS(
    unsigned int,
    count_leading_zeroes,
    count_trailing_zeroes,
    find_first_set,
    find_last_set
)

DEFINE_CLZ_FUNCTIONS(
    unsigned long,
    count_leading_zeroes_l,
    count_trailing_zeroes_l,
    find_first_set_l,
    find_last_set_l
)

#if __STDC_VERSION__ >= 199901L
DEFINE_CLZ_FUNCTIONS(
    unsigned long long,
    count_leading_zeroes_ll,
    count_trailing_zeroes_ll,
    find_first_set_ll,
    find_last_set_ll
)
#endif

#endif /* CLZ_H */

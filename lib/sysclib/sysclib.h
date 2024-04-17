/*
# _____     ___ ____     ___ ____
#  ____|   |    ____|   |        | |____|
# |     ___|   |____ ___|    ____| |    \    PS2DEV Open Source Project.
#-----------------------------------------------------------------------
# Copyright (c) 2003 Marcus R. Brown <mrbrown@0xd6.org>
# Licenced under Academic Free License version 2.0
# Review ps2sdk README & LICENSE files for further details.
*/

/**
 * @file
 * Standard C Library subset.
 */

#ifndef __SYSCLIB_H__
#define __SYSCLIB_H__

#include <types.h>
#include <stdarg.h>
#include <setjmp.h>
#include <ctype.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*print_callback_t)(void *context, int c);
int prnt(print_callback_t, void *context, const char * format, va_list ap);

/* These functions are used in the process of ctype.h and is non-standard. */
unsigned char look_ctype_table(char character);
void *get_ctype_table();

void *memchr(const void *s, int c, size_t n);
int memcmp(const void *p, const void *q, size_t size);
void * memcpy(void *dest, const void *src, size_t size);
void *memmove(void *dest, const void *src, size_t size);
void * memset(void *ptr, int c, size_t size);
int bcmp(const void *, const void *, size_t);
void bcopy(const void *, void *, size_t);
void bzero(void *, size_t);
int sprintf(char *str, const char *format, ...);
char *strcat(char *dest, const char *src);
char *strchr(const char *s, int c);
int strcmp(const char *p, const char *q);
char *strcpy(char *dest, const char *src);
size_t strcspn(const char *s, const char *reject);
char *index(const char *s, int c);
char *rindex(const char *s, int c);
size_t strlen(const char *s);
char *strncat(char *dest, const char *src, size_t size);
int strncmp(const char *p, const char *q, size_t size);
char *strncpy(char *dest, const char *src, size_t size);
char *strpbrk(const char *s, const char *accept);
char *strrchr(const char *s, int c);
size_t strspn(const char *s, const char *accept);
char *strstr(const char *haystack, const char *needle);
char *strtok(char *s, const char *delim);
long strtol(const char *s, char **endptr, int base);
unsigned long strtoul(const char *s, char **endptr, int base);
int vsprintf(char *, const char *, va_list);
char *strtok_r(char *s, const char *delim, char **lasts);

#ifndef SYSCLIB_DISABLE_BUILTINS
#ifndef memchr
#define memchr __builtin_memchr
#endif
#ifndef memcmp
#define memcmp __builtin_memcmp
#endif
#ifndef memcpy
#define memcpy __builtin_memcpy
#endif
#ifndef memset
#define memset __builtin_memset
#endif
#ifndef bcmp
#define bcmp __builtin_bcmp
#endif
#ifndef bzero
#define bzero __builtin_bzero
#endif
#ifndef sprintf
#define sprintf __builtin_sprintf
#endif
#ifndef strcat
#define strcat __builtin_strcat
#endif
#ifndef strchr
#define strchr __builtin_strchr
#endif
#ifndef strcmp
#define strcmp __builtin_strcmp
#endif
#ifndef strcpy
#define strcpy __builtin_strcpy
#endif
#ifndef strcspn
#define strcspn __builtin_strcspn
#endif
#ifndef index
#define index __builtin_index
#endif
#ifndef rindex
#define rindex __builtin_rindex
#endif
#ifndef strlen
#define strlen __builtin_strlen
#endif
#ifndef strncat
#define strncat __builtin_strncat
#endif
#ifndef strncmp
#define strncmp __builtin_strncmp
#endif
#ifndef strncpy
#define strncpy __builtin_strncpy
#endif
#ifndef strpbrk
#define strpbrk __builtin_strpbrk
#endif
#ifndef strrchr
#define strrchr __builtin_strrchr
#endif
#ifndef strspn
#define strspn __builtin_strspn
#endif
#ifndef strstr
#define strstr __builtin_strstr
#endif
#ifndef vsprintf
#define vsprintf __builtin_vsprintf
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif /* __SYSCLIB_H__ */

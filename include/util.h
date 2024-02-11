/* See LICENSE file for copyright and license details. */
#ifndef UTIL_H_
#define UTIL_H_

#include <sys/types.h> /* provide */
#include <stdint.h>   /* types   */

typedef unsigned char uchar;


/* buf.c */
#define BUFLEN 4096

struct Buf {
	char *data;
	size_t size;
};

extern struct Buf *buf_create(size_t);
extern void buf_free(struct Buf *);


/* io.c */
extern void eprintf(char *, ...);
extern void die(int, char *, ...);

extern int copy_file(int, int);
extern ssize_t write_all(int, void *, size_t);
extern void xwrite_all(int, void *, size_t);
extern void xclose(int);
extern ssize_t get_line(int, struct Buf *);


/* mem.c */
extern void *xmalloc(size_t, size_t);
extern void *xrealloc(void *, size_t, size_t);


/* num.c */
#define OCT 8
#define DEC 10
#define HEX 16

static inline _Bool overflow_mul(size_t a, size_t b)
{
	return (a > 0 && b > SIZE_MAX / a) ? 1 : 0;
}

static inline _Bool is_digit(char c)
{
	return (c >= 0x30 && c <= 0x39);
}

static inline size_t count_digits(char *num)
{
	size_t n = 0;

	for (; *num && is_digit(*num); ++num, ++n)
		;
	return n;
}

extern int_least64_t to_num(char *);
extern uint_least64_t to_unum(char *);
extern int_least64_t to_num_base(char *, int);

#endif /* UTIL_H_ */

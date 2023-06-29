/* See LICENSE file for copyright and license details. */
#include <stdlib.h>

#include "util.h"

void *
emalloc(size_t size)
{
	void *buf;

	if (!(buf = malloc(size)))
		die("malloc:");

	return buf;
}

void *
erealloc(void *buf, size_t size)
{
	if (!(buf = realloc(buf, size)))
		die("realloc:");

	return buf;
}

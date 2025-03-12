#ifndef HEX_H
#define HEX_H

#include <stdio.h>

size_t dump(void *mem, size_t len);
size_t fdump(FILE *f, void *mem, size_t len, size_t start);

#endif

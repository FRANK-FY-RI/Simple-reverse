#ifndef XMALLOC_H
#define XMALLOC_H

#include <stdlib.h>

#ifdef TEST_MALLOC
void* xmalloc(size_t n);
#define malloc xmalloc
#endif

#endif

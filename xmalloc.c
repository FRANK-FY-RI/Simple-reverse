#include "xmalloc.h"

#ifdef TEST_MALLOC
#undef malloc
static int counter = 0;

void* xmalloc(size_t n) {
    counter++;
    if(counter%3 == 0) return NULL;
    return malloc(n);   //real malloc
}
#endif

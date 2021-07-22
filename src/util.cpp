#include "util.h"

void err_handle(const char* err) {
    printf("%s\n",err);;
    _exit(-1);
    return;
}

int malloc_usable_size(void* ptr) {
    int x = *(long*)((char*)ptr-sizeof(long));
    if (__glibc_unlikely(x & 2)) {
        if (x & 4) {
            return x - (sizeof(long)+6);
        } else {
            return x - (sizeof(long)+2);
        }
    }
    if (x & 1) {
        return x - (sizeof(long)+1);
    }
    return 0;
}

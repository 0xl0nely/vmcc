#ifndef UTIL_H
#define UTIL_H
#include <stdio.h>
#include <unistd.h>
void err_handle(const char*);
int malloc_usable_size(void*);
#endif

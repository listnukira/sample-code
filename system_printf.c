#define _GNU_SOURCE // cause stdio.h to include asprintf
#include <stdio.h>  // printf, asprintf
#include <stdlib.h> // system
#include <assert.h>

#define System_printf(ret, ...) {           \
    char *string_sys_tmp;                   \
    asprintf(&string_sys_tmp, __VA_ARGS__); \
    ret = system(string_sys_tmp);           \
    free(string_sys_tmp);                   \
}

int main(int argc, char const* argv[])
{
    assert(argc == 2);
    int ret;
    System_printf(ret, "ls %s", argv[1]);
    
    return ret;
}

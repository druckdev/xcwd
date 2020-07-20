#include <limits.h>
#include <stdio.h>

#include "xcwdlib.h"

int main(int argc, const char *argv[])
{
    (void)argc;
    (void)argv;

    size_t buflen = 1;
#ifdef LINUX
    buflen = 255;
#endif
#ifdef FREEBSD
    buflen = PATH_MAX;
#endif
#ifdef OPENBSD
    buflen = PATH_MAX;
#endif

    char buf[buflen];
    int ret = xcwd(buf, &buflen);
    if (buflen)
        fprintf(stdout, "%s\n", buf);
    return ret;
}

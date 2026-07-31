#include "p101_host/host.h"
#include <p101_env/wrapper.h>
#ifdef __linux__
    #include <crypt.h>
#endif
#include <unistd.h>

long p101_gethostid(const struct p101_env *env)
{
    long ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = gethostid();

    P101_TRACE_EXIT(env);
    return ret_val;
}

#include <p101_env/env.h>
#include <p101_error/error.h>
#include <p101_host/p101_stdlib.h>
#include <p101_host/p101_unistd.h>
#include <p101_host/sys/p101_utsname.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    struct p101_error *err;
    struct p101_env   *env;
    long               wrapped;
    long               native;

    err = p101_error_create(false);
    if(err == NULL)
    {
        return EXIT_FAILURE;
    }
    env = p101_env_create(err, NULL);
    if(env == NULL)
    {
        p101_error_destroy(err);
        return EXIT_FAILURE;
    }
    /* P101_TEST_CASE(p101_gethostid) */
    wrapped = p101_gethostid(env);
    native  = gethostid();
    p101_env_destroy(env);
    p101_error_destroy(err);
    return wrapped == native ? EXIT_SUCCESS : EXIT_FAILURE;
}

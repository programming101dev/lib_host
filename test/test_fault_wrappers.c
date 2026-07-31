#include <errno.h>
#include <p101_env/env.h>
#include <p101_error/error.h>
#include <p101_host/host.h>
#include <stdio.h>
#include <stdlib.h>

static int failures;

#define EXPECT(condition)                                                                                                                                                                                                                                          \
    do                                                                                                                                                                                                                                                             \
    {                                                                                                                                                                                                                                                              \
        if(!(condition))                                                                                                                                                                                                                                           \
        {                                                                                                                                                                                                                                                          \
            fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #condition);                                                                                                                                                                                   \
            failures++;                                                                                                                                                                                                                                            \
        }                                                                                                                                                                                                                                                          \
    } while(0)

struct fault_state
{
    int checks;
};

static int fail_next_call(const struct p101_env *env, const char *call_name, void *user_data)
{
    struct fault_state *state;

    (void)env;
    (void)call_name;
    state = user_data;
    state->checks++;
    return EIO;
}

/* P101_TEST_CASE(p101_confstr) */
static void test_p101_confstr(struct p101_env *env, struct p101_error *err)
{
    struct fault_state state = {0};

    p101_env_set_fault_injector(env, fail_next_call, &state);
    size_t result = p101_confstr(env, err, 0, NULL, 0);
    (void)result;
    EXPECT(state.checks == 1);
    EXPECT(p101_error_has_error(err));
    p101_error_reset(err);
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_getdomainname) */
static void test_p101_getdomainname(struct p101_env *env, struct p101_error *err)
{
    struct fault_state state = {0};

    p101_env_set_fault_injector(env, fail_next_call, &state);
    int result = p101_getdomainname(env, err, NULL, 0);
    (void)result;
    EXPECT(state.checks == 1);
    EXPECT(p101_error_has_error(err));
    p101_error_reset(err);
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_gethostname) */
static void test_p101_gethostname(struct p101_env *env, struct p101_error *err)
{
    struct fault_state state = {0};

    p101_env_set_fault_injector(env, fail_next_call, &state);
    int result = p101_gethostname(env, err, NULL, 0);
    (void)result;
    EXPECT(state.checks == 1);
    EXPECT(p101_error_has_error(err));
    p101_error_reset(err);
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_getloadavg) */
static void test_p101_getloadavg(struct p101_env *env, struct p101_error *err)
{
    struct fault_state state = {0};

    p101_env_set_fault_injector(env, fail_next_call, &state);
    int result = p101_getloadavg(env, err, NULL, 0);
    (void)result;
    EXPECT(state.checks == 1);
    EXPECT(p101_error_has_error(err));
    p101_error_reset(err);
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_setdomainname) */
static void test_p101_setdomainname(struct p101_env *env, struct p101_error *err)
{
    struct fault_state state = {0};

    p101_env_set_fault_injector(env, fail_next_call, &state);
    int result = p101_setdomainname(env, err, NULL, 0);
    (void)result;
    EXPECT(state.checks == 1);
    EXPECT(p101_error_has_error(err));
    p101_error_reset(err);
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_sysconf) */
static void test_p101_sysconf(struct p101_env *env, struct p101_error *err)
{
    struct fault_state state = {0};

    p101_env_set_fault_injector(env, fail_next_call, &state);
    long result = p101_sysconf(env, err, 0);
    (void)result;
    EXPECT(state.checks == 1);
    EXPECT(p101_error_has_error(err));
    p101_error_reset(err);
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_uname) */
static void test_p101_uname(struct p101_env *env, struct p101_error *err)
{
    struct fault_state state = {0};

    p101_env_set_fault_injector(env, fail_next_call, &state);
    int result = p101_uname(env, err, NULL);
    (void)result;
    EXPECT(state.checks == 1);
    EXPECT(p101_error_has_error(err));
    p101_error_reset(err);
    p101_env_set_fault_injector(env, NULL, NULL);
}

int main(void)
{
    struct p101_error *err;
    struct p101_env   *env;

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
    test_p101_confstr(env, err);
    test_p101_getdomainname(env, err);
    test_p101_gethostname(env, err);
    test_p101_getloadavg(env, err);
    test_p101_setdomainname(env, err);
    test_p101_sysconf(env, err);
    test_p101_uname(env, err);
    p101_env_destroy(env);
    p101_error_destroy(err);
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

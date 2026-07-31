#ifndef LIBP101_HOST_HOST_H
#define LIBP101_HOST_HOST_H

/*
 * Copyright 2026 D'Arcy Smith.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 */

#include <inttypes.h>
#include <p101_env/env.h>
#include <p101_error/attributes.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C"
{
#endif

    size_t p101_confstr(const struct p101_env *env, struct p101_error *err, int name, char *buf, size_t len);
    int    p101_getdomainname(const struct p101_env *env, struct p101_error *err, char *name, size_t namelen);
    long   p101_gethostid(const struct p101_env *env);
    int    p101_gethostname(const struct p101_env *env, struct p101_error *err, char *name, size_t namelen);
    int    p101_getloadavg(const struct p101_env *env, struct p101_error *err, double loadavg[], int nelem);
    int    p101_setdomainname(const struct p101_env *env, struct p101_error *err, const char *name, size_t namelen);
    long   p101_sysconf(const struct p101_env *env, struct p101_error *err, int name);
    int    p101_uname(const struct p101_env *env, struct p101_error *err, struct utsname *name);

#ifdef __cplusplus
}
#endif

#endif    // LIBP101_HOST_HOST_H

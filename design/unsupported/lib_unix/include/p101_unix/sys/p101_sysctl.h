#ifndef LIBP101_UNIX_SYS_P101_SYSCTL_H
#define LIBP101_UNIX_SYS_P101_SYSCTL_H

/*
 * Copyright 2022-2024 D'Arcy Smith.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <p101_env/env.h>
#include <stddef.h>

/*
 * Source-controlled platform research placeholder; this header is not
 * installed because Linux has no compatible libc sysctl() interface.
 */
#if defined(__APPLE__) || defined(__FreeBSD__)
    #include <sys/sysctl.h>
    #define P101_UNIX_HAS_SYSCTL 1
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef P101_UNIX_HAS_SYSCTL
    int p101_sysctl(const struct p101_env *env, struct p101_error *err, int *name, unsigned int namelen, void *oldp, size_t *oldlenp, void *newp, size_t newlen);
#endif

#ifdef __cplusplus
}
#endif

#endif    // LIBP101_UNIX_SYS_P101_SYSCTL_H

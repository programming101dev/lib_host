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

#include "p101_host/host.h"
#include <limits.h>
#include <p101_env/wrapper.h>

int p101_getdomainname(const struct p101_env *env, struct p101_error *err, char *name, size_t namelen)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
#if defined(__APPLE__) || defined(__FreeBSD__)
    if(namelen > (size_t)INT_MAX)
    {
        P101_ERROR_RAISE_ERRNO(err, ERANGE);
        ret_val = -1;
    }
    else
    {
        ret_val = getdomainname(name, (int)namelen);
        if(ret_val == -1)
        {
            P101_ERROR_RAISE_ERRNO(err, errno);
        }
    }
#else
    ret_val = getdomainname(name, namelen);
    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }
#endif

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_setdomainname(const struct p101_env *env, struct p101_error *err, const char *name, size_t namelen)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
#if defined(__APPLE__) || defined(__FreeBSD__)
    if(namelen > (size_t)INT_MAX)
    {
        P101_ERROR_RAISE_ERRNO(err, ERANGE);
        ret_val = -1;
    }
    else
    {
        ret_val = setdomainname(name, (int)namelen);
        if(ret_val == -1)
        {
            P101_ERROR_RAISE_ERRNO(err, errno);
        }
    }
#else
    ret_val = setdomainname(name, namelen);
    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }
#endif

    P101_WRAPPER_DONE(env);
    return ret_val;
}

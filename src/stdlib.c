/*
 * Copyright 2026 D'Arcy Smith.
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

#include "p101_host/p101_stdlib.h"
#include "p101_host/p101_unistd.h"
#include "p101_host/sys/p101_utsname.h"
#include <p101_env/wrapper.h>

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

#include <stdlib.h>
#ifdef __has_include
    #if __has_include("bsd/stdlib.h")
        #include <bsd/stdlib.h>
    #endif
#endif
int p101_getloadavg(const struct p101_env *env, struct p101_error *err, double loadavg[], int nelem)
{
    int caller_errno;
    int actual_errno;
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    caller_errno = errno;
    errno        = 0;
    ret_val      = getloadavg(loadavg, nelem);
    actual_errno = errno;

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, (actual_errno == 0) ? EIO : actual_errno);
    }
    else
    {
        errno = caller_errno;
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

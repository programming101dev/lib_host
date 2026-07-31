# Project metadata
set(PROJECT_NAME "p101_host")
set(PROJECT_VERSION "0.0.1")
set(PROJECT_DESCRIPTION "Host identity, configuration, and load information")
set(PROJECT_LANGUAGE "C")

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(STANDARD_FLAGS
        -D_POSIX_C_SOURCE=200809L
        -D_XOPEN_SOURCE=700
        -Werror
)
set(DARWIN_STANDARD_FLAGS -D_DARWIN_C_SOURCE)
set(LINUX_STANDARD_FLAGS -D_GNU_SOURCE)
set(BSD_STANDARD_FLAGS -D_BSD_SOURCE -D__BSD_VISIBLE)

set(LIBRARY_TARGETS p101_host)
set(p101_host_SOURCES
        src/posix/sys/utsname.c
        src/posix/unistd.c
        src/posix_xsi/unistd.c
        src/unix/stdlib.c
        src/unix/unistd.c
)
set(p101_host_HEADERS
        include/p101_host/host.h
)
set(p101_host_LINK_LIBRARIES
        p101_error
        p101_env
        p101_tool_event
        p101_c
)


# design/unsupported contains documented interfaces that are deliberately
# neither compiled nor installed because the three-platform contract fails.

cmake_minimum_required(VERSION 3.8)
project(Dict)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        main.c
        dict.c
        dict.h
        zmalloc.c
        zmalloc.h
        siphash.c
        atomicvar.h
        config.h
        fmacros.h
        redisassert.h
)
add_executable(Dict ${SOURCE_FILES})

cmake_minimum_required(VERSION 3.3)
project(modelEquations)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    cabuf.c
    caconc.c
    ibg.c
    ical.c
    iclca.c
    iki.c
    ikp.c
    ikr.c
    iks.c
    ina.c
    inak.c
    incx.c
    ipk.c
    ito.c
    main.c
    naconc.c
    sa.h
    srflux.c)

add_executable(modelEquations ${SOURCE_FILES})
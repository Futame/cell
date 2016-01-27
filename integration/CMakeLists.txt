cmake_minimum_required(VERSION 3.3)
project(integration)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    beta.h
    cabuf.c
    caconc.c
    elphys.cpp
    elphys.h
    funsignalling.cpp
    funsignalling.h
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
    settings.cpp
    settings.h
    signalling.cpp
    signalling.h
    srflux.c)

add_executable(integration ${SOURCE_FILES})
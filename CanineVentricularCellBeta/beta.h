//
// Created by sokian on 15.09.15.
//

#ifndef CANINEVENTRICULARCELLBETA_BETA_H
#define  CANINEVENTRICULARCELLBETA_BETA_H


#include <math.h>
#include <stdio.h>
#include "signalling.h"
#include "settings.h"
#include "funsignalling.h"

/*
//Universal Constants
const double pi = 3.141592;
const int  F=96487;   // Faraday constant
const int  R=8314;    // Gas constant
const int  T=310;      // Temperature
const double  frt= F/ T/ R;
const double  RTF=1./frt;
*/


#define debug(x) \
if (isnan(x)){ \
    printf("%s is nan\n",#x); \
    assert(false); \
}

#define iscomplex(x)\
if (x < 0) { \
    printf("%s is less than zero\n", #x); \
    assert(false); \
}

//Cell parameters

#endif //CANINEVENTRICULARCELLBETA_BETA_H
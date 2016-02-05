// Rapidly Activating K Current Calculation
//
// A Model of Human Ventricular Tissue
//
// Authors:
//     Alexander V. Ashikhmin <clegling@gmail.com>, 2015
//     Laboratory of Human Physiology, Moscow Institute of Physics and Technology, 2015
//
// License:
//     Redistribution and use of the code with or without modification
//     are permitted for any scientific, research and educational purposes.
//
//     Redistribution and use of the code with or without modification
//     are prohibited for any commercial purposes.
//
// Checked:
//     Sep. 14, 2015 by Alexander V. Ashikhmin (see comments below)

#include "sa.h"

REAL ikr(REAL time, struct State *S, struct State *Sn, REAL ht, struct Cpar *C, struct Is *I)
{
    static int  first = 1;
    static REAL EK;
    REAL        gkr, xrss, txr, rkr;
    
    // Nernst Potentials Calculation
    for( ; first; first = 0 )
    {
        EK = RTF * log(Ko/Ki);
    }

    gkr  = 0.035*sqrt(Ko/5.4);
    xrss =   1.0/(1.0 + exp(-(S->E + 10.0)/5.0));
    txr  = 550.0/(1.0 + exp(-(S->E + 22.0)/9.0)) * 6.0/(1.0 + exp((S->E + 11.0)/9.0)) + 230.0/(1.0 + exp( (S->E + 40.0)/20.0));                                          // S->E - - 11.0 == S->E + 11.0 и S->E - - 40.0 == S->E + 40.0 ???
    rkr  =   1.0/(1.0 + exp((S->E + 74.0)/24.0));

    Sn->xkr = xrss - (xrss - S->xkr)*exp(-ht/txr);
    I->Ikr = gkr * S->xkr * rkr * (S->E - EK);
    return I->Ikr;

} /** ikr **/

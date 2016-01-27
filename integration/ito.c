// Transient Outward K Current Calculation
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
//     Sep. 14, 2015 by Zoya A. Kiyan

#include "sa.h"

REAL ito(struct State *S, struct State *Sn, REAL ht, struct Cpar *C, struct Is *I)
{
    static int  first = 1;
    static REAL EK;
    REAL        xtoss, ytoss;
    REAL        txtos, tytos;           // Time Slow Component
    REAL        txtof, tytof;           // Time Fast Component
    REAL        ItoSlow, ItoFast;       // Current Components
  
    // Nernts Potential Calculation
    for( ; first; first = 0 )
    {
        EK = RTF * log(Ko/Ki);
    }

    // Slow Component
    xtoss =   1.0/(1.0 + exp(-(S->E - 19.0)/13.0));
    ytoss =   1.0/(1.0 + exp( (S->E + 19.5)/5.0));
    
    txtos =   9.0/(1.0 + exp( (S->E +  3.0)/15.0)) + 0.5;
    tytos = 800.0/(1.0 + exp( (S->E + 60.0)/10.0)) + 30.0;
    
    Sn->xtos = xtoss - (xtoss - S->xtos) * exp(-ht/txtos);
    Sn->ytos = ytoss - (ytoss - S->ytos) * exp(-ht/tytos);

    // Fast Component

//    tauxtof = 8.5 * exp(-sqr((V_m+45{mV})/50{mV}))+0.5{msec};
    txtof = 8.5  * exp(-(S->E + 45.0)*(S->E + 45.0)/25.0E2) + 0.5;
    tytof = 85.0 * exp(-(S->E + 40.0)*(S->E + 40.0)/220.0) + 7.0;
    
    Sn->xtof = xtoss - (xtoss - S->xtof) * exp(-ht/txtof);
    Sn->ytof = ytoss - (ytoss - S->ytof) * exp(-ht/tytof);
    
    // Current Components Calculation
    I->ItoSlow = C->GtoSlow * S->xtos * S->ytos * (S->E - EK);
    I->ItoFast = C->GtoFast * S->xtof * S->ytof * (S->E - EK);

    return I->ItoSlow + I->ItoFast;

} /** ito **/

// Plateau K Current Calculation
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
//     Sep. 14, 2015 by Alexander V. Ashikhmin

#include "sa.h"

REAL ikp(struct State *S, struct State *Sn, REAL ht,  struct Cpar *C, struct Is *I)
{
    static int  first = 1;
    static REAL EK;
    REAL        IkpJunc, IkpSl;
    REAL        kp;
    
    // Nernst Potentials Calculation
    for( ; first; first = 0 )
    {
        EK = RTF * log(Ko/Ki);
    }

    //kp_kp = 1 /(1 + exp(7.488 - V_m/5.98));
    kp      = 1.0/(1.0 + exp(7.488 - S->E/5.98));

    //I_kp_junc = Fjunc * gkp * kp_kp * (V_m - ek);
    IkpJunc = Fjunc * C->Gkp * kp * (S->E - EK);

    //I_kp_sl = Fsl * gkp * kp_kp * (V_m - ek);
    IkpSl   = Fsl   * C->Gkp * kp * (S->E - EK);

    //I_kp = I_kp_junc + I_kp_sl;
    I->Ikp = IkpJunc + IkpSl;
    
    return I->Ikp;
} /** ikp **/
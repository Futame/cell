// Inward Rectifier K Current Calculation
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

REAL iki(REAL time,struct State *S, struct State *Sn, REAL ht, struct Cpar *C, struct Is *I) {
    static int  first = 1;
    static REAL EK;
    REAL        aKi, bKi;
    REAL        Kiss;

    // Nernts Potential Calculation
    for( ; first; first = 0 )
    {
        EK = RTF * log(Ko/Ki);
    }

    if (time == 0.0){
        aKi = 0;
        bKi = 0;
        Kiss = 0;
    }
    else {
        //aki = 1.02/(1+exp(0.2385*(V_m-ek-59.215)));
        aKi = 1.02 / (1.0 + exp(0.2385 * (S->E - EK - 59.215)));

        //bki = (0.49124*exp(0.08032*(V_m + 5.476 - ek)) + exp(0.06175 * (V_m - ek - 594.31{mV}))) / (1 + exp(-0.5143 * (V_m - ek + 4.753{mV})));
        bKi = (0.49214 * exp(0.08032 * (S->E - EK + 5.476)) + exp(0.06175 * (S->E - EK - 594.31))) /
              (1.0 + exp(-0.5143 * (S->E - EK + 4.753)));
        //kiss = aki/(aki + bki);
        Kiss = aKi / (aKi + bKi);
    }
    fprintf(aki, "%e %e\n", time, aKi);
    fprintf(kiss, "%e %e\n", time, Kiss);
    fprintf(bki, "%e %e\n", time, bKi);

    //I_ki = 0.35 * sqrt(Ko/5.4) * kiss * (V_m - ek);
        I->Iki = 0.35 * sqrt(Ko / 5.4) * Kiss * (S->E - EK);

    return I->Iki;
} /** iki **/

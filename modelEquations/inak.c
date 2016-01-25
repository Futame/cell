// Na/K Pump Current Calculation
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

REAL inak(struct State *S, struct State *Sn, REAL ht, struct Cpar *C, struct Is *I)
{
    REAL sigma, fNaK;

    sigma    = (exp(Nao/67.3) - 1.0)/7.0;
    fNaK     = 1.0/(1.0 + 0.1245*exp((-0.1*S->E)/RTF) + 0.0365*sigma*exp((-S->E)/RTF));

    //I_nak_junc = Fjunc * IbarNaK * fnak*Ko/(1 + pow(KmNaip/Na_j, 4{dimensionless}))/(Ko+KmKo);
    I->INaKJunc = Fjunc * C->INaK * fNaK/(1.0 + pow(KmNaip/S->NaJ, 4))  * Ko/(Ko + KmKo);
    //I_nak_sl = Fsl*IbarNaK*fnak*Ko/(1{dimensionless}+pow(KmNaip/Na_sl, 4))/(Ko+KmKo);
    I->INaKSl   = Fsl   * C->INaK * fNaK/(1.0 + pow(KmNaip/S->NaSl, 4)) * Ko/(Ko + KmKo);

    return I->INaKJunc + I->INaKSl;

} /** inak **/

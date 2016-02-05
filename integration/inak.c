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


REAL inakp(struct State *S, struct State *Sn, REAL ht, struct Cpar *C, struct Is *I)
{
    REAL sigmap, fNaKp;

    sigmap    = (exp(Nao/67.3) - 1.0)/7.0;
    fNaKp     = 1.0/(1.0 + 0.1245*exp((-0.1*S->E)/RTF) + 0.0365*sigmap*exp((-S->E)/RTF));

    I->INaKJuncp = Fjunc * C->INaKp * fNaKp/(1.0 + pow(KmNaip/S->NaJ, 4))  * Ko/(Ko + KmKo); //TODO: don't sure in this equations
    I->INaKSlp   = Fsl   * C->INaKp * fNaKp/(1.0 + pow(KmNaip/S->NaSl, 4)) * Ko/(Ko + KmKo); //TODO: don't sure in this equations

    return I->INaKJuncp + I->INaKSlp;

} /** inakp **/

REAL inak(struct State *S, struct State *Sn, REAL ht, struct Cpar *C, struct Is *I)
{
    REAL sigma, fNaK;

    sigma    = (exp(Nao/67.3) - 1.0)/7.0;
    fNaK     = 1.0/(1.0 + 0.1245*exp((-0.1*S->E)/RTF) + 0.0365*sigma*exp((-S->E)/RTF));

    I->INaKJunc = Fjunc * C->INaK * fNaK/(1.0 + pow(KmNaip/S->NaJ, 4))  * Ko/(Ko + KmKo);
    I->INaKSl   = Fsl   * C->INaK * fNaK/(1.0 + pow(KmNaip/S->NaSl, 4)) * Ko/(Ko + KmKo);

//TODO: fINaK_P
    double fINaK_P = 0.0;
    return (I->INaKJunc + I->INaKSl) * (1 - fINaK_P) + fINaK_P * inakp(S,Sn,ht,C,I);

} /** inak **/

// Fast Na Current Calculation
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
REAL inap(struct State *S, struct State *Sn, REAL ht, struct Cpar *C, struct Is *I)
{
    REAL        ENaJunc, ENaSl;
    REAL        mssp, hssp, jssp;
    REAL        tm,  th,  tj;
    REAL        ah, bh, aj, bj;

    // m calculation
    double dV_activation = -5.9;
    double Va = S->E - dV_activation; //TODO: may be there are a problem with sign
    mssp   = pow(1.0/(1.0 + exp(-(56.86 + Va)/9.03)), 2);

    tm    = 0.1292 * exp(-pow((Va + 45.79)/15.54, 2)) + 0.06487 * exp(-pow((Va + 4.823)/51.12, 2));
    Sn->mp = mssp - (mssp - S->mp) * exp(-ht/tm);

    double dV_inactivation = -8;
    double Vi = S->E - dV_inactivation;
    // h calculation
    hssp   = pow(1.0/(1.0 + exp((71.55 + Vi)/7.43)), 2);
    if (Vi < -40.0)
    {
        ah = 0.057 * exp(-(Vi + 80)/6.8);
        bh = 2.7   * exp(0.079 * Vi) + 3.1 * 1E5 * exp(0.3485*Vi);
    }
    else
    {
        ah = 0;
        bh = 0.77/(0.13 * (1 + exp(-(Vi + 10.66)/11.1)));
    }
    th    = 1.0/(ah + bh);
    Sn->hp = hssp - (hssp - S->hp) * exp(-ht/th);
    
    // j calculation
    jssp = pow(1.0/(1.0 + exp((Vi + 71.55)/7.43)), 2);
    if (Vi < -40.0)
    {
        aj = (-2.5428 * 1E4 * exp(0.2444 * Vi) - 6.9481 * 1E-6 * exp(-0.04391 * Vi)*(Vi + 37.78))/(1.0 + exp(0.311 * (Vi
                                                                                                          + 79.23)));
        bj =  0.02424 * exp(-0.01052 * Vi)/(1.0 + exp(-0.1378 * (Vi + 40.14)));
    }
    else
    {
        aj = 0;
        bj = 0.6 * exp(0.057 * Vi)/(1.0 + exp(-0.1 * (Vi + 32)));
    }
    tj    = 1.0/(aj + bj);
    Sn->jp = jssp - (jssp - S->jp) * exp(-ht/tj);
    
    // Fast Na Current Calculation in the Junctional Cleft and the Subsarcolemmal Space
    I->INaJuncp = Fjunc * C->GNap * pow(S->mp, 3) * S->hp * S->jp * (S->E - C->ENaJunc);
    I->INaSlp   = Fsl   * C->GNap * pow(S->mp, 3) *  S->hp * S->jp * (S->E - C->ENaSl);

    return I->INaJuncp + I->INaSlp;
} /** inap **/



REAL ina(struct State *S, struct State *Sn, REAL ht, struct Cpar *C, struct Is *I)
{
    static int  first = 1;
    REAL        ENaJunc, ENaSl;
    REAL        mss, hss, jss;
    REAL        tm,  th,  tj;
    REAL        ah, bh, aj, bj;

    // m calculation
    mss   = pow(1.0/(1.0 + exp(-(56.86 + S->E)/9.03)), 2);

    tm    = 0.1292 * exp(-pow((S->E + 45.79)/15.54, 2)) + 0.06487 * exp(-pow((S->E + 4.823)/51.12, 2));
    Sn->m = mss - (mss - S->m) * exp(-ht/tm);

    // h calculation
    hss   = pow(1.0/(1.0 + exp((71.55 + S->E)/7.43)), 2);
    if (S->E < -40.0)
    {
        ah = 0.057 * exp(-(S->E + 80)/6.8);
        bh = 2.7   * exp(0.079 * S->E) + 3.1 * 1E5 * exp(0.3485*S->E);
    }
    else
    {
        ah = 0;
        bh = 0.77/(0.13 * (1 + exp(-(S->E + 10.66)/11.1)));
    }
    th    = 1.0/(ah + bh);
    Sn->h = hss - (hss - S->h) * exp(-ht/th);
    
    // j calculation
    jss = pow(1.0/(1.0 + exp((S->E + 71.55)/7.43)), 2);
    if (S->E < -40.0)
    {
        aj = (-2.5428 * 1E4 * exp(0.2444 * S->E) - 6.9481 * 1E-6 * exp(-0.04391 * S->E)*(S->E + 37.78))/(1.0 + exp(0.311 * (S->E + 79.23)));
        bj =  0.02424 * exp(-0.01052 * S->E)/(1.0 + exp(-0.1378 * (S->E + 40.14)));
    }
    else
    {
        aj = 0;
        bj = 0.6 * exp(0.057 * S->E)/(1.0 + exp(-0.1 * (S->E + 32)));
    }
    tj    = 1.0/(aj + bj);
    Sn->j = jss - (jss - S->j) * exp(-ht/tj);
    
    // Fast Na Current Calculation in the Junctional Cleft and the Subsarcolemmal Space
    I->INaJunc = Fjunc * C->GNa * pow(S->m, 3) * S->h * S->j * (S->E - C->ENaJunc);
    I->INaSl   = Fsl   * C->GNa * pow(S->m, 3) * S->h * S->j * (S->E - C->ENaSl);

	inap(S,Sn,ht,C,I);

	//TODO: need fINa_P
    double fINa_P = 0.0;
    return (I->INaJunc + I->INaSl)*(1-fINa_P) + fINa_P * (I->INaJuncp + I->INaSlp);
} /** ina **/

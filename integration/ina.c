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

REAL ina(struct State *S, struct State *Sn, REAL ht, struct Cpar *C, struct Is *I)
{
    static int  first = 1;
    REAL        ENaJunc, ENaSl;
    REAL        mss, hss, jss;
    REAL        tm,  th,  tj;
    REAL        ah, bh, aj, bj;
/*
 *
             ah = sel
            case V_m >= -40{mV}:
                0{dimensionless};
            otherwise:
                0.057{dimensionless}*exp(-(V_m+80{mV})/6.8{mV});
        endsel;

        bh = sel
            case V_m >= -40{mV}:
                0.77{dimensionless}/(0.13{dimensionless}*(1{dimensionless}+exp(-(V_m+10.66{mV})/11.1{mV})));
            otherwise:
                2.7{dimensionless}*exp(0.079{per_mV}*V_m)+3.1e5{dimensionless}*exp(0.3485{per_mV}*V_m);
        endsel;

        tauh = 1{msec}/(ah+bh);
        hss = 1{dimensionless}/sqr(1{dimensionless}+exp((V_m+71.55{mV})/7.43{mV}));

        aj = sel
            case V_m >= -40{mV}:
                0{dimensionless};
            otherwise:
                (-2.5428e4{per_mV}*exp(0.2444{per_mV}*V_m)-6.948e-6{per_mV}*exp(-0.04391{per_mV}*V_m))*(V_m+37.78{mV})/(1{dimensionless}+exp(0.311{per_mV}*(V_m+79.23{mV})));
        endsel;

        bj = sel
            case V_m >= -40{mV}:
                0.6{dimensionless}*exp(0.057{per_mV}*V_m)/(1{dimensionless}+exp(-0.1{per_mV}*(V_m+32{mV})));
            otherwise:
                0.02424{dimensionless}*exp(-0.01052{per_mV}*V_m)/(1{dimensionless}+exp(-0.1378{per_mV}*(V_m+40.14{mV})));
        endsel;

        tauj = 1{msec}/(aj+bj);
        jss = 1{dimensionless}/sqr(1{dimensionless}+exp((V_m+71.55{mV})/7.43{mV}));
        ode(m, time) = (mss-m)/taum;
        ode(h, time) = (hss-h)/tauh;
        ode(j, time) = (jss-j)/tauj;
        I_Na_junc = Fjunc*GNa*pow(m, 3{dimensionless})*h*j*(V_m-ena_junc);
        I_Na_sl = Fsl*GNa*pow(m, 3{dimensionless})*h*j*(V_m-ena_sl);
        I_Na = I_Na_junc+I_Na_sl;
 */
    // m calculation
    //mss = 1 / sqr(1 + exp(-(56.86 + V_m)/9.03));
    mss   = pow(1.0/(1.0 + exp(-(56.86 + S->E)/9.03)), 2);

    //taum = 0.1292 * exp(-sqr((V_m+45.79)/15.54{mV}))+0.06487 * exp(-sqr((V_m-4.823{mV})/51.12{mV}));
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
        //(     -2.5428e4   *     exp(0.2444 * V_m) - 6.948e-6  *   exp(-0.04391 * V_m))*(V_m + 37.78)/(1 + exp(0.311 * (V_m + 79.23)));
        aj = (-2.5428 * 1E4 * exp(0.2444 * S->E) - 6.9481 * 1E-6 * exp(-0.04391 * S->E)*(S->E + 37.78))/(1.0 + exp(0.311 * (S->E + 79.23)));
  //                0.02424 *exp(-0.01052{per_mV}*V_m)/(1 +exp(-0.1378{per_mV}*(V_m+40.14{mV})));
        bj =  0.02424 * exp(-0.01052 * S->E)/(1.0 + exp(-0.1378 * (S->E + 40.14)));
    }
    else
    {
        aj = 0;
//        0.6{dimensionless}*exp(0.057{per_mV}*V_m)/(1{dimensionless}+exp(-0.1{per_mV}*(V_m+32{mV})));

        bj = 0.6 * exp(0.057 * S->E)/(1.0 + exp(-0.1 * (S->E + 32)));
    }
    tj    = 1.0/(aj + bj);
    Sn->j = jss - (jss - S->j) * exp(-ht/tj);
    
    // Fast Na Current Calculation in the Junctional Cleft and the Subsarcolemmal Space
    I->INaJunc = Fjunc * C->GNa * pow(S->m, 3) * S->h * S->j * (S->E - C->ENaJunc);
    I->INaSl   = Fsl   * C->GNa * pow(S->m, 3) * S->h * S->j * (S->E - C->ENaSl);

    return I->INaJunc + I->INaSl;
} /** ina **/

// L-type Calcium Current Calculation
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

REAL ical(struct State *S, struct State *Sn, REAL ht, struct Cpar *C, struct Is *I)
{
    REAL dss, fss;
    REAL td, tf;
    REAL ICaJ, ICaS, INaJ, INaS, IK;
    REAL ICa, ICaNa;
    
    // d calculation
    dss   = 1.0/(1.0 + exp(-(S->E + 5.0)/6.0));
    td    = dss * (1.0 - exp(-(S->E + 5.0)/6.0))/(0.035 * (S->E + 5.0));
    Sn->d = dss - (dss - S->d) * exp(-ht/td);
    
    // f calculation
    fss   = 1.0/(1.0 + exp((S->E + 35.0)/9.0)) + 0.6/(1.0 + exp(-(S->E - 50.0)/20.0));
    tf    = 1.0/(0.0197 * exp(-11.3569E-4 * (S->E + 14.5) * (S->E + 14.5)) + 0.02);
    Sn->f = fss - (fss - S->f) * exp(-ht/tf);
    
    // fCaB Components Calculation
    Sn->fCaBJunc = S->fCaBJunc + (1.7 * S->CaJ * (1.0 - S->fCaBJunc) - 11.9E-3 * S->fCaBJunc) * ht;
    Sn->fCaBSl   = S->fCaBSl   + (1.7 * S->CaSl * (1.0 - S->fCaBSl)   - 11.9E-3 * S->fCaBSl) * ht;

    
    // Currents' Amplitude Calculation
    ICaJ = 1.364 * pCa * FRD/RTF * S->E * (S->CaJ  * exp(2.0 * (S->E)/RTF) - Cao)/(exp(2.0 * (S->E)/RTF) - 1.0);
    ICaS = 1.364 * pCa * FRD/RTF * S->E * (S->CaSl * exp(2.0 * (S->E)/RTF) - Cao)/(exp(2.0 * (S->E)/RTF) - 1.0);
    INaJ =  0.75 * pNa * FRD/RTF * S->E * (S->NaJ  * exp((S->E)/RTF) - Nao)/(exp((S->E)/RTF) - 1.0);
    INaS =  0.75 * pNa * FRD/RTF * S->E * (S->NaSl * exp((S->E)/RTF) - Nao)/(exp((S->E)/RTF) - 1.0);
    IK   =  0.75 * pK  * FRD/RTF * S->E * (Ki * exp((S->E)/RTF) - Ko)/(exp((S->E)/RTF) - 1.0);
                       
    // Ca, Ca-K and Ca-Na Currents Calculation
    I->ICaJunc   = 0.45 * FjuncCaL * ICaJ * S->d * S->f * (1.0 - S->fCaBJunc);
    I->ICaSl     = 0.45 * FslCaL   * ICaS * S->d * S->f * (1.0 - S->fCaBSl);
    ICa  = I->ICaJunc + I->ICaSl;
    //I_CaK = ibark* d*f* ( Fjunc_CaL*(1-f_Ca_Bj)   +    Fsl_CaL*(fcaCaMSL+1-f_Ca_Bsl) )*0.45;
    I->ICaK   = IK * S->d * S->f * (FjuncCaL * (1.0 - S->fCaBJunc) + FslCaL * (1 - S->fCaBSl)) * 0.45;


    //I_CaNa_junc = Fjunc_CaL *?ibarna_j?* d * f * (1-f_Ca_Bj) *0.45;

    I->ICaNaJunc = FjuncCaL * INaJ * S->d * S->f * (1 - S->fCaBJunc) * 0.45;

    //I_CaNa_sl = Fsl_CaL *ibarna_sl* d*f*(1-f_Ca_Bsl)* 0.45;
    I->ICaNaSl = FslCaL *INaS * S->d * S->f * (1.0 - S->fCaBSl) * 0.45;
    //I->ICaNaSl   = INaS * I->ICaSl/ICaS;
    
    ICaNa = I->ICaNaJunc + I->ICaNaSl;
                                                                                   
    return ICa + I->ICaK + ICaNa;
} /** ical **/

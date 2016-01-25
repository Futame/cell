// Sodium Concentrations Calculation
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


REAL naconc(struct State *S, struct State *Sn, REAL ht, struct Cpar * C, struct Js *J, struct Is *I)
{
    REAL NaJ_t, NaSl_t, Nai_t;
    REAL NaBj_t, NaBSl_t;

    // Total Na Current Calculation in the junctional cleft and the subsarcolemmal space

    // I_Na_tot_junc = I_Na_junc + I_nabk_junc + 3 * I_ncx_junc + 3 * I_nak_junc + I_CaNa_junc;
    I->INaTotJunc = I->INaJunc + I->INaBkJunc + 3.0 * I->IncxJunc + 3.0 * I->INaKJunc + I->ICaNaJunc;

    //I_Na_tot_sl = I_Na_sl + I_nabk_sl + 3 * I_ncx_sl + 3 * I_nak_sl + I_CaNa_sl;
    I->INaTotSl    = I->INaSl + I->INaBkSl + 3.0 * I->IncxSl + 3.0 * I->INaKSl + I->ICaNaSl;
    
    // Sodium Buffer Calculation
    NaBj_t  = KonNa * S->NaJ  * (BmaxNaJ  - S->NaBj)  - KoffNa * S->NaBj;
    NaBSl_t = KonNa * S->NaSl * (BmaxNaSl - S->NaBSl) - KoffNa * S->NaBSl;
    
    Sn->NaBj  = S->NaBj  + NaBj_t  * ht;
    Sn->NaBSl = S->NaBSl + NaBSl_t * ht;
    
    // Sodium Concentrations Calculation
    NaJ_t  = -I->INaTotJunc * Cmem/(Vjunc * FRD) + JNaJuncSl/Vjunc * (S->NaSl - S->NaJ) - NaBj_t;
    NaSl_t = -I->INaTotSl   * Cmem/(Vsl * FRD)   + JNaJuncSl/Vsl * (S->NaJ - S->NaSl) + JNaSlMyo/Vsl * (S->Nai - S->NaSl) - NaBSl_t;
    Nai_t  = JNaSlMyo/Vmyo * (S->NaSl - S->Nai);
    
    Sn->NaJ  = S->NaJ  + NaJ_t  * ht;
    Sn->NaSl = S->NaSl + NaSl_t * ht;
    Sn->Nai  = S->Nai  + Nai_t  * ht;
    
    return I->INaTotJunc + I->INaTotSl;
} /** naconc **/
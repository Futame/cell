// Calcium Concentrations Calculation
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

REAL caconc(struct State *S, struct State *Sn, REAL ht, struct Cpar * C, struct Js *J, struct Is *I)
{
    REAL CaJ_t, CaSl_t, Cai_t, CaSR_t;              // Calcium Concetrations Time Derivatives
    REAL Csqnb_t;                                   // SR Calcium Buffer Time Derivative
    
    // SR Calcium Buffer Calculation
    Csqnb_t = KonCsqn * S->CaSR * (BmaxCsqn - S->Csqnb) - KoffCsqn * S->Csqnb;
    Sn->Csqnb = S->Csqnb + Csqnb_t * ht;
    
    // Total Calcium Current Calculation in the Junctional Cleft and the Subsarcolemmal Space
    I->ICaTotJunc = I->ICaJunc + I->ICaBkJunc + I->IpCaJunc - 2.0 * I->IncxJunc;
    I->ICaTotSl    = I->ICaSl + I->ICaBkSl + I->IpCaSl - 2.0 * I->IncxSl;
    
    // Calcium Concentrations Time Derivatives Calculation
    CaJ_t  = -I->ICaTotJunc * Cmem/(2.0 * Vjunc * FRD) + JCaJuncSl/Vjunc * (S->CaSl - S->CaJ) - J->JCaBJunc + J->JSRCaRel * Vsr/Vjunc + J->JSRLeak * Vmyo/Vjunc;
    CaSl_t = -I->ICaTotSl   * Cmem/(2.0 * Vsl * FRD)   + JCaJuncSl/Vsl * (S->CaJ - S->CaSl) + JCaSlMyo/Vsl * (S->Cai - S->CaSl) - J->JCaBSl;

    Cai_t  = -J->JserCa * Vsr/Vmyo - J->JCaBCytosol + JCaSlMyo/Vmyo * (S->CaSl - S->Cai);
    CaSR_t = J->JserCa - J->JSRLeak * Vmyo/Vsr - J->JSRCaRel - Csqnb_t;
    
    // Calcium Concentrations Calculation
    Sn->CaJ  = S->CaJ  + CaJ_t  * ht;
    Sn->CaSl = S->CaSl + CaSl_t * ht;
    Sn->Cai  = S->Cai  + Cai_t  * ht;
    Sn->CaSR = S->CaSR + CaSR_t * ht;
    
    // Return of Total Calcium Current
    return I->ICaTotJunc + I->ICaTotSl;
} /** caconc **/
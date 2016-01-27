// Cytosolic, Junctional and SL  Calcium Buffers Calculation
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

int cabuf(struct State *S, struct State *Sn, REAL ht, struct Cpar * C, struct Js *J, struct Buf *B, struct Buf *Bn)
{
    REAL  TnCl_t, TnChc_t, TnChm_t, CaM_t, Myoc_t, Myom_t, SRB_t;   // Cytosolic Ca Buffers Time Derivatives
    REAL  SLLj_t, SLLsl_t, SLHj_t, SLHsl_t;                         // Junctional and SL Ca Buffers Time Derivatives
    
    // Cytosolic Ca Buffers Time Derivative
    TnCl_t  = KonTnCl   * S->Cai * (BmaxTnClow  - B->TnCl) - KoffTnCl * B->TnCl;
    TnChc_t = KonTnChCa * S->Cai * (BmaxTnChigh - B->TnChc - B->TnChm) - KoffTnChCa * B->TnChc;
    TnChm_t = KonTnChMg * Mgi    * (BmaxTnChigh - B->TnChc - B->TnChm) - KoffTnChMg * B->TnChm;
    CaM_t   = KonCaM    * S->Cai * (BmaxCaM     - B->CaM)  - KoffCaM * B->CaM;
    Myoc_t  = KonMyoCa  * S->Cai * (BmaxMyosin  - B->Myoc  - B->Myom)  - KoffMyoCa * B->Myoc;
    Myom_t  = KonMyoMg  * Mgi    * (BmaxMyosin  - B->Myoc  - B->Myom)  - KoffMyoMg * B->Myom;
    SRB_t   = KonSR     * S->Cai * (BmaxSR      - B->SRB)  - KoffSR * B->SRB;
    
    // Cytosolic Ca Buffers
    Bn->TnCl  = B->TnCl  + TnCl_t  * ht;
    Bn->TnChc = B->TnChc + TnChc_t * ht;
    Bn->TnChm = B->TnChm + TnChm_t * ht;
    Bn->CaM   = B->CaM   + CaM_t   * ht;
    Bn->Myoc  = B->Myoc  + Myoc_t  * ht;
    Bn->Myom  = B->Myom  + Myom_t  * ht;
    Bn->SRB   = B->SRB   + SRB_t   * ht;
    
    J->JCaBCytosol = TnCl_t + TnChc_t + TnChm_t + CaM_t + Myoc_t + Myom_t + SRB_t;
    
    // Junctional and SL Ca Buffers Time Derivative
    SLLj_t  = KonSll * S->CaJ  * (BmaxSLlowJ  - B->SLLj)  - KoffSll * B->SLLj;
    SLLsl_t = KonSll * S->CaSl * (BmaxSLlowS  - B->SLLsl) - KoffSll * B->SLLsl;
    SLHj_t  = KonSlh * S->CaJ  * (BmaxSLhighJ - B->SLHj)  - KoffSlh * B->SLHj;
    SLHsl_t = KonSlh * S->CaSl * (BmaxSLhighS - B->SLHsl) - KoffSlh * B->SLHsl;
    
    //printf ("%e\t%e\n", SLLsl_t, SLHsl_t);
    
    // Junctional and SL Ca Buffers
    Bn->SLLj  = B->SLLj  + SLLj_t   * ht;
    Bn->SLLsl = B->SLLsl + SLLsl_t * ht;
    Bn->SLHj  = B->SLHj  + SLHj_t  * ht;
    Bn->SLHsl = B->SLHsl + SLHsl_t * ht;
    
    J->JCaBJunc = SLLj_t  + SLHj_t;
    J->JCaBSl   = SLLsl_t + SLHsl_t;
    //J_CaB_cytosol = kon_tncl*Ca_i*(Bmax_TnClow-Tn_CL)-koff_tncl*Tn_CL+kon_tnchca*Ca_i*(Bmax_TnChigh-Tn_CHc-Tn_CHm)-koff_tnchca*Tn_CHc+kon_tnchmg*Mgi*(Bmax_TnChigh-Tn_CHc-Tn_CHm)-koff_tnchmg*Tn_CHm+kon_cam*Ca_i*(Bmax_CaM-CaM)-koff_cam*CaM+kon_myoca*Ca_i*(Bmax_myosin-Myo_c-Myo_m)-koff_myoca*Myo_c+kon_myomg*Mgi*(Bmax_myosin-Myo_c-Myo_m)-koff_myomg*Myo_m+kon_sr*Ca_i*(Bmax_SR-SRB)-koff_sr*SRB;
    return 0;
} /** cabuf **/
// SR fluxes: Calcium Release, SR Ca Pump, SR Ca Leak Calculation
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


int srflux(struct State *S, struct State *Sn, REAL ht,  struct Cpar *C, struct Js *J)
{
    const REAL MaxSR = 15.0;
    const REAL MinSR = 1.0;
    REAL  kCaSR, koSRCa, kiSRCa;
    REAL  RI;
    
    kCaSR  = MaxSR - (MaxSR - MinSR)/(1.0 + pow(ec50SR/S->CaSR, 2.5));
    koSRCa = koCa/kCaSR;
    kiSRCa = kiCa * kCaSR;
    
    RI   = 1.0 - S->RyRr - S->RyRo - S->RyRi;
    Sn->RyRr = S->RyRr + ((kiM * RI - kiSRCa * S->CaJ * S->RyRr) - (koSRCa * S->CaJ * S->CaJ * S->RyRr - koM * S->RyRo)) * ht;
    Sn->RyRo = S->RyRo + ((koSRCa * S->CaJ * S->CaJ * S->RyRr - koM * S->RyRo) - (kiSRCa * S->CaJ * S->RyRo - kiM * S->RyRi)) * ht;
    Sn->RyRi = S->RyRi + ((kiSRCa * S->CaJ * S->RyRo - kiM * S->RyRi) - (koM * S->RyRi - koSRCa * S->CaJ * S->CaJ * RI)) * ht;
    
    J->JSRCaRel = ks * S->RyRo * (S->CaSR - S->CaJ);
    J->JserCa   = VmaxSRCaP * (pow(S->Cai/Kmf, hillSRCaP) -  pow(S->CaSR/Kmr, hillSRCaP))/(1.0 + pow(S->Cai/Kmf, hillSRCaP) +  pow(S->CaSR/Kmr, hillSRCaP));
    J->JSRLeak  = 5.348e-6 * (S->CaSR - S->CaJ);
    
    return 0;
} /** srflux **/
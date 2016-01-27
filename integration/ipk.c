// Sarcolemmal Ca Pump Current Calculation
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
//     Redistribution and use of the code with or w ithout modification
//     are prohibited for any commercial purposes.
//
// Checked:
//     Sep. 14, 2015 by Alexander V. Ashikhmin


#include "sa.h"


REAL ipk(struct State *S, struct State *Sn, REAL ht,  struct Cpar *C, struct Is *I)
{
    I->IpCaJunc = Fjunc * C->IPMCA * pow(S->CaJ,  1.6)/(pow(KmPCa, 1.6) + pow(S->CaJ,  1.6));
    I->IpCaSl   = Fsl   * C->IPMCA * pow(S->CaSl, 1.6)/(pow(KmPCa, 1.6) + pow(S->CaSl, 1.6));
    
    return I->IpCaJunc + I->IpCaSl;
} /** ipk **/
// Slowly Activating K Current
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

REAL iks_ph(struct State *S, struct State *Sn, REAL ht, struct Cpar *C, struct Is *I){
	REAL       xsssp, txsp;
    REAL       IKsJunkp, IKsSlp;
    xsssp    =   1.0/(1.0 + exp(-(S->E + 3.8)/14.25));
    txsp     = 990.1/(1.0 + exp(-(S->E + 2.436)/14.12));

    Sn->xksp = xsssp - (xsssp - S->xksp)*exp(-ht/txsp);	
    IKsJunkp = Fjunc * C->GksJuncp * S->xksp * S->xksp * (S->E - C->EKsJunc);
    IKsSlp   = Fsl   * C->GksSlp   * S->xksp * S->xksp * (S->E - C->EKsSl);
    I->Iks_ph = IKsJunkp + IKsSlp;
    
}

REAL iks(struct State *S, struct State *Sn, REAL ht, struct Cpar *C, struct Is *I)
{
    static int first = 1;
    REAL       xsss, txs;
    REAL       IKsJunk, IKsSl;

    xsss    =   1.0/(1.0 + exp(-(S->E + 3.8)/14.25));
    txs     = 990.1/(1.0 + exp(-(S->E + 2.436)/14.12));

    Sn->xks = xsss - (xsss - S->xks)*exp(-ht/txs);	
    IKsJunk = Fjunc * C->GksJunc * S->xks * S->xks * (S->E - C->EKsJunc);
    IKsSl   = Fsl   * C->GksSl   * S->xks * S->xks * (S->E - C->EKsSl);
    I->Iks = IKsJunk + IKsSl;
	//TODO: need fIKS_P
    double fIKS_P = 0.0;
    I->Iks_tot = fIKS_P * iks_ph(S,Sn,ht,C,I) + (1 - fIKS_P) * I->Iks;
    return I->Iks_tot;

} /** iks **/

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

REAL iks(struct State *S, struct State *Sn, REAL ht, struct Cpar *C, struct Is *I)
{
    static int first = 1;
    REAL       xsss, txs;
    REAL       IKsJunk, IKsSl;
    /*
     *     eks = 1{dimensionless}/FoRT*ln((Ko+pNaK*Nao)/(K_i+pNaK*Na_i));
        gks_junc = 0.0035{mS_per_uF};
        gks_sl = 0.0035{mS_per_uF};





     */
    //    xsss = 1{dimensionless}/(1{dimensionless}+exp(-(V_m+3.8{mV})/14.25{mV}));
    xsss    =   1.0/(1.0 + exp(-(S->E + 3.8)/14.25));

    //tauxs = 990.1{msec}/(1{dimensionless}+exp(-(V_m+2.436{mV})/14.12{mV}));
    txs     = 990.1/(1.0 + exp(-(S->E + 2.436)/14.12));

    //ode(x_ks, time) = (xsss-x_ks)/tauxs;
    Sn->xks = xsss - (xsss - S->xks)*exp(-ht/txs);	// solve eq

    //I_ks_junc = Fjunc * gks_junc * sqr(x_ks) * (V_m-eks);
    //TODO: EKs -> EksJunc
    IKsJunk = Fjunc * C->GksJunc * S->xks * S->xks * (S->E - C->EKsJunc);

    //I_ks_sl = Fsl * gks_sl * sqr(x_ks) * (V_m-eks);
    //TODO: Eks -> EKsSl
    IKsSl   = Fsl   * C->GksSl   * S->xks * S->xks * (S->E - C->EKsSl);

    //I_ks = I_ks_junc + I_ks_sl;
    I->Iks = IKsJunk + IKsSl;
    
    return I->Iks;

} /** iks **/

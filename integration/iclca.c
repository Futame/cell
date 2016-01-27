// Ca-activated Cl Current Calculation
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

REAL iclca(struct State *S, struct State *Sn, REAL ht,  struct Cpar *C, struct Is *I)
{
    static int  first = 1;
    static REAL ECl;
    REAL        IClCaJunc, IClCaSl;
    
    // Nernst Potentials Calculation
    for( ; first; first = 0 )
    {
        ECl = RTF * log(Cli/Clo);
    }
    /*


        I_ClCa = I_ClCa_junc+I_ClCa_sl;
     */
    //*  I_ClCa_junc = Fjunc*GClCa/(1+KdClCa/Ca_j)*(V_m-ecl);
    IClCaJunc = Fjunc * C->GClCa * (S->E - ECl)/(1.0 + KdClCa/S->CaJ);

    //I_ClCa_sl = Fsl*GClCa/(1{dimensionless}+KdClCa/Ca_sl)*(V_m-ecl);
    IClCaSl   = Fsl   * C->GClCa * (S->E - ECl)/(1.0 + KdClCa/S->CaSl);
    
    I->IClCa = IClCaJunc + IClCaSl;
    
    return I->IClCa;
} /** iclca **/
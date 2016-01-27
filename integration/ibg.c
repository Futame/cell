// Calculation of Na, Cl and Ca Background Currents
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

//  Background Na Current
REAL ibgna(struct State *S, struct State *Sn, REAL ht,  struct Cpar *C, struct Is *I)
{
    I->INaBkJunc = Fjunc * C->GNaB * (S->E - C->ENaJunc);
    I->INaBkSl   = Fsl   * C->GNaB * (S->E - C->ENaSl);
    
    return I->INaBkJunc + I->INaBkSl;
} /** ibgna **/


// Backgound Cl Current
REAL ibgcl(struct State *S, struct State *Sn, REAL ht,  struct Cpar *C, struct Is *I)
{
    static int  first = 1;
    static REAL ECl;
    
    // Nernst Potentials Calculation
    for( ; first; first = 0 )
    {
        ECl = RTF * log(Cli/Clo);
    }

    //    I_Clbk = GClB*(V_m-ecl);
    I->IBgCl = C->GClB * (S->E - ECl);
    
    return I->IBgCl;
} /** ibgcl **/


// Backgound Ca Current
REAL ibgca(struct State *S, struct State *Sn, REAL ht,  struct Cpar *C, struct Is *I)
{
    I->ICaBkJunc = Fjunc * C->GCaB * (S->E - C->ECaJunc);
    I->ICaBkSl   = Fsl * C->GCaB * (S->E - C->ECaSl);
    
    return I->ICaBkJunc + I->ICaBkSl;
} /** ibgca **/

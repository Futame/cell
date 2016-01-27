// Na/Ca Exchanger Current Calculation
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

REAL incx(struct State *S, struct State *Sn, REAL ht,  struct Cpar *C, struct Is *I)
{
    REAL KaJunc, KaSl;
    REAL s1junc, s2junc, s3junc;
    REAL s1sl,   s2sl,   s3sl;
    
    KaJunc = 1.0/(1.0 + (KdAct/S->CaJ)  * (KdAct/S->CaJ));
    KaSl   = 1.0/(1.0 + (KdAct/S->CaSl) * (KdAct/S->CaSl));
    
    s1junc = exp(nu * S->E/RTF) * (S->NaJ * S->NaJ * S->NaJ) * Cao;
    s1sl   = exp(nu * S->E/RTF) * (S->NaSl * S->NaSl * S->NaSl) * Cao;
    
    s2junc = exp((nu - 1) * S->E/RTF) * (Nao*Nao*Nao) * S->CaJ;
    s2sl   = exp((nu - 1) * S->E/RTF) * (Nao*Nao*Nao) * S->CaSl;

    //s3_junc = KmCai * pow(Nao, 3) * (1 + pow(Na_j/KmNai, 3))+pow(KmNao, 3)*Ca_j*(1{dimensionless}+Ca_j/KmCai)+ KmCao*pow(Na_j, 3{dimensionless})+pow(Na_j, 3)*Cao+pow(Nao, 3{dimensionless})*Ca_j;
    s3junc = (Nao*Nao*Nao) * KmCai * (1.0 + (S->NaJ/KmNai) * (S->NaJ/KmNai) * (S->NaJ/KmNai)) + (KmNao*KmNao*KmNao) * S->CaJ * (1.0 + S->CaJ/KmCai) + (KmCao + Cao) * (S->NaJ * S->NaJ * S->NaJ) +  S->CaJ * (Nao*Nao*Nao);
    s3sl   = (Nao*Nao*Nao) * KmCai * (1.0 + (S->NaSl/KmNai) * (S->NaSl/KmNai) * (S->NaSl/KmNai)) + (KmNao*KmNao*KmNao) * S->CaSl * (1.0 + S->CaSl/KmCai) + (KmCao + Cao) * (S->NaSl * S->NaSl * S->NaSl) +  S->CaSl * (Nao*Nao*Nao);
    
    //I_ncx_junc = Fjunc*IbarNCX*Ka_junc*(s1_junc-s2_junc)/s3_junc/(1{dimensionless}+ksat*exp((nu-1{dimensionless})*V_m*FoRT));
    I->IncxJunc = (Fjunc * C->INCX * KaJunc * (s1junc - s2junc))/(s3junc * (1.0 + ksat * exp((nu - 1) * (S->E)/RTF)));
    I->IncxSl   = (Fsl * C->INCX * KaSl * (s1sl - s2sl))/(s3sl * (1.0 + ksat * exp((nu - 1) * (S->E)/RTF)));
    
    return I->IncxJunc + I->IncxSl;
} /** incx **/
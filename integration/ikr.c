// Rapidly Activating K Current Calculation
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
//     Sep. 14, 2015 by Alexander V. Ashikhmin (see comments below)

#include "sa.h"

REAL ikr(REAL time, struct State *S, struct State *Sn, REAL ht, struct Cpar *C, struct Is *I)
{
    static int  first = 1;
    static REAL EK;
    REAL        gkr, xrss, txr, rkr;
    
    // Nernst Potentials Calculation
    for( ; first; first = 0 )
    {
        EK = RTF * log(Ko/Ki);
    }

    /*





     */
    //gkr = 0.035{mS_per_uF}*sqrt(Ko/5.4{mM});
    gkr  = 0.035*sqrt(Ko/5.4);

    //    xrss = 1{dimensionless}/(1{dimensionless}+exp(-(V_m+10{mV})/5{mV}));
    xrss =   1.0/(1.0 + exp(-(S->E + 10.0)/5.0));

    //tauxr = 550 /(1 + exp((-22 - V_m)/9{mV})) * 6 /(1 + exp(( V_m-(-11{mV}))/9{mV}))+230{msec}/(1 +exp((V_m-(-40{mV}))/20{mV}));
    txr  = 550.0/(1.0 + exp(-(S->E + 22.0)/9.0)) * 6.0/(1.0 + exp((S->E + 11.0)/9.0)) + 230.0/(1.0 + exp( (S->E + 40.0)/20.0));                                          // S->E - - 11.0 == S->E + 11.0 и S->E - - 40.0 == S->E + 40.0 ???

    //rkr = 1{dimensionless}/(1{dimensionless}+exp((V_m+74{mV})/24{mV}));
    rkr  =   1.0/(1.0 + exp((S->E + 74.0)/24.0));

    //ode(x_kr, time) = (xrss-x_kr)/tauxr;
    Sn->xkr = xrss - (xrss - S->xkr)*exp(-ht/txr);

    //FILE *, *, *, *, *xkr1, *xrss;
    fprintf(gkrf,"%e %e\n",time,gkr);
    fprintf(rkrf,"%e %e\n",time,rkr);
    fprintf(tauxkr,"%e %e\n",time,txr);
    fprintf(xkrf,"%e %e\n",time,S->xkr);
    fprintf(xrssf,"%e %e\n",time,xrss);
    fprintf(xkr1f,"%e %e\n",time,Sn->xkr - S->xkr);
    /*fprintf(,"%e %e\n",time,);
    fprintf(,"%e %e\n",time,);*/

    //I_kr = gkr * x_kr * rkr * (V_m - ek);
    I->Ikr = gkr * S->xkr * rkr * (S->E - EK);
    return I->Ikr;

} /** ikr **/

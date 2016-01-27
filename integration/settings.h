//
// Created by sokian on 18.09.15.
//

#ifndef CANINEVENTRICULARCELLBETA_SETTINGS_H
#define CANINEVENTRICULARCELLBETA_SETTINGS_H

#include "beta.h"

namespace settings {
    extern int applyVoltageClamp, vcRate, runSignalingPathway, runElectrophysiol;
    extern double APDRepLevel;
    extern int showProgress, bcl, freq, LastBCLstoreLast;
    extern double K_o, Ca_o, Na_o, Cl_o, Istim, stimdur;


    extern double IKsNPParams[], IKsPParams[], LCCNPParams[], LCCPParams[], INaNPParams[];
    extern double RyRP_Amp, RyRP_Tau, TauTr, observeICaLSS;

    extern double ICaLB, IKsB, IKrB, INaKB, INaCaB, IKpB, IK1B, INabB;
    extern double ITo1B, ITo2B, INaB, INaLB, IClB, IpCaB, CTKClB, CTNaClB;
    extern double ICabB, IrelB, IupB, ItrB, IleakB, IdiffB, CAMKIIB;

    extern double *getInitialVector();

    extern double ISO;

    extern int bcl;
    extern int freq;
    extern int storeLast;
};

struct BAR_Blockade {
    double I, II;
};


extern const double Bblocked[];

extern const double x0[];

extern const double a, ISO, l, vcell;


#endif //CANINEVENTRICULARCELLBETA_SETTINGS_H

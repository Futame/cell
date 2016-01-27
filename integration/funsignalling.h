//
// Created by sokian on 05.10.15.
//



#ifndef CANINEVENTRICULARCELLBETA_FUNSIGNALLING_H
#define CANINEVENTRICULARCELLBETA_FUNSIGNALLING_H

#include "beta.h"


struct Concentration {
    Concentration();

    double Gs_aGTP_CAV, Gs_aGTP_ECAV;
    double Gs_bg_CAV, Gs_bg_ECAV, Gs_bg_CYT;
    double Gs_aGDP_CAV, Gs_aGDP_ECAV, Gs_aGDP_CYT;
    double cAMP_CAV, cAMP_ECAV, cAMP_CYT;
    double R_pkap_tot_CAV, R_pkap_tot_ECAV, R_pkap_tot_CYT;
    double R_grkp_tot_CAV, R_grkp_tot_ECAV, R_grkp_tot_CYT;

    double RLC_CAV, RLC_ECAV, RLC_CYT;
    double L2RC_CAV, L2RC_ECAV, L2RC_CYT;
    double L2R_CAV, L2R_ECAV, L2R_CYT;
    double C_CAV, C_ECAV, C_CYT;
    double PKI_CAV, PKI_ECAV, PKI_CYT;

    double PDE3_P_CAV, PDE3_P_CYT;
    double PDE4_P_CAV, PDE4_P_ECAV, PDE4_P_CYT;

    double Inhib1_P_CYT;

    double fLCC_P, fIKS_P, fPLB_P, fTnI_P, fINa_P, fINaK_P, fRyR_P, fIKur_P;

    double Rb2_pkap_tot_CAV, Rb2_pkap_tot_ECAV;
    double Rb2_grkp_tot_CAV, Rb2_grkp_tot_ECAV;
    double Gi_aGTP_CAV, Gi_aGTP_ECAV;
    double Gi_bg_CAV, Gi_bg_ECAV;
    double Gi_aGDP_CAV, Gi_aGDP_ECAV;
    double Gs_a_GTP_CYT;
};

struct FilesForConcentration {
public:
    void open();

    void close();

    void print(double time, Concentration y);

private:
    FILE *Gs_aGTP_CAV, *Gs_aGTP_ECAV;
    FILE *Gs_bg_CAV, *Gs_bg_ECAV, *Gs_bg_CYT;
    FILE *Gs_aGDP_CAV, *Gs_aGDP_ECAV, *Gs_aGDP_CYT;
    FILE *cAMP_CAV, *cAMP_ECAV, *cAMP_CYT;
    FILE *R_pkap_tot_CAV, *R_pkap_tot_ECAV, *R_pkap_tot_CYT;
    FILE *R_grkp_tot_CAV, *R_grkp_tot_ECAV, *R_grkp_tot_CYT;

    FILE *RLC_CAV, *RLC_ECAV, *RLC_CYT;
    FILE *L2RC_CAV, *L2RC_ECAV, *L2RC_CYT;
    FILE *L2R_CAV, *L2R_ECAV, *L2R_CYT;
    FILE *C_CAV, *C_ECAV, *C_CYT;
    FILE *PKI_CAV, *PKI_ECAV, *PKI_CYT;

    FILE *PDE3_P_CAV, *PDE3_P_CYT;
    FILE *PDE4_P_CAV, *PDE4_P_ECAV, *PDE4_P_CYT;

    FILE *Inhib1_P_CYT;

    FILE *fLCC_P, *fIKS_P, *fPLB_P, *fTnI_P, *fINa_P, *fINaK_P, *fRyR_P, *fIKur_P;

    FILE *Rb2_pkap_tot_CAV, *Rb2_pkap_tot_ECAV;
    FILE *Rb2_grkp_tot_CAV, *Rb2_grkp_tot_ECAV;
    FILE *Gi_aGTP_CAV, *Gi_aGTP_ECAV;
    FILE *Gi_bg_CAV, *Gi_bg_ECAV;
    FILE *Gi_aGDP_CAV, *Gi_aGDP_ECAV;
    FILE *Gs_a_GTP_CYT;
};



Concentration funSignalling(Concentration y);

Concentration multiply(Concentration y, double a);

Concentration sum(Concentration y, Concentration dy);

struct LigRecepGprot {
    LigRecepGprot();

    double RG, LRG, dR_pkap_tot, dR_grkp_tot;
};

struct LigRecepGprotWithBeta2 {
    double Rb1Gs, LRb1Gs, Rb2Gs, LRb2Gs, Rb2Gi, LRb2Gi, dRb1_pkap_tot, dRb1_grkp_tot, dRb2_pkap_tot, dRb2_grkp_tot;
};

struct CAMP_AC {
    double dcAMPAC56_CAV, dcAMPAC56_CYT, dcAMPAC47_ECAV, dcAMPAC47_CYT;
};

struct PKA {
    double dcAMP_PKA_CAV, dcAMP_PKA_ECAV, dcAMP_PKA_CYT;
};

#endif //CANINEVENTRICULARCELLBETA_FUNSIGNALLING_H
//
// Created by sokian on 15.09.15.
//

#ifndef CANINEVENTRICULARCELLBETA_SIGNALLING_H
#define CANINEVENTRICULARCELLBETA_SIGNALLING_H

#include <cmath>
//#include "beta.h"
#include "funsignalling.h"
#include <complex>


//extern const double PP1_tot_CYT = 0.2;



struct SConst {
    SConst();

    double f_PP1_Inh1;
    double IBMX;
    double AC56_CAV, AC56_CYT, AC47_ECAV, AC47_CYT;
    double IKs_AKAP_PKA, IKs_AKAP_PKA_PP1;
    double ICaL_AKAP_PKA, ICaL_AKAP_PKA_PP, RyR_AKAP_PKA, RyR_AKAP_PKA_PP;

    double k_b1_dp;
    double PDE3_tot, PDE4_tot;
    double f_PDE3_CAV, f_PDE4_ECAV;

    double khydr_Gs, kreas_Gs, khydr_Gi, kreas_Gi, ATP, KmATP;

    double AC47_hill_Gs, AC47_basal, AC47_Km_Gs, AC47_Vmax_Gi, AC47_hill_Gi, AC47_Km_Gi;

    double kPDE2, KmPDE2, kPDE3, KmPDE3, kPDE4, KmPDE4;

    double k_PKA_f1, K_PKAII_1, K_PKAI_1, k_PKA_f2;
    double K_PKAII_2, K_PKAI_2, k_PKA_f3, K_PKAII_3;
    double K_PKAI_3, k_PKA_fPKI, K_PKA_PKI;

    double KI1, PP1_tot_CYT, I1_tot_CYT, kfI1p, KmI1p, kbI1p, PP2A_CYT, KmI1dp;
    double PP_CAV, PP1_ECAV;
    double K_PP1_Yotiao, K_PKA_Yotiao, K_IKs_Yotiao, IKs_tot, Yotiao_tot;
    double K_PP1_AKAP_ICaL, K_PKA_AKAP_ICaL, K_ICaL_AKAP, ICaL_tot, AKAP_ICaL_tot;
    double K_PP1_AKAP_RyR, K_PKA_AKAP_RyR, K_RyR_AKAP, RyR_tot, AKAP_RyR_tot;
    double J_CAV_ECAV, J_CAV_CYT, J_ECAV_CYT, AKAP_Factor;
    double rate_bds, rate_camp, k_GsAct_b2;
    double Gi_tot, R_b2_tot, R_b1_tot, Gs_tot, f_Rb1_CAV, f_Rb1_ECAV, f_Rb2_CAV, f_Gi_CAV;
    double K_b1_h, K_b1_l, K_b1_c;
    double K_b2_h, K_b2_l, K_b2_c, K_b2_a, K_b2_f, K_b2_n;
    double f_Gs_CAV, f_Gs_ECAV, kact1_Gs, kact2_Gs, kact1_Gi, kact2_Gi;
    double AC_tot, f_AC56_AC47, f_AC56_CAV, f_AC47_ECAV;
    double AC56_basal, AC56_hill_Gs, AC56_Km_Gs, AC56_V_GsGi, AC56_hill_GsGi, AC56_Km_GsGi, AC56_Km_Gi;
    double AF56, AF47;
    double f_CYT_PDE3, f_PDE4_PART, r_PDE3_PDE4, f_PART_PDE;
    double PDE2_tot, f_PDE2_CAV, f_PDE2_ECAV, f_PDE4_CAV, f_PDE3_ECAV;
    double k_b1_pkap, k_b1_grkp, K_b1_PKA, k_b1_grkdp;
    double kfPDEp, KPDEp, GRK_CAV, GRK_ECAV, GRK_CYT;
    double PKA_tot, f_PKA_CAV, f_PKA_ECAV, PKI_tot, f_PKI_CAV, f_PKI_ECAV;
    double temp_rate_LCC, k_PKALCC, Km_PKALCC, k_PPLCC, Km_PPLCC;
    double temp_rate_RyR, k_PKARyR, Km_PKARyR, k_PPRyR, Km_PPRyR;
    double k_PKAIKS, Km_PKAIKS, k_PP1IKS, Km_PP1IKS;
    double k_PKAPLB, Km_PKAPLB, k_PP1PLB, Km_PP1PLB;
    double k_PKATnI, Km_PKATnI, k_PPTnI, Km_PPTnI;
    double k_PKAINa, Km_PKAINa, k_PP1INa, Km_PP1INa;
    double k_PKAINaK, Km_PKAINaK, k_PP1INaK, Km_PP1INaK;
    double temp_rate_IKur, k_PKAIKur, Km_PKAIKur, k_PPIKur, Km_PPIKur;
    double f_Rb2_ECAV;
};

struct VConst {
    VConst();
    double cell, cav, ecav, cyt, tot, tot_per_cav, tot_per_ecav, tot_per_cyt;
};

void setCompartmentalValues();

extern SConst sc;
extern VConst V;
#endif //CANINEVENTRICULARCELLBETA_SIGNALLING_H

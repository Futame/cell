//
// Created by sokian on 15.09.15.
//checked by Zoya Kiyan 14.10
//

#include "signalling.h"

VConst V = VConst();
SConst sc;

VConst::VConst() {
    cell = vcell;
    cav = 0.02 * cell;
    ecav = 0.04 * cell;
    cyt = 0.678 * cell;
    tot = cell;
    tot_per_cav = tot/cav;
    tot_per_ecav = tot/ecav;
    tot_per_cyt = tot/cyt;
}

SConst::SConst() {
    khydr_Gs = 0.8;
    kreas_Gs = 1.21E3;
    khydr_Gi = khydr_Gs;
    kreas_Gi = kreas_Gs;
    ATP = 5E3;
    KmATP = 315;

    AC47_hill_Gs = 1.0043;
    AC47_basal = 0.03135;
    AC47_Km_Gs = 0.031544;
    AC47_Vmax_Gi = 0;
    AC47_hill_Gi = 0.8921;
    AC47_Km_Gi = 0.053733;


    kPDE2 = 20;
    KmPDE2 = 50;
    kPDE3 = 2.5;
    KmPDE3 = 0.8;
    kPDE4 = 4.0;
    KmPDE4 = 1.4;

    k_PKA_f1 = 100;    K_PKAII_1 = 2.4984;    K_PKAI_1 = 0.1088;
    k_PKA_f2 = 100;    K_PKAII_2 = 11.359;    K_PKAI_2 = 0.4612;
    k_PKA_f3 = 100;    K_PKAII_3 = 0.3755;    K_PKAI_3 = 0.3755;
    k_PKA_fPKI = 50;   K_PKA_PKI = 0.01 / 50;

    KI1 = 1E-3;
    PP1_tot_CYT = 0.89;
    I1_tot_CYT = 0.3;
    kfI1p = 1.0145e-002;
    KmI1p = 1.4690e-003;
    kbI1p = 3.5731e-003;
    PP2A_CYT = 1;
    KmI1dp = 1.9526e-005;

    PP_CAV = 0.25;
    PP1_ECAV = 0.1;


    K_PP1_Yotiao = 0.01; // 10 nM affinity similar to PKA based on Zakhary et al.
    K_PKA_Yotiao = 0.01;
    K_IKs_Yotiao = 1E-4; //1E-4; % From Saucerman et al. 2004
    IKs_tot = 0.025;    Yotiao_tot = IKs_tot;

    K_PP1_AKAP_ICaL = 0.01; // 10 nM affinity similar to PKA based on Zakhary et al.
    K_PKA_AKAP_ICaL = 0.01;
    K_ICaL_AKAP = 1E-4; // From Saucerman et al. 2004
    ICaL_tot = 0.025;    AKAP_ICaL_tot = ICaL_tot;

    K_PP1_AKAP_RyR = 0.01; // 10 nM affinity similar to PKA based on Zakhary et al.
    K_PKA_AKAP_RyR = 0.01;
    K_RyR_AKAP = 1E-4; // From Saucerman et al. 2004
    RyR_tot = 5 * 0.025;    AKAP_RyR_tot = RyR_tot;


    J_CAV_ECAV = 5E-15 * 1E6;
    J_CAV_CYT = 7.5E-14 * 1E6;
    J_ECAV_CYT = 0.9E-14 * 1E6;
    AKAP_Factor = 1;

    rate_bds = 0.35;
    rate_camp = 1.0;
    k_GsAct_b2 = 1.0;

    Gi_tot = 0.5;
    R_b2_tot = 0.15 * 0.025;
    R_b1_tot = 0.85 * 0.025;
    Gs_tot = 224 * R_b1_tot;
    f_Rb1_CAV = 8.1161e-002;
    f_Rb1_ECAV = 4.8744e-001;
    f_Rb2_CAV = 0.85;
    f_Gi_CAV = 0.85;

    K_b1_h = 0.062;
    K_b1_l = 0.567;
    K_b1_c = 2.4490e+000;

    K_b2_h = 0.012;
    K_b2_l = 1.053;
    K_b2_c = 1.8463e+000;
    K_b2_a = 1.6655e+000;
    K_b2_f = 0.1;
    K_b2_n = 1.053;

    f_Gs_CAV = 1.1071e-003;
    f_Gs_ECAV = 5.6640e-001;
    kact1_Gs = 4.9054e+000;
    kact2_Gs = 2.5945e-001;
    kact1_Gi = 4;
    kact2_Gi = 0.05;

    AC_tot = 3 * R_b1_tot;
    f_AC56_AC47 = 1 / (1 + 0.35);
    f_AC56_CAV = 8.7459e-002;
    f_AC47_ECAV = 1.6479e-001;

    AC56_basal = 3.7696e-002;
    AC56_hill_Gs = 1.3574;
    AC56_Km_Gs = 0.0852;
    AC56_V_GsGi = 0.8569;
    AC56_hill_GsGi = 0.6623;
    AC56_Km_GsGi = 0.4824;
    AC56_Km_Gi = 0.0465;

    AF56 = 4.1320e+001;
    AF47 = 3.3757e+000;

    f_CYT_PDE3 = 0.35; // 35% of cytosolic PDE is PDE Type 3
    f_PDE4_PART = 0.125; // 7 times more cytosolic PDE4 than particulate PDE4
    r_PDE3_PDE4 = 3.71; // ratio of PDE3 to PDe4 in particulate fraction is 78 : 21
    f_PART_PDE = 0.2;

    PDE2_tot = 2.9268e-002;
    f_PDE2_CAV = 1.6957e-001;
    f_PDE2_ECAV = 2.1257e-004;
    f_PDE4_CAV = 1.2481e-001;
    f_PDE3_ECAV = 0.0;

    k_b1_pkap = 0.0065;
    k_b1_grkp = 0.00133;
    K_b1_PKA = 1.5629e-001;
    k_b1_grkdp = 0.0009833;

    kfPDEp = 0.0196;
    KPDEp = 5.2218e-001;
    GRK_CAV = 1.0;
    GRK_ECAV = 1.0;
    GRK_CYT = 1.0;

    PKA_tot = 0.5;
    f_PKA_CAV = 0.0388;
    f_PKA_ECAV = 0.1;
    PKI_tot = 0.2 * PKA_tot;
    f_PKI_CAV = f_PKA_CAV;
    f_PKI_ECAV = f_PKA_ECAV;

    temp_rate_LCC = 1.0;
    k_PKALCC = 5.1009e-004;
    Km_PKALCC = 1.2702e-006;
    k_PPLCC = 6.9030e-004;
    Km_PPLCC = 6.3064e-003;

    temp_rate_RyR = 1.0;
    k_PKARyR = 2.5548e-003;
    Km_PKARyR = 6.6298e-005;
    k_PPRyR = 3.8257e-003;
    Km_PPRyR = 4.3003e-02;

    k_PKAIKS = 1.6305e-001;
    Km_PKAIKS = 9.9794e-005;
    k_PP1IKS = 1.0542;
    Km_PP1IKS = 1.1147e-004;

    k_PKAPLB = 1.1348e-001;
    Km_PKAPLB = 9.8854e-004;
    k_PP1PLB = 4.8302e-001;
    Km_PP1PLB = 8.0737e-001;

    k_PKATnI = 1.0408e-001;
    Km_PKATnI = 2.7143e-005;
    k_PPTnI = 5.2633e-002;
    Km_PPTnI = 2.6714e-001;

    k_PKAINa = 1.3680e-002;
    Km_PKAINa = 1.0988e-001;
    k_PP1INa = 5.2811e-02;
    Km_PP1INa = 7.8605e+00;

    k_PKAINaK = 1.5265e-002;
    Km_PKAINaK = 1.1001e-03;
    k_PP1INaK = 9.2455e-02;
    Km_PP1INaK = 5.7392e+00;

    temp_rate_IKur = 1.0;
    k_PKAIKur = 6.9537e-002;
    Km_PKAIKur = 2.7623e-001;
    k_PPIKur = 3.1700e-001;
    Km_PPIKur = 2.3310e-003;

    PP1_tot_CYT = 0.2;
    f_PP1_Inh1 = 0.3;
    IBMX = 0;

    f_Rb2_ECAV = 1 - f_Rb2_CAV;
    setCompartmentalValues();
}



void setCompartmentalValues() {
    sc.k_b1_dp = sc.K_b1_PKA * sc.k_b1_pkap;
    double r_PDE3_CYT = (sc.f_CYT_PDE3 / (1 - sc.f_CYT_PDE3));
    double f_PDE2_PART = sc.f_PDE2_CAV + sc.f_PDE2_ECAV;
    double alpha_PDE3 = r_PDE3_CYT *
                        (sc.f_PDE4_PART * (1 + sc.r_PDE3_PDE4 - sc.r_PDE3_PDE4 * f_PDE2_PART - sc.f_PART_PDE) +
                         f_PDE2_PART * (sc.f_PART_PDE - 1))
                        + sc.r_PDE3_PDE4 * sc.f_PDE4_PART * (sc.f_PART_PDE - f_PDE2_PART);

    double beta_PDE3 = sc.f_PDE4_PART * (1 + sc.r_PDE3_PDE4 + sc.f_PART_PDE * (r_PDE3_CYT - sc.r_PDE3_PDE4)) -
                       sc.f_PART_PDE * (1 + r_PDE3_CYT);
    sc.PDE3_tot = (alpha_PDE3 / beta_PDE3) * sc.PDE2_tot;
    sc.PDE4_tot = ((sc.f_PART_PDE - f_PDE2_PART) * sc.PDE2_tot + sc.f_PART_PDE * sc.PDE3_tot) /
                  ((1 + sc.r_PDE3_PDE4) * sc.f_PDE4_PART - sc.f_PART_PDE);

    sc.f_PDE3_CAV = (sc.r_PDE3_PDE4 * sc.f_PDE4_PART * sc.PDE4_tot) / sc.PDE3_tot;
    sc.f_PDE4_ECAV = sc.f_PDE4_PART - sc.f_PDE4_CAV;

    sc.PDE2_tot = sc.PDE2_tot * (1 - (pow(sc.IBMX, 1.167) / (21.58 + pow(sc.IBMX, 1.167) )));
    sc.PDE3_tot = sc.PDE3_tot * (1 - (pow(sc.IBMX, 0.7629) / (2.642 + pow(sc.IBMX, 0.7629) )));
    sc.PDE4_tot = sc.PDE4_tot * (1 - (pow(sc.IBMX, 0.9024) / (11.89 + pow(sc.IBMX, 0.9024) )));

    sc.AC56_CAV = sc.f_AC56_CAV * sc.f_AC56_AC47 * sc.AC_tot * (V.tot_per_cav);
    sc.AC56_CYT = (1 - sc.f_AC56_CAV) * sc.f_AC56_AC47 * sc.AC_tot * (V.tot_per_cyt);
    sc.AC47_ECAV = sc.f_AC47_ECAV * (1 - sc.f_AC56_AC47) * sc.AC_tot * V.tot_per_ecav;
    sc.AC47_CYT = (1 - sc.f_AC47_ECAV) * (1 - sc.f_AC56_AC47) * sc.AC_tot * (V.tot_per_cyt);

    double PKA_CAV = sc.f_PKA_CAV * sc.PKA_tot * V.tot_per_cav;
    double PKA_ECAV = sc.f_PKA_ECAV * sc.PKA_tot * V.tot_per_ecav;

    //IKs: compartment with 1 AKAP
    double PP1_ECAV_free = 0.5 * sc.K_PP1_Yotiao * (-(1 + (1 / sc.K_PP1_Yotiao) * (sc.Yotiao_tot - sc.PP1_ECAV))
                + sqrt(pow((1 +  (sc.Yotiao_tot - sc.PP1_ECAV) / sc.K_PP1_Yotiao), 2) + 4 * sc.PP1_ECAV * (1 / sc.K_PP1_Yotiao)));

    double IKs_free = 0.5 * sc.K_IKs_Yotiao * (-(1 + (sc.Yotiao_tot - sc.IKs_tot) / sc.K_IKs_Yotiao) +
                      sqrt(pow((1 + (sc.Yotiao_tot - sc.IKs_tot) / sc.K_IKs_Yotiao), 2) + 4 * sc.IKs_tot / sc.K_IKs_Yotiao));

     double R_free = 0.5 * sc.K_PKA_Yotiao * (-(1 + (sc.Yotiao_tot - PKA_ECAV) / sc.K_PKA_Yotiao)
           + sqrt(pow((1 + (sc.Yotiao_tot - PKA_ECAV) / sc.K_PKA_Yotiao), 2) + 4 * PKA_ECAV / sc.K_PKA_Yotiao));

    
    double Yotiao_free = (sc.Yotiao_tot - sc.IKs_tot + IKs_free) /  ((1 / sc.K_PP1_Yotiao) * PP1_ECAV_free + (1 / sc.K_PKA_Yotiao) * ((1 / sc.K_PP1_Yotiao) * PP1_ECAV_free + 1) * R_free + 1);

    sc.IKs_AKAP_PKA = (1 / (sc.K_IKs_Yotiao * sc.K_PKA_Yotiao)) * IKs_free * Yotiao_free * R_free;
    sc.IKs_AKAP_PKA_PP1 = sc.IKs_AKAP_PKA * (1 / sc.K_PP1_Yotiao) * PP1_ECAV_free;


    //ICaL and RyR: compartment with 2 AKAPs
    std::complex<double> b_pp1 = sc.AKAP_ICaL_tot + sc.AKAP_RyR_tot + sc.K_PP1_AKAP_ICaL + sc.K_PP1_AKAP_RyR - sc.PP_CAV;
    std::complex<double> c_pp1 = sc.AKAP_ICaL_tot * sc.K_PP1_AKAP_RyR + sc.AKAP_RyR_tot * sc.K_PP1_AKAP_ICaL +
                   sc.K_PP1_AKAP_ICaL * sc.K_PP1_AKAP_RyR - sc.PP_CAV * (sc.K_PP1_AKAP_ICaL + sc.K_PP1_AKAP_RyR);
    std::complex<double>  d_pp1 = sc.PP_CAV * sc.K_PP1_AKAP_ICaL * sc.K_PP1_AKAP_RyR;
    std::complex<double> phi_pp1 = pow((0.5 * d_pp1 + (b_pp1 * c_pp1 / 6.0) - (b_pp1 * b_pp1 * b_pp1 / 27.0) +
                          pow((-(pow(b_pp1, 3) * d_pp1 / 27.0) - (b_pp1 * b_pp1 * c_pp1 * c_pp1 / 108.0)
                               + (b_pp1 * c_pp1 * d_pp1 / 6.0) + (c_pp1 * c_pp1 * c_pp1 / 27.0) + (d_pp1 * d_pp1 / 4.0)),
                              0.5)), (1 / 3.0));


    std::complex<double>  PP1_CAV_fr = (phi_pp1 - (1.0 / phi_pp1) * ((c_pp1 / 3.0) - (b_pp1 * b_pp1 / 9.0)) - (b_pp1 / 3.0));
    double PP1_CAV_free = PP1_CAV_fr.real();

    std::complex<double>  b_pka = sc.AKAP_ICaL_tot + sc.AKAP_RyR_tot + sc.K_PKA_AKAP_ICaL + sc.K_PKA_AKAP_RyR - PKA_CAV;
    std::complex<double>  c_pka = sc.AKAP_ICaL_tot * sc.K_PKA_AKAP_RyR + sc.AKAP_RyR_tot * sc.K_PKA_AKAP_ICaL +
                   sc.K_PKA_AKAP_ICaL * sc.K_PKA_AKAP_RyR - PKA_CAV * (sc.K_PKA_AKAP_ICaL + sc.K_PKA_AKAP_RyR);
    std::complex<double>  d_pka = PKA_CAV * sc.K_PKA_AKAP_ICaL * sc.K_PKA_AKAP_RyR;
    std::complex<double>  phi_pka = pow((0.5 * d_pka + (b_pka * c_pka / 6.0) - (b_pka * b_pka * b_pka / 27.0) +
                          sqrt(-(b_pka * b_pka * b_pka * d_pka / 27.0) - (b_pka * b_pka * c_pka * c_pka / 108.0)
                               + (b_pka * c_pka * d_pka / 6.0) + (c_pka * c_pka * c_pka / 27.0) + (d_pka * d_pka / 4.0))),
                         (1 / 3.0));
    std::complex<double>  R_CAV_fr = (phi_pka - (1.0 / phi_pka) * ((c_pka / 3.0) - (b_pka * b_pka / 9.0)) - (b_pka / 3.0));
    double R_CAV_free = R_CAV_fr.real();

    double ICaL_free = 0.5 * sc.K_ICaL_AKAP * (-(1.0 + (1.0 / sc.K_ICaL_AKAP) * (sc.AKAP_ICaL_tot - sc.ICaL_tot))
                                               + sqrt(pow((1.0 + (1.0 / sc.K_ICaL_AKAP) * (sc.AKAP_ICaL_tot - sc.ICaL_tot)),
                                                          2) + 4.0 * sc.ICaL_tot * (1.0 / sc.K_ICaL_AKAP)));

    double RyR_free = 0.5 * sc.K_RyR_AKAP * (-(1.0 + (1.0 / sc.K_RyR_AKAP) * (sc.AKAP_RyR_tot - sc.RyR_tot))
                                             + sqrt(pow((1.0 + (1.0 / sc.K_RyR_AKAP) * (sc.AKAP_RyR_tot - sc.RyR_tot)), 2) +
                                                    4.0 * sc.RyR_tot * (1.0 / sc.K_RyR_AKAP)));

    double AKAP_ICaL_free = (sc.AKAP_ICaL_tot - sc.ICaL_tot + ICaL_free) / ((1 / sc.K_PP1_AKAP_ICaL) * PP1_CAV_free
                                                                            + (1 / sc.K_PKA_AKAP_ICaL) *
                                                                              ((1 / sc.K_PP1_AKAP_ICaL) * PP1_CAV_free +
                                                                               1) * R_CAV_free + 1);

    double AKAP_RyR_free = (sc.AKAP_RyR_tot - sc.RyR_tot + RyR_free) / ((1 / sc.K_PP1_AKAP_RyR) * PP1_CAV_free
                                                                        + (1 / sc.K_PKA_AKAP_RyR) *
                                                                          ((1 / sc.K_PP1_AKAP_RyR) * PP1_CAV_free + 1) *
                                                                          R_CAV_free + 1);

    sc.ICaL_AKAP_PKA = (1 / (sc.K_ICaL_AKAP * sc.K_PKA_AKAP_ICaL)) * ICaL_free * AKAP_ICaL_free * R_CAV_free;
    sc.ICaL_AKAP_PKA_PP = sc.ICaL_AKAP_PKA * (1 / sc.K_PP1_AKAP_ICaL) * PP1_CAV_free;

    sc.RyR_AKAP_PKA = (1 / (sc.K_RyR_AKAP * sc.K_PKA_AKAP_RyR)) * RyR_free * AKAP_RyR_free * R_CAV_free;
    sc.RyR_AKAP_PKA_PP = sc.RyR_AKAP_PKA * (1 / sc.K_PP1_AKAP_RyR) * PP1_CAV_free;
}
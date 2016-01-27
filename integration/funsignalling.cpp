//
// Created by Zoya Kiyan on 05.10.15.
// Checked by Zoya Kiyan on 20.10.15
//

#include "funsignalling.h"

const double L = ISO;
Concentration dy;

void FilesForConcentration::open() {
    Gs_aGTP_CAV = fopen("./Conc/Gs_aGTP_CAV", "w");
    Gs_aGTP_ECAV = fopen("./Conc/Gs_aGTP_ECAV", "w");
    Gs_aGDP_CAV = fopen("./Conc/Gs_aGDP_CAV", "w");
    Gs_bg_CYT = fopen("./Conc/Gs_bg_CYT", "w");
    Gs_bg_ECAV = fopen("./Conc/Gs_bg_ECAV", "w");
    Gs_bg_CAV = fopen("./Conc/Gs_bg_CAV", "w");
    Gs_aGDP_ECAV = fopen("./Conc/Gs_aGDP_ECAV", "w");
    Gs_aGDP_CYT = fopen("./Conc/Gs_aGDP_CYT", "w");
    cAMP_CAV = fopen("./Conc/cAMP_CAV", "w");
    cAMP_ECAV = fopen("./Conc/cAMP_ECAV", "w");
    cAMP_CYT = fopen("./Conc/cAMP_CYT", "w");
    R_pkap_tot_CAV = fopen("./Conc/R_pkap_tot_CAV", "w");
    R_pkap_tot_ECAV = fopen("./Conc/R_pkap_tot_ECAV", "w");
    R_pkap_tot_CYT = fopen("./Conc/R_pkap_tot_CYT", "w");
    R_grkp_tot_CAV = fopen("./Conc/R_grkp_tot_CAV", "w");
    R_grkp_tot_ECAV = fopen("./Conc/R_grkp_tot_ECAV", "w");
    R_grkp_tot_CYT = fopen("./Conc/R_grkp_tot_CYT", "w");
    RLC_CAV = fopen("./Conc/RLC_CAV", "w");
    RLC_ECAV = fopen("./Conc/RLC_ECAV", "w");
    RLC_CYT = fopen("./Conc/RLC_CYT", "w");
    L2RC_CAV = fopen("./Conc/L2RC_CAV", "w");
    L2RC_ECAV = fopen("./Conc/L2RC_ECAV", "w");
    L2RC_CYT = fopen("./Conc/L2RC_CYT", "w");
    L2R_CAV = fopen("./Conc/L2R_CAV", "w");
    L2R_ECAV = fopen("./Conc/L2R_ECAV", "w");
    L2R_CYT = fopen("./Conc/L2R_CYT", "w");
    C_CAV = fopen("./Conc/C_CAV", "w");
    C_ECAV = fopen("./Conc/C_ECAV", "w");
    C_CYT = fopen("./Conc/C_CYT", "w");
    PKI_ECAV = fopen("./Conc/PKI_ECAV", "w");
    PKI_CYT = fopen("./Conc/PKI_CYT", "w");
    PKI_CAV = fopen("./Conc/PKI_CAV", "w");
    PDE3_P_CAV = fopen("./Conc/PDE3_P_CAV", "w");
    PDE3_P_CYT = fopen("./Conc/PDE3_P_CYT", "w");
    PDE4_P_CAV = fopen("./Conc/PDE4_P_CAV", "w");
    PDE4_P_ECAV = fopen("./Conc/PDE4_P_ECAV", "w");
    PDE4_P_CYT = fopen("./Conc/PDE4_P_CYT", "w");
    Inhib1_P_CYT = fopen("./Conc/Inhib1_P_CYT", "w");
    fLCC_P = fopen("./Conc/fLCC_P", "w");
    fIKS_P = fopen("./Conc/fIKS_P", "w");
    fPLB_P = fopen("./Conc/fPLB_P", "w");
    fTnI_P = fopen("./Conc/fTnI_P", "w");
    fINa_P = fopen("./Conc/fINa_P", "w");
    fINaK_P = fopen("./Conc/fINaK_P", "w");
    fRyR_P = fopen("./Conc/fRyR_P", "w");
    fIKur_P = fopen("./Conc/fIKur_P", "w");
    Rb2_pkap_tot_CAV = fopen("./Conc/Rb2_pkap_tot_CAV", "w");
    Rb2_pkap_tot_ECAV = fopen("./Conc/Rb2_pkap_tot_ECAV", "w");
    Rb2_grkp_tot_CAV = fopen("./Conc/Rb2_grkp_tot_CAV", "w");
    Rb2_grkp_tot_ECAV = fopen("./Conc/Rb2_grkp_tot_ECAV", "w");
    Gi_aGTP_CAV = fopen("./Conc/Gi_aGTP_CAV", "w");
    Gi_aGTP_ECAV = fopen("./Conc/Gi_aGTP_ECAV", "w");
    Gi_bg_ECAV = fopen("./Conc/Gi_bg_ECAV", "w");
    Gi_bg_CAV = fopen("./Conc/Gi_bg_CAV", "w");
    Gi_aGDP_CAV = fopen("./Conc/Gi_aGDP_CAV", "w");
    Gi_aGDP_ECAV = fopen("./Conc/Gi_aGDP_ECAV", "w");
    Gs_a_GTP_CYT = fopen("./Conc/Gs_a_GTP_CYT", "w");
}

void FilesForConcentration::close() {
    fclose(Gs_aGTP_CAV);
    fclose(Gs_aGTP_ECAV);
    fclose(Gs_bg_CAV);
    fclose(Gs_bg_ECAV);
    fclose(Gs_bg_CYT);
    fclose(Gs_aGDP_CAV);
    fclose(Gs_aGDP_ECAV);
    fclose(Gs_aGDP_CYT);
    fclose(cAMP_CAV);
    fclose(cAMP_ECAV);
    fclose(cAMP_CYT);
    fclose(R_pkap_tot_CAV);
    fclose(R_pkap_tot_ECAV);
    fclose(R_pkap_tot_CYT);
    fclose(R_grkp_tot_CAV);
    fclose(R_grkp_tot_ECAV);
    fclose(R_grkp_tot_CYT);

    fclose(RLC_CAV);
    fclose(RLC_ECAV);
    fclose(RLC_CYT);
    fclose(L2RC_CAV);
    fclose(L2RC_ECAV);
    fclose(L2RC_CYT);
    fclose(L2R_CAV);
    fclose(L2R_ECAV);
    fclose(L2R_CYT);
    fclose(C_CAV);
    fclose(C_ECAV);
    fclose(C_CYT);
    fclose(PKI_CAV);
    fclose(PKI_ECAV);
    fclose(PKI_CYT);

    fclose(PDE3_P_CAV);
    fclose(PDE3_P_CYT);
    fclose(PDE4_P_CAV);
    fclose(PDE4_P_ECAV);
    fclose(PDE4_P_CYT);

    fclose(Inhib1_P_CYT);

    fclose(fLCC_P);
    fclose(fIKS_P);
    fclose(fPLB_P);
    fclose(fTnI_P);
    fclose(fINa_P);
    fclose(fINaK_P);
    fclose(fRyR_P);
    fclose(fIKur_P);

    fclose(Rb2_pkap_tot_CAV);
    fclose(Rb2_pkap_tot_ECAV);
    fclose(Rb2_grkp_tot_CAV);
    fclose(Rb2_grkp_tot_ECAV);
    fclose(Gi_aGTP_CAV);
    fclose(Gi_aGTP_ECAV);
    fclose(Gi_bg_CAV);
    fclose(Gi_bg_ECAV);
    fclose(Gi_aGDP_CAV);
    fclose(Gi_aGDP_ECAV);
    fclose(Gs_a_GTP_CYT);

}

void FilesForConcentration::print(double time, Concentration y) {

    fprintf(Gs_aGTP_CAV, "%e %e\n", time, y.Gs_aGTP_CAV);
    fprintf(Gs_aGTP_ECAV, "%e %e\n", time, y.Gs_aGTP_ECAV);
    fprintf(Gs_bg_CAV, "%e %e\n", time, y.Gs_bg_CAV);
    fprintf(Gs_bg_ECAV, "%e %e\n", time, y.Gs_bg_ECAV);
    fprintf(Gs_bg_CYT, "%e %e\n", time, y.Gs_bg_CYT);
    fprintf(Gs_aGDP_CAV, "%e %e\n", time, y.Gs_aGDP_CAV);
    fprintf(Gs_aGDP_ECAV, "%e %e\n", time, y.Gs_aGDP_ECAV);
    fprintf(Gs_aGDP_CYT, "%e %e\n", time, y.Gs_aGDP_CYT);

    fprintf(cAMP_CAV, "%e %e\n", time, y.cAMP_CAV);
    fprintf(cAMP_ECAV, "%e %e\n", time, y.cAMP_ECAV);
    fprintf(cAMP_CYT, "%e %e\n", time, y.cAMP_CYT);
    fprintf(R_pkap_tot_CAV, "%e %e\n", time, y.R_pkap_tot_CAV);
    fprintf(R_pkap_tot_ECAV, "%e %e\n", time, y.R_pkap_tot_ECAV);
    fprintf(R_pkap_tot_CYT, "%e %e\n", time, y.R_pkap_tot_CYT);
    fprintf(R_grkp_tot_CAV, "%e %e\n", time, y.R_grkp_tot_CAV);
    fprintf(R_grkp_tot_ECAV, "%e %e\n", time, y.R_grkp_tot_ECAV);
    fprintf(R_grkp_tot_CYT, "%e %e\n", time, y.R_grkp_tot_CYT);

    fprintf(RLC_CAV, "%e %e\n", time, y.RLC_CAV);
    fprintf(RLC_ECAV, "%e %e\n", time, y.RLC_ECAV);
    fprintf(RLC_CYT, "%e %e\n", time, y.RLC_CYT);
    fprintf(L2RC_CAV, "%e %e\n", time, y.L2RC_CAV);
    fprintf(L2RC_ECAV, "%e %e\n", time, y.L2RC_ECAV);
    fprintf(L2RC_CYT, "%e %e\n", time, y.L2RC_CYT);
    fprintf(L2R_CAV, "%e %e\n", time, y.L2R_CAV);
    fprintf(L2R_ECAV, "%e %e\n", time, y.L2R_ECAV);
    fprintf(L2R_CYT, "%e %e\n", time, y.L2R_CYT);
    fprintf(C_CAV, "%e %e\n", time, y.C_CAV);
    fprintf(C_ECAV, "%e %e\n", time, y.C_ECAV);
    fprintf(C_CYT, "%e %e\n", time, y.C_CYT);
    fprintf(PKI_CAV, "%e %e\n", time, y.PKI_CAV);
    fprintf(PKI_ECAV, "%e %e\n", time, y.PKI_ECAV);
    fprintf(PKI_CYT, "%e %e\n", time, y.PKI_CYT);

    fprintf(PDE3_P_CAV, "%e %e\n", time, y.PDE3_P_CAV);
    fprintf(PDE3_P_CYT, "%e %e\n", time, y.PDE3_P_CYT);
    fprintf(PDE4_P_CAV, "%e %e\n", time, y.PDE4_P_CAV);
    fprintf(PDE4_P_ECAV, "%e %e\n", time, y.PDE4_P_ECAV);
    fprintf(PDE4_P_CYT, "%e %e\n", time, y.PDE4_P_CYT);

    fprintf(Inhib1_P_CYT, "%e %e\n", time, y.Inhib1_P_CYT);

    fprintf(fLCC_P, "%e %e\n", time, y.fLCC_P);
    fprintf(fIKS_P, "%e %e\n", time, y.fIKS_P);
    fprintf(fPLB_P, "%e %e\n", time, y.fPLB_P);
    fprintf(fTnI_P, "%e %e\n", time, y.fTnI_P);
    fprintf(fINa_P, "%e %e\n", time, y.fINa_P);
    fprintf(fINaK_P, "%e %e\n", time, y.fINaK_P);
    fprintf(fRyR_P, "%e %e\n", time, y.fRyR_P);
    fprintf(fIKur_P, "%e %e\n", time, y.fIKur_P);

    fprintf(Rb2_pkap_tot_CAV, "%e %e\n", time, y.Rb2_pkap_tot_CAV);
    fprintf(Rb2_pkap_tot_ECAV, "%e %e\n", time, y.Rb2_pkap_tot_ECAV);
    fprintf(Rb2_grkp_tot_CAV, "%e %e\n", time, y.Rb2_grkp_tot_CAV);
    fprintf(Rb2_grkp_tot_ECAV, "%e %e\n", time, y.Rb2_grkp_tot_ECAV);
    fprintf(Gi_aGTP_CAV, "%e %e\n", time, y.Gi_aGTP_CAV);
    fprintf(Gi_aGTP_ECAV, "%e %e\n", time, y.Gi_aGTP_ECAV);
    fprintf(Gi_bg_CAV, "%e %e\n", time, y.Gi_bg_CAV);
    fprintf(Gi_bg_ECAV, "%e %e\n", time, y.Gi_bg_ECAV);
    fprintf(Gi_aGDP_CAV, "%e %e\n", time, y.Gi_aGDP_CAV);
    fprintf(Gi_aGDP_ECAV, "%e %e\n", time, y.Gi_aGDP_ECAV);
    fprintf(Gs_a_GTP_CYT, "%e %e\n", time, y.Gs_a_GTP_CYT);
}


Concentration::Concentration() {
    Gs_aGTP_CAV = 0;
    Gs_aGTP_ECAV = 0;
    Gs_a_GTP_CYT = 0;
    Gs_bg_CAV = 0;
    Gs_bg_ECAV = 0;
    Gs_bg_CYT = 0;
    Gs_aGDP_CAV = 0;
    Gs_aGDP_ECAV = 0;
    Gs_aGDP_CYT = 0;
    cAMP_CAV = 0;
    cAMP_ECAV = 0;
    cAMP_CYT = 0;
    R_pkap_tot_CAV = 0;
    R_pkap_tot_ECAV = 0;
    R_pkap_tot_CYT = 0;
    R_grkp_tot_CAV = 0;
    R_grkp_tot_ECAV = 0;
    R_grkp_tot_CYT = 0;

    RLC_CAV = 0;
    RLC_ECAV = 0;
    RLC_CYT = 0;
    L2RC_CAV = 0;
    L2RC_ECAV = 0;
    L2RC_CYT = 0;
    L2R_CAV = 0;
    L2R_ECAV = 0;
    L2R_CYT = 0;
    C_CAV = 0;
    C_ECAV = 0;
    C_CYT = 0;
    PKI_CAV = 0;
    PKI_ECAV = 0;
    PKI_CYT = 0;

    PDE3_P_CAV = 0;
    PDE3_P_CYT = 0;
    PDE4_P_CAV = 0;
    PDE4_P_ECAV = 0;
    PDE4_P_CYT = 0;

    Inhib1_P_CYT = 0;


    fLCC_P = 0;
    fIKS_P = 0;
    fPLB_P = 0;
    fTnI_P = 0;
    fINa_P = 0;
    fINaK_P = 0;
    fRyR_P = 0;
    fIKur_P = 0;

    Rb2_pkap_tot_CAV = 0;
    Rb2_pkap_tot_ECAV = 0;
    Rb2_grkp_tot_CAV = 0;
    Rb2_grkp_tot_ECAV = 0;
    Gi_aGTP_CAV = 0;
    Gi_aGTP_ECAV = 0;
    Gi_bg_CAV = 0;
    Gi_bg_ECAV = 0;
    Gi_aGDP_CAV = 0;
    Gi_aGDP_ECAV = 0;
}

Concentration multiply(Concentration y, double a) {
    y.Gs_aGTP_CAV *= a;
    y.Gs_aGTP_ECAV *= a;
    y.Gs_bg_CAV *= a;
    y.Gs_bg_ECAV *= a;
    y.Gs_bg_CYT *= a;
    y.Gs_aGDP_CAV *= a;
    y.Gs_aGDP_ECAV *= a;
    y.Gs_aGDP_CYT *= a;
    y.cAMP_CAV *= a;
    y.cAMP_ECAV *= a;
    y.cAMP_CYT *= a;
    y.R_pkap_tot_CAV *= a;
    y.R_pkap_tot_ECAV *= a;
    y.R_pkap_tot_CYT *= a;
    y.R_grkp_tot_CAV *= a;
    y.R_grkp_tot_ECAV *= a;
    y.R_grkp_tot_CYT *= a;

    y.RLC_CAV *= a;
    y.RLC_ECAV *= a;
    y.RLC_CYT *= a;
    y.L2RC_CAV *= a;
    y.L2RC_ECAV *= a;
    y.L2RC_CYT *= a;
    y.L2R_CAV *= a;
    y.L2R_ECAV *= a;
    y.L2R_CYT *= a;
    y.C_CAV *= a;
    y.C_ECAV *= a;
    y.C_CYT *= a;
    y.PKI_CAV *= a;
    y.PKI_ECAV *= a;
    y.PKI_CYT *= a;

    y.PDE3_P_CAV *= a;
    y.PDE3_P_CYT *= a;
    y.PDE4_P_CAV *= a;
    y.PDE4_P_ECAV *= a;
    y.PDE4_P_CYT *= a;

    y.Inhib1_P_CYT *= a;

    y.fLCC_P *= a;
    y.fIKS_P *= a;
    y.fPLB_P *= a;
    y.fTnI_P *= a;
    y.fINa_P *= a;
    y.fINaK_P *= a;
    y.fRyR_P *= a;
    y.fIKur_P *= a;

    y.Rb2_pkap_tot_CAV *= a;
    y.Rb2_pkap_tot_ECAV *= a;
    y.Rb2_grkp_tot_CAV *= a;
    y.Rb2_grkp_tot_ECAV *= a;
    y.Gi_aGTP_CAV *= a;
    y.Gi_aGTP_ECAV *= a;
    y.Gi_bg_CAV *= a;
    y.Gi_bg_ECAV *= a;
    y.Gi_aGDP_CAV *= a;
    y.Gi_aGDP_ECAV *= a;
    y.Gs_a_GTP_CYT *= a;

    return y;
}

Concentration sum(Concentration y, Concentration dy) {
    y.Gs_aGTP_CAV += dy.Gs_aGTP_CAV;
    y.Gs_aGTP_ECAV += dy.Gs_aGTP_ECAV;
    y.Gs_bg_CAV += dy.Gs_bg_CAV;
    y.Gs_bg_ECAV += dy.Gs_bg_ECAV;
    y.Gs_bg_CYT += dy.Gs_bg_CYT;
    y.Gs_aGDP_CAV += dy.Gs_aGDP_CAV;
    y.Gs_aGDP_ECAV += dy.Gs_aGDP_ECAV;
    y.Gs_aGDP_CYT += dy.Gs_aGDP_CYT;
    y.cAMP_CAV += dy.cAMP_CAV;
    y.cAMP_ECAV += dy.cAMP_ECAV;
    y.cAMP_CYT += dy.cAMP_CYT;

    y.R_pkap_tot_CAV += dy.R_pkap_tot_CAV;
    y.R_pkap_tot_ECAV += dy.R_pkap_tot_ECAV;
    y.R_pkap_tot_CYT += dy.R_pkap_tot_CYT;
    y.R_grkp_tot_CAV += dy.R_grkp_tot_CAV;
    y.R_grkp_tot_ECAV += dy.R_grkp_tot_ECAV;
    y.R_grkp_tot_CYT += dy.R_grkp_tot_CYT;

    y.RLC_CAV += dy.RLC_CAV;
    y.RLC_ECAV += dy.RLC_ECAV;
    y.RLC_CYT += dy.RLC_CYT;
    y.L2RC_CAV += dy.L2RC_CAV;
    y.L2RC_ECAV += dy.L2RC_ECAV;
    y.L2RC_CYT += dy.L2RC_CYT;
    y.L2R_CAV += dy.L2R_CAV;
    y.L2R_ECAV += dy.L2R_ECAV;
    y.L2R_CYT += dy.L2R_CYT;
    y.C_CAV += dy.C_CAV;
    y.C_ECAV += dy.C_ECAV;
    y.C_CYT += dy.C_CYT;
    y.PKI_CAV += dy.PKI_CAV;
    y.PKI_ECAV += dy.PKI_ECAV;
    y.PKI_CYT += dy.PKI_CYT;

    y.PDE3_P_CAV += dy.PDE3_P_CAV;
    y.PDE3_P_CYT += dy.PDE3_P_CYT;
    y.PDE4_P_CAV += dy.PDE4_P_CAV;
    y.PDE4_P_ECAV += dy.PDE4_P_ECAV;
    y.PDE4_P_CYT += dy.PDE4_P_CYT;

    y.Inhib1_P_CYT += dy.Inhib1_P_CYT;

    y.fLCC_P += dy.fLCC_P;
    y.fIKS_P += dy.fIKS_P;
    y.fPLB_P += dy.fPLB_P;
    y.fTnI_P += dy.fTnI_P;
    y.fINa_P += dy.fINa_P;
    y.fINaK_P += dy.fINaK_P;
    y.fRyR_P += dy.fRyR_P;
    y.fIKur_P += dy.fIKur_P;

    y.Rb2_pkap_tot_CAV += dy.Rb2_pkap_tot_CAV;
    y.Rb2_pkap_tot_ECAV += dy.Rb2_pkap_tot_ECAV;
    y.Rb2_grkp_tot_CAV += dy.Rb2_grkp_tot_CAV;
    y.Rb2_grkp_tot_ECAV += dy.Rb2_grkp_tot_ECAV;
    y.Gi_aGTP_CAV += dy.Gi_aGTP_CAV;
    y.Gi_aGTP_ECAV += dy.Gi_aGTP_ECAV;
    y.Gi_bg_CAV += dy.Gi_bg_CAV;
    y.Gi_bg_ECAV += dy.Gi_bg_ECAV;
    y.Gi_aGDP_CAV += dy.Gi_aGDP_CAV;
    y.Gi_aGDP_ECAV += dy.Gi_aGDP_ECAV;
    y.Gs_a_GTP_CYT += dy.Gs_a_GTP_CYT;

    return y;
}

LigRecepGprot::LigRecepGprot() {
    RG = 0;
    LRG = 0;
    dR_pkap_tot = 0;
    dR_grkp_tot = 0;
}

LigRecepGprot Mod_LigRecepGprot(double R_tot, double R_pkap_tot, double R_grkp_tot, double L, double G_abg, double PKAC,
                                double GRK) {
    LigRecepGprot ligRecepGprot;
    double R_np_tot = R_tot - R_pkap_tot - R_grkp_tot;

    // NP distribution
    // x = "a"
    double x = ((sc.K_b1_h + L) * (sc.K_b1_l + L)) / sc.K_b1_l;
    double b = G_abg * sc.K_b1_h - R_np_tot * (sc.K_b1_h + L) + G_abg * L + sc.K_b1_c * sc.K_b1_h +
               (sc.K_b1_c * sc.K_b1_h * L) / sc.K_b1_l;
    double c = -R_np_tot * sc.K_b1_c * sc.K_b1_h;

    double Rf = (-b + sqrt(b * b - 4 * x * c)) / (2 * x);
    double Gf = G_abg / (1 + Rf / sc.K_b1_c + L * Rf / (sc.K_b1_c * sc.K_b1_h));
    double LR = (L * Rf) / sc.K_b1_l;
    ligRecepGprot.RG = (Rf * Gf) / sc.K_b1_c;
    ligRecepGprot.LRG = (L * Rf * Gf) / (sc.K_b1_h * sc.K_b1_c);

    ligRecepGprot.dR_pkap_tot = sc.rate_bds * sc.k_b1_pkap * PKAC * R_np_tot - sc.rate_bds * sc.k_b1_dp * R_pkap_tot;
    ligRecepGprot.dR_grkp_tot =
            sc.rate_bds * sc.k_b1_grkp * GRK * (LR + ligRecepGprot.LRG) - sc.rate_bds * sc.k_b1_grkdp * R_grkp_tot;

    ligRecepGprot.RG = ligRecepGprot.RG + Bblocked[1] * ligRecepGprot.LRG;
    ligRecepGprot.LRG = ligRecepGprot.LRG * (1 - Bblocked[1]);

    return ligRecepGprot;
}

LigRecepGprotWithBeta2 Mod_LigRecepGprotWithBeta2(double Rb1_tot, double Rb1_pkap_tot, double Rb1_grkp_tot,
                                                  double Rb2_tot, double Rb2_pkap_tot, double Rb2_grkp_tot,
                                                  double Gs_abg, double Gi_abg, double PKAC, double GRK) {
    LigRecepGprotWithBeta2 lRGwithBeta2;
    double Rb1_np_tot = Rb1_tot - Rb1_pkap_tot - Rb1_grkp_tot;
    double Rb2_np_tot = Rb2_tot - Rb2_pkap_tot - Rb2_grkp_tot;

    double KF2 = sc.K_b2_f;
    double KA2 = sc.K_b2_a;
    double KN2 = sc.K_b2_n;
    double x = ((KF2 + L) * (KN2 + L)) / KN2;
    double b = Gi_abg * KF2 - Rb2_pkap_tot * (KF2 + L) + Gi_abg * L + KA2 * KF2 + (KA2 * KF2 * L) / KN2;
    double c = -Rb2_pkap_tot * KA2 * KF2;

    double Rb2_pkap_f = (-b + sqrt(b * b - 4 * x * c)) / (2 * x);
    double Gi_f = Gi_abg / (1 + Rb2_pkap_f / KA2 + L * Rb2_pkap_f / (KA2 * KF2));
    lRGwithBeta2.Rb2Gi = Rb2_pkap_f * Gi_f / KA2;
    lRGwithBeta2.LRb2Gi = L * lRGwithBeta2.Rb2Gi / KF2;

    // Beta 1 and Beta 2 Nonphosphorylated receptors distribution
    double KL1 = sc.K_b1_l;
    double KC1 = sc.K_b1_c;
    double KH1 = sc.K_b1_h;
    double KL2 = sc.K_b2_l;
    double KC2 = sc.K_b2_c;
    double KH2 = sc.K_b2_h;

    b = Rb1_np_tot + (KC1 * KH1 * KL2 * L * L -
                      Gs_abg * (KL1 * KL2 * L * L + KH1 * KH2 * KL1 * KL2 + KH1 * KL1 * KL2 * L + KH2 * KL1 * KL2 * L) +
                      KC2 * KH2 * KL1 * L * L + KL1 * KL2 * L * L * Rb2_np_tot
                      + KC1 * KH1 * KH2 * KL1 * KL2 + KC2 * KH1 * KH2 * KL1 * KL2 + KC1 * KH1 * KH2 * KL2 * L +
                      KC2 * KH1 * KH2 * KL1 * L + KC1 * KH1 * KL1 * KL2 * L + KC2 * KH2 * KL1 * KL2 * L +
                      KH1 * KH2 * KL1 * KL2 * Rb2_np_tot
                      + KH1 * KL1 * KL2 * L * Rb2_np_tot + KH2 * KL1 * KL2 * L * Rb2_np_tot) /
                     (KL1 * KL2 * L * L + KH1 * KH2 * KL1 * KL2 + KH1 * KL1 * KL2 * L + KH2 * KL1 * KL2 * L);
    c = (KC1 * KH1 * L * L * Rb2_np_tot - Gs_abg * KC1 * KH1 * L * L - Gs_abg * KC1 * KH1 * KH2 * KL1 -
         Gs_abg * KC2 * KH1 * KH2 * KL1 - Gs_abg * KC1 * KH1 * KH2 * L - Gs_abg * KC1 * KH1 * KL1 * L -
         Gs_abg * KC2 * KH2 * KL1 * L
         + KC1 * KC2 * KH1 * KH2 * KL1 + KC1 * KC2 * KH1 * KH2 * L + KC1 * KH1 * KH2 * KL1 * Rb2_np_tot +
         KC2 * KH1 * KH2 * KL1 * Rb1_np_tot + KC1 * KH1 * KH2 * L * Rb2_np_tot + KC1 * KH1 * KL1 * L * Rb2_np_tot
         + KC2 * KH2 * KL1 * L * Rb1_np_tot) / (KL1 * (KH1 + L) * (KH2 + L)) +
        (KC1 * KC2 * KH1 * KH2 * L * L - Gs_abg * KC2 * KH2 * KL1 * L * L + KC2 * KH2 * KL1 * L * L * Rb1_np_tot -
         Gs_abg * KC2 * KH1 * KH2 * KL1 * L
         + KC1 * KC2 * KH1 * KH2 * KL1 * L + KC2 * KH1 * KH2 * KL1 * L * Rb1_np_tot) /
        (KL1 * KL2 * (KH1 + L) * (KH2 + L));


    double d = (Gs_abg * KC1 * KC2 * KH1 * KH2 * (KL1 + L) * (KL2 + L)) / (KL1 * KL2 * (KH1 + L) * (KH2 + L));

    std::complex<double> b1 = b;
    std::complex<double> c1 = c;
    std::complex<double> d1 = d;

    std::complex<double> phi = pow((0.5 * d1 + (b1 * c1 / 6.0) - (b1 * b1 * b1 / 27.0) +
               sqrt(-(b1 * b1 * b1 * d1 / 27.0) - (b1 * b1 * c1 * c1 / 108.0) + (b1 * c1 * d1 / 6.0) + (c1 * c1 * c1 / 27.0) + (d1 * d1 / 4.0))),
              (1 / 3.0));
    double Gs_f = std::abs((phi - (1.0 / phi) * ((c / 3.0) - (b * b / 9.0)) - (b / 3.0)));
    double Rb1_f = Rb1_np_tot / (1 + L / KL1 + (1 / KC1 + L / (KC1 * KH1)) * Gs_f);
    double Rb2_f = Rb2_np_tot / (1 + L / KL2 + (1 / KC2 + L / (KC2 * KH2)) * Gs_f);

    double LRb1 = (L * Rb1_f) / KL1;
    lRGwithBeta2.Rb1Gs = (Rb1_f * Gs_f) / KC1;
    lRGwithBeta2.LRb1Gs = (L * Rb1_f * Gs_f) / (KH1 * KC1);

    double LRb2 = (L * Rb2_f) / KL2;
    lRGwithBeta2.Rb2Gs = (Rb2_f * Gs_f) / KC2;
    lRGwithBeta2.LRb2Gs = (L * Rb2_f * Gs_f) / (KH2 * KC2);

    lRGwithBeta2.dRb1_pkap_tot =
            sc.rate_bds * sc.k_b1_pkap * PKAC * Rb1_np_tot - sc.rate_bds * sc.k_b1_dp * Rb1_pkap_tot;
    lRGwithBeta2.dRb1_grkp_tot = sc.rate_bds * sc.k_b1_grkp * GRK * (LRb1 + lRGwithBeta2.LRb1Gs) -
                                 sc.rate_bds * sc.k_b1_grkdp * Rb1_grkp_tot;
    lRGwithBeta2.dRb2_pkap_tot =
            sc.rate_bds * sc.k_b1_pkap * PKAC * Rb2_np_tot - sc.rate_bds * sc.k_b1_dp * Rb2_pkap_tot;
    lRGwithBeta2.dRb2_grkp_tot = sc.rate_bds * sc.k_b1_grkp * GRK * (LRb2 + lRGwithBeta2.LRb2Gs) -
                                 sc.rate_bds * sc.k_b1_grkdp * Rb2_grkp_tot;


/*
    lRGwithBeta2.Rb1Gs = lRGwithBeta2.Rb1Gs + lRGwithBeta2.LRb1Gs * Bblocked.I;
    lRGwithBeta2.LRb1Gs = lRGwithBeta2.LRb1Gs * (1 - Bblocked.I);

    lRGwithBeta2.Rb2Gs = lRGwithBeta2.Rb2Gs + Bblocked.II * lRGwithBeta2.LRb2Gs;
    lRGwithBeta2.LRb2Gs = lRGwithBeta2.LRb2Gs * (1 - Bblocked.II);

    lRGwithBeta2.Rb2Gi = lRGwithBeta2.Rb2Gi + Bblocked.II * lRGwithBeta2.LRb2Gi;
    lRGwithBeta2.LRb2Gi = lRGwithBeta2.LRb2Gi * (1 - Bblocked.II);
*/
    return lRGwithBeta2;
}

void Mod_GprotAct(Concentration y, double RGsTot_CAV, double LRGsTot_CAV, double Rb2Gi_CAV, double LRb2Gi_CAV,
                  double RG_ECAV, double LRG_ECAV, double Rb2Gi_ECAV, double LRb2Gi_ECAV,
                  double RG_CYT, double LRG_CYT) {
    dy.Gs_aGTP_CAV = RGsTot_CAV * sc.kact2_Gs + LRGsTot_CAV * sc.kact1_Gs - y.Gs_aGTP_CAV * sc.khydr_Gs;
    dy.Gi_aGTP_CAV = Rb2Gi_CAV * sc.kact2_Gi + LRb2Gi_CAV * sc.kact1_Gi - y.Gi_aGTP_CAV * sc.khydr_Gi;

    dy.Gs_aGTP_ECAV = RG_ECAV * sc.kact2_Gs + LRG_ECAV * sc.kact1_Gs - y.Gs_aGTP_ECAV * sc.khydr_Gs;
    dy.Gi_aGTP_ECAV = Rb2Gi_ECAV * sc.kact2_Gi + LRb2Gi_ECAV * sc.kact1_Gi - y.Gi_aGTP_ECAV * sc.khydr_Gi;
    dy.Gs_a_GTP_CYT = RG_CYT * sc.kact2_Gs + LRG_CYT * sc.kact1_Gs - y.Gs_a_GTP_CYT * sc.khydr_Gs;

    dy.Gs_bg_CAV = RGsTot_CAV * sc.kact2_Gs + LRGsTot_CAV * sc.kact1_Gs - y.Gs_bg_CAV * y.Gs_aGDP_CAV * sc.kreas_Gs;
    dy.Gi_bg_CAV = Rb2Gi_CAV * sc.kact2_Gi + LRb2Gi_CAV * sc.kact1_Gi - y.Gi_bg_CAV * y.Gi_aGDP_CAV * sc.kreas_Gi;
    dy.Gs_bg_ECAV = RG_ECAV * sc.kact2_Gs + LRG_ECAV * sc.kact1_Gs - y.Gs_bg_ECAV * y.Gs_aGDP_ECAV * sc.kreas_Gs;
    dy.Gi_bg_ECAV = Rb2Gi_ECAV * sc.kact2_Gi + LRb2Gi_ECAV * sc.kact1_Gi - y.Gi_bg_ECAV * y.Gi_aGDP_ECAV * sc.kreas_Gi;
    dy.Gs_bg_CYT = RG_CYT * sc.kact2_Gs + LRG_CYT * sc.kact1_Gs - y.Gs_bg_CYT * y.Gs_aGDP_CYT * sc.kreas_Gs;

    dy.Gs_aGDP_CAV = y.Gs_aGTP_CAV * sc.khydr_Gs - y.Gs_bg_CAV * y.Gs_aGDP_CAV * sc.kreas_Gs;
    dy.Gi_aGDP_CAV = y.Gi_aGTP_CAV * sc.khydr_Gi - y.Gi_bg_CAV * y.Gi_aGDP_CAV * sc.kreas_Gi;
    dy.Gs_aGDP_ECAV = y.Gs_aGTP_ECAV * sc.khydr_Gs - y.Gs_bg_ECAV * y.Gs_aGDP_ECAV * sc.kreas_Gs;
    dy.Gi_aGDP_ECAV = y.Gi_aGTP_ECAV * sc.khydr_Gi - y.Gi_bg_ECAV * y.Gi_aGDP_ECAV * sc.kreas_Gi;
    dy.Gs_aGDP_CYT = y.Gs_a_GTP_CYT * sc.khydr_Gs - y.Gs_bg_CYT * y.Gs_aGDP_CYT * sc.kreas_Gs;
}

CAMP_AC Mod_AC(Concentration y) {
    CAMP_AC cAMP_AC;

    double kAC56_CAV = (sc.AC56_basal +
                        pow(y.Gs_aGTP_CAV, sc.AC56_hill_Gs) / (sc.AC56_Km_Gs + pow(y.Gs_aGTP_CAV, sc.AC56_hill_Gs)))
                       * (1 - (1 - sc.AC56_V_GsGi * pow(y.Gs_aGTP_CAV, sc.AC56_hill_GsGi) /
                                   (sc.AC56_Km_GsGi + pow(y.Gs_aGTP_CAV, sc.AC56_hill_GsGi))) * y.Gi_bg_CAV /
                              (sc.AC56_Km_Gi + y.Gi_bg_CAV));
    cAMP_AC.dcAMPAC56_CAV = (kAC56_CAV * sc.AC56_CAV * sc.AF56 * sc.ATP) / (sc.KmATP + sc.ATP);

    double kAC56_CYT = (sc.AC56_basal +
                        pow(y.Gs_a_GTP_CYT, sc.AC56_hill_Gs) / (sc.AC56_Km_Gs + pow(y.Gs_a_GTP_CYT, sc.AC56_hill_Gs)))
                       * (1 - (1 - sc.AC56_V_GsGi * pow(y.Gs_a_GTP_CYT, sc.AC56_hill_GsGi) / (sc.AC56_Km_GsGi + pow(y.Gs_a_GTP_CYT, sc.AC56_hill_GsGi))) * 0.0 / (sc.AC56_Km_Gi + 0.0));
    cAMP_AC.dcAMPAC56_CYT = (kAC56_CYT * sc.AC56_CYT * sc.AF56 * sc.ATP) / (sc.KmATP + sc.ATP);

    double kAC47_ECAV = (sc.AC47_basal + pow(y.Gs_aGTP_ECAV, sc.AC47_hill_Gs) / (sc.AC47_Km_Gs + pow(y.Gs_aGTP_ECAV, sc.AC47_hill_Gs)))
                        * (1 + (sc.AC47_Vmax_Gi * pow(y.Gi_bg_ECAV, sc.AC47_hill_Gi)) /
                               (sc.AC47_Km_Gi + pow(y.Gi_bg_ECAV, sc.AC47_hill_Gi)));
    cAMP_AC.dcAMPAC47_ECAV = (kAC47_ECAV * sc.AC47_ECAV * sc.AF47 * sc.ATP) / (sc.KmATP + sc.ATP);

    double kAC47_CYT = sc.AF47 * (sc.AC47_basal + pow(y.Gs_a_GTP_CYT, sc.AC47_hill_Gs) /
                                                  (sc.AC47_Km_Gs + pow(y.Gs_a_GTP_CYT, sc.AC47_hill_Gs)));
    cAMP_AC.dcAMPAC47_CYT = (kAC47_CYT * sc.AC47_CYT * sc.ATP) / (sc.KmATP + sc.ATP);

    return cAMP_AC;
}

double Mod_PDE_Sub(double cAMP, double PDE, double PDEp, double kPDE, double KmPDE) {
    double dcAMP_PDEx_C = kPDE * (PDE + 3.0 * PDEp) * cAMP / (KmPDE + cAMP);
    return dcAMP_PDEx_C;
}

void Mod_Channel_Phosphorylation(Concentration y, double PP1_CYT) {

    //Substrates without AKAP
    dy.fPLB_P = ((sc.k_PKAPLB * y.C_CYT * (1 - y.fPLB_P)) / (sc.Km_PKAPLB + (1 - y.fPLB_P)) -
                 (sc.k_PP1PLB * PP1_CYT * y.fPLB_P) / (sc.Km_PP1PLB + y.fPLB_P));
    dy.fTnI_P = (sc.k_PKATnI * y.C_CYT * (1 - y.fTnI_P)) / (sc.Km_PKATnI + (1 - y.fTnI_P)) -
                (sc.k_PPTnI * sc.PP2A_CYT * y.fTnI_P) / (sc.Km_PPTnI + y.fTnI_P);
    dy.fINa_P = ((sc.k_PKAINa * y.C_CAV * (1 - y.fINa_P)) / (sc.Km_PKAINa + (1 - y.fINa_P)) -
                 (sc.k_PP1INa * sc.PP_CAV * y.fINa_P) / (sc.Km_PP1INa + y.fINa_P));
    dy.fINaK_P = (sc.k_PKAINaK * y.C_CAV * (1 - y.fINaK_P)) / (sc.Km_PKAINaK + (1 - y.fINaK_P)) -
                 (sc.k_PP1INaK * sc.PP_CAV * y.fINaK_P) / (sc.Km_PP1INaK + y.fINaK_P);
    dy.fIKur_P = sc.temp_rate_IKur * ((sc.k_PKAIKur * y.C_ECAV * (1 - y.fIKur_P)) / (sc.Km_PKAIKur + (1 - y.fIKur_P)) -
                                      (sc.k_PPIKur * sc.PP1_ECAV * y.fIKur_P) / (sc.Km_PPIKur + y.fIKur_P));
    //Substrates with AKAP
    dy.fIKS_P = ((sc.k_PKAIKS * y.C_ECAV * (sc.IKs_AKAP_PKA_PP1 - y.fIKS_P)) /
                 (sc.Km_PKAIKS / sc.AKAP_Factor + (sc.IKs_AKAP_PKA_PP1 - y.fIKS_P)))
                - ((sc.k_PP1IKS * sc.PP1_ECAV * y.fIKS_P) / (sc.Km_PP1IKS / sc.AKAP_Factor + y.fIKS_P));
    dy.fLCC_P = sc.temp_rate_LCC * (((sc.k_PKALCC * y.C_CAV * (sc.ICaL_AKAP_PKA_PP - y.fLCC_P)) /
                                     (sc.Km_PKALCC / sc.AKAP_Factor + (sc.ICaL_AKAP_PKA_PP - y.fLCC_P))) -
                                    ((sc.k_PPLCC * sc.PP_CAV * y.fLCC_P) / (sc.Km_PPLCC / sc.AKAP_Factor + y.fLCC_P)));

    dy.fRyR_P = sc.temp_rate_RyR * (((sc.k_PKARyR * y.C_CAV * (sc.RyR_AKAP_PKA_PP - y.fRyR_P)) /
                                     (sc.Km_PKARyR / sc.AKAP_Factor + (sc.RyR_AKAP_PKA_PP - y.fRyR_P)))-
                                    ((sc.k_PPRyR * sc.PP_CAV * y.fRyR_P) / (sc.Km_PPRyR / sc.AKAP_Factor + y.fRyR_P)));

    /*
     * it is a comment from matlab
         if (y.fLCC_P < 0){
             dy.fLCC_P = 0.001;
         }
         if (y.fLCC_P > sc.ICaL_AKAP_PKA_PP){
             dy.fLCC_P = -0.001;
         }
         if (y(46) < 0){
             dy(46) = 0.001;
         }
         if (y.fPLB_P > 1){
            dy.fPLB_P = -0.001;
         }
     */
}

double Mod_PP1_Inhibition(Concentration y) {
    double pp1;
    double I1_tot_CYT = sc.f_PP1_Inh1 / (1 - sc.f_PP1_Inh1) * sc.KI1 + sc.f_PP1_Inh1 * sc.PP1_tot_CYT;

    dy.Inhib1_P_CYT = (sc.kfI1p * y.C_CYT * (I1_tot_CYT - y.Inhib1_P_CYT)) / (sc.KmI1p + (I1_tot_CYT - y.Inhib1_P_CYT)) -
            (sc.kbI1p * sc.PP2A_CYT * y.Inhib1_P_CYT) / (sc.KmI1dp + y.Inhib1_P_CYT);
    pp1 = 0.5 * sqrt(pow((sc.KI1 + y.Inhib1_P_CYT - sc.PP1_tot_CYT), 2) + 4 * sc.PP1_tot_CYT * sc.KI1) +
          0.5 * sc.PP1_tot_CYT - 0.5 * sc.KI1 - 0.5 * y.Inhib1_P_CYT;

    return pp1;
}

void Mod_PDE_Phosphorylation(Concentration y) {
 //   PDE3_CAV = data.f_PDE3_CAV * data.PDE3_tot * (data.V_tot / data.V_CAV);         %Note f_PDE3_ECAV = 0;
    double PDE3_CAV = sc.f_PDE3_CAV * sc.PDE3_tot * (V.tot_per_cav);         //Note f_PDE3_ECAV = 0;
    //PDE3_CYT = (1 - data.f_PDE3_CAV) * data.PDE3_tot * (data.V_tot / data.V_CYT);
    double PDE3_CYT = (1 - sc.f_PDE3_CAV) * sc.PDE3_tot * (V.tot_per_cyt);

//  PDE4_CAV = data.f_PDE4_CAV * data.PDE4_tot * (data.V_tot / data.V_CAV);
    double PDE4_CAV = sc.f_PDE4_CAV * sc.PDE4_tot * (V.tot_per_cav);
    //PDE4_ECAV = data.f_PDE4_ECAV * data.PDE4_tot * (data.V_tot / data.V_ECAV);
    double PDE4_ECAV = sc.f_PDE4_ECAV * sc.PDE4_tot * (V.tot_per_ecav);
    //PDE4_CYT = (1 - data.f_PDE4_CAV - data.f_PDE4_ECAV) * data.PDE4_tot * (data.V_tot / data.V_CYT);
    double PDE4_CYT = (1 - sc.f_PDE4_CAV - sc.f_PDE4_ECAV) * sc.PDE4_tot * (V.tot_per_cyt);


    double kbPDEp = sc.KPDEp * sc.kfPDEp;
    dy.PDE3_P_CAV = sc.kfPDEp * y.C_CAV * (PDE3_CAV - y.PDE3_P_CAV) - kbPDEp * y.PDE3_P_CAV;
    dy.PDE3_P_CYT = sc.kfPDEp * y.C_CYT * (PDE3_CYT - y.PDE3_P_CYT) - kbPDEp * y.PDE3_P_CYT;
    dy.PDE4_P_CAV = sc.kfPDEp * y.C_CAV * (PDE4_CAV - y.PDE4_P_CAV) - kbPDEp * y.PDE4_P_CAV;
    dy.PDE4_P_ECAV = sc.kfPDEp * y.C_ECAV * (PDE4_ECAV - y.PDE4_P_ECAV) - kbPDEp * y.PDE4_P_ECAV;
    dy.PDE4_P_CYT = sc.kfPDEp * y.C_CYT * (PDE4_CYT - y.PDE4_P_CYT) - kbPDEp * y.PDE4_P_CYT;
}

PKA Mod_PKA(Concentration y) {
    PKA pka;
    double PKAcav = sc.f_PKA_CAV * sc.PKA_tot * (V.tot_per_cav);
    double PKAecav = sc.f_PKA_ECAV * sc.PKA_tot * (V.tot_per_ecav);
    double PKAcyt = (1 - sc.f_PKA_CAV - sc.f_PKA_ECAV) * sc.PKA_tot * (V.tot_per_cyt);

    double PKIcav = sc.f_PKI_CAV * sc.PKI_tot * (V.tot_per_cav);
    double PKIecav = sc.f_PKI_ECAV * sc.PKI_tot * (V.tot_per_ecav);
    double PKIcyt = (1 - sc.f_PKI_CAV - sc.f_PKI_ECAV) * sc.PKI_tot * (V.tot_per_cyt);

    double kPKAb1 = sc.k_PKA_f1 * sc.K_PKAII_1;
    double kPKAb2 = sc.k_PKA_f2 * sc.K_PKAII_2;
    double kPKAb3 = sc.k_PKA_f3 * sc.K_PKAII_3;
    double kPKAbpki = sc.k_PKA_fPKI * sc.K_PKA_PKI;

    // CAV Compartment
    double cAMP = y.cAMP_CAV;
    double LRC = y.RLC_CAV;
    double L2RC = y.L2RC_CAV;
    double L2R = y.L2R_CAV;
    double C = y.C_CAV;
    double PKIC = y.PKI_CAV;
    double RC = PKAcav - LRC - L2RC - L2R;
    double PKI = PKIcav - PKIC;

    pka.dcAMP_PKA_CAV = -sc.k_PKA_f1 * RC * cAMP + kPKAb1 * LRC - sc.k_PKA_f2 * LRC * cAMP + kPKAb2 * L2RC;
    dy.RLC_CAV = sc.k_PKA_f1 * RC * cAMP - kPKAb1 * LRC + kPKAb2 * L2RC - sc.k_PKA_f2 * LRC * cAMP;
    dy.L2RC_CAV = sc.k_PKA_f2 * LRC * cAMP - kPKAb2 * L2RC - sc.k_PKA_f3 * L2RC + kPKAb3 * L2R * C;
    dy.L2R_CAV = sc.k_PKA_f3 * L2RC - kPKAb3 * L2R * C;
    dy.C_CAV = sc.k_PKA_f3 * L2RC - kPKAb3 * L2R * C + kPKAbpki * PKIC - sc.k_PKA_fPKI * PKI * C;
    dy.PKI_CAV = -kPKAbpki * PKIC + sc.k_PKA_fPKI * PKI * C;

    // ECAV Compartment
    cAMP = y.cAMP_ECAV;
    LRC = y.RLC_ECAV;
    L2RC = y.L2RC_ECAV;
    L2R = y.L2R_ECAV;
    C = y.C_ECAV;
    PKIC = y.PKI_ECAV;
    RC = PKAecav - LRC - L2RC - L2R;
    PKI = PKIecav - PKIC;

    pka.dcAMP_PKA_ECAV = -sc.k_PKA_f1 * RC * cAMP + kPKAb1 * LRC - sc.k_PKA_f2 * LRC * cAMP + kPKAb2 * L2RC;
    dy.RLC_ECAV = sc.k_PKA_f1 * RC * cAMP - kPKAb1 * LRC + kPKAb2 * L2RC - sc.k_PKA_f2 * LRC * cAMP;
    dy.L2RC_ECAV = sc.k_PKA_f2 * LRC * cAMP - kPKAb2 * L2RC - sc.k_PKA_f3 * L2RC + kPKAb3 * L2R * C;
    dy.L2R_ECAV = sc.k_PKA_f3 * L2RC - kPKAb3 * L2R * C;
    dy.C_ECAV = sc.k_PKA_f3 * L2RC - kPKAb3 * L2R * C + kPKAbpki * PKIC - sc.k_PKA_fPKI * PKI * C;
    dy.PKI_ECAV = -kPKAbpki * PKIC + sc.k_PKA_fPKI * PKI * C;

    // CYT Compartment
    kPKAb1 = sc.k_PKA_f1 * sc.K_PKAI_1;
    kPKAb2 = sc.k_PKA_f2 * sc.K_PKAI_2;
    kPKAb3 = sc.k_PKA_f3 * sc.K_PKAI_3;
    kPKAbpki = sc.k_PKA_fPKI * sc.K_PKA_PKI;

    cAMP = y.cAMP_CYT;
    LRC = y.RLC_CYT;
    L2RC = y.L2RC_CYT;
    L2R = y.L2R_CYT;
    C = y.C_CYT;
    PKIC = y.PKI_CYT;
    RC = PKAcyt - LRC - L2RC - L2R;
    PKI = PKIcyt - PKIC;

    pka.dcAMP_PKA_CYT = -sc.k_PKA_f1 * RC * cAMP + kPKAb1 * LRC - sc.k_PKA_f2 * LRC * cAMP + kPKAb2 * L2RC;
    dy.RLC_CYT = sc.k_PKA_f1 * RC * cAMP - kPKAb1 * LRC + kPKAb2 * L2RC - sc.k_PKA_f2 * LRC * cAMP;
    dy.L2RC_CYT = sc.k_PKA_f2 * LRC * cAMP - kPKAb2 * L2RC - sc.k_PKA_f3 * L2RC + kPKAb3 * L2R * C;
    dy.L2R_CYT = sc.k_PKA_f3 * L2RC - kPKAb3 * L2R * C;
    dy.C_CYT = sc.k_PKA_f3 * L2RC - kPKAb3 * L2R * C + kPKAbpki * PKIC - sc.k_PKA_fPKI * PKI * C;
    dy.PKI_CYT = -kPKAbpki * PKIC + sc.k_PKA_fPKI * PKI * C;

    return pka;
}

void Mod_cAMP(Concentration y, PKA pka, CAMP_AC cAMP_AC) {

    double PDE2_CAV = sc.f_PDE2_CAV * sc.PDE2_tot * (V.tot_per_cav);
    double PDE2_ECAV = sc.f_PDE2_ECAV * sc.PDE2_tot * (V.tot_per_ecav);
    double PDE2_CYT = (1 - sc.f_PDE2_CAV - sc.f_PDE2_ECAV) * sc.PDE2_tot * (V.tot_per_cyt);

    double PDE3_CAV = sc.f_PDE3_CAV * sc.PDE3_tot * (V.tot_per_cav);         //Note f_PDE3_ECAV = 0;
    double PDE3_CYT = (1 - sc.f_PDE3_CAV) * sc.PDE3_tot * (V.tot_per_cyt);

    double PDE4_CAV = sc.f_PDE4_CAV * sc.PDE4_tot * (V.tot_per_cav);
    double PDE4_ECAV = sc.f_PDE4_ECAV * sc.PDE4_tot * (V.tot_per_ecav);
    double PDE4_CYT = (1 - sc.f_PDE4_CAV - sc.f_PDE4_ECAV) * sc.PDE4_tot * (V.tot_per_cyt);

    double dCAMP_PDEs[] = {
            Mod_PDE_Sub(y.cAMP_CAV, PDE2_CAV, 0, sc.kPDE2, sc.KmPDE2),
            Mod_PDE_Sub(y.cAMP_CAV, PDE3_CAV - y.PDE3_P_CAV, y.PDE3_P_CAV, sc.kPDE3, sc.KmPDE3),
            Mod_PDE_Sub(y.cAMP_CAV, PDE4_CAV - y.PDE4_P_CAV, y.PDE4_P_CAV, sc.kPDE4, sc.KmPDE4),
            Mod_PDE_Sub(y.cAMP_ECAV, PDE2_ECAV, 0, sc.kPDE2, sc.KmPDE2),
            Mod_PDE_Sub(y.cAMP_ECAV, PDE4_ECAV - y.PDE4_P_ECAV, y.PDE4_P_ECAV, sc.kPDE4, sc.KmPDE4),
            Mod_PDE_Sub(y.cAMP_CYT, PDE2_CYT, 0, sc.kPDE2, sc.KmPDE2),
            Mod_PDE_Sub(y.cAMP_CYT, PDE3_CYT - y.PDE3_P_CYT, y.PDE3_P_CYT, sc.kPDE3, sc.KmPDE3),
            Mod_PDE_Sub(y.cAMP_CYT, PDE4_CYT - y.PDE4_P_CYT, y.PDE4_P_CYT, sc.kPDE4, sc.KmPDE4)
    };

    dy.cAMP_CAV = pka.dcAMP_PKA_CAV + sc.rate_camp * (cAMP_AC.dcAMPAC56_CAV - (dCAMP_PDEs[0] + dCAMP_PDEs[1] + dCAMP_PDEs[2])) -
                  sc.J_CAV_ECAV * ((y.cAMP_CAV - y.cAMP_ECAV) / V.cav) - sc.J_CAV_CYT * ((y.cAMP_CAV - y.cAMP_CYT) / V.cav);
    dy.cAMP_ECAV = pka.dcAMP_PKA_ECAV + sc.rate_camp * (cAMP_AC.dcAMPAC47_ECAV - (dCAMP_PDEs[3] + dCAMP_PDEs[4])) +
                   sc.J_CAV_ECAV * ((y.cAMP_CAV - y.cAMP_ECAV) / V.ecav)
                   - sc.J_ECAV_CYT * ((y.cAMP_ECAV - y.cAMP_CYT) / V.ecav);
    dy.cAMP_CYT = pka.dcAMP_PKA_CYT + sc.rate_camp * (cAMP_AC.dcAMPAC47_CYT + cAMP_AC.dcAMPAC56_CYT -
                    (dCAMP_PDEs[5] + dCAMP_PDEs[6] + dCAMP_PDEs[7])) + sc.J_CAV_CYT *((y.cAMP_CAV -y.cAMP_CYT) /V.cyt) +
                            sc.J_ECAV_CYT * ((y.cAMP_ECAV - y.cAMP_CYT) / V.cyt);
}

Concentration funSignalling(Concentration y) {
    dy = Concentration();

    double Gs_abg_CAV = sc.f_Gs_CAV * sc.Gs_tot * (V.tot_per_cav) - y.Gs_aGTP_CAV - y.Gs_aGDP_CAV;
    double Gi_abg_CAV = sc.f_Gi_CAV * sc.Gi_tot * (V.tot_per_cav) - y.Gi_aGTP_CAV - y.Gi_aGDP_CAV;

    double R_b1_comp = sc.f_Rb1_CAV * sc.R_b1_tot * (V.tot_per_cav);
    double R_b2_comp = sc.f_Rb2_CAV * sc.R_b2_tot * V.tot_per_cav;

    LigRecepGprotWithBeta2 lGCPRwithBeta2_CAV = Mod_LigRecepGprotWithBeta2(R_b1_comp, y.R_pkap_tot_CAV,
                                                                           y.R_grkp_tot_CAV, R_b2_comp,
                                                                           y.Rb2_pkap_tot_CAV,
                                                                           y.Rb2_grkp_tot_CAV, Gs_abg_CAV, Gi_abg_CAV,
                                                                           y.C_CAV, sc.GRK_CAV);
    dy.R_pkap_tot_CAV = lGCPRwithBeta2_CAV.dRb1_pkap_tot;

    dy.R_grkp_tot_CAV = lGCPRwithBeta2_CAV.dRb1_grkp_tot;

    dy.Rb2_pkap_tot_CAV = lGCPRwithBeta2_CAV.dRb2_pkap_tot;

    dy.Rb2_grkp_tot_CAV = lGCPRwithBeta2_CAV.dRb2_grkp_tot;

    double Gs_abg_ECAV = (sc.f_Gs_ECAV * sc.Gs_tot * (V.tot_per_ecav)) - y.Gs_aGTP_ECAV - y.Gs_aGDP_ECAV;
    double Gi_abg_ECAV = ((1 - sc.f_Gi_CAV) * sc.Gi_tot * (V.tot_per_ecav)) - y.Gi_aGTP_ECAV - y.Gi_aGDP_ECAV;

    R_b1_comp = sc.f_Rb1_ECAV * sc.R_b1_tot * (V.tot_per_ecav);
    R_b2_comp = sc.f_Rb2_ECAV * sc.R_b2_tot * (V.tot_per_ecav);

    LigRecepGprotWithBeta2 lGCPRwithBeta2_ECAV = Mod_LigRecepGprotWithBeta2(R_b1_comp, y.R_pkap_tot_ECAV,
                                                                            y.R_grkp_tot_ECAV, R_b2_comp,
                                                                            y.Rb2_pkap_tot_ECAV, y.Rb2_grkp_tot_ECAV,
                                                                            Gs_abg_ECAV, Gi_abg_ECAV, y.C_ECAV,
                                                                            sc.GRK_ECAV);
    dy.R_pkap_tot_ECAV = lGCPRwithBeta2_ECAV.dRb1_pkap_tot;
    dy.R_grkp_tot_ECAV = lGCPRwithBeta2_ECAV.dRb1_grkp_tot;
    dy.Rb2_pkap_tot_ECAV = lGCPRwithBeta2_ECAV.dRb2_pkap_tot;
    dy.Rb2_grkp_tot_ECAV = lGCPRwithBeta2_ECAV.dRb2_grkp_tot;

    double Gs_f_CYT = ((1 - sc.f_Gs_CAV - sc.f_Gs_ECAV) * sc.Gs_tot * (V.tot_per_cyt)) - y.Gs_a_GTP_CYT - y.Gs_aGDP_CYT;
    double R_comp = (1 - sc.f_Rb1_CAV - sc.f_Rb1_ECAV) * sc.R_b1_tot * (V.tot_per_cyt);
    LigRecepGprot ligRecepGprot = Mod_LigRecepGprot(R_comp, y.R_pkap_tot_CYT, y.R_grkp_tot_CYT, L, Gs_f_CYT, y.C_CYT,
                                                    sc.GRK_CYT);

    dy.R_pkap_tot_CYT = ligRecepGprot.dR_pkap_tot;
    dy.R_grkp_tot_CYT = ligRecepGprot.dR_grkp_tot;

    Mod_GprotAct(y, lGCPRwithBeta2_CAV.Rb1Gs + sc.k_GsAct_b2 * lGCPRwithBeta2_CAV.Rb2Gs,
             lGCPRwithBeta2_CAV.LRb1Gs + sc.k_GsAct_b2 * lGCPRwithBeta2_CAV.LRb2Gs,
             lGCPRwithBeta2_CAV.Rb2Gi, lGCPRwithBeta2_CAV.LRb2Gi,

             lGCPRwithBeta2_ECAV.Rb1Gs + sc.k_GsAct_b2 * lGCPRwithBeta2_ECAV.Rb2Gs, //RG_ECAV
             lGCPRwithBeta2_ECAV.LRb1Gs + sc.k_GsAct_b2 * lGCPRwithBeta2_ECAV.LRb2Gs, //LRG_ECAV

             lGCPRwithBeta2_ECAV.Rb2Gi, lGCPRwithBeta2_ECAV.LRb2Gi, ligRecepGprot.RG, ligRecepGprot.LRG);

    CAMP_AC cAMP_AC = Mod_AC(y);
    PKA pka = Mod_PKA(y);
    Mod_cAMP(y, pka, cAMP_AC);
    Mod_PDE_Phosphorylation(y);
    double pp1 = Mod_PP1_Inhibition(y);
    Mod_Channel_Phosphorylation(y, pp1);

    return dy;
}



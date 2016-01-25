#include <iostream>
#include "beta.h"
#include "complex.h"


using namespace std;
/*
struct settings{

    int applyVoltageClamp = 0;
    int vcRate = -100;
    int runSignalingPathway = 1;
    int runElectrophysiol = 1;
    float APDRepLevel = 0.95;
    int showProgress = 1;
    int bcl = 1000;
    int freq = 10;
    int LastBCL = 10; //settings.freq, always
    int storeLast = NAN;
    float K_o = 5.4;
    float Ca_o = 1.8;
    int Na_o = 140;
    int Cl_o = 100;
    int Istim = -80;
    float stimdur = 0.5;


    double IKsNPParams[22] = {7.3990e-003,3.1196e-002,8.0019e-001,5.6992e-003,4.1520e-002,1.3489e+000,3.8839e-001,-1.5019e-001,6.0693e-001,9.0654e-002,-1.1157e-001,2.8330e-002,3.1124e-003,-5.1660e-002,1.5522e+000,2.7304e-003,4.4198e-004,-1.2022e+000,4.0173e-004,2.0873e-004,1.9561e-001};
    double IKsPParams[21] =  {9.9415e-003,4.4809e-002,5.8172e-001,3.3201e-003,9.4217e-002,9.5364e-001,5.6356e-001,-1.7986e-001,
                            5.8381e-001,6.5700e-002,-1.1899e-001,1.2406e-002,3.8525e-004,-6.4118e-002,7.7992e-001,4.6171e-003,
                            2.3730e-004,-1.9742e+000,2.2652e-004,2.4689e-004,1.9561e-001};
   double LCCNPParams[36] = {0.59,0.8,0.052,13,0.132,13.56,9.45,70,49.1,10.349,26.553,0.213,10.807,17.5,3,0.2474,13.825,6.3836,0.001,
                           14.9186,1E-6,1.552E-4,1.1E-3,3.3696,1.2E-2};
   double LCCPParams[35] = {0.59,0.8,0.052,13,0.132,-4.7980,7.5699,70,49.1,10.349,38.494,0.213,10.807,29.979,3.1775,0.1,32.5,18.0,
                          0.0001,6.0,1E-6,2.579E-04,0.002,10,0.01};
   double INaNPParams[29] = {2.15*8.25*1.1, 0.13, 10.66+16.7434, -11.1, 0.3, -2.535E-7, -0.1, 32, 0.135, 80+7, -6.8, 3.56, 0.079,
                              3.1E5, 0.35, -1.2714E5, 0.2444, -6.948E-5, -0.04391, 37.78, 0.311, 79.23, 0.1212, -0.01052, -0.1378,
                              40.14, -47.1-11.3729, -13.7299, -7};
   double RyRP_Amp = 1.9925;
   double RyRP_Tau = 0.5357;
   int TauTr = 75;
   int observeICaLSS = 0;

    float ICaLB = 0.0;
    float IKsB = 0.0;
    float IKrB = 0.0;
    float INaKB =0.0;
    float INaCaB = 0.0;
    float IKpB = 0.0;
    float IK1B = 0.0;
    float INabB = 0.0;
    float ITo1B = 0.0;
    float ITo2B = 0.0;
    float INaB = 0.0;
    float INaLB = 0.0;
    float IClB = 0.0;
    float IpCaB = 0.0;
    float CTKClB = 0.0;
    float CTNaClB = 0.0;
    float ICabB = 0.0;
    float IrelB = 0.0;
    float IupB = 0.0;
    float ItrB = 0.0;
    float IleakB = 0.0;
    float IdiffB = 0.0;
    int CAMKIIB = 0;
};

struct data{

};

 */
const double dt = 3e-4;
const double MAX_TIME = 300;

//verified by Zoya Kiyan 14.10
Concentration getY0(){
    Concentration y0;
    y0.Gs_aGTP_CAV = 0.00685041638458665;
    y0.Gs_aGTP_ECAV = 0.0184627603007976;
    y0.Gs_a_GTP_CYT = 0.000731420577213056;
    y0.Gs_bg_CAV = 0.00745773247314215;
    y0.Gs_bg_ECAV = 0.0191017987408719;
    y0.Gs_bg_CYT = 0.00115141243826747;
    y0.Gs_aGDP_CAV = 0.000607316088556676;
    y0.Gs_aGDP_ECAV = 0.000639038440072507;
    y0.Gs_aGDP_CYT = 0.000419991861054322;
    y0.cAMP_CAV = 0.347102959606005;
    y0.cAMP_ECAV = 9.62359241535767;
    y0.cAMP_CYT = 0.474081735738211;
    y0.R_pkap_tot_CAV = 0.0149041813757831;
    y0.R_pkap_tot_ECAV = 0.203016833596288;
    y0.R_pkap_tot_CYT = 0.00944463350378086;
    y0.R_grkp_tot_CAV = 2.49592854373432e-10;
    y0.R_grkp_tot_ECAV = 1.18055788874765e-09;
    y0.R_grkp_tot_CYT = 7.07824478944671e-11;

    y0.RLC_CAV = 0.0904820284659604;
    y0.L2RC_CAV = 0.00276490711096605;
    y0.L2R_CAV = 0.225475702283053;
    y0.C_CAV = 0.0326565916584703;
    y0.PKI_CAV = 0.192819110624505;
    y0.RLC_ECAV = 0.205444874210056;
    y0.L2RC_ECAV = 0.174057375932567;
    y0.L2R_ECAV = 0.817161796756964;
    y0.C_ECAV = 0.567249910261073;
    y0.PKI_ECAV = 0.249911886495890;
    y0.RLC_CYT = 0.0646928309115710;
    y0.L2RC_CYT = 0.0664997605558791;
    y0.L2R_CYT = 0.489063888619456;
    y0.C_CYT = 0.362113356111496;
    y0.PKI_CYT = 0.126950532507959;

    y0.PDE3_P_CAV = 0.0236821659448037;
    y0.PDE3_P_CYT = 0.0128402905095188;
    y0.PDE4_P_CAV = 0.00637363047239019;
    y0.PDE4_P_ECAV = 4.29171113639322e-05;
    y0.PDE4_P_CYT = 0.00917039986149184;

    y0.Inhib1_P_CYT = 0.0282662056977524;

    y0.fLCC_P = 0.000673713947839317;
    y0.fIKS_P = 0.000765988420110534;
    y0.fPLB_P = 0.592167467082831;
    y0.fTnI_P = 0.673518785672382;
    y0.fINa_P = 0.239479458960528;
    y0.fINaK_P = 0.126345311579566;
    y0.fRyR_P = 0.00410693810508171;
    y0.fIKur_P = 0.0589379755147718;

    y0.Rb2_pkap_tot_CAV = 0.0275455839709412;
    y0.Rb2_grkp_tot_CAV = 8.91799633266019e-10;
    y0.Gi_aGTP_CAV = 0.00159632196638178;
    y0.Gi_bg_CAV = 0.00209911481235842;
    y0.Gi_aGDP_CAV = 0.000502792845976641;
    y0.Rb2_pkap_tot_ECAV = 0.0110248953370551;
    y0.Rb2_grkp_tot_ECAV = 1.13428924662652e-10;
    y0.Gi_aGTP_ECAV = 0.000364315164237569;
    y0.Gi_bg_ECAV = 0.000705656306851923;
    y0.Gi_aGDP_ECAV = 0.000341341142614041;

    return y0;
}



int main() {
    double time = 0;
    Concentration y = getY0();
    FilesForConcentration f;
    f.open();
    f.print(time,y);

    int i = 0;
    while (time <= MAX_TIME) {
        if (i%25 == 0) {
            printf("t = %e \n", time);
        }
        y = sum(y, multiply(funSignalling(y), dt));
        time += dt;
        ++ i;
        f.print(time,y);
    }
    f.close();

    return 0;
}

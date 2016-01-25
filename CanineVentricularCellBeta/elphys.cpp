//
// Created by sokian on 15.09.15.
//

///*
////General parameters zone
//double ageo  = 2*3.14*a*a+2*pi*a*l,
//        Acap= ageo*2;
//double vmyo = vcell * 0.678;     //Myoplasm volume (uL)
//double vsr = vcell * 0.06;       //SR volume (uL)
//double vnsr = vcell * 0.0552;    // NSR volume (uL)
//double vjsr =  vcell * 0.0048;    //JSR volume (uL)
//double vss = vcell * 0.02;        //Subspace volume (uL)
//double vssCaL = vcell * 0.002; //L-type subspace volume (uL)
//double AF = Acap / F;
//
//// Sodium
//double GNa = 9.075,
//        GNaL = 65e-4;
//double KmCa = 1.25e-4;     // Na-Ca Exchanger Current
//double NCXmax = 4.5,    ksat = 0.32,
//        eta = 0.27,     KmNai = 12.3,
//        KmNao = 87.5,   KmCai = 0.0036,
//        KmCao = 1.3;
//
//// Calcium
//double ibarpca =0.0575; // Max. Ca current through sarcolemmal Ca pump (uA/uF)
//double kmpca = 5e-4;    // Half-saturation concentration of sarcolemmal Ca pump (mM)
//double gcab=1.995084e-7; // ICab
//
//double k_JSR_Leak = 1.75E-04;
//double k_JSR_Leak_P = 5.0E-04;
//double Km_JSR_Leak = 20;
//double Km_JSR_Leak_P = 1.1;
//
//double cmdnbar = 0.050;   //Buffer constants
//double trpnbar = 0.070;
//double kmcmdn = 0.00238;
//double kmtrpn = 0.0005;
//double kmcsqn=0.8;
//double csqnbar=10;
//double BSRmax=0.047; double KmBSR=0.00087;
//double BSLmax=1.124; double KmBSL=0.0087;
//
//double KmCaMK=0.25;       // Iup
//double iupmax=0.004375;
//double Kmup=0.00092;
//double nsrmax=15.0;
//
//double dKmPLBCAMK = 0.00017;
//double dKmPLBPKA = 0.46 * Kmup;
//double dKmPLBBoth = dKmPLBPKA;
//double dJupmax=0.75;
//
//double CaMK0=0.05;        // CAMKII signaling
//double Km=1.5e-3;
//double betaCamK=6.8e-4;
//double alphaCamK=0.05;
//
//double tau_PLB_CaMKII = 100000;
//double tau_RyR_CaMKII = 10000;
//
//// Potassium
//double GK1max = 0.5;
//double GKpmax = 3.84E-03; //2.76E-3; ? commentarium from matlab' code
//double GKrmax = 0.0138542;
//double prnak=0.01833;     // IKs sodium / potassium permeability ratio
//
//double kmnai_NP = 2.6;    // Half-saturation concentration of NaK pump (mM)
//double kmnai_P = 1.846;   // Half-saturation concentration of NaK pump (mM)
//double kmko = 1.5;        // Half-saturation concentration of NaK pump (mM)
//double ibarnak = 1.4;     // Max. current through Na-K pump (uA/uF)
//
//double gitodv = 0.4975;   // ITo1
//
//// Chloride
//// ================================================
//double Kmto2=0.1502;      // ITo2
//double PCl=9e-7;
//double GClb=2.25e-4;      // IClb
//
//double CTKClmax=1.77E-5;
//double CTNaClmax=2.46108E-5;
//
//
////dfun zone <- settings?
////TODO:
//double* dy(double t,double y[]){ //в matlab там также были flags and settings
//    function dy = dfun_Electrophysiol(t, y, flags, settings)
//  /*      % The new Electrophysiological state vector looks as follows:
//        %   1  Vm           2  Ca_i
//        %   3  Ca_ss        4  Ca_ssCaL
//        %   5  Ca_JSR       6  Ca_NSR
//        %   7  Ca_trap      8  Na_i
//        %   9  Na_ss       10  K_i
//        %  11  Cl_i        12  Cl_ss
//        %  13  Irel        14  H
//        %  15  m           16  J
//        %  17  mL          18  hL
//        %  19  to_a        20  to_if
//        %  21  to_is       22  xr
//        %  23  AA
//        %
//        %  24 - 31 ICaL Markov states (NP)
//        %  32 - 48 IKs Markov states (NP)
//        %  49 - 56 ICaL Markov states (P)
//        %  57 - 73 IKs Markov states (P)
//        %  74  H (P)         75  m (P)
//        %  76  J (P)         77  m (P, CAMKII)
//        %  78  h (P, CAMKII) 79  J (P, CAMKII)
//        %  80  IRel (P)
//        %  81  to_if_CaMKII  82  to_is_CaMKII
//        %  83  fPLBP_CaMKII  84  fRyRP_CaMKII
//        %  85  fIToP_CaMKII  86  fINaP_CaMKII
//        %  87  fIK1P_CaMKII  88  fICaLP_CaMKII
//*/
//}
////TODO:
//double* dyt_INa(double y, double Cactive){
//
//}
//
////TODO:
//double* dyt_INaL(double y, double Cactive){
//
//}
////TODO:
//double* dyt_INaCa_INaCass(double y){
//
//}
//
////TODO:
//double* dyt_INaK(double y){
//
//}
//
////TODO:
//double* dyt_INab(double y){ }
//
////TODO:
//double* dyt_IK1(double y){ }
//
////TODO:
//double* dyt_IKp(double y){}
//
////TODO:
//double dyt_IKr(double y){}
//
////TODO:
//double dyt_ITo1(double y, double Cactive){}
//
////TODO:
//double dyt_CTNaCl_CTKCl_IClb_Ito2(double y){}
//
////TODO:
//double dyt_IKs(double y){}
//
////TODO:
//double dyt_ICaL_ICaLNP_ICaLP(double y,double Cactive){}
//
////TODO:
//double* dyt_Ileak_Iup_IpCa_ICab_Itr_IdiffssCaL_IdiffCa_IdiffNa_IdiffCl(double y, Cactive){}
//
////TODO:
//double dyt(double y,double ICaL,double ICab,double IpCa,double INa,double INaL,double INaCa,double INaCass,double INaK,double INab,double IClb,
//           double Ito2,double Iup,double Ileak,double Itr,double Idiff_Ca,double Idiff_ssCaL,double Idiff_Na,double Idiff_Cl,double CTNaCl,
//           double CTKCl,double  IKtot,double  Ileak_JSR){}
//
//double* dyt_IleakJSR(double y,double ICaL){}
//
////TODO:
//double Ca_CaMKII(double y){
//    //Ctrap = y(7);
//    //cass = y(3);
////    Cactive = (1 - CAMKIIB) * data.CaMK0*(1-Ctrap)/(1 + Km/cass)+Ctrap;
//}
//
////TODO:
//double Buff_Ca_i(double ca_t) {
//    //    kmtrpn = (1 - settings.fTnIP) * data.kmtrpn + settings.fTnIP * 1.5 * data.kmtrpn;
//   // double kmtrp = (1 -
//
//    //bmyo = data.cmdnbar+data.trpnbar-ca_t+kmtrpn+data.kmcmdn;
//    //cmyo = data.kmcmdn*kmtrpn -ca_t*(kmtrpn+data.kmcmdn)+data.trpnbar*data.kmcmdn+data.cmdnbar*kmtrpn;
//    //dmyo = -kmtrpn*data.kmcmdn*ca_t;
//
//    //cai =( 2*(bmyo.*bmyo-3*cmyo).^(1/2)/3).*cos(acos((9*bmyo.*cmyo-2*bmyo.*bmyo.*bmyo-27*dmyo)./(2*(bmyo.*bmyo-3*cmyo).^1.5))/3)-(bmyo/3);
//   // return cai;
//}
//
//double Buff_Ca_jsr(double  ca_t){
////    b=data.csqnbar+data.kmcsqn-ca_t;
//    double b = csqnbar + kmcsqn - ca_t;
////    c=ca_t*data.kmcsqn;
//    double c = ca_t * kmcsqn;
////    cajsr=-b/2+(b.^2+4*c).^(1/2)/2;
//    double cajsr = - b/2 + pow(b*b + 4*c, 0.5) / 2;
//    return cajsr;
//}
//
//double Buff_Ca_ss(double ca_t){
////    bmyo = data.BSLmax+data.BSRmax-ca_t+data.KmBSR+data.KmBSL;
//    double bmyo = BSLmax + BSRmax - ca_t + KmBSR + KmBSL;
////    cmyo = data.KmBSL*data.KmBSR -ca_t*(data.KmBSR+data.KmBSL)+data.BSRmax*data.KmBSL+data.BSLmax*data.KmBSR;
//    double cmyo = KmBSL * KmBSR - ca_t * (KmBSR + KmBSL) + BSRmax * KmBSL + BSLmax * KmBSR;
////    dmyo = -data.KmBSR*data.KmBSL*ca_t;
//    double dmyo = - KmBSR * KmBSL * ca_t;
//
//    //cass =( 2*(bmyo.*bmyo-3*cmyo).^(1/2)/3).*cos(acos((9*bmyo.*cmyo-2*bmyo.*bmyo.*bmyo-27*dmyo)./(2*(bmyo.*bmyo-3*cmyo).^1.5))/3)-(bmyo/3);
//    //TODO: be careful with power and dots!!!
//    double cass = 2* pow((bmyo*bmyo - 3*cmyo),0.5)/3 * cos(acos((9*bmyo * cmyo - 2*bmyo * bmyo * bmyo - 27 * dmyo)/(2*pow(bmyo * bmyo - 3 * cmyo, 1.5))/3)- bmyo/3;
//    return cass;
//}
//













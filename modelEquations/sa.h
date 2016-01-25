// Basic Variables and Descriptions
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

#include <math.h>
#include <stdio.h>

typedef double REAL;

FILE *E;                                     // Potential
FILE *m, *h, *j;                               // Activation and Inactivation Components for Fast Na Current
FILE *xkr, *xks;                              // Components of Rapidly Activating K Current
FILE *xtos, *ytos, *xtof, *ytof;                // Slow and Fast Components for Transient Outward K Current
FILE *d, *f;                                  //
FILE *fCaBJunc, *fCaBSl;                      //
FILE *Csqnb;                                 // SR Calcium Buffer
FILE *RyRr, *RyRo, *RyRi;                      //
FILE *NaJ, *NaSl, *Nai, *CaJ, *CaSl, *Cai, *CaSR;  // Na and Ca Concentrations
FILE *NaBj, *NaBSl;

FILE *ItoSlow, *ItoFast, *Iks, *Iki, *INaKJunc, *INaKJuncPlusINaKSl, *INaKSl, *IncxJunc, *IncxSl,*IncxJuncPlusIncxSl;
FILE *INaBkJunc, *INaBkSl, *ICaBkJunc, *ICaBkSl, *ICaJunc, *ICaSl, *ICaK, *ICaNaJunc, *ICaNaSl,
        *INaTotJunc, *INaTotSl,*ICaTotJunc, *ICaTotSl, *Ikr, *Ikp, *IClCa, *IBgCl;

FILE *inafile, *ICaNa, *INaK;

FILE *Iepi, *Iendo, *Ikl, *icalfile;

FILE *gkrf, *rkrf, *tauxkr, *xkrf, *xkr1f, *xrssf;


//for iki
FILE *aki, *bki,*kiss;

//for ical
FILE *Dss, *Fss,*Td,*Tf, *icaj, *icas, *inaj, *inas, *ik;


struct State
{
    REAL E;                                     // Potential
    REAL m, h, j;                                // Activation and Inactivation Components for Fast Na Current
    REAL xkr, xks;                              // Components of Rapidly Activating K Current
    REAL xtos, ytos, xtof, ytof;                // Slow and Fast Components for Transient Outward K Current
    REAL d, f;                                  //
    REAL fCaBJunc, fCaBSl;                      //
    REAL Csqnb;                                 // SR Calcium Buffer
    REAL RyRr, RyRo, RyRi;                      //
    REAL NaJ, NaSl, Nai, CaJ, CaSl, Cai, CaSR;  // Na and Ca Concentrations
    REAL NaBj, NaBSl;                           // Na Buffers Concentrations
} CurrentState, NextState;

struct Cpar
{
    REAL GNa, GNaB, GClB, GCaB, Gkp, GksJunc, GksSl, GtoSlow, GtoFast, GClCa;   // Conductivities
    REAL ENaJunc, ENaSl, ECaJunc, ECaSl, EKsJunc, EKsSl, EKs;                   // Nernst Potentials in the Junctional Cleft and the Subsarcolemmal Space
    REAL INaK;                                                                  // Current Amplitude in Na/K Pump (const, not equal to INaKJunc + INaKSl)
    REAL INCX;                                                                  // Na/Ca Exchanger Current Amplitude
    REAL IPMCA;                                                                 // Sarcolemmal Ca Pump Current Amplitude
} ModelParameters;


struct Is
{
    REAL INaKJunc, INaKSl;                                                      // Na/K Pump Currents in the Junctional Cleft and the Subsarcolemmal Space
    REAL INaJunc, INaSl;                                                        // Fast Na Currents
    REAL INaBkJunc, INaBkSl;                                                    // Background Na Currents
    REAL ICaBkJunc, ICaBkSl;                                                    // Background Ca Currents
    REAL ICaJunc, ICaSl;                                                        // L-type Calcium Currents
    REAL ICaK, ICaNaJunc, ICaNaSl;                                              // Ca-K, Ca-Na Currents
    REAL IpCaJunc, IpCaSl;                                                      // Sarcolemmal Ca Pump Currents
    REAL IncxJunc, IncxSl;                                                      // Na/Ca Exchanger Currents
    REAL INaTotJunc, INaTotSl;                                                  // Total Sodium Currents
    REAL ICaTotJunc, ICaTotSl;                                                  // Total Calcium Currents
    REAL ItoSlow, ItoFast;
    REAL Ikr, Iks;
    REAL Iki, Ikp;
    REAL IClCa, IBgCl;
} IValues;

struct Js
{
    REAL JSRCaRel, JserCa, JSRLeak;                                             //
    REAL JCaBCytosol, JCaBJunc, JCaBSl;                                         //
} JValues;

struct Buf
{
    REAL TnCl, TnChc, TnChm, CaM, Myoc, Myom, SRB;                              // Cytosolic Ca Buffers
    REAL SLLj, SLLsl, SLHj, SLHsl;                                              // Junctional and SL Ca Buffers
} CurrentBuffersState, NextBuffersState;
    
// Model Parameters
//Fractional Currents
#define Fjunc       0.11
#define Fsl         (1.0-Fjunc)
#define FjuncCaL    0.9
#define FslCaL      (1.0-FjuncCaL)

// Enviromental Parameters
#define pi          3.14159265358979
#define cellLength  100.0                 // (um)
#define cellRadius  10.25               // (um)
#define juncLength  160e-3              // (um)
#define juncRadius  15e-3               // (um)
#define distSLcyto  0.45                // (um)
#define distJuncSL  0.5                 // (um)
#define DcaJuncSL   1.64e-6             // (cm^2/sec)
#define DcaSLcyto   1.22e-6             // (cm^2/sec)
#define DnaJuncSL   1.09e-5             // (cm^2/sec)
#define DnaSLcyto   1.79e-5             // (cm^2/sec)
#define Vcell       (pi*cellRadius*cellRadius*cellLength*1e-15)      // (L)
#define Vmyo        (0.65*Vcell)          // (um^2)
#define Vsr         (0.035*Vcell)         // (um^2)
#define Vsl         (0.02*Vcell)          // (um^2)
#define Vjunc       (5.39e-4*Vcell)       // (um^2)
#define SAjunc      (40.3e3*pi*juncLength*juncRadius)                // (um^2)
#define SAsl        (pi*2.0*cellLength*cellRadius)                   // (um^2)
#define JCaJuncSl   8.2413e-13          // (L/ms)
#define JCaSlMyo    3.2743e-12          // (L/ms)
#define JNaJuncSl   1.83128e-14         // (L/ms)
#define JNaSlMyo    1.63863e-12         // (L/ms)
    
// Ion Concentrations
#define Cli         15.0                  // (mM)
#define Mgi         1.0                   // (mM)
#define Ki          120.0                 // (mM)
#define Clo         150.0                 // (mM)
#define Ko          5.4                 // (mM)
#define Nao         140.0                 // (mM)
#define Cao         1.8                 // (mM)

// Na Transport
#define gNa         23.0                  // Conductivity (mS/uF)
#define gNaB        0.597e-3            // Conductivity (mS/uF)
#define iNaK        1.8                 // Current (A/F)
#define KmNaip      11.0                  // Michaelis Constant (mM)
#define KmKo        1.5                 // Michaelis Constant (mM)

// Ca transport
#define pNa         (0.5*1.5e-8)          // (cm/sec)
#define pCa         (0.5*5.4e-4)          // (cm/sec)
#define pK          (0.5*2.7e-7)          // (cm/sec)
#define iNCX        4.5                 // Current (A/F)
#define iPMCA       0.0673              // Current (A/F)
#define KmCai       3.59e-3             // Michaelis Constant (mM)
#define KmCao       1.3                 // Michaelis Constant (mM)
#define KmNai       12.29               // Michaelis Constant (mM)
#define KmNao       87.5                // Michaelis Constant (mM)
#define KmPCa       0.5e-3              // Michaelis Constant (mM)
#define ksat        0.32
#define nu          0.27
#define KdAct       0.15e-3             // Dissociation Constant (mM)
#define gCaB        5.513e-4            // (A/F)


    
// Cl Currents
#define gClCa       (0.5*0.109625)   // Conductivity (mS/uF)
#define gClB        9e-3                // Conductivity (mS/uF)
#define KdClCa      0.1                 // Dissociation Constant(mM)
    
// K Currents
#define pNaK        0.01833
#define gkp         0.002               // Conductivity (mS/uF)
#define gksJunc     0.0035              // Conductivity (mS/uF)
#define gksSl       0.0035              // Conductivity (mS/uF)
#define gtoSlowEpi  0.0156              // Conductivity (mS/uF)
#define gtoFastEpi  0.1144              // Conductivity (mS/uF)
#define gtoSlowEndo 0.0376              // Conductivity (mS/uF)
#define gtoFastEndo 0.0014              // Conductivity (mS/uF)

// SR Ca Fluxes
#define VmaxSRCaP   5.3114e-3           // (mM/ms)
#define Kmf         0.246e-3            // Michaelis Constant (mM)
#define Kmr         1.7                 // Michaelis Constant (mM)
#define hillSRCaP   1.787
#define ks          25.0                  // (1/ms)
#define koCa        10.0                  // (mM^2/ms)
#define koM         0.06                // (1/ms)
#define kiCa        0.5                 // (1/(ms*mM))
#define kiM         0.005               // (1/ms)
#define ec50SR      0.45                // (mM)

// Buffering
#define BmaxNaJ     7.561               // (mM)
#define BmaxNaSl    1.65                // (mM)
#define KoffNa      1e-3                // (1/ms)
#define KonNa       1e-4                // (1/(ms*mM))
#define BmaxTnClow  7e-2                // (mM)
#define KoffTnCl    0.0196              // (1/ms)
#define KonTnCl     32.7                // (1/(ms*mM))
#define BmaxTnChigh 0.14                // (mM)
#define KoffTnChCa  0.32e-4             // (1/ms)
#define KonTnChCa   2.37                // (1/(ms*mM))
#define KoffTnChMg  3.33e-3             // (1/ms)
#define KonTnChMg   3e-3                // (1/(ms*mM))
#define BmaxCaM     0.024               // (mM)
#define KoffCaM     0.238               // (1/ms)
#define KonCaM      34.0                  // (1/(ms*mM))
#define BmaxMyosin  0.14                // (mM)
#define KoffMyoCa   0.46e-3             // (1/ms)
#define KonMyoCa    13.8                // (1/(ms*mM))
#define KoffMyoMg   0.57e-4             // (1/ms)
#define KonMyoMg    0.0157              // (1/(ms*mM))
#define BmaxSR      (19.0*0.9e-3)         // (mM)
#define KoffSR      6e-2                // (1/ms)
#define KonSR       100.0                 // (1/(ms*mM))
#define BmaxSLlowS  ((Vmyo*1e13)/(Vsl*1e13)*0.0374)   // (mM)
#define BmaxSLlowJ  (4.6e-4*(Vmyo*1e13)/(Vjunc*1e13))   // (mM)
#define KoffSll     1.3                 // (1/ms)
#define KonSll      100.0                 // (1/(ms*mM))
#define BmaxSLhighS (13.4e-3*(Vmyo*1e13)/(Vsl*1e13))    // (mM)
#define BmaxSLhighJ (1.65e-4*(Vmyo*1e13)/(Vjunc*1e13))  // (mM)
#define KoffSlh     0.03                // (1/ms)
#define KonSlh      100.0                 // (1/(ms*mM))
#define BmaxCsqn    (0.14*(Vmyo*1e13)/(Vsr*1e13))       // (mM)
#define KoffCsqn    65.0                  // (1/ms)
#define KonCsqn     100.0

// Physical Constants
#define R           8314.0              // Universal Gas Constant (J/kmol*K)
#define FRD         96485.0             // Faraday's Constant (C/mol)
#define TEMP        310.0               // Temperature (K)
#define RTF         (R*TEMP/FRD)        // Const (1/mV)
#define Cmem        1.381e-10           // (F)





// Main Module
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

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "sa.h"

extern int  cabuf(struct State *, struct State *, REAL, struct Cpar *, struct Js *, struct Buf *, struct Buf *);
extern int  srflux(struct State *, struct State *, REAL, struct Cpar *, struct Js *);

extern REAL caconc(struct State *, struct State *, REAL, struct Cpar *, struct Js *, struct Is *);
extern REAL naconc(struct State *, struct State *, REAL, struct Cpar *, struct Js *, struct Is *);

extern REAL ibgna(struct State *, struct State *, REAL, struct Cpar *, struct Is *);
extern REAL ibgcl(struct State *, struct State *, REAL, struct Cpar *, struct Is *);
extern REAL ibgca(struct State *, struct State *, REAL, struct Cpar *, struct Is *);
extern REAL ical(struct State *, struct State *, REAL, struct Cpar *, struct Is *);
extern REAL iclca(struct State *, struct State *, REAL, struct Cpar *, struct Is *);
extern REAL iki(REAL time, struct State *, struct State *, REAL, struct Cpar *, struct Is *);
extern REAL ikp(struct State *, struct State *, REAL, struct Cpar *, struct Is *);
extern REAL ikr(REAL time, struct State *, struct State *, REAL, struct Cpar *, struct Is *);
extern REAL iks(struct State *, struct State *, REAL, struct Cpar *, struct Is *);
extern REAL ina(struct State *, struct State *, REAL, struct Cpar *, struct Is *);
extern REAL inak(struct State *, struct State *, REAL, struct Cpar *, struct Is *);
extern REAL incx(struct State *, struct State *, REAL, struct Cpar *, struct Is *);
extern REAL ipk(struct State *, struct State *, REAL, struct Cpar *, struct Is *);
extern REAL ito(struct State *, struct State *, REAL, struct Cpar *, struct Is *);

bool EPI = true;


// Parameter Initialisation Using Constants from Header
void parametersInitialisation()
{
    ModelParameters.GNa      = gNa;
    ModelParameters.GNaB     = gNaB;
    ModelParameters.GClB     = gClB;
    ModelParameters.GCaB     = gCaB;
    ModelParameters.Gkp      = gkp;
    ModelParameters.GksJunc  = gksJunc;
    ModelParameters.GksSl    = gksSl;
    ModelParameters.GtoSlow  = EPI ? gtoSlowEpi : gtoSlowEndo;
    ModelParameters.GtoFast  = EPI ? gtoFastEpi : gtoFastEndo;
    ModelParameters.GClCa    = gClCa;
    ModelParameters.INaK     = iNaK;
    ModelParameters.INCX     = iNCX;
    ModelParameters.IPMCA    = iPMCA;
} /** parametersInitialisation **/

// Nernst Potentials Calculation Using Intra- and Extra- Concentrations
void nernstPotentials()
{
    ModelParameters.ENaJunc = RTF * log(Nao/CurrentState.NaJ);
    ModelParameters.ENaSl 	= RTF * log(Nao/CurrentState.NaSl);
    ModelParameters.ECaJunc = RTF/ 2.0 * log(Cao/CurrentState.CaJ);
    ModelParameters.ECaSl   = RTF/ 2.0 * log(Cao/CurrentState.CaSl);
    ModelParameters.EKsJunc = RTF * log((Ko + pNaK * Nao)/(Ki + pNaK * CurrentState.NaJ));
    ModelParameters.EKsSl   = RTF * log((Ko + pNaK * Nao)/(Ki + pNaK * CurrentState.NaSl));
    ModelParameters.EKs     = RTF * log((Ko + pNaK * Nao)/(Ki + pNaK * CurrentState.Nai));
} /** nernstPotentials **/

void stateInitialisation()
{
    CurrentState.E          = -80.9763;
    CurrentState.m          = 1.405627e-3;
    CurrentState.h          = 9.867005e-1;
    CurrentState.j          = 9.91562e-1;
    CurrentState.xkr        = 8.641386e-3;
    CurrentState.xks        = 5.412034e-3;
    CurrentState.xtos       = 4.051574e-3;
    CurrentState.ytos       = 9.945511e-1;
    CurrentState.xtof       = 4.051574e-3;
    CurrentState.ytof       = 9.945511e-1;
    CurrentState.d          = 7.175662e-6;
    CurrentState.f          = 1.000681;
    CurrentState.fCaBJunc   = 2.421991e-2;
    CurrentState.fCaBSl     = 1.452605e-2;
    CurrentState.Csqnb      = 1.242988;
    CurrentState.RyRr       = 8.884332e-1;
    CurrentState.RyRo       = 8.156628e-7;
    CurrentState.RyRi       = 1.024274e-7;
    
    CurrentState.NaJ    = 9.06;
    CurrentState.NaSl   = 9.06;
    CurrentState.Nai    = 9.06;
    CurrentState.CaJ    = 1.737475e-4;
    CurrentState.CaSl   = 1.031812e-4;
    CurrentState.CaSR   = 0.1e-1;
    CurrentState.Cai    = 8.597401e-5;
    CurrentState.NaBj   = 3.539892;
    CurrentState.NaBSl  = 7.720854e-1;
} /** stateInitialisation **/

void bufferInitialisation()
{
    CurrentBuffersState.TnCl    = 8.773191e-3;
    CurrentBuffersState.TnChc   = 1.078283e-1;
    CurrentBuffersState.TnChm   = 1.524002e-2;
    CurrentBuffersState.CaM     = 2.911916e-4;
    CurrentBuffersState.Myoc    = 1.298754e-3;
    CurrentBuffersState.Myom    = 1.381982e-1;
    CurrentBuffersState.SRB     = 2.143165e-3;
    CurrentBuffersState.SLLj    = 9.566355e-3;
    CurrentBuffersState.SLLsl   = 1.110363e-1;
    CurrentBuffersState.SLHj    = 7.347888e-3;
    CurrentBuffersState.SLHsl   = 7.297378e-2;
} /** bufferInitialisation **/

REAL totalCurrent(REAL time, struct State *S, struct State *Sn, REAL ht, struct Cpar *C, struct Is *I, struct Js *J, struct Buf *B, struct Buf *Bn)
{
    REAL IKtot, INatot, ICltot, ICatot;
    
    srflux(S, Sn, ht,  C, J);
    cabuf(S, Sn, ht, C, J, B, Bn);
    
    ical(S, Sn, ht, C, I);
    ibgca(S, Sn, ht, C, I);
    ipk(S, Sn, ht, C, I);
    ina(S, Sn, ht, C, I);
    ibgna(S, Sn, ht, C, I);
    incx(S, Sn, ht, C, I);
    inak(S, Sn, ht, C, I);
    ito(S, Sn, ht, C, I);
    ikr(time, S, Sn, ht, C, I);
    iks(S, Sn, ht, C, I);
    iki(time,S, Sn, ht, C, I);
    ikp(S, Sn, ht, C, I);
    iclca(S, Sn, ht, C, I);
    ibgcl(S, Sn, ht, C, I);
    
    caconc(S, Sn, ht, C, J, I);
    naconc(S, Sn, ht, C, J, I);
    
    INatot = (I->INaJunc + I->INaSl) + (I->INaBkJunc + I->INaBkSl) + 3.0 * (I->IncxJunc + I->IncxSl) + 3.0 * (I->INaKJunc + I->INaKSl) + (I->ICaNaJunc + I->ICaNaSl);
    IKtot = (I->ItoSlow + I->ItoFast) + (I->Ikr  + I->Iks) + I->Iki - 2.0 * (I->INaKJunc + I->INaKSl) + I->Ikp + I->ICaK;
    ICltot = I->IClCa + I->IBgCl;
    ICatot = I->ICaTotJunc + I->ICaTotSl;
    
    return INatot + IKtot + ICltot + ICatot;
}/** totalCurrent **/

void printState(REAL time, struct State *S, struct Is *I)
{
//    printf ("%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\n", time, S->E, S->m, S->h, S->j, S->xkr, S->xks, S->xtos, S->ytos, S->xtof, S->ytof, S->d, S->f, S->fCaBJunc, S->fCaBSl, S->Csqnb, S->RyRr, S->RyRo, S->RyRi, S->NaJ, S->NaSl, S->Nai, S->CaJ, S->CaSl, S->Cai, S->CaSR, S->NaBj, S->NaBSl);
    fprintf(E,"%e %e\n",time, S->E);
    fprintf(m,"%e %e\n",time, S->m);
    fprintf(h,"%e %e\n",time, S->h);
    fprintf(j,"%e %e\n",time, S->j);
    fprintf(xkr,"%e %e\n",time, S->xkr);
    fprintf(xks,"%e %e\n",time, S->xks);
    fprintf(xtos,"%e %e\n",time, S->xtos);
    fprintf(ytos,"%e %e\n",time, S->ytos);
    fprintf(xtof,"%e %e\n",time, S->xtof);
    fprintf(ytof,"%e %e\n",time, S->ytof);
    fprintf(d,"%e %e\n",time, S->d);
    fprintf(f,"%e %e\n",time, S->f);
    fprintf(fCaBJunc,"%e %e\n",time, S->fCaBJunc);
    fprintf(fCaBSl,"%e %e\n",time, S->fCaBSl);
    fprintf(Csqnb,"%e %e\n",time, S->Csqnb);
    fprintf(RyRr,"%e %e\n",time, S->RyRr);
    fprintf(RyRo,"%e %e\n",time, S->RyRo);
    fprintf(RyRi,"%e %e\n",time, S->RyRi);
    fprintf(NaSl,"%e %e\n",time, S->NaSl);
    fprintf(Nai,"%e %e\n",time, S->Nai);
    fprintf(CaJ,"%e %e\n",time, S->CaJ);
    fprintf(CaSl,"%e %e\n",time, S->CaSl);
    fprintf(Cai,"%e %e\n",time, S->Cai);
    fprintf(CaSR,"%e %e\n",time, S->CaSR);
    fprintf(NaBj,"%e %e\n",time, S->NaBj);
    fprintf(NaJ,"%e %e\n",time, S->NaJ);
    fprintf(NaBSl,"%e %e\n",time, S->NaBSl);

    fprintf(IncxJuncPlusIncxSl,"%e %e\n",time, I->IncxJunc + I->IncxSl);
//    fprintf(NaBSl,"%e %e\n",time, S->NaBSl);

}

void printCurrents(REAL time, struct Is *I)
{
 //   printf ("%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\n", time, I->INaKJunc, I->INaKSl, I->INaJunc, I->INaSl, I->INaBkJunc, I->INaBkSl, I->ICaBkJunc, I->ICaBkSl, I->ICaJunc, I->ICaSl, I->ICaK, I->ICaNaJunc, I->ICaNaSl, I->IpCaJunc, I->IpCaSl, I->IncxJunc, I->IncxSl, I->ItoSlow, I->ItoFast, I->Ikr, I->Iks, I->Iki, I->Ikp, I->IClCa, I->IBgCl);
    fprintf(inafile,"%e %e\n", time, I->INaJunc + I->INaSl);
    fprintf(icalfile, "%e %e\n", time, I->ICaJunc + I->ICaSl + I->ICaK + I->ICaNaJunc + I->ICaNaSl);
    fprintf(ICaNa,"%e %e\n",time, I->ICaNaJunc + I->ICaNaSl);
    fprintf(INaK,"%e %e\n",time, I->INaKJunc + I->INaKSl);
    fprintf(Ikr,"%e %e\n",time, I->Ikr);
    fprintf(Iks,"%e %e\n",time, I->Iks);
    fprintf(Ikl,"%e %e\n",time, I->Iki);


    fprintf(IBgCl,"%e %e\n",time, I->IBgCl);
    fprintf(IClCa,"%e %e\n",time, I->IClCa);
    fprintf(Ikp,"%e %e\n",time, I->Ikp);
    fprintf(Ikr,"%e %e\n",time, I->Ikr);
    fprintf(ICaTotSl,"%e %e\n",time, I->ICaTotSl);
    fprintf(ICaTotJunc,"%e %e\n",time, I->ICaTotJunc);
    fprintf(INaTotJunc,"%e %e\n",time, I->INaTotJunc);
    fprintf(ICaNaSl,"%e %e\n",time, I->ICaNaSl);
    fprintf(ICaNaJunc,"%e %e\n",time, I->ICaNaJunc);
    fprintf(ICaK,"%e %e\n",time, I->ICaK);
    fprintf(ICaJunc,"%e %e\n",time, I->ICaJunc);
    fprintf(ICaBkSl,"%e %e\n",time, I->ICaBkSl);
    fprintf(ICaBkJunc,"%e %e\n",time, I->ICaBkJunc);
    fprintf(INaBkSl,"%e %e\n",time, I->INaBkSl);
    fprintf(INaBkJunc,"%e %e\n",time, I->INaBkJunc);
    fprintf(ItoFast,"%e %e\n",time, I->ItoFast);
    fprintf(ItoSlow,"%e %e\n",time, I->ItoSlow);
    fprintf(Iepi,"%e %e\n",time, 0.88*I->ItoFast + 0.12*I->ItoSlow);
    fprintf(Iendo,"%e %e\n",time, 0.036*I->ItoFast + 0.964*I->ItoSlow);


    //fprintf(,"%e %e\n",time, I->);
}

void printBuffers(REAL time, struct Buf *B)
{
    printf ("%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\n", time, B->TnCl, B->TnChc, B->TnChm, B->CaM, B->Myoc, B->Myom, B->SRB, B->SLLj, B->SLLsl, B->SLHj, B->SLHsl);
}

void printJs(REAL time, struct Js *J)
{
    printf ("%e\t%e\t%e\t%e\t%e\t%e\t%e\n", time, J->JSRCaRel, J->JserCa, J->JSRLeak, J->JCaBCytosol, J->JCaBJunc, J->JCaBSl);
}

void openFiles(){

    Iks = fopen("./tests/Iks.txt","w");
    Ikl = fopen("./tests/Ikl.txt","w");
    icalfile = fopen("./tests/IcaL.txt","w");
    IncxJuncPlusIncxSl = fopen("./tests/incx.txt","w");
    E = fopen("./tests/E.txt","w");
    m = fopen("tests/m.txt","w");
    h = fopen("tests/h.txt","w");
    j = fopen("tests/j.txt","w");
    xkr = fopen("tests/xkr.txt","w");
    xks = fopen("tests/xks.txt","w");
    xtos = fopen("tests/xtos.txt","w");
    ytos = fopen("tests/ytos.txt","w");
    xtof = fopen("tests/xtof.txt","w");
    ytof = fopen("tests/ytof.txt","w");
    d = fopen("tests/d.txt","w");
    f = fopen("tests/f.txt","w");
    fCaBJunc = fopen("tests/fCaBJunc.txt","w");
    fCaBSl = fopen("tests/fCaBSl.txt","w");
    Csqnb = fopen("tests/Csqnb.txt","w");

    RyRr = fopen("tests/RyRr.txt","w");
    RyRo = fopen("tests/RyRo.txt","w");
    RyRi = fopen("tests/RyRi.txt","w");
    NaJ = fopen("tests/NaJ.txt","w");
    NaSl = fopen("tests/NaSl.txt","w");
    Nai = fopen("tests/Nai.txt","w");
    CaJ = fopen("tests/CaJ.txt","w");
    CaSl = fopen("tests/CaSl.txt","w");
    Cai = fopen("tests/Cai.txt","w");
    CaSR = fopen("tests/CaSR.txt","w");
    NaBj = fopen("tests/NaBj.txt","w");
    NaBSl = fopen("tests/NaBSl.txt","w");

    INaBkJunc = fopen("tests/INaBkJunc.txt","w");
    INaBkSl = fopen("tests/INaBkSl.txt","w");
    ICaBkJunc = fopen("tests/ICaBkJunc.txt","w");
    ICaBkSl = fopen("tests/ICaBkSl.txt","w");
    ICaJunc = fopen("tests/IICaJunc.txt","w");
    ICaK = fopen("tests/ICaK.txt","w");
    ICaNaJunc = fopen("tests/ICaNaJunc.txt","w");
    ICaNaSl = fopen("tests/ICaNaSl.txt","w");
    INaTotJunc = fopen("tests/INaTotJunc.txt","w");
    ICaTotJunc = fopen("tests/ICaTotJunc.txt","w");
    ICaTotSl = fopen("tests/ICaTotSl.txt","w");
    Ikr = fopen("tests/Ikr.txt","w");
    Ikp = fopen("tests/Ikp.txt","w");
    IClCa = fopen("tests/IClCa.txt","w");
    IBgCl = fopen("tests/IBgCl.txt","w");

    inafile = fopen("tests/INa.txt","w");
    ICaNa = fopen("tests/ICaNa.txt","w");
    INaK = fopen("tests/INaK.txt","w");
    gkrf= fopen("tests/gkr.txt","w");
    rkrf= fopen("tests/rkr.txt","w");
    tauxkr= fopen("tests/tauxkr.txt","w");
    xkrf= fopen("tests/xkr.txt","w");
    xkr1f= fopen("tests/xkr1.txt","w");
    xrssf= fopen("tests/xrss.txt","w");

    ItoFast = fopen("tests/ItoFast.txt","w");
    ItoSlow= fopen("tests/ItoSlow.txt","w");
    Iepi= fopen("tests/Iepi.txt","w");
    Iendo= fopen("tests/Iendo.txt","w");

    aki = fopen("tests/aki.txt","w");
    bki = fopen("tests/bki.txt","w");
    kiss = fopen("tests/kiss.txt","w");

    Dss = fopen("tests/Dss.txt","w");
    Fss = fopen("tests/Fss.txt","w");
    Td = fopen("tests/Td.txt","w");
    Tf = fopen("tests/Tf.txt","w");
    icaj = fopen("tests/icaj.txt","w");
    icas = fopen("tests/icas.txt","w");
    inaj = fopen("tests/inaj.txt","w");
    inas = fopen("tests/inas.txt","w");
    ik= fopen("tests/ik.txt","w");

    // = fopen("tests/.txt","w");

}

void closeFiles(){
    fclose(Dss);
    fclose(Fss);
    fclose(Td);
    fclose(Tf);
    fclose(icaj);
    fclose(icas);
    fclose(inaj);
    fclose(inas);
    fclose(ik);

    fclose(aki);
    fclose(bki);
    fclose(kiss);


    fclose(gkrf);
    fclose(rkrf);
    fclose(tauxkr);
    fclose(xkrf);
    fclose(xkr1f);
    fclose(xrssf);

    fclose(Ikl);
    fclose(Iks);
    fclose(icalfile);
    fclose(Iendo);
    fclose(Iepi);
    fclose(ItoSlow);
    fclose(ItoFast);

    fclose(IncxJuncPlusIncxSl);
    fclose(ICaNa);
    fclose(INaK);
    fclose(Ikr);

    fclose(inafile);
    fclose(IBgCl);
    fclose(IClCa);
    fclose(Ikp);
 //   fclose(Ikr);
    fclose(ICaTotSl);
    fclose(ICaTotJunc);
    fclose(INaTotJunc);
    fclose(ICaNaSl);
    fclose(ICaNaJunc);
    fclose(ICaK);
    fclose(ICaJunc);
    fclose(ICaBkSl);
    fclose(ICaBkJunc);
    fclose(INaBkSl);
    fclose(INaBkJunc);

    fclose(E);
    fclose(m);
    fclose(h);
    fclose(j);
    fclose(xkr);
    fclose(xks);
    fclose(xtos);
    fclose(ytos);
    fclose(xtof);
    fclose(ytof);
    fclose(d);
    fclose(f);
    fclose(fCaBJunc);
    fclose(fCaBSl);
    fclose(Csqnb);
    fclose(RyRr);
    fclose(RyRo);
    fclose(RyRi);
    fclose(NaJ);
    fclose(NaSl);
    fclose(Nai);
    fclose(CaJ);
    fclose(CaSl);
    fclose(Cai);
    fclose(CaSR);
    fclose(NaBj);
    fclose(NaBSl);
}

int main(int argc, char **argv)
{
    openFiles();
    printf("files are opened\n");
    REAL time = 0.0;
    int  f = 0;
    REAL timeStep = 5e-3;
    REAL Itotal;
    parametersInitialisation();
    stateInitialisation();
    bufferInitialisation();
    
    for (time = 0.0; time <= 100000.0; time = time + timeStep)
    {

        printf("%e\n",time);
        nernstPotentials();
        if((time >= 99000)&&(f%100 == 0))
        {
            printf("%e\n",time);
            printState(time, &CurrentState, &IValues);
            printCurrents(time, &IValues);
            //printBuffers(time, &CurrentBuffersState);
            //printJs(time, &JValues);
        }
       f++;
        
        Itotal = totalCurrent(time,&CurrentState, &NextState, timeStep, &ModelParameters, &IValues, &JValues, &CurrentBuffersState, &NextBuffersState);

        NextState.E = (((int) time) % 1000 < 5.0)? CurrentState.E - (Itotal - 10.0)*timeStep : CurrentState.E - Itotal*timeStep;
        CurrentState = NextState;
        CurrentBuffersState = NextBuffersState;
    }
    closeFiles();
    printf("\ndone\n");
    return 0;
}












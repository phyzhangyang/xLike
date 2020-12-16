#include "Higgs_CEPC.hpp"

namespace xLike {

double HiggsCEPC::lnlike(){
    
    double cepcpre[11];
    cepcpre[1] = 0.5/100.; //Zh production
    cepcpre[2] = 0.27/100.; //h->bb channel
    cepcpre[3] = 3.3/100.;  //h->cc channel
    cepcpre[4] = 1.3/100.;  //h->gg channel
    cepcpre[5] = 1.0/100.;  //h->WW channel
    cepcpre[6] = 0.8/100.;  //h->tautau channel
    cepcpre[7] = 5.1/100.;  //h->ZZ channel
    cepcpre[8] = 6.8/100.;  //h->gaga channel
    cepcpre[9] = 17.0/100.; //h->mumu channel
    cepcpre[10] = 2.8/100.; //(nunu)h->bb channel
    
    double cepcobs[11];
    //normalized decay strength
    double kh=(kb*kb*brb + kW*kW*brw + kZ*kZ*brz + ktau*ktau*brtau + kg*kg*brg + kgamma*kgamma*brgamma +
               kc*kc*brc + ks*ks*brs +kmu*kmu*brmu)/(brb+brw + brz + brtau + brg + brgamma+brc + brs +brmu);
    //normalized signal strength
    cepcobs[1] = kZ*kZ; //normalized Zh production signal strength
    cepcobs[2] = kZ*kZ/kh*kb*kb;
    cepcobs[3] = kZ*kZ/kh*kc*kc;
    cepcobs[4] = kZ*kZ/kh*kg*kg;
    cepcobs[5] = kZ*kZ/kh*kW*kW;
    cepcobs[6] = kZ*kZ/kh*ktau*ktau;
    cepcobs[7] = kZ*kZ/kh*kZ*kZ;
    cepcobs[8] = kZ*kZ/kh*kgamma*kgamma;
    cepcobs[9] = kZ*kZ/kh*kmu*kmu;
    cepcobs[10] = kW*kW/kh*kb*kb; //normalized (nunu)h->bb production signal strength
    
    double chisqu=0.0;
    for(int i=1;i<=10;i++){
        chisqu += (cepcobs[i] - 1.0)*(cepcobs[i] - 1.0)/(cepcpre[i]*cepcpre[i]);
    }
    return chisqu;
}


} // namespace xLike


#include <iostream>
#include <cmath>

namespace xLike {
class HiggsCEPC {
  public:
    HiggsCEPC(double kZ_, double kW_, double kg_,
              double kgamma_, double ktau_, double kmu_,
              double kb_, double kt_, double ks_,
              double kc_, double kzgamma_):
              kZ(kZ_), kW(kW_), kg(kg_),
              kgamma(kgamma_), ktau(ktau_), kmu(kmu_),
              kb(kb_), kt(kt_), ks(ks_),
              kc(kc_), kzgamma(kzgamma_){};
    double lnlike();

  private:
    double kZ, kW, kg, kgamma, ktau, kmu,
           kb, kt, ks, kc, kzgamma;
  
    double brb = 0.578;
    double brtau = 0.0637;
    double brmu = 2.21E-4;
    double brs = 4.4E-4;
    double brc = 2.68E-2;
    double brg = 8.56E-2;
    double brgamma = 2.30E-3;
    double brw = 0.216;
    double brz = 0.0267;

}; // class HiggsCEPC

} // namespace xLike

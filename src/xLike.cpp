
#include "Higgs_CEPC.hpp"

int main(){
  xLike::HiggsCEPC model(1.0025,1,1,
                  1,1,1,
                  1,1,1,
                  1,1);
  std::cout << "lnlike = " << model.lnlike() << std::endl;
  
  return 0;
}


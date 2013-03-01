#include "class_blackjackAction.h"
#include <iostream>

namespace casino{

  blackjackAction::atype blackjackAction::getAtype(){
    return actionType;
  }

  void blackjackAction::print(){
    std::cout << actionType << std::endl;
  }

  blackjackAction::blackjackAction(controlType c){
    if(c == TERMINAL){
      bool ok = false;
      while(!ok){
        std::string in;
        std::cout << "HIT (h) or STAND (s)?" << std::endl;
        std::cin >> in;
        if(in == "HIT" || in == "hit" || in == "h"){
          actionType = HIT;
          ok = true;
        }
        else if(in == "STAND" || in == "stand" || in == "s"){
          actionType = STAND;
          ok = true;
        }
      }
    }
  }

}

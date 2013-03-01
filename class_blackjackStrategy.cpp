#include "class_blackjackStrategy.h"
#include "class_blackjackAction.h"

namespace casino
{

  action* blackjackStrategy::takeAction(gameState* g){
    blackjackAction b(TERMINAL);
    action* a = &b;
    return a;
  }

  blackjackStrategy::blackjackStrategy(controlType){
  }

}

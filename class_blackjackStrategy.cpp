#include "class_blackjackStrategy.h"
#include "class_blackjackAction.h"

namespace casino
{

  action* blackjackStrategy::takeAction(gameState* g){
    g->print();

    blackjackAction* b = new blackjackAction(TERMINAL);

    return b;
  }

  blackjackStrategy::blackjackStrategy(controlType){
  }

}

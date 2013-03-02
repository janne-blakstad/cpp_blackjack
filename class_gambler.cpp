#include "class_gambler.h"
#include "class_blackjackStrategy.h"

namespace casino{

  gambler::gambler(std::string fname, std::string lname){
    gamblerId = 1;
    firstName = fname;
    lastName = lname;
    readyToPlay = true;
  }

  gambler::gambler(controlType c){
    blackjackStrategy b = blackjackStrategy(c);
    strategy* s = &b;
    strategies.push_back(s);
  }

  void gambler::giveMoney(cash amount){
    wallet += amount;
  }

  cash gambler::placeBet(){
    wallet -= 100;
    return 100;
  }

  std::string gambler::name(){
    return firstName + " " + lastName;
  }

  bool gambler::ready(){
    return readyToPlay;
  }

  action* gambler::takeAction(gameState* g){
    return strategies[0]->takeAction(g);
  }

  void gambler::joinGame(game& g){
    readyToPlay = false;
  }

}

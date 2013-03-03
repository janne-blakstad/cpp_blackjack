#include "class_gambler.h"
#include "class_blackjackStrategy.h"
#include <iostream>

namespace casino{

  int gambler::gamblerNr=1;

  gambler::gambler(std::string fname, std::string lname){
    gamblerId = gamblerNr++;
    firstName = fname;
    lastName = lname;
    readyToPlay = true;
  }

  gambler::gambler(controlType c){
    gamblerId = gamblerNr++;
    blackjackStrategy blackjackStrat = new blackjackStrategy(TERMINAL);
    strategies.push_back(&blackjackStrat);
    std::cout << "Skriv inn fornavn:" << std::endl;
    std::cin >> firstName;
    std::cout << "Skriv inn etternavn:" << std::endl;
    std::cin >> lastName;
    readyToPlay = true;
  }

  void gambler::giveMoney(cash amount){
    wallet += amount;
  }

  cash gambler::placeBet(){
    if(wallet >= 100)
    {
      wallet -= 100;
      return 100;
    }
    else
      return 0;
  }

  std::string gambler::name(){
    return firstName + " " + lastName;
  }

  bool gambler::ready(){
    return readyToPlay;
  }

  action* gambler::takeAction(gameState* g){
    return strategies.front()->takeAction(g);
  }

  void gambler::joinGame(game& g){
    readyToPlay = false;
  }

}

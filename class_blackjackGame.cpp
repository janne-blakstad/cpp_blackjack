#include "class_blackjackGame.h"
#include <iostream>
//#include "class_deck.h"
#include <vector>
#include "class_blackjackAction.h"
#include "class_blackjackState.h"
#include "class_blackjackStrategy.h" //temp

namespace casino{
 
    int dealer;
    int hero;
    std::vector<std::vector<cards::card> > cardsDealt;

  void blackjackGame::playRound(){
    cards::deck d;

    cash bet = gamblers[hero].placeBet();

    if(bet == 0)
    {
      std::cout << "Wallet fund too low" << std::endl;
      return;
    }

    d.shuffle();
    cardsDealt[dealer].push_back(d.deal());

    cardsDealt[hero].push_back(d.deal());
    cardsDealt[hero].push_back(d.deal());
    std::cout << "Your hand: ";
    printHand(cardsDealt[hero]);

    if(countPoints(cardsDealt[hero]) == 21){
      std::cout << "Blackjack!" << std::endl;
      gamblers[hero].giveMoney(bet*2.5);
      std::cout << "Won " << bet*1.5 << " cash" << std::endl;
    }
    else{
      cardsDealt[dealer].push_back(d.deal());
      cardsDealt[dealer].push_back(d.deal());
      printDealersHand();

      //std::string action;

      //std::cout << "HIT or STAND?" << std::endl;
      //std::cin >> action;

      blackjackState bjState = blackjackState(cardsDealt, hero, dealer);
      //gameState* state = &bjState;

      blackjackStrategy bStrat(TERMINAL);

      //blackjackAction* a = (blackjackAction*) gamblers[hero].takeAction(&bjState);
      //delete a;

      //blackjackAction bjAction = (blackjackAction) *a;

/*      while(bjAction.getAtype() == blackjackAction::HIT){
        cardsDealt[hero].push_back(d.deal());
        printHand(cardsDealt[hero]);

        if(countPoints(cardsDealt[hero]) > 21) break;

        cardsDealt[dealer].push_back(d.deal());
        printDealersHand();

        if(countPoints(cardsDealt[dealer]) > 21) break;

        delete bjState;

        bjState = blackjackState(cardsDealt, hero, dealer);
        bjAction = (blackjackAction*) gamblers[hero].takeAction(&bjState);

        //std::cout << "HIT or STAND?" << std::endl;
        //std::cin >> action;
     }
*/
      int playerPoints = countPoints(cardsDealt[hero]);
      std::cout << "You got " << playerPoints << " points" << std::endl;

      if(playerPoints > 21)
        std::cout << "You lost." << std::endl;
      else{
        resolveDealersHand(d);

        int dealerPoints = countPoints(cardsDealt[dealer]);

        printHand(cardsDealt[dealer]);

        if(dealerPoints > 21){
          std::cout << "Bust, you won" << std::endl;
          gamblers[hero].giveMoney(bet*2);
          std::cout << "Won " << bet << " cash" << std::endl;
        }
        else if(playerPoints > dealerPoints){
          std::cout << "You won!" << std::endl;
          gamblers[hero].giveMoney(bet*2);
          std::cout << "Won " << bet << " cash" << std::endl;
        }
        else if(playerPoints < dealerPoints){
          std::cout << "You lost.." << std::endl;
          std::cout << "Lost " << bet << " cash" << std::endl;
        }
        else{
          std::cout << "Push, it's a draw" << std::endl;
          gamblers[hero].giveMoney(bet);
          std::cout << "Got " << bet << " cash back" << std::endl;
        }
      }
    }

    cardsDealt[hero].clear();
    cardsDealt[dealer].clear();
  }

  blackjackGame::blackjackGame(int players): game::game(blackjack, players){  
    gamblers.push_back(gambler());

    for(int i = 0; i <= players; i++)
    {
      std::vector<cards::card> v;
      cardsDealt.push_back(v);
    }

    dealer = 0;
    hero = 1;

    gamblers[hero].giveMoney(1000);
/*
    std::vector<cards::card> dealercards;
    cardsDealt[dealer] = dealercards;

    std::vector<cards::card> herocards;
    cardsDealt[hero] = herocards;
*/
  }

  void blackjackGame::start(){
    std::cout << "--Welcome to blackjack!--" << std::endl;

    char playMore;
    do{
      playRound();
      do{
        std::cout << "Play another round? (Y/N)" << std::endl;
        std::cin >> playMore;
        if(playMore != 'n' && playMore != 'N' && playMore != 'y' && playMore != 'Y')
          std::cout << "Command not recognized" << std::endl;
      }while(playMore != 'n' && playMore != 'N' && playMore != 'y' && playMore != 'Y');
      if(playMore == 'N' || playMore == 'n') std::cout << "Byebye!" << std::endl;
      else if(playMore == 'Y' || playMore == 'y') std::cout << "New round!" << std::endl;
    }while(playMore == 'Y' || playMore == 'y');
  }

  int blackjackGame::cardPoints(cards::t_rank cardRank){
    switch(cardRank)
    {
      case 'T' :
      case 'J' :
      case 'Q' :
      case 'K' :
        return 10;
      case 'A' : return 1;
      default : return (int) cardRank - '0';
    }
  }

  void blackjackGame::resolveDealersHand(cards::deck d){
    int dealerPoints = countPoints(cardsDealt[dealer]);

    while(dealerPoints < 17){
      std::cout << "Dealer: " << dealerPoints << " points" << std::endl;
      std::cout << "Dealer: HIT" << std::endl;
      cardsDealt[dealer].push_back(d.deal());
      dealerPoints = countPoints(cardsDealt[dealer]);
    }
    std::cout << "Dealer: " << dealerPoints << " points" << std::endl;
    if(dealerPoints <= 21)
      std::cout << "Dealer: STAND" << std::endl;
  }

  int blackjackGame::countPoints(std::vector<cards::card> hand){
    int aces = 0;
    int points = 0;
    for(std::vector<cards::card>::iterator it = hand.begin() ; it != hand.end(); ++it)
    {
      cards::t_rank cardRank = it->getRank();
      if(cardRank == 'A') aces++;
      points += cardPoints(cardRank);
    }

    while(points < 12 && aces > 0)
    {
      points += 10;
      aces--;
    }

    return points;
  }

  void blackjackGame::getBestHand(){ 
  }

  void blackjackGame::printHand(std::vector<cards::card> hand){
    for(std::vector<cards::card>::iterator it = hand.begin() ; it != hand.end(); ++it){
      std::cout << it->name() << " ";
    }
    std::cout << std::endl;
  }

  void blackjackGame::printDealersHand(){
    std::cout << "Dealers cards: ";
    std::vector<cards::card>::iterator it = cardsDealt[dealer].begin();
    it++;
    for(it; it != cardsDealt[dealer].end(); ++it){
      std::cout << it->name() << " ";
    }
    std::cout << std::endl;
  }
}

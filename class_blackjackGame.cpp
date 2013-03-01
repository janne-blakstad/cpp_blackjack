#include "class_blackjackGame.h"
#include <iostream>
#include "class_deck.h"
#include <vector>

namespace casino{
 
    std::vector<cards::card> playersHand;
    std::vector<cards::card> dealersHand;
    cards::deck d;
 
  void blackjackGame::playRound(){
    d.shuffle();

    playersHand.push_back(d.deal());
    playersHand.push_back(d.deal());
    printHand(playersHand);
    if(countPoints(playersHand) == 21){
      std::cout << "Blackjack!" << std::endl;
    }
    else{
      dealersHand.push_back(d.deal());
      dealersHand.push_back(d.deal());
      printDealersHand();

      std::string action;

      std::cout << "HIT or STAND?" << std::endl;
      std::cin >> action;

      while(action == "HIT"){
        playersHand.push_back(d.deal());
        printHand(playersHand);

        if(countPoints(playersHand) > 21) break;

        dealersHand.push_back(d.deal());
        printDealersHand();

        if(countPoints(dealersHand) > 21) break;

        std::cout << "HIT or STAND?" << std::endl;
        std::cin >> action;
      }

      int playerPoints = countPoints(playersHand);
      std::cout << "You got " << playerPoints << " points" << std::endl;

      if(playerPoints > 21)
        std::cout << "You lost." << std::endl;
      else{
        resolveDealersHand();

        int dealerPoints = countPoints(dealersHand);

        printHand(dealersHand);

        if(dealerPoints > 21)
          std::cout << "Bust, you won" << std::endl;
        else if(playerPoints > dealerPoints)
          std::cout << "You won!" << std::endl;
        else if(playerPoints < dealerPoints)
          std::cout << "You lost.." << std::endl;
        else
          std::cout << "Push, it's a draw" << std::endl;
      }

    }

    playersHand.clear();
    dealersHand.clear();
  }

  blackjackGame::blackjackGame(int players): game::game(blackjack, players){  
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

  void blackjackGame::resolveDealersHand(){
    int dealerPoints = countPoints(dealersHand);

    while(dealerPoints < 17){
      std::cout << "Dealer: " << dealerPoints << " points" << std::endl;
      std::cout << "Dealer: HIT" << std::endl;
      dealersHand.push_back(d.deal());
      dealerPoints = countPoints(dealersHand);
    }
    std::cout << "Dealer: " << dealerPoints << " points" << std::endl;
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
    std::cout << "Your cards: ";
    for(std::vector<cards::card>::iterator it = hand.begin() ; it != hand.end(); ++it){
      std::cout << it->name() << " ";
    }
    std::cout << std::endl;
  }

  void blackjackGame::printDealersHand(){
    std::cout << "Dealers cards: ";
    std::vector<cards::card>::iterator it = dealersHand.begin();
    it++;
    for(it; it != dealersHand.end(); ++it){
      std::cout << it->name() << " ";
    }
    std::cout << std::endl;
  }
}

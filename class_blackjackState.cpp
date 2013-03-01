#include "class_blackjackState.h"
#include <iostream>

namespace casino
{
  blackjackState::blackjackState(std::vector<std::vector<cards::card> > cardv, int iHero, int iDealer){
    cardsDealt = cardv;
    ourHero = iHero;
    dealer = iDealer;
  }

  void blackjackState::print(){
    std::cout << "Your cards: ";
    for(std::vector<cards::card>::iterator it = cardsDealt[ourHero].begin() ; it !=  cardsDealt[ourHero].end(); ++it){
      std::cout << it->name() << " ";
    }
    std::cout << std::endl;


    std::cout << "Dealers cards: ";
    for(std::vector<cards::card>::iterator it = cardsDealt[dealer].begin()++ ; it !=  cardsDealt[dealer].end(); ++it){
      std::cout << it->name() << " ";
    }
    std::cout << std::endl;

  }

  std::vector<cards::card> blackjackState::dealersCards(){
    return cardsDealt[dealer];
  }

  std::vector<cards::card> blackjackState::myCards(){
    return cardsDealt[ourHero];
  }

  std::vector<cards::card> blackjackState::cardsI(int i){
    return cardsDealt[i];
  }

  int blackjackState::getOurHero(){
    return ourHero;
  }

  int blackjackState::getDealer(){
    return dealer;
  }
}

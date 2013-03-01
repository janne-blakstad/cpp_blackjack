  #include <iostream>
  /*#include "class_deck.cpp"
  #include "class_card.cpp"*/
  #include "class_blackjackGame.h"
  
//  using namespace casino;
  
  int main()
  {
  /*
    deck d;
	d.shuffle();
	card c = d.deal();
	std::cout << c.name() << std::endl;
	
	card c2 = d.deal();
	std::cout << c2.name() << std::endl;
	
	card c3 = d.deal();
	std::cout << c3.name() << std::endl;*/
    casino::blackjackGame g;
    g.start();
  }

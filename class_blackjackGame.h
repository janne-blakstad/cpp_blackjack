#ifndef CLASS_BLACKJACKGAME_H
#define CLASS_BLACKJACKGAME_H
#include "class_game.h"
#include "class_deck.h"

namespace casino{

  class blackjackGame : public game
  {
    int dealer;
    int hero;
    std::vector<std::vector<cards::card> > cardsDealt;

    //Overridden from game
    virtual void playRound();

  public:

    //Constructor
    blackjackGame(int players=1);
    //Overridden from game
    virtual void start();

    int cardPoints(cards::t_rank cardRank);

    void resolveDealersHand(cards::deck d);

    int countPoints(std::vector<cards::card> hand);

    void printHand(std::vector<cards::card>);

    void printDealersHand();
  };
}
#endif

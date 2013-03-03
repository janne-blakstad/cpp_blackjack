#include "class_deck.h"
#include <algorithm> // std::random_shuffle 
#include <vector>
#include <time.h>

namespace cards{
  deck::deck(){
    for(int i = 0; i < NUM_RANKS; i++)
	{
	  cards.push_back(card(SPADES,ranks[i]));
	  cards.push_back(card(HEARTS,ranks[i]));
	  cards.push_back(card(CLUBS,ranks[i]));
	  cards.push_back(card(DIAMONDS,ranks[i]));
	}
  }
  
  deck::deck(int deckCount){
    for(int i = 0; i < deckCount; i++)
	{
	    for(int i = 0; i < NUM_RANKS; i++)
		{
		  cards.push_back(card(SPADES,ranks[i]));
		  cards.push_back(card(HEARTS,ranks[i]));
		  cards.push_back(card(CLUBS,ranks[i]));
		  cards.push_back(card(DIAMONDS,ranks[i]));
		}
	}
  }
  
  void deck::shuffle(){
    std::srand(time(NULL));
    //std::random_shuffle(cards.begin(), cards.end());
    int index;
    for(int i = 0; i < cards.size(); i++){
      index = rand() % cards.size();
      card temp = cards[i];
      cards[i] = cards[index];
      cards[index] = temp;
    }

  }
  
  
  card deck::deal(){
    card dealtCard = cards.front();
	cards.erase(cards.begin());
	return dealtCard;
  }
  
  int deck::size(){
    return cards.size();
  }
}

#include "class_card.h"
namespace cards{
  
  card::card(t_suit s, t_rank r){
    suit = s;
    rank = r;
  }
  
  std::string card::name(){
    //std::string s = rank;
    std::string s;
    s += suit_name[suit];
    s.push_back(rank);
    return s;
  }
  
  t_suit card::getSuit(){
    return suit;
  }
  
  t_rank card::getRank(){
    return rank;
  }
  
      
} //End of namespace

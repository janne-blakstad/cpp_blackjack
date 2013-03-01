#include "class_game.h"
namespace casino{
  
  game::game(gameType g, int players){
    t = g;
    players = 1;
  }
  gameType game::getType(){
    return t;
  }
}

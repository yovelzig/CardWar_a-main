#include "player.hpp"
namespace ariel{
    class Game
    {
    private:
        Player p1;
        Player p2;
    public:
        Game(Player a , Player b){
            // this->p1 = a;
            // this->p2 = b;
        }
        void playTurn(){};
        void printLastTurn(){};
        void playAll(){}; 
        void printWiner(){}; 
        void printLog(){}; 
        void printStats(){};
        ~Game();
   
    };
         Game::~Game()
    {
    }
}
    
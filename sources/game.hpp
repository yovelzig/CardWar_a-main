#pragma once
#include "player.hpp"
namespace ariel{
    class Game
    {
    private:
        Player p1;
        Player p2;
    public:
        Game(Player ply1 , Player ply2);
        void playTurn();
        void printLastTurn();
        void playAll(); 
        void printWiner(); 
        void printLog();
        void printStats();
   
    };
}
    
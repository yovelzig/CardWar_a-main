#include "game.hpp"
using namespace ariel;
Game::Game(Player a, Player b)
{
    this->p1 = a;
    this->p2 = b;
}
void Game::playTurn(){}
void Game::playAll(){}
void Game::printLastTurn(){}
void Game::printLog(){}
void Game::printStats(){}
void Game::printWiner(){}

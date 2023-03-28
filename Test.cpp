#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <stdexcept>
// using namespace std;
using namespace ariel;
TEST_CASE("initialization") {
    Player p1("Alice");
    Player p2("Bob");     
    CHECK(p1.cardesTaken() == 0);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK(p2.cardesTaken() == 0);
    Game game(p1,p2);
    CHECK(p1.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.stacksize() == 26);
    CHECK(p2.cardesTaken() == 0);
    CHECK(p2.stacksize() + p2.stacksize() == 52); 
}
TEST_CASE("changes in each stack after a single turn") {
    Player p1("Alice");
    Player p2("Bob");     
    Game game(p1,p2);
    game.playTurn();
    CHECK(p1.stacksize() < 26);
    CHECK(p2.stacksize() < 26);
    CHECK(p1.cardesTaken() + p2.cardesTaken() > 0);
    CHECK((p1.cardesTaken() + p1.stacksize() + p2.cardesTaken() + p2.stacksize()) == 52);
    CHECK(p2.stacksize() + p2.stacksize() < 52);
}
TEST_CASE("changes in each stack after the game") {
    Player p1("Alice");
    Player p2("Bob");     
    Game game(p1,p2);
    game.playAll();
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK(p1.cardesTaken() + p2.cardesTaken() > 0);
    CHECK(p1.cardesTaken() + p2.cardesTaken() == 52);
    CHECK(p2.stacksize() + p2.stacksize() == 0);
}
TEST_CASE("check for notThrow error") {
    Player p1("Alice");
    Player p2("Bob");     
    Game game(p1,p2);
    game.playAll();
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printStats());
    CHECK_NOTHROW(game.printWiner());
} 

TEST_CASE("check for errors") {
    Player p1("Alice");
    Player p2("Bob");     
    Game game(p1,p2);
    CHECK_THROWS(game.printLastTurn());
    CHECK_THROWS(game.printLog());
    CHECK_THROWS(game.printWiner()); 
    CHECK_THROWS(game.printStats()); 
} 
TEST_CASE("check for error if we init only single Player") {
    Player p1("Alice");    
    Game game(p1,p1);
    CHECK_THROWS(game.playTurn());
    CHECK_THROWS(game.playAll());
    CHECK_THROWS(game.printLog());
    CHECK_THROWS(game.printWiner()); 
    CHECK_THROWS(game.printStats()); 
    CHECK_THROWS(game.printLastTurn()); 
} 
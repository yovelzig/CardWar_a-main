#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <stdexcept>
using namespace std;
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


TEST_CASE("check for errors") {
    ariel::Player p1("Alice");
    ariel::Player p2("Bob");     
    ariel::Game game(p1,p2);
    CHECK_THROWS(game.printLastTurn());
    CHECK_THROWS(game.printLog());
    game.playTurn();
    CHECK_THROWS(game.printWiner());
    
    // game.printStats()
    CHECK(p1.stacksize() < 26);
    CHECK(p2.stacksize() < 26);
    CHECK(p1.cardesTaken() + p2.cardesTaken() > 0);
    CHECK((p1.cardesTaken() + p1.stacksize() + p2.cardesTaken() + p2.stacksize()) == 52);
    CHECK(p2.stacksize() + p2.stacksize() < 52);
} 


// TEST_CASE("Factorials of negative numbers") { 
//     CHECK_THROWS(factorial(-1));  // check that some exception is thrown
//     CHECK_THROWS_AS(factorial(-2), std::out_of_range);  // check that a specific exception type is thrown
//     CHECK_THROWS_AS(factorial(-2), std::exception);  // check that a specific exception type (or a descendant) is thrown
//}
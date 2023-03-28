#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
using namespace std;
namespace ariel{
    class Player
    {
    private:
        string name;
        // int stack_s;
        // int winnings;
    public:
    Player(){};
    Player(std::string name_){}
        // this->name = name_;
        // this->stack_s = 0;
        // this->winnings = 0;
    //}
    int stacksize(){return 0;}
    int cardesTaken(){return 0;}
    // void setStack_size(int a){this->stack_s = a;}
    ~Player();
    };
    Player::~Player()
    {
    }  
}
#endif // PLAYER_HPP    
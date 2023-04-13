#pragma once
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
    Player();
    Player(std::string name_);
        // this->name = name_;
        // this->stack_s = 0;
        // this->winnings = 0;
    //}
    int stacksize();
    int cardesTaken();
    // void setStack_size(int a){this->stack_s = a;}
    }; 
}
   
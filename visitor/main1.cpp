/// here we have an interface having an is-a relationship

// here we could have add more functionality by adding more member functions
// what wrong we have do is like principle :
    // Dont Repeat Yourself

// further have to look forward to see way to extend it 

#include<iostream>
#include<vector>

struct Monster{
    virtual ~Monster() {};
    virtual void sing() = 0;
};


struct Orc : public Monster{

    Orc() {
        std::cout << "Orc::Orc" ;
    }

    void sing() {
        std::cout << "orc::sing" << std::endl;
    }

};

struct Goblin : public Monster{

    Goblin() {
        std::cout << "Goblin::Goblin \n" ;
    }

    void sing() {
        std::cout << "Goblin::sing" <<  std::endl;
    }

};

int main(){

    std::vector<Monster*> monsters;
    monsters.emplace_back(new Orc);
    monsters.emplace_back(new Goblin);

    for(const auto& i : monsters){
        i->sing();
    }

    return 0;
}
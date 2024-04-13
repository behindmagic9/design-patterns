// here we have done like extended with IMonsterVisitor  
// used open-close princicpe -> we can add new operation to existing objet(open),
// without modifying the strcuture (closed) i.e Monster is not changed

//  The alogorithmic behaviour is thus seprated from the object
// - This is a 'good thing' if our goal is extensible software design
// - we can try many MonsterVisitor to try different behaviour


// monster interface connects to the visitor class by implementing an accpet member function
// can be read as ' i accpet functionality from the Monsterisitor heirarchy' 


// pros and cons
// Pros: 
// - observe open-close principle(easy to extend behaviour)
//  -implementing details are isolated from class


// Cons : 
// - Potentail makes it harder to introduce new type later i a project -- need to do lots of potential implementation
// - Restrcite to the public interface (or otherwise need to use getters to expose data)
//  - Performance may be negatively affected
    // - Lots of ploymorphism (double dispatch)
    // - Potentailly more heap allocation and mmeory management needed      
#include <iostream>
#include <vector>

struct Goblin;
struct Orc;

struct IMonsterVisitor
{
    virtual ~IMonsterVisitor() = default;
    virtual void visit(const Orc &orc) const = 0;
    virtual void visit(const Goblin &Goblin) const = 0;
};

struct DrawMonster : public IMonsterVisitor
{
    void visit(const Orc& orc) const override
    {
        std::cout << "DrawMonsterVisitor::visitor(orc)\n";
    }

    void visit(const Goblin& goblin) const override
    {
        std::cout << "DrawMonsterVisitor::visitor(goblin)\n";
    }
};

struct Monster
{
    virtual ~Monster(){};
    virtual void accept(const IMonsterVisitor &visitor) = 0;
};

struct Orc : public Monster
{

    Orc()
    {
        std::cout << "Orc::Orc\n";
    }

    void accept(const IMonsterVisitor &visitor) override
    {
        std::cout << "orc::accept" << std::endl;
        visitor.visit(*this);
    }
};

struct Goblin : public Monster
{

    Goblin()
    {
        std::cout << "Goblin::Goblin \n";
    }

    void accept(const IMonsterVisitor &visitor) override
    {
        std::cout << "Goblin::accept" << std::endl;
        visitor.visit(*this);
    }
};

void DrawAllMonster(const std::vector<Monster *> &monsters)
{
    for (auto const &m : monsters)
    {
        m->accept(DrawMonster{});
    }
}

int main()
{

    std::vector<Monster *> monsters;
    monsters.emplace_back(new Orc);
    monsters.emplace_back(new Goblin);

    std::cout << "\n\n"
     << std::endl;

    DrawAllMonster(monsters);

    std::cout << "\n\n"
     << std::endl;

    Monster *mmonster = new Orc;
    DrawMonster dm;       // creating behaviour
    mmonster->accept(dm); // executing behaviour


    return 0;
}
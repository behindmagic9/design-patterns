#include<iostream>
#include<variant>


struct ClassicalActor{
    ClassicalActor(const std::string& name){
        std::cout << name << " is a classical actor" << std::endl;
    }
};

struct MethodActor{
    MethodActor(const std::string& name){
        std::cout << name << " is a classical actor" << std::endl;
    }
};

using Actor = std::variant<ClassicalActor,MethodActor>;

struct practiseVisitor{
    void operator()(const ClassicalActor& clas){
        std::cout << "Practising Classical " << std::endl;
    }

    void operator()(const MethodActor& clas){
        std::cout << "Practising Classical " << std::endl;
    }
};


int main(){

    Actor a = MethodActor("mike");

    std::visit(practiseVisitor{},a);

    Actor b = MethodActor("shah");

    std::visit(practiseVisitor{},b);



    return 0;
}

//
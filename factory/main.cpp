// the factory method pattern provides a generalised way to create an instances of an object and ca be a great way to hide the implementation deatails for the derived class
// it is a inheritance based polymorphism

// pros and cons
// pros:
// 1 : single responsibility -> factory function()
// 2 : easy to update and is extensible

// cons :
// 1 -> update 2 things every time -> enum and if else condition
// 2 -> may need several factories for different heirarchies

#include <iostream>
#include <string>
#include <memory>

class IGameObject
{
public:
    virtual ~IGameObject() {} // importatn t0o decalre the destrutor as virtual also when using the real virtual function so as tp get the correct order of destrcution and everything get detrcuted successfully without any memory leaks

    virtual void Update() = 0;
    virtual void Render() = 0;
};

class Boat : public IGameObject
{
public:
    Boat(){};
    void Update() {};
    void Render() {};
};

class Plane : public IGameObject
{
public:
    Plane(){};
    void Update() {};
    void Render() {};
};

enum class objectType
{
    PLANE,
    BOAT
};

// std::shared_ptr<IGameObject> ObjectFactory(objectType type)
//     {
//         if (type == objectType::BOAT)
//         {
//             s_boat++;
//             return std::make_shared<Boat>();
//         }
//         else if (type == objectType::PLANE)
//         {
//             s_plane++;
//             return std::make_shared<Plane>();
//         }
//         return nullptr;
//     }

// made Factory a singleton
class Factory
{
public:
    static std::shared_ptr<IGameObject> ObjectFactory(objectType type)
    {
        if (type == objectType::BOAT)
        {
            s_boat++;
            return std::make_shared<Boat>();
        }
        else if (type == objectType::PLANE)
        {
            s_plane++;
            return std::make_shared<Plane>();
        }
        return nullptr;
    }

    static void PrintCount(){
        std::cout << "numer of plane  : " << s_plane << std::endl;
        std::cout << "number of boat : " << s_boat << std::endl;
    }

private:
    Factory() {}
    ~Factory() {}
    Factory(const Factory &o) = delete;
    static int s_plane;
    static int s_boat;
};
int Factory::s_plane = 0;
int Factory::s_boat = 0;

int main()
{

    Boat b;
    Plane p;


    // std::shared_ptr<IGameObject> object1 = ObjectFactory(objectType::BOAT);
    // std::shared_ptr<IGameObject> object2 = ObjectFactory(objectType::PLANE);
    // std::shared_ptr<IGameObject> object3 = ObjectFactory(objectType::PLANE);

// after i,plementting a Factory swith also ingleton design 
    std::shared_ptr<IGameObject> object1 = Factory::ObjectFactory(objectType::BOAT);
    std::shared_ptr<IGameObject> object2 = Factory::ObjectFactory(objectType::PLANE);
    std::shared_ptr<IGameObject> object3 = Factory::ObjectFactory(objectType::PLANE);

    Factory::PrintCount();
    return 0;
}


// Question  : stil remain like how can we track of the alive object in the game or delete and object on run time ....
// #include<iostream>
#include<string>
#include "Gameobject.hpp"
#include "Factory.hpp"

int main(){

    Factory::Register("Plane", Plane::Create);
    Factory::Register("Boat", Boat::Create);

    IGameObject* fact = Factory::objectFactory("Plane");

    return 0;
}

// // @directory exensible 
// // g++ -std=c++17 main.cpp GameObjects.cpp Factory.cpp -o prog
// #include <vector>
// #include <memory>
// #include <fstream>
// #include <string>

// #include "factory.hpp"
// #include "Gameobject.hpp"

// // For fun, create a new type
// class Ant : public IGameObject{
//     public:
//     Ant(int x,int y){ 
//         ObjectsCreated++;
//     }
//     void ObjectPlayDefaultAnimation() { /* ... */}
//     void ObjectMoveInGame() { /* ... */}
//     void Update() { /* ... */}
//     void Render() { /* ... */}
//     static IGameObject* Create() {
//         return new Ant(0,0);
//     }
//     private:
//         static int ObjectsCreated;
// };

// int Ant::ObjectsCreated = 0;

// int main(){
//     // Register a Different type
//     Factory::Register("plane",Plane::Create);
//     Factory::Register("boat",Boat::Create);
//     Factory::Register("ant",Ant::Create);
    
//     std::vector<IGameObject*> gameObjectCollection; 
//     // Add the correct object to our collection
//     // based on a .txt file
//     std::string line;
//     std::ifstream myFile("level1.txt");
//     if(myFile.is_open()){
//         while(std::getline(myFile,line)){
//             // For each line that is read in, then create a game object for that type
//             IGameObject* object = Factory::objectFactory(line);
//             // Add the object to the collection
//             gameObjectCollection.push_back(object);
//         }
//     }

//     // Run our game...
//     while(true){
//         for(auto& e: gameObjectCollection){
//             e->Update();
//             e->Render();
//         }
//     }

//     return 0;
// }
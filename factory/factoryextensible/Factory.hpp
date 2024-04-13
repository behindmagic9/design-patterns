#ifndef FACTORY_HPP
#define FACTORY_HPP


#include"Gameobject.hpp"
#include<map>
#include<string>
#include<memory>

class Factory {
    typedef IGameObject *(*Callbackfunc)();
public : 

    static void Register(const std::string &type , Callbackfunc cb );
    static void UnRegister(const std::string &type );
    static IGameObject* objectFactory(const std::string &type);
private:

    // Factory(const Factory& o) = delete;
    typedef std::map<std::string ,Callbackfunc> CallMap;
    static CallMap mapper;

};
#endif 
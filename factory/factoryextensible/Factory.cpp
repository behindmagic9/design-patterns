#include "Factory.hpp"
#include"Gameobject.cpp"


Factory::CallMap Factory::mapper;

void Factory::Register(const std::string &type , Callbackfunc cb ){
    mapper[type] = cb;
}

void Factory::UnRegister(const std::string &type ){
    mapper.erase(type);
}

IGameObject* Factory::objectFactory(const std::string &type){
    CallMap::iterator it  = mapper.find(type);
    if(it != mapper.end()){
        return (it->second());
    }
    
    return nullptr; // has to do exception handling here like if not found then guve tge exceotion errir
}






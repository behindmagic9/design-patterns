#ifndef IOBSERVER_HPP
#define IOBSERVER_HPP

#include "ISubject.hpp"
#include<string>

class IObserver{
public :
    virtual ~IObserver() { }
    virtual void OnNotify() = 0;
};

class Watcher : public IObserver{
public :

// we will automatically register the watcher to a subjet when we create it 
    explicit Watcher(ISubject& _subject, std::string _Name) ; 

// we will automatically remove the watcher from whatever Isubejct that it is Observing
    ~Watcher(); 
    void OnNotify() ;

private: 
    std::string Name;
    ISubject& subject;

};
#endif
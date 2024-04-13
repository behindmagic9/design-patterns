#ifndef IOBSERVER_HPP
#define IOBSERVER_HPP

#include "ISubject.hpp"
#include<string>
#include<memory>

//Abtract classs which we derive from 'Base Class'
class IObserver{
public :
    virtual ~IObserver() { }
    virtual void OnNotify() = 0;
};

// Concrete implementatiton of our Observer
class Watcher : public IObserver  /*std::enable_shared_from_this<Watcher>*/{
public :

// we will automatically register the watcher to a subjet when we create it 
    explicit Watcher(ISubject& _subject,int message,const std::string& _Name) ; 

// we will automatically remove the watcher from whatever Isubejct that it is Observing
    ~Watcher(); 
    void OnNotify() ;


private: 
    std::string Name;
    int Message;
    // std::shared_ptr<ISubject> subjectPtr;
    ISubject& subject;
};
#endif
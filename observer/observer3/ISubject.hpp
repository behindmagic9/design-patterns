#ifndef ISUBJECT_HPP
#define ISUBJECT_HPP

#include<forward_list>

class IObserver;

class ISubject{
public:

    ISubject::ISubject();

    virtual ~ISubject() ;
    virtual void AddObserver(IObserver* ob); 

    virtual void RemoveObserver(IObserver* ob); 

    void NotifyAll();

private:
    std::forward_list<IObserver*> AllObservers;
};

class Subject1 : public ISubject{
public :

};
#endif

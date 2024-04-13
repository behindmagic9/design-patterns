#ifndef ISUBJECT_HPP
#define ISUBJECT_HPP

#include<forward_list>
#include<map>

class IObserver;

class ISubject{
public:
    ISubject();
    virtual ~ISubject();
    virtual void AddObserver(int message , IObserver* ob); 

    virtual void RemoveObserver(int message  , IObserver* ob); 

    void NotifyAll();
    void Notify(int message);

private:
    typedef std::forward_list<IObserver*> AllObservers;
    typedef std::map<int,AllObservers> ObserverMap;
    // key/Value pair
    // key = is na 'int' or (enum) in this simple demo
    // Value = std::forward_list of our observers
    ObserverMap mObservers;
};


class Subject1 : public ISubject{
public :
    enum MessageType{ PLAYSOUND , HANDLEPHYSICS, LOG};
};
#endif

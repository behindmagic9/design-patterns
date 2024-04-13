#ifndef ISUBJECT_HPP
#define ISUBJECT_HPP

#include<forward_list>
#include<map>
#include<memory>

class IObserver;

class ISubject{
public:
    ISubject();
    virtual ~ISubject();
    virtual void AddObserver(int message , std::shared_ptr<IObserver> ob); 

    virtual void RemoveObserver(int message  ,std::shared_ptr<IObserver> ob); 

    void NotifyAll();
    void Notify(int message);

private:
    typedef std::forward_list<std::weak_ptr<IObserver>> AllObservers;
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

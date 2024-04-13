#include "ISubject.hpp"
#include "IObserver.hpp"

ISubject::ISubject() { }

ISubject::~ISubject() { }

void ISubject::AddObserver(IObserver* ob) {
    AllObservers.push_front(ob);
}

void ISubject::RemoveObserver(IObserver* ob) {
    AllObservers.remove(ob);
}

void ISubject::NotifyAll() {
    for(auto i : AllObservers){
        i->OnNotify();
    }
}
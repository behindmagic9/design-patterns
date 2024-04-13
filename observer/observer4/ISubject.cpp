#include "ISubject.hpp"
#include "IObserver.hpp"

ISubject::ISubject() { }

ISubject::~ISubject() { }

void ISubject::AddObserver(int message , IObserver* ob) {
    auto it = mObservers.find(message);
    if(it == mObservers.end()){
        mObservers[message] = AllObservers();
    }

    mObservers[message].push_front(ob);
}

void ISubject::RemoveObserver(int message  , IObserver* ob) {
    auto it = mObservers.find(message);
    if(it != mObservers.end()){
        AllObservers& list = mObservers[message];
        list.remove(ob); // shorter implementation of below code 
        
        // for(AllObservers::iterator li = list.begin() ; li != list.end();){
        //     if((*li) == ob){
        //         list.remove(ob); break; 
        //     }else{
        //         ++li;
        //     }
        // }
    }
}

void ISubject::NotifyAll() {
    for(ObserverMap::iterator it = mObservers.begin() ; it != mObservers.end(); ++it){
        for(auto & o : mObservers[it->first]){
            o->OnNotify();
        }
    }
}

void ISubject::Notify(int message){
    for(auto& o : mObservers[message]){
        o->OnNotify();
    }
}
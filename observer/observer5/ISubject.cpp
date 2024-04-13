#include "ISubject.hpp"
#include "IObserver.hpp"
#include<iostream>

ISubject::ISubject() { }

ISubject::~ISubject() { }

void ISubject::AddObserver(int message , std::shared_ptr<IObserver>  ob) {
    
    auto it = mObservers.find(message);
    if(it == mObservers.end()){
        mObservers[message] = AllObservers();
    }

    mObservers[message].push_front(ob);
}

void ISubject::RemoveObserver(int message  , std::shared_ptr<IObserver>  ob) {
    auto it = mObservers.find(message);
    if(it != mObservers.end()){
        AllObservers& list = mObservers[message];
        // list.remove(ob); // shorter implementation of below code 
        list.remove_if([ob](std::weak_ptr<IObserver>& weakOb) {
            return weakOb.expired() || weakOb.lock() == ob;
        });
    }
}

void ISubject::NotifyAll() {
    for(ObserverMap::iterator it = mObservers.begin() ; it != mObservers.end(); ++it){
        for(auto & o : it->second){
            if(auto ob = o.lock()){
                ob->OnNotify();
            }
        }
    }
}

void ISubject::Notify(int message){
    for(auto& o : mObservers[message]){
        // auto a = o.lock();

        if (auto ob = o.lock()) {
            std::cout << "Dfgdf" << std::endl;
            // if(a == nullptr){
            //     std::cout << "nullptr" << std::endl;
            // }
            ob->OnNotify();
        }
    // }
    }
}
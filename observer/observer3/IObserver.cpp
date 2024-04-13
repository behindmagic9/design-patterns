#include "IObserver.hpp"
#include<iostream>

Watcher::Watcher(ISubject& _subject, std::string _Name) : subject(_subject) ,Name(_Name) {
        subject.AddObserver(this);
}

Watcher::~Watcher(){
    subject.RemoveObserver(this);
}

void Watcher::OnNotify(){
    std::cout << Name  << " says Hello " << std::endl;
}
#include "IObserver.hpp"
#include<iostream>

Watcher::Watcher(ISubject& _subject, int _message ,const std::string& _Name) : subject(_subject),Message(_message) ,Name(_Name) {
        subject.AddObserver(Message,this);
}

Watcher::~Watcher(){
    subject.RemoveObserver(Message,this);
}

void Watcher::OnNotify(){
    std::cout << Name  << " says Hello " << std::endl;
}
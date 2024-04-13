#include "IObserver.hpp"
#include <iostream>

Watcher::Watcher(ISubject &_subject, int _message, const std::string &_Name) : subject(_subject), Message(_message), Name(_Name)
{
    auto sharedPtr = std::weak_ptr<Watcher>().lock();
    subject.AddObserver(Message,sharedPtr);
}

Watcher::~Watcher()
{
    subject.RemoveObserver(Message,std::shared_ptr<Watcher>());
}

void Watcher::OnNotify()
{
    std::cout << Name << " says Hello " << std::endl;
}

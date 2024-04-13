// Pros and Cons 
// Questions :
    // Q1 : Flexible -> Yes , eg -> NotifyAll(),Notify(specific Subsystem), 
    // we can easily derive IObserber classes
    // Q2 : Maintable -> Yes, the heavy lifting is abstracted to each derivation of IObserver
        // subject tierating throught the right set of observer
    // Q3 : Extensible -> yes , we showed this with different types of IObservers



#include<iostream>
#include "IObserver.hpp"
#include "ISubject.hpp"

int main(){

    Subject1 s1;
    Watcher w1(s1,Subject1::PLAYSOUND,"Wall");
    Watcher w2(s1,Subject1::HANDLEPHYSICS,"Animal");
    Watcher w5(s1,Subject1::HANDLEPHYSICS,"Animal2");

    {
        Watcher w3(s1,Subject1::LOG,"birds"); // now safe to do so 
    }

    // {
        Watcher w4(s1,Subject1::LOG,"birds"); // now safe to do so 
    // }

    s1.NotifyAll();

    std::cout << std::endl;

    s1.Notify(Subject1::HANDLEPHYSICS); // this be give all specififc observer to the subject 

    return 0;
}
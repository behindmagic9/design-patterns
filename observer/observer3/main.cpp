#include<iostream>
#include "IObserver.hpp"
#include "ISubject.hpp"

int main(){

    Subject1 s1;
    Watcher w1(s1,"Wall");
    Watcher w2(s1,"Animal");
    {
        Watcher w3(s1,"birds"); // now safe to do so 
    }
    s1.NotifyAll();

    return 0;
}
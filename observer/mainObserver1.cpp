// type of behaviour design pattern , where concerned with communication between objects
//the observer design pattern is a software design pattern in which an object named the subject maintains a list of its dependents called observers and notifies them automatically of any state changes usually by calling one of their methods

//  like the MVC model view controller 
// MODEL -> VIEW -> USER -> CONTROLLER -> MODEL

// Subject -> the thing of interest that we want to keep track of any interesting state changes
// Observer -> there are the objects we want to react based on the subject
// typical use case is like having a 1 to many relationship between the Subject and Observer

// basically like 
    // observer1 -> subject1
    // observer2 -> subject2
    // observer3 -> subject3


// pros and cons
// no desogn pattern is perfect its just about trade-offs
// Question ot ask :
    // 1-> Flexible ? -Not Really
    // 2-> Maintainable ? - Maybe
    // 3-> Extensible ? - Not Really

// we make it better in next improved programs

#include<iostream>
#include<string>
#include<forward_list>

class Observer{
public : 
    Observer(std::string name) : Name(name){ }

    void OnNotify(){
        std::cout << Name << " says Hello " << std::endl;
    }

private:
    std::string Name;
};

class Subject{
public:
    // Subject() { }

    void AddObserver(Observer* ob) {
        AllObservers.push_front(ob);
    }

    void RemoveObserver(Observer* ob){
        AllObservers.remove(ob);
    }

    void NotifyAll(){
        for(auto i : AllObservers){
            i ->OnNotify();
        }
    }


private:
    std::forward_list<Observer*> AllObservers;

};

int main(){

    Observer ob1("Wall");
    Observer ob2("Bricks");

    Subject s1;
    s1.AddObserver(&ob1);
    s1.AddObserver(&ob2);
    

    s1.NotifyAll();

    s1.RemoveObserver(&ob2);
    std::cout << std::endl;
    s1.NotifyAll();




    return 0;
}
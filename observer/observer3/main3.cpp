// this wont work untill we devide every class to another file 
// so done that with main.cpp look at that its just before that file 

// the thing we have improved is called RAII - Resource Acquition is Initialization

// like what was happenning before is like 
// if we have condition of scope like 

    // Subject1 s1;
    // Watcher w1("Wall");
    // {
    //     Watcher w2("Animal");
    //     s1.AddObserver(&w1);
    //     s1.AddObserver(&w2);
    // }
    // s1.NotifYAll(); // give segmentation fault as the &w2 is out of its scope

    // s1.RemoveObserver(&w2); // if removed then this be give the compilation error 

// so to solve this resource scope condition , 
// what we have done is to take care of adding and deleting it goes out of scope
// so we have done adding and deleting inside the constructor as well as the destrcutor of the Watcher respectively
// mean subscribing the ubsject when we create them .. unsubscribe them when goes out of scope automatically
// .. further code in files .. look Isubject.hpp IOserver.hpp main.cpp andpther files respectively...

#include<iostream>
#include<string>
#include<forward_list>

class IObserver{
public :
    virtual ~IObserver() { }
    virtual void OnNotify() = 0;
};

class ISubject;

class Watcher : public IObserver{
public :
// we wwil automatically register the watcher to a subjet when we create it 
    explicit Watcher(ISubject& _subject, std::string _Name) : subject(_subject) Name(_Name) {
        subject.AddObserver(this);
    }
// we will automatically remove the watcher from whatever Isubejct that it is Observing
    ~Watcher(){
        subject.RemoveObserver(this);
    }
    void OnNotify() { 
        std::cout << Name  << " says Hello " << std::endl;
    }

private: 
    std::string Name;
    ISubject& subject;


};

class ISubject{
public:
    void AddObserver(IObserver* ob){
        AllObservers.push_front(ob);
    }

    void RemoveObserver(IObserver* ob){
        AllObservers.remove(ob);
    }

    void NotifyAll(){
        for(auto i : AllObservers){
            i->OnNotify();
        }
    }

private:
    std::forward_list<IObserver*> AllObservers;
};

class Subject1 : public ISubject{
public :

};



int main(){

    Subject1 s1;
    Watcher w1(s1,"Wall");
    Watcher w2(s1,"Animal");

    // s1.AddObserver(&w1);
    // s1.AddObserver(&w2);

    s1.NotifyAll();

    

    

    return 0;
}
// pros and Cons

// Questions :
//1 -> Flexible - Needs more power , not quite there yet
// 2-> Maintainable -> More , just needs to keeps the interface abstract/ Otherwise changes be made jmostly at the Watcher end
// 2-> Extensible -  Utilizing inheritance we can make use of this pattern 

// improving too in next part ....
// here what improved is make the calss Abstract to make most beneffit of Concreate class and making it Extenisble more 
#include<iostream>
#include<string>
#include<forward_list>

class IObserver{
public :
    virtual ~IObserver() { }
    virtual void OnNotify() = 0;
};

class Watcher : public IObserver{
public :
    Watcher(std::string _Name) : Name(_Name) {
        
    }
    void OnNotify() { 
        std::cout << Name  << " says Hello " << std::endl;
    }

private: 
    std::string Name;


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
    Watcher w1("Wall");
    Watcher w2("Animal");

    s1.AddObserver(&w1);
    s1.AddObserver(&w2);

    s1.NotifyAll();

    

    

    return 0;
}
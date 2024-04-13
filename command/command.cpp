// behaviour pattern allows you to focus on how object are interconnected
// specific behaviour design pattern is command pattern - alo known as action and reaction

// uses :
// 1-> Object used as callback
// 2-> can store or enqueue commands
// 3-> redo or undo sysytems

#include<iostream>
#include<vector>

struct Character{
public:
    int x , y;
    std::string name;
    Character(std::string _name) : name(_name){ }
    void move(int _x, int _y ) {
        x = _x;
        y = _y ; 
    }
    
};

class Command{
public:
    virtual ~Command() {}
    virtual void execute(Character& c) = 0;
    virtual void undo(Character& c) = 0;
    // well redo  can also be done by pushing element into it when doing the undo 
    // and best ds fro redo and undo is the stack data strcuture
};


class Jump : public Command{
public:
    void execute(Character& c) { 
        int _x = std::rand() % 4;
        int _y = std::rand() % 4;

        c.move(_x,_y);
        x = _x;
        y = _y;
        std::cout << c.name << " moved " << x << " , " << y << std::endl;
        
    }
    void undo(Character& c)  { 
        // std::cout << c.name << " undo moved " << std::endl;
        c.move(-x,-y);
        std::cout << c.name << " undo moved " << -x << " , " << -y << std::endl;

        
    }

    private:
        int x,y;
        // Character* ref; // this can be use to point to certain character move

};

class Accept : public Command{
public:
    void execute(Character& c) {}
    void undo(Character& c)  { }
};

int main(){

    Character mike("mike");
    std::vector<Command*> command_queue;

    Jump* j1 = new Jump;
    command_queue.push_back(j1);
    Jump* j2 = new Jump;
    command_queue.push_back(j2);

    for(int i =0; i < command_queue.size() ; i++){
        command_queue[i]->execute(mike);
    }

    for(int i =command_queue.size() - 1 ; i > -1 ; --i){
        command_queue[i]->undo(mike);
    }

    // And of course some cleanup...
    for(int i=0; i < command_queue.size(); i++){
        delete command_queue[i];
    }



    return 0;
}
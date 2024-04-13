// allows creation of only 1 instance in the program
// for single instance is we can do is using the 
// 1-> public private specifiers -> declaring constructor private
// 2->  using the static keyword -> it control the lifetime or duration of the variable
//static -> it initialised and store that to the global and on only one memory block

#include<iostream>
#include<string>
#include<vector>

class Logger{
    public : 
        static Logger* GetInstance(){
            static Logger* s_instance = new Logger;
        //     if(s_instance ==nullptr){
        //         return new Logger;
        //     }
           return s_instance;
        }
        void printMessage(){
            for(const auto &i : messagesQueue){
                std::cout << i << std::endl;
            }
        }

        void Addmessage(const std::string &message){
            messagesQueue.push_back(message);
        }

    private :
        ~Logger(){
            std::cout << "The logger was destroyed " << std::endl;
        }
        Logger(){
            std::cout << "The logger was created " << std::endl;
            // logger_count++;
        }

        
        // static int logger_count ;
        // static Logger* s_instance ;
        std::vector<std::string> messagesQueue;
};
// Logger* Logger::s_instance = nullptr;

// int Logger::logger_count = 0;

int main(){

    // Logger::GetInstance();
    // Logger::GetInstance();
    // Logger* point_to_logger = Logger::GetInstance();
    // delete point_to_logger;
    // Logger::GetInstance();
    // cause runtime error cause it as first destrcutor is public , so always put destructpr private in singleton , but now static got deleted and cant get that address now in the static finction 
    // with destrcutor private -> it be show the error or warns you compile time 

    // so solution is by make getinstance a & return Logger instead of the Logger and moving the s_instance inside the function to make that only initialized only once 
    // as when s_instance was inside the class if it redefined somewhere else in the pther function mistakenly then can caueas multiple instance ,
    // to prevent moving the s_instance inside the GetInstance then it will  only be initialised and static only once 
    // as scope of the static is till proragm exit so it be last after the scope end also

    Logger::GetInstance();

    Logger::GetInstance()->Addmessage("hi, first message");
    Logger::GetInstance()->printMessage();


    return 0;
}
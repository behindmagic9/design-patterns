// iteratotor pattern is a design pattern is used to traverse a container and access the container elements/strcuture.
#include<iostream>
#include<vector>
#include<iterator>
#include<unordered_map>

int main(){
    
    std::vector<int> vect{1,2,3,4,5,6,7,8,9};

    std::cout << "iterator" << std::endl;
    for(std::vector<int>::iterator it = vect.begin(); it != vect.end();++it){
        std::cout << *it << ", ";
    }
    std::cout << std::endl << std::endl;


    std::cout << "Const iterator " << std::endl;
    for(std::vector<int>::const_iterator it = vect.cbegin(); it != vect.end(); ++it){
        std::cout << *it << ", ";
    }
    std::cout << std::endl << std::endl;


    std::cout << "Reverse iterator " << std::endl;
    for(std::vector<int>::reverse_iterator it = vect.rbegin() ; it != vect.rend() ; ++it){
        std::cout << *it << ", ";
    }
    std::cout << std::endl << std::endl;



    auto it = vect.begin(); // equivalent of saying  std::vector<int>::iterator it = vect.begin()
    while(it != vect.end()){
        auto element = std::next(it,0); // it- current iterator , 0 for current elemnt, 1 for nect and 2 for 2 later element
        std::cout << *it  << ", ";
        std::advance(it,1); // same as of doing ++it
    }
    std::cout << std::endl << std::endl;

    std::cout <<"unordered map" << std::endl;
    std::unordered_map<std::string,int> Person;

    Person["Jack"] = 100;
    Person["Smith"] = 200;

    using PersonIterator = std::unordered_map<std::string,int>::iterator;
    for(PersonIterator it = Person.begin(); it != Person.end(); ++it){
        std::cout << it->first << ", " << it->second << std::endl;
    }
    return 0;
}
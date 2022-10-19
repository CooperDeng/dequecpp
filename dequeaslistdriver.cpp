#include <iostream>
#include <string>
#include "deque.h"

int main () {

    
    std::string first_input;
    std::string first_letter;
    std::string size;
    int size_int;
    std::getline(std::cin, first_input);
    first_letter = first_input.substr(0,1);

    //getting the deque size from command m and input
    if (first_letter == "m") {
        size = first_input.substr(2);
        size_int = stoi(size);
    }

    //declaring a deque
    deque d(size_int);


    //the while loop that keeps searching for inputs
    while(true){

        std::string user_input;
        std::getline(std::cin, user_input);
        int found = user_input.find(" ");
        std::string input_c = user_input.substr(0, found);
        std::string rest = user_input.substr(found+1);

        //checking input
        if (input_c == "push_front"){
            found = rest.find(" ");
            std::string U_N = rest.substr(0,found);
            std::string U = rest.substr(found+1);
            d.push_front(U_N, U);
        }
        if (input_c == "push_back"){
            found = rest.find(" ");
            std::string U_N = rest.substr(0,found);
            std::string U = rest.substr(found+1);
            d.push_back(U_N, U);
        }
        if (input_c == "pop_front"){
            d.pop_front();
        }
        if (input_c == "pop_back"){
            d.pop_back();
        }
        if (input_c == "clear"){
            d.clear();
        }
        if (input_c == "size"){
            d.size();
        }
        if (input_c == "front"){
            d.front();
        }
        if (input_c == "back"){
            d.back();
        }
        if (input_c == "empty"){
            d.empty();
        }
        if (input_c == "find"){
            std::string UN = rest;
            d.find(UN);
        }
        if (input_c == "print"){
            d.print();
        }
        
        //if input is exit, we break out of the while loop and call destructor        
        if (input_c == "exit"){
            break;
        }

    }

    d.~deque();
    return 0;

};


#include <iostream>
#include <string>
#include "linkedlist.h"

// public inheritence 
class deque : public linkedlist {
    public:
        //default constructor
        deque();

        //constructor with specified value
        deque(int input);

        //insert at beginneing
        void push_front(std::string URL_NAME, std::string URL);

        //insert at end of deque
        void push_back(std::string URL_NAME, std::string URL);

        //removes first element
        void pop_front();

        //removes last element
        void pop_back();

        //default destructor
        ~deque();

};

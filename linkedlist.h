#include <iostream>
#include "Node.h"

class linkedlist {
   
    protected:
    Node* head;
    Node* tail;
    //number of elements in the list
    int length;

    //maximum number of elements in the list
    int max_length;


    public:
    //default constructor
    linkedlist();

    //constructor with specified value
    linkedlist(int input);
    void clear();
    void size();
    void front();
    void back();
    bool empty();
    void find(std::string input);
    void print();

    //default destructor
    ~linkedlist();
};

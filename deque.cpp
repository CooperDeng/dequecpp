#include <iostream>
#include "deque.h"

deque::deque(){
    head = NULL;
    tail = NULL;
    length = 0;
    max_length=0;
}

deque::deque(int input){
    head = NULL;
    tail = NULL;
    length = 0;
    max_length = input;
    std::cout << "success" << "\n";
}

void deque::push_front(std::string URL_NAME, std::string URL) {

    //if the list is full, we pop one at the tail
    if (length == max_length) {
        Node* newNode = new Node(URL_NAME, URL);
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        head->prev = NULL;
        
        //popping one at the tail
        Node* tempPTR = tail;
        tail = tempPTR -> prev;
        tail->prev->next = tail;
        tail->next = NULL;
        delete tempPTR;
        tempPTR = NULL;

        newNode = NULL;
        length--; 
    }

    //if the list is empty, we make head = tail
    else if(length == 0){
        Node* newNode = new Node(URL_NAME, URL);
        head = newNode;
        tail = head;
        newNode = NULL;
    }

    //if the list is not full, we do normal stuff
    else {
        Node* newNode = new Node(URL_NAME, URL);
        head->prev = newNode;
        newNode->next = head;       
        head = newNode;
        head->prev = NULL;
        newNode = NULL;
    }

    length++;

    std::cout << "success" << "\n";

}

void deque::push_back(std::string URL_NAME, std::string URL) {

    //if the list is full, we pop one at the head
    if (length == max_length) {
        Node* newNode = new Node(URL_NAME, URL);
        newNode->prev = tail;
        tail = newNode;
        tail->prev->next = tail;

        //popping one at the head
        Node* tempPTR = head;
        head = tempPTR->next;
        head->next->prev = head;
        head->prev = NULL;
        delete tempPTR;
        tempPTR = NULL;

        newNode = NULL;

        length--;
    }

    //if the list is empty, we make head = tail
    else if(length == 0){
        Node* newNode = new Node(URL_NAME, URL);
        tail = newNode;
        head = tail;
        newNode = NULL;
    }

    //if the list is not full, we do normal stuff
    else {
        Node* newNode = new Node(URL_NAME, URL);
        newNode->prev = tail;
        tail = newNode;
        tail->prev->next = tail;
        tail->next = NULL;
        newNode = NULL;
    }
    
    length++;

    std::cout << "success"<< "\n";

}

void deque::pop_front(){

    //if the list is empty
    if (length == 0) {
        std::cout << "failure" << "\n";
    }
    //if the list has only one node
    else if(length == 1){
        //pop both head and tail
        delete head;
        head = NULL;
        tail = NULL;
        std::cout << "success" << "\n";
        length--;
    }

    else if(length == 2){
        Node* tempPTR = head;
        tail->prev = NULL;
        head = tail;
        delete tempPTR;
        tempPTR = NULL;
        length--;
        std::cout <<"success" <<"\n";
    }
    //normal pop when element in the list is more than 1
    else{
        Node* tempPTR = head;
        head = tempPTR->next;
        head->next->prev = head;
        head->prev=NULL;
        delete tempPTR;
        tempPTR = NULL;
        std::cout << "success" << "\n";
        length--;
    }

}

void deque::pop_back(){

    //if the list is empty
    if (length == 0) {
        std::cout << "failure" << "\n";
    }
    //if the list has only one node
    else if(length == 1) {
        //pop both head and tail
        delete head;
        head = NULL;
        tail = NULL;
        std::cout << "success" << "\n";
        length--;
    }    
    else if(length == 2) {
        Node* tempPTR = tail;
        head->next = NULL;
        tail = head;
        delete tempPTR;
        tempPTR = NULL;
        std::cout <<"success" <<"\n";
        length--;
    }
    //normal pop when element in the list is more than 1
    else {
        Node* tempPTR = tail;
        tail = tempPTR->prev;
        tail->prev->next=tail;
        tail->next=NULL;
        delete tempPTR;
        tempPTR = NULL;
        std::cout << "success" << "\n";
        length--;
    } 

}

deque::~deque(){
    tail = NULL;    
    while (head != NULL) {
        Node* tempPTR = head;
        head = head->next;
        delete tempPTR;
        tempPTR = NULL;
    }
    //setting the length to zero
    length = 0;
}
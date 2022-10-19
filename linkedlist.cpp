#include <iostream>
#include "linkedlist.h"

linkedlist::linkedlist() {
    head = NULL;
    tail = NULL;
    length = 0;
    max_length = 0;
}

linkedlist::linkedlist(int input) {
    head = NULL;
    tail = NULL;
    length = 0;
    max_length = input; 
    std::cout << "success" << "\n";

}

void linkedlist::clear() {
    while (head!=tail) {
        Node* tempPTR = head;
        head = head->next;
        head->prev = NULL;
        delete tempPTR;
        tempPTR = NULL;
    }

    if (head == tail){
        delete head;
        head = NULL;
        tail = NULL;
    }
    
    length = 0;
    std::cout << "success" << "\n";
}

void linkedlist::size(){
    std::cout << "size is " << length << "\n";
}

void linkedlist::front(){
    if (head==NULL){
        std::cout << "failure" << "\n";
    }
    else {
        std::string U_N = head->UN.substr(1);
        int found_UN = U_N.find("\"");
        U_N = U_N.substr(0,found_UN);

        std::string U_O = head->U.substr(1);
        int found_U = U_O.find("\"");
        U_O = U_O.substr(0,found_U);

        std::cout <<"front is " << head->UN <<" "<< head->U << "\n";
    }
}

void linkedlist::back(){
    if(head==NULL){
        std::cout <<"failure" << "\n";
    }
    else{
        std::string U_N = tail->UN.substr(1);
        int found_UN = U_N.find("\"");
        U_N = U_N.substr(0,found_UN);

        std::string U_O = tail->U.substr(1);
        int found_U = U_O.find("\"");
        U_O = U_O.substr(0,found_U);

        std::cout <<"back is " << tail->UN <<" "<< tail->U << "\n";    }
}

bool linkedlist::empty(){
    if (head == NULL) {
        std::cout << "empty 1" <<"\n";
        return true;
    }
    else {
        std::cout << "empty 0" <<"\n";
        return false;
    }
}

void linkedlist::find(std::string input){

    if(length == 0) {
        std::cout << "not found " << input << "\n";
        return;
    }

    std::string url_name = input;

    //move through Nodes to find the urlname
    Node* currentNode = head;
    while (currentNode->next != NULL) {
       if (currentNode->UN == url_name){
            std::cout << "found " <<currentNode->UN <<" " << currentNode->U <<"\n";
            return;
       }

       else{
        currentNode = currentNode->next;
       }
    }

    std::cout << "not found " << url_name << "\n";
    return;
}

void linkedlist::print(){

    Node* currentNode = tail;

    if(length == 0) {
        std::cout << "deque is empty" << "\n";
    }
    else {
        while(currentNode != NULL) {
            std::cout << currentNode->UN + " " + currentNode->U <<"\n";
            currentNode = currentNode->prev;
        }   
    }

}


linkedlist::~linkedlist() {
    
}

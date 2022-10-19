#include <iostream>
#include "Node.h"

Node::Node(std::string URL_NAME, std::string URL) { 
    UN = URL_NAME;
    U = URL;
}

Node::~Node(){
    UN = "";
    U = "";
}


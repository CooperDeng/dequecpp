#include <iostream>

class Node {
    public:

    std::string UN;
    std::string U;

    Node *prev, *next;

    Node(std::string URL_NAME, std::string URL);

    ~Node();

};

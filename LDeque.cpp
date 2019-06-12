#include "LDeque.hpp"

/*FYE: Functions were provided by the lecture notes given by Dr. Oropallo on this particular
      implementation of a deque data structure*/


//CONSTRUCTOR/DESTRUCTOR
//----------------------------------------------------------------------------------------->
LDeque::LDeque() : D(), n(0) {}
LDeque::~LDeque(){}

//CHECK FOR SIZE OF DEQUE (No. OF NODES IN IT ) && IF ITS EMPTY
//----------------------------------------------------------------------------------------->
int LDeque::size() const{
    return n;
}

bool LDeque::empty() const {
    return n == 0;
}

//REFERENCE TO FRONT AND REAR OF DEQUE 
//----------------------------------------------------------------------------------------->
const string& LDeque::front() const throw () {
    return D.front();
}

const string& LDeque::back() const throw () {
    return D.back();
}

//ENQUEUE AND DEQUEUE 
//----------------------------------------------------------------------------------------->
void LDeque::removeFront() throw() {
    D.removeFront();
    n--;
}

void LDeque::removeBack() throw() {
    D.removeBack();
    n--;
}

void LDeque::insertFront(const string &e) {
    D.addFront(e);
    n++;
}

void LDeque::insertBack(const string &e) {
    D.addBack(e);
    n++;
}


#include <string>

using std::string;

typedef string Elem;
class DNode {
 /*     A node consists of: 
            |------------------------|
            |<-prev* | elem | *next->|
            |------------------------|
*/
private:
    Elem elem;
    DNode* prev;
    DNode* next;
    friend class DLinkedList;
};
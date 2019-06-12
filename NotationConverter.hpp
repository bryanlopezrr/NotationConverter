#include "NotationConverterInterface.hpp"
#include "LDeque.hpp"

//This class inherets from the abstract class given by the professor 
//and overrides the functions to have the functionality their individual names have
class NotationConverter : public NotationConverterInterface {
    private:
        //The new_deque data member allows us to manipulate the strings and produce 
        //the correct output
        LDeque new_deque;
        int size;
    public:
        //Sets of functions to work with and define:
        std::string postfixToInfix(std::string inStr);
        std::string postfixToPrefix(std::string inStr);
        
        std::string infixToPostfix(std::string inStr);
        std::string infixToPrefix(std::string inStr);
        
        std::string prefixToInfix(std::string inStr);
        std::string prefixToPostfix(std::string inStr);
       
       //Functions to assist with the program 
        bool isoperator(char o);
        bool isvariable(char v);
        int order_of_oper(string order);
    
};
/*             ____________                       ____________
              |___IN_______|                     |___OUT______|   
             /                                      
1.  |       |      |  2. |              |  3. |      ^       |
    |       v      |     |              |     |      |       |
    |              |     |              |     |       \      |   
    |              |     |              |     |              |
    |              |     |              |     |              |
    |              |     |______________|     |              |
    |______________|     |______________|     |______________|

    This is what conceptually I am using for my deque to insert and remove the [Last In First Out] to 
    modify the operations (**Looks like a stack lol) because deques can operate as stacks
*/


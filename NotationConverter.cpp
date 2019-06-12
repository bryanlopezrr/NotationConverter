/**************************************************************

Project2: This program is a Notation Converter that will take in 
          expressions in a certain format. Whether it is INFIX,
          POSTFIX, or PREFIX, and modify them to output an 
          equivalent expression in a different notation. I used
          a deque to implement it as instructed with a doubly 
          linked list under the hood.
        
Author: Bryan Lopez 
Class: Data Structures; Dr. Oropallo
    
***************************************************************/

#include "NotationConverter.hpp"

//FYE: Although the deque can be used like a stack/queue where you can remove last and
//first, this implementation of the NotationConverter behaves in a stack-like manner
//Also, remember every mathematical operation has 3 components and nothing else
//TWO OPERANDS and ONE OPERATOR, this concept will allow us to implement the program

//BEGINNING OF FUNCTIONS
//-------------------------------------------------------------------------------------->
bool NotationConverter::isoperator(char _operator){
    /*This function will take in an operator as a parameter and pass it to 
      a switch statement to check if it is a valid operator or not */
    switch(_operator){
        case '+':
        case '-':
        case '*':
        case '/':
            return true; 
        default:
            return false; 
    }
}

bool NotationConverter::isvariable(char var){
    /*This function will check the character 'var' to make sure it is a valid variable
      or part of the English alphabet to evaluate the expressions later in the program*/
    if((var >= 'a' && var <= 'z') || (var >= 'A' && var <= 'Z') ){
        return true;
    }
    else{
        return false;
    }

}

int NotationConverter::order_of_oper(string _operator){
    /*This function will establish the precedence and importance of order of operations when
      an expression is passed. 
      The order is 100 being the highest, 50 lowest and -1 as a catch for incorrect input*/
    if(_operator == "/" || _operator == "*")
        return 100;
    else if(_operator == "-" || _operator == "+")
        return 50;
    else
        return -1;
}

//PRE ----> IN/POST
//-------------------------------------------------------------------------------------->
std::string NotationConverter::prefixToInfix(std::string inStr) {
    /*This function will cycle through the inStr input with a loop and check all the different
      conditions to make sure the right output is provided for the deque
      
      **The reason why this loop starts at the end is because it serves as a 'reverse' version
      of the string to produce the correct output. PRE --> IN is opposite to IN --> PRE
      */
    for (int i = inStr.size()-1; i >= 0; i--) {
        //Check for any blank spaces and continue (ignore) them
        if(string(1,inStr[i]) == " "){
            continue;
        }
        //Check if the inStr character is part of the alphabet  
        else if(isvariable(inStr[i])){   
            //If it is, then its classified as an OPERAND and pushed to the deque
            new_deque.insertFront(string(1, inStr[i]));
        }
        //Check if the inStr is an operator
        else if (isoperator(inStr[i])) {
            /*If it is then pull the 2 operands that correspond to this operator on the expression
              concatenate this string and push it to the deque as an expression*/
            string f_operand = new_deque.front();
                    new_deque.removeFront();
            string s_operand = new_deque.front();
                    new_deque.removeFront();
            
            string expression = "(" + f_operand + " " + inStr[i] + " " + s_operand + ")";
            new_deque.insertFront(expression);
        }
        else{
            //The input is invalid, exception
            throw("Invalid input for this operation");
        }
    }
    //When we return we have the new expression on the deque with correct output
    return new_deque.front() + " ";
}

std::string NotationConverter::prefixToPostfix(std::string inStr) {
    /*To reduce the work and not code all 6 functions, I made the Pre --> Post function in 
      terms of In --> Post. To do so, I added a middle step from Pre --> In
      EX: [a = b = c] === [a = c] */
    string expression = prefixToInfix(inStr);
    return infixToPostfix(expression);
}

//IN ----> POST/PRE
//-------------------------------------------------------------------------------------->
std::string NotationConverter::infixToPostfix(std::string inStr) {
    //Intialize a value 'expression' to manipulate later on the program and insert 'blank' to our deque
    string expression = "XXXXX";
    new_deque.insertFront("");

    /*This function will cycle through the inStr input with a loop and check all the different
      conditions to make sure the right output is provided for the deque
      
      **Loop is not altered here like on the other function PRE --> IN
      */
    for (int i = 0; i < inStr.size(); i++) {
        //Check for any blank spaces and continue (ignore) them
        if(string(1,inStr[i]) == " "){
            continue;
        }
        //Check if the inStr character is part of the alphabet 
        else if(isvariable(inStr[i])) {
            expression += inStr[i];
        }
        //Check if the inStr is an operator
        else if (isoperator(inStr[i])) {
            /*If it is then, check for the order of operations on the expression and room a loop where depending on 
              the correct order of operations it will append what is infront of the deque and add it to the expression
              that way the operators will be after the operands*/
            while(new_deque.front() != "" && order_of_oper(string(1,inStr[i])) <= order_of_oper(new_deque.front()))
            {
                string x = new_deque.front();
                new_deque.removeFront();
                expression += x;
            }
            new_deque.insertFront(string(1,inStr[i]));
            expression += " "; //Adding the spaces for correct output to match PP2Test.cpp
        } 
        /*The following 'else-if' statements take into account parenthesis for format and insert them accordingly to the 
          expression */
        else if(inStr[i] == '(') {
            new_deque.insertFront("(");
        }
        else if(inStr[i] == ')')
        {
            /*This loop will deal with parenthesis as Postfix operations dont use them. This algorithm will run 
              and make sure parenthesis are placed accordinglty*/
            while(new_deque.front() != "" && new_deque.front() != "(")
            {
                expression += " ";
                string x = new_deque.front();
                new_deque.removeFront();
                expression += x;
            }
            if(new_deque.front() == "(")
            {
                string x = new_deque.front() + " ";
                new_deque.removeFront();
            }
        }
        else {
            //The input is invalid, exception
            throw("Invalid input for this operation");
        }
    }
    /*Return the deque by removing the front element one by one until it becomes empty.
      That way the expression returned at the end of this function is the Postfix of the expression*/
    while(new_deque.front() != "")
    {
        string x = new_deque.front();
        new_deque.removeFront();
        expression += x;
    }
    return expression;
}

std::string NotationConverter::infixToPrefix(std::string inStr) {
    /*To reduce the work and not code all 6 functions, I made the In --> Pre function in 
      terms of Post --> Pre. To do so, I added a middle step from In --> Post
      EX: [a = b = c] === [a = c] */
    string expression = infixToPostfix(inStr);
    return postfixToPrefix(expression);
}

//POST ----> IN/PRE
//-------------------------------------------------------------------------------------->
std::string NotationConverter::postfixToInfix(std::string inStr) {
    /*This function will cycle through the inStr input with a loop and check all the different
      conditions to make sure the right output is provided for the deque*/
    for (int i = 0; i < inStr.size(); i++) {
        //Check for any blank spaces and continue (ignore) them
        if(string(1,inStr[i]) == " "){
            continue;
        }
        //Check if the inStr character is part of the alphabet 
        else if(isvariable(inStr[i])) {
            //If it is, initiliaze a string variable to hold that character to insert to deque
            string operand(1, inStr[i]);
            new_deque.insertFront(operand);
        }
        //Check if the inStr is an operator
        else if(isoperator(inStr[i])){
            /*If it is then pull the 2 operands that correspond to this operator on the expression
              concatenate this string and push it to the deque as an expression
              
              **NOTICE order is switched from other function for correct output*/
            string f_operand = new_deque.front();
                    new_deque.removeFront();
            string s_operand = new_deque.front();
                    new_deque.removeFront();
                    
            new_deque.insertFront("(" + s_operand + " "  +  inStr[i] + " " + f_operand + ")");
        }
        else {
            //The input is invalid, exception
            throw("Invalid input for this operation");
        }
    }
    //When we return we have the new expression on the deque with correct output
    return new_deque.front();
}

std::string NotationConverter::postfixToPrefix(std::string inStr) {
    /*This function will cycle through the inStr input with a loop and check all the different
      conditions to make sure the right output is provided for the deque*/
    for (int i = 0; i < inStr.size(); i++) {
         //Check for any blank spaces and continue (ignore) them
        if (string(1,inStr[i]) == " "){
            continue;
        }
        //Check if the inStr character is part of the alphabet 
        else if(isvariable(inStr[i])) {
            //If it is, initiliaze a string variable to hold that character to insert to deque
            string operand(1, inStr[i]);
            new_deque.insertFront(operand);
        }
         //Check if the inStr is an operator
        else if (isoperator(inStr[i])){
            /*If it is then pull the 2 operands that correspond to this operator on the expression
              concatenate this string and push it to the deque as an expression
              
              **NOTICE the spaces added at the beginning to match approprite format to the PP2TEST.cpp */
            string f_operand = " " + new_deque.front();
                    new_deque.removeFront();
            string s_operand = " " +  new_deque.front();
                    new_deque.removeFront();

            string expression = inStr[i] + s_operand + f_operand;
            new_deque.insertFront(expression);
        }
        else{
             //The input is invalid, exception
             throw("Invalid input for this operation");
        }
    }
    //When we return we have the new expression on the deque with correct output
    return new_deque.front() + " ";
}



//-------------------------------------------------------------------------------------->
//END OF PROGRAM FUNCTIONS

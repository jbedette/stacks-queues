#include "head.h"

int main(){
    stack myStack; 
    //push test
    char term1[10];
    char term2[10];
    char term3[10];
    
    //pop test
    int test4 = 0;
    char test5[50];

    cout << "\nterm1: ";
    charGet(term1);
    cout << "\nterm2: ";
    charGet(term2);
    cout << "\nterm3: ";
    charGet(term3);
    myStack.display();// ----> testing display before init
    myStack.push(1,term1);
    myStack.push(2,term2);
    myStack.push(3,term3);
    myStack.display();
    cerr << "\n\n";
    cerr << "-->post display 1\n";
    /*
    myStack.pop(test4,test5);
    cerr << "-->post pop1\n\n" << test4 << ':' << test5 << '\n';
    cerr << "\n\n";
    myStack.pop(test4,test5);
    cerr << "-->post pop2\n\n" << test4 << ':' << test5 << '\n';
    cerr << "\n\n";
    myStack.display();
    */

    return 0;
}

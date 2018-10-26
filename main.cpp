#include "head.h"

int main(){
    client myClient;
    myClient.init();
    myClient.addSeg();
    myClient.addSeg();
    myClient.addSeg();
    myClient.addSeg();
    myClient.addSeg();
    myClient.addSeg();
    myClient.queToStack();
    myClient.stackPop();






        /*
        //push test
        char term1[10];
        char term2[10];
    char term3[10];
    cout << "\nterm1: ";
    charGet(term1);
    cout << "\nterm2: ";
    charGet(term2);
    cout << "\nterm3: ";
    charGet(term3);
    myQue.enqueue(1,term1);
    myQue.enqueue(2,term2);
    myQue.enqueue(3,term3);
    myQue.display();
    // queue output testing
    int test1 = 0;
    char test2[10];
    int test3 = 0;
    char test4[10];
    int test5 = 0;
    char test6[10];
    myQue.dequeue(test1,test2);
    myQue.dequeue(test3,test4);
    myQue.dequeue(test5,test6);
    cerr << "\n" << test1 << ':' << test2;
    cerr << "\n" << test3 << ':' << test4;
    cerr << "\n" << test5 << ':' << test6;
    myQue.display();
    */
    /*
    //push test
    char term1[10];
    char term2[10];
    char term3[10];
    cout << "\nterm1: ";
    charGet(term1);
    cout << "\nterm2: ";
    charGet(term2);
    cout << "\nterm3: ";
    charGet(term3);
    myStack.push(1,term1);
    myStack.push(2,term2);
    myStack.push(3,term3);
    //stack array test section
    char term4[10];
    char term5[10];
    char term6[10];
    cout << "\nterm4: ";
    charGet(term4);
    cout << "\nterm5: ";
    charGet(term5);
    cout << "\nterm6: ";
    charGet(term6);
    myStack.push(4,term4);
    myStack.push(5,term5);
    myStack.push(6,term6);
    //array pop test
    int test1 = 0;
    char test2[10];
    int test3 = 0;
    char test4[10];
    myStack.pop(test1,test2);
    cerr <<"\nPop " <<test1 << ':' << test2 << '\n';
    myStack.pop(test3,test4);
    cerr <<"\nPop " <<test3 << ':' << test4 << '\n';
    //peek test
    int test5 = 0;
    char test6[10];
    myStack.peek(test5,test6);
    cerr <<"\npeek " <<test5 << ':' << test6 << '\n';
    myStack.display();
    */
    return 0;
}


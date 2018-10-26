#include <iostream>
#include <cstring>
using namespace std;

//John Bedette, cs163
//travel planner app


//todo:
//1comment, of course
//2fix count, should be able to output without for loops, but for loops are really nice
//3add rest of dyn arrs
//  - type of travel - just a dyn array, user can put that in
//  - start and end point -probably store in top level, feed into both at same time
//  - recommendations. frankly this just seems redundant
//4set dist to float, super annoying
//5find memory leaks - think it's my copyTo, but it save me so much space in my funcs
//6streamline
//7-->>> efficiency report
//      - definitely could have slimmed down the enque, push, pop
//      - my display's are kinda bad
//      - client program could be better

//utility
int copyTo(char * & out, char in[]);
void charGet(char in[]);
bool topMod5(int top);
bool confirm();


//structs
struct segment{
    char * name = NULL;
    int dist = 0;
};
struct node{
    node * next;
    segment * data;
};
//classes
class stack{
    public:
        stack();
        ~stack();
        //wrappers, generally weren't needed. Recursion is only minimally useful here
        int display();
        //public member funcs
        int pop(int & data, char name[]);
        int init();
        int push(int data, char name[]);
        int peek(int & data, char name[]);
        //testing
    private:
        int display(node * head);
        int pop(node * & head, int & data, char name[]);
        node * head;
        int top;
};
class queue{
    public:
        queue();
        ~queue();
        //wrappers
        int dequeue(int & data, char name[]);
        //public funcs
        int display();
        int enqueue(int data, char name[]);
        int peek(int & data, char name[]);
    private:
        int dequeue(node * & rear, int & data, char name[]);
        node * rear;
};
class client{
    public:
        client();
        ~client();
        //public funcs
        int init();
        int addSeg();
        int queToStack();
        int stackPop();
        int peek(int opt);//opt determines peek at stack(1) or queue(0)
    private:
        int count;
        queue *  myQue;
        stack * myStack;
};







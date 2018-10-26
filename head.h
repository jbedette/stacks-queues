#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
//state 10-16 6:45
//issues getting display and pop working
//display is running off the end of the array
//pop isn't reassinging head correctly

//utility
int copyTo(char * & out, char in[]);
void charGet(char in[]);
bool topMod5(int top);
//structs
struct segment{
    char * name;
    int dist;
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
        //wrappers
        int display();
        int pop(int & data, char name[]);
        //meat funcs
        int init();
        int push(int data, char name[]);
        int pop(node * & head, int & data, char name[]);
        int peek();
        int isEmpty(); int isFull();
        //testing
        int display(node * head);
    private:
        node * head;
        int top = 0;
};
class queue{
    public:
        queue();
        ~queue();
        int init();
        //wrappers
        int display();
        int dequeue(int & data, char name[]);
        int enqueue(int data, char name[]);
        //
        int enqueue(node * head,int data, char name[]);
        int dequeue(node * & head, int & data, char name[]);
        int peek();
        bool isEmpty(); bool isFull();
        //peek
        int display(node * head);
    private:
        node * head;
        node * tail;
};







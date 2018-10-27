#include <iostream>
#include <cstring>
using namespace std;

//John Bedette, cs163
//travel planner app,
//A main client class manages a stack and a queue
//the stack and queue both self delete with normal usage
//they use a multi purpose set of structs where the 
//segment pointer is capable of bing a single instance or an array 
//
//the user is prompted serveral times, then after 6 answers, 
//the trip is run out first in first out form the queue
//it is displayed to the user, then pushed into the stack adt
//the user is asked if they want to go home, the stack displays
//the reverse order
//
//while the queue dequeues it deallocates memory
//while the stack pops it it deallocates memory as necessary
//
//I've run into strange issues with calling an add function from itself
//with my confirm function. I wish I had figured it out



//utility
bool topMod5(int top);//determines when to add new stack nodes
bool confirm();//confirm action, currently causeing problems


//structs
//store a basic char arr and a float for distance
struct segment{
    char * name = NULL;
    float dist = 0;
};
//multipurpose node, in queue, segment is a single instance,
//in stack it's an array of segments
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
        int pop(float & data, char name[]); //pops off a frame,caps values
                                            //destroys as it works
                                            //or decrements the top of the
                                            //stack array
        int init();//initializing head instance
        int push(float data, char name[]);  //takes in data,passes to node
                                            //array of segments
        int peek(float & data, char name[]);//doesn't destroy,
    private:
        int display(node * head);//--->recursive<--- display
        int pop(node * & head, float & data, char name[]);//same as above
        node * head;//contains an array of segments
        int top;//keeps track of working locatin in arr
};
class queue{
    public:
        queue();
        ~queue();
        //wrappers
        int dequeue(float & data, char name[]);
        //public funcs
        int display();
        int enqueue(float data, char name[]);   //takes in data, assigns
                                                //to queue
        int peek(float & data, char name[]);    //takes data w/o delete
        int addHomeDest(char home[], char dest[]);  //adds a home and dest
                                                    //for trip
        int dispHomeDest(int opt);  //opt determines home or dest displayed
                                    //opt 0 displays home, 1 is dest
        int addMeth(char method[]);
        int dispMeth();
    private:
        //dequeue destroys at it serves info
        int dequeue(node * & rear, int & data, char name[]);
        node * rear;
        char * home;
        char * dest;
        char * method;
};
class client{
    public:
        client();
        ~client();
        //public funcs
        int init();//initializes the stack and queue
        int addSeg();   //adds a segment to the queue, having issues
                        //with repetitive calls, unable to solve
        int queToStack();   //dequeues all of queue, displays,
                            //pushes into stack
        int stackPop(); //pops all of stack out to the user
        int peek(int opt);//opt determines peek at stack(1) or queue(0)
        int addDest();  //calls methods on queue to disp home and destination
        int addMeth();  //adds a method of transport, only too late did I 
                        //realize it should be each segment
    private:
        int count;
        queue *  myQue;
        stack * myStack;
};







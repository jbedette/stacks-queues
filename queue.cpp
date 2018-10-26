#include "head.h"


queue::queue(){
    cerr << "\nConstructing\n";
    head = NULL;
    tail = NULL;
}
queue::~queue(){
    cerr << "\nDeconstructing\n";
}
int init(){//do we want init?
    int flag = 0; 
    head = NULL;
    tail = head;
    tail->next = head;
    head->next = tail;
    if (!head) ++flag;//if head has been set to NULL return true?
    return flag;
}
//wrappers
int queue::enqueue(int data, char name[]){ enqueue(head,data,name);}
int queue::dequeue(int & data, char name[]){ dequeue(head,data,name);}
int queue::display(){ display(head);}

//delicous recursive member functions
int queue::enqueue(node * head,int data, char name[]){//needs to recursive, add to end;
    int flag = 0;
    if(!head){
       head = new node; 
       copyTo(head->name, name);
       head->data = data;
       tail = head;
       head->next = tail;
       tail->next = head;
       ++flag;
    }else{
        node * temp = new node;
        copyTo(temp->name,name);
        temp->data = data;
        temp->next = head;
        if(head!=tail)tail->next = temp;
        tail = temp;
        ++flag;
    }
    return flag;
}
int queue::dequeue(node * & head, int & data, char name[]){
    int flag = 0;
    if(!head) return flag;
    data = head->data;
    strcpy(name,head->name);
    else{//what happens when head==tail
        node * temp = head->next;
        delete head->name;
        delete head;
        head = temp;
        ++flag;
    }
    return flag;
}
int queue::peek(){}
bool queue::isEmpty(){}
bool queue::isFull(){}
//testing
int queue::display(node * head){
    int flag = 0;
    return flag;
}






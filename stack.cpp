#include "head.h"

stack::stack(){
    head = NULL;
    int top = 0;
    cerr << "\nConstructing\n\n";
}
stack::~stack(){
    cerr << "\nDeconstructing\n\n";
}

//wrappers
int stack::display(){
    cerr << "--->display wrapper\n";
    return display(head, 0);
}
int stack::pop(int & data,char name[]){return pop(head,data,name);}
//

int stack::init(){
    cerr << "\n-->init\n";
    int flag = 0;
    if(!head){
        head = new node;
        head->next = NULL;
        ++flag;
    }
    return flag;
}
int stack::push(int data, char name[]){
    int flag = 0;
    if(!head){
        /*
        cerr << "\nPush init head\n";
        head = new node;
        head->next = NULL;
        head->data = data;
        copyTo(head->name,name);
        ++flag;
        */
        ///*
        if(init()){//should initialize head
            head->data = data;
            copyTo(head->name,name);
            ++flag;
        }
        //*/
    }
    else{
        node * temp = new node;//do I need to delete this? 10-17, No;
        temp->data = data;
        copyTo(temp->name,name);
        temp->next = head;
        head = temp;
        ++flag;
    }
    return flag;
};
int stack::pop(node * & head, int & data, char name[]){
    cerr << "--->pop:\n";
    int flag = 0;
    if(!head) return flag;
    node * temp = head->next;
    data = head->data;
    strcpy(name,head->name);
    cerr << "prepop\n";
    cerr << "-->temp->next: " << temp->next->data << ":" << temp->next->name << '\n';
    cerr << "-->head: " << head->data << ":" << head->name <<'\n';
    cerr << "-->temp: " << temp->data << ":" << temp->name <<"\n\n";
    delete head->name;
    delete head;
    head = temp;
    cerr << "postpop\n";
    cerr << "-->temp->next: " << temp->next->data << ":" << temp->next->name << '\n';
    cerr << "-->temp: " << temp->data << ":" << temp->name <<'\n';
    cerr << "-->head: " << head->data << ":" << head->name <<"\n\n";
    ++flag;
    return flag;
}
int stack::peek(){return 0;}
int stack::display(node * head, int i){
    cerr << "--->display recur\n";
    int flag = 0;
    if(!head){
        cerr << "--->display !head\n";
        return flag;
    }
    cout << "\nName: " << head->name << '\n';
    cout << "Data: " << head->data <<'\n';
    cout << "Count: " << i <<'\n';
    ++i;
    ++flag;
    display(head->next,i);
    return flag;
}

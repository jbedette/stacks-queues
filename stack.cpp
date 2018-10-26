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
    return display(head);
}
int stack::pop(int & data,char name[]){return pop(head,data,name);}
//

int stack::init(){
    cerr << "\n-->init\n";
    int flag = 0;
    if(!head){
        head = new node;
        head->data = new segment[6];
        head->next = NULL;
        ++flag;
    }
    return flag;
}
int stack::push(int data, char name[]){
    int flag = 0;
    if(!head){
        if(init()){//should initialize head
            head->data[top].dist = data;
            copyTo(head->data[top].name,name);
            ++top;
            ++flag;
        }
    }
    else if(topMod5(top)){
        node * temp = new node;
        temp->next = head;
        temp->data[0].dist = data;
        copyTo(head->data[0].name,name);
        top = 1;
        ++flag;
    }
    else{
        node * temp = new node;//do I need to delete this? 10-17, No;
        temp->data[top].dist = data;
        copyTo(temp->data[top].name,name);
        temp->next = head;
        head = temp;
        ++top;
        ++flag;
    }
    return flag;
};
/*
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
*/
int stack::peek(){return 0;}


int stack::display(node * head){
    cerr << "--->display recur\n";
    int flag = 0;
    if(!head){
        cerr << "\n--->display !head\n";
        return flag;
    }
    for(int i = 0; i < 5; ++i){
        cout << "\nName: " << head->data[i].name << '\n';
        cout << "Data: " << head->data[i].dist <<'\n';
    }
    ++flag;
    display(head->next);
    return flag;
}

#include "head.h"

stack::stack(){
    head = NULL;
    top = 0;
    cerr << "\nConstructing\n\n";
}
stack::~stack(){
    cerr << "\nDeconstructing\n\n";
}

//wrappers
int stack::display(){return display(head);}
int stack::pop(int & data,char name[]){return pop(head,data,name);}
//

int stack::init(){
    int flag = 0;
    if(!head){
        top = 0;
        head = new node;
        head->data = new segment[6];
        head->next = NULL;
        ++flag;
    }
    return flag;
}

//I could totally shrink this and just have one new node creation path
int stack::push(int data, char name[]){
    int flag = 0;
    if(!head){
        if(init()){//should initialize head
            cerr << "->push to empty arr";
            cerr << head->data[top].dist;
            head->data[top].dist = data;
            copyTo(head->data[top].name,name);
            ++top;
            ++flag;
        }
    }
    else if(topMod5(top)){
        cerr << "creating new node";
        node * temp = head;
        head = new node;
        head->next = temp;
        head->data = new segment[6];
        copyTo(head->data[0].name,name);
        head->data[0].dist = data;
        cerr << "\nNext Name: " << head->next->data[0].name << '\n';
        cerr << "Next Data: " << head->next->data[0].dist <<'\n';
        top = 1;
        ++flag;
    }
    else{
        cerr << "pushing to arr[" << top << "]\n";
        head->data[top].dist = data;
        copyTo(head->data[top].name,name);
        ++top;
        ++flag;
    }
    return flag;
};
int stack::pop(node * & head, int & data, char name[]){
    int flag = 0;
    if(!head) return flag;
    else if(--top <= 0){
        cerr << "\ntop: "<< top << "arr pop" << '\n';
        node * temp = head->next; 
        data = head->data[top].dist;
        strcpy(name, head->data[top].name);
        delete head->data[top].name;
        delete head->data[top].name;
        delete head->data;
        delete head;
        head = temp;
        top = 5;
    }else{
        cerr << "\ntop: "<< top << "reg pop" << '\n';
        data = head->data[top].dist;
        strcpy(name, head->data[top].name);//make client arr big
        delete head->data[top].name;
        head->data[top].name = NULL;
    }
    return flag;
}

int stack::peek(int & data, char name[]){
    if(!head)return 0;
    segment temp = head->data[top-1]; 
    strcpy(name,temp.name);
    data = temp.dist;
    return 1;
}


int stack::display(node * head){
    //cerr << "--->display recur\n";
    int flag = 0;
    if(!head){
        cerr << "\n--->display !head\n";
        return flag;
    }
    for(int i = 0; i < 5; ++i){
        char * outText = head->data[i].name;
        int outNum = head->data[i].dist;
        if(outNum && outText){
            cout << "\nName: " << head->data[i].name << '\n';
            cout << "Data: " << head->data[i].dist <<'\n';
        }
    }
    ++flag;
    display(head->next);
    return flag;
}

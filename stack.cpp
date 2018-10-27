#include "head.h"

stack::stack(){
    head = NULL;
    top = 0;
}
stack::~stack(){
}

//wrappers
int stack::display(){return display(head);}
int stack::pop(float & data,char name[]){return pop(head,data,name);}
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
int stack::push(float data, char name[]){
    int flag = 0;
    if(!head){
        if(init()){
            head->data[top].dist = data;
            head->data[top].name = new char[strlen(name)+1];
            strcpy(head->data[top].name,name);
            ++top;
            ++flag;
        }
    }
    else if(topMod5(top)){
        node * temp = head;
        head = new node;
        head->next = temp;
        head->data = new segment[6];
        head->data[0].name = new char[strlen(name)+1];
        strcpy(head->data[0].name,name);
        head->data[0].dist = data;
        top = 1;
        ++flag;
    }
    else{
        head->data[top].dist = data;
        head->data[top].name = new char[strlen(name)+1];
        strcpy(head->data[top].name,name);
        ++top;
        ++flag;
    }
    return flag;
};
int stack::pop(node * & head, float & data, char name[]){
    int flag = 0;
    if(!head) return flag;
    else if(--top <= 0){
        node * temp = head->next; 
        data = head->data[top].dist;
        strcpy(name, head->data[top].name);
        delete head->data[top].name;
        delete head->data;
        delete head;
        head = temp;
        top = 5;
    }else{
        data = head->data[top].dist;
        strcpy(name, head->data[top].name);//make client arr big
        delete head->data[top].name;
        head->data[top].name = NULL;
    }
    return flag;
}

int stack::peek(float & data, char name[]){
    if(!head)return 0;
    segment temp = head->data[top-1]; 
    strcpy(name,temp.name);
    data = temp.dist;
    return 1;
}


int stack::display(node * head){
    int flag = 0;
    if(!head){
        return flag;
    }
    for(int i = 0; i < 5; ++i){
        char * outText = head->data[i].name;
        float outNum = head->data[i].dist;
        if(outNum && outText){
            cout << "\nName: " << head->data[i].name << '\n';
            cout << "Data: " << head->data[i].dist <<'\n';
        }
    }
    ++flag;
    display(head->next);
    return flag;
}

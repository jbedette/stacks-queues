#include "head.h"


queue::queue(){
    rear = NULL;
    home = NULL;
    dest = NULL;
}
queue::~queue(){
    delete home;
    delete dest;
    delete method;
}
//wrappers
int queue::dequeue(float & data, char name[]){
    node * out = rear->next;
    if(out == rear){
        data = out->data->dist;
        strcpy(name,out->data->name);
        delete rear->data->name;
        delete rear->data;
        delete rear;
        rear = NULL;
    }else{
        data = out->data->dist;
        strcpy(name,out->data->name);
        rear->next = out->next;
        delete out->data->name;
        delete out->data;
        delete out;
        out->next = NULL;
        out = NULL;
    }
    return 0;
}
int queue::dispHomeDest(int opt){
    int flag = 0;
    if(opt)cout << dest;
    else cout << home;
    return flag;
}

//member functions
int queue::enqueue(float data, char name[]){
    //fi-fo
    int flag = 0;
    if(!rear){
        rear = new node;
        rear->data = new segment;
        rear->next = rear;
        rear->data->name = new char[strlen(name)+1];
        strcpy(rear->data->name,name);
        rear->data->dist = data;
        ++flag;
    }else{
        node * temp = rear;
        rear = new node;
        rear->data = new segment;
        rear->data->name = new char[strlen(name)+1];
        strcpy(rear->data->name,name);
        rear->data->dist = data;
        rear->next = temp->next;
        temp->next = rear;
        ++flag;
    }
    return flag;
}
int queue::peek(float & data, char name[]){
    data = rear->next->data->dist;
    strcpy(name,rear->next->data->name);
    return 0;
}
int queue::addMeth(char meth[]){
    method = new char[strlen(meth)+1];
    strcpy(method,meth);
    return 0;
}
int queue::dispMeth(){
    cout << "\n>The method of transportation is: " << method;
    return 0;
}
//testing
    
int queue::display(){
    int flag = 0;
    if(!rear){
        cerr << "\n--------!rear\n";
        return 0;
    }
    node * current = rear;
    current = current->next;
    cout << "\nname: " << current->data->name << '\n';
    cout << "\ndist: " << current->data->dist << '\n';
    while(current != rear){
    current = current->next;
    cout << "\nname: " << current->data->name << '\n';
    cout << "\ndist: " << current->data->dist << '\n';
    }
    return flag;
}
int queue::addHomeDest(char hIn[], char dIn[]){
    home = new char[strlen(hIn)+1];
    strcpy(home,hIn);
    dest = new char[strlen(dIn)+1];
    strcpy(dest,dIn);
    return 0;
}






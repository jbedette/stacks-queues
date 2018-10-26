#include "head.h"


queue::queue(){
    rear = NULL;
    cerr << "\nConstructing\n";
}
queue::~queue(){
    cerr << "\nDeconstructing\n";
}
//wrappers
int queue::dequeue(int & data, char name[]){
    //if only rear, destroy lll
    //else save rear->n->n
    //cour really shrink this with recursion
    //doesn't totally destroy LL
    node * out = rear->next;
    if(out == rear){
        cerr << "====out = rear";
        data = out->data->dist;
        strcpy(name,out->data->name);
        delete rear->data->name;
        delete rear->data;
        delete rear;
        rear = NULL;
    }
    data = out->data->dist;
    strcpy(name,out->data->name);
    rear->next = out->next;
    delete out->data->name;
    delete out->data;
    delete out;
    out->next = NULL;
    out = NULL;
    return 0;
}

//member functions
int queue::enqueue(int data, char name[]){
    cerr << "\nEnque\n";
    //fi-fo
    int flag = 0;
    if(!rear){
        rear = new node;
        rear->data = new segment;
        rear->next = rear;
        copyTo(rear->data->name, name);
        rear->data->dist = data;
        ++flag;
    }else{
        node * temp = rear;
        rear = new node;
        rear->data = new segment;
        copyTo(rear->data->name, name);
        rear->data->dist = data;
        rear->next = temp->next;
        temp->next = rear;
        ++flag;
    }
    return flag;
}
//testing
    
int queue::display(){
    cerr << "\ndisp: " << rear;
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






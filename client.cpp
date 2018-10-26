#include "head.h"
client::client(){
    myQue = NULL;
    myStack = NULL;
    count = 0;
}
client::~client(){
}
int client::init(){
    myQue = new queue;
    myStack = new stack;
}

void client::addSeg(){
    char name[100];
    int dist = 0;
    cout << "\n>What's the name of your travel segment?\n";
    cin.get(name,99,'\n');
    cin.clear();
    cin.ignore(100,'\n');
    /*
    cout << "\n>How many meters away is that?\n";
    cin >> dist;
    cin.clear();
    cin.ignore(15,'\n');
    */
    if(!myQue->enqueue(dist,name)){
        cout << "\n--ERR: failed to queue segment'\n";
    }else{
        ++count;
        cout << "\n>Would you like to enter another segment?\n";
        if(confirm()) addSeg();
    }
}

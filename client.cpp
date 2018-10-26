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
    return 0;
}

int client::addSeg(){
    char name[100];
    int dist = 0;
    cout << "\n>Travel Segment #" << count +1;
    cout << "\n>What's the name of your travel segment?: ";
    cin.get(name,99,'\n');
    cin.clear();
    cin.ignore(100,'\n');
    cout << "\n>How many meters away is that?: ";
    cin >> dist;
    cin.clear();
    cin.ignore(15,'\n');
    myQue->enqueue(dist,name);
    ++count;
    return 0;
}
int client::queToStack(){
    char out[100];
    int dist = 0;
    //myQue->display();
    for (int i = 0; i < count; ++i){
        myQue->dequeue(dist,out);
        cout << "\nStep #" << i+1;
        cout << "\nTitle: " << out;
        cout << "\nDistance: " << dist << " meters\n";
        myStack->push(dist,out);
    }
    return 0;
}
int client::stackPop(){
    char out[100];
    int dist = 0;
    for (int i = 0; i < count; --count){
        myStack->pop(dist,out);
        cout << "\nStep #" << count;
        cout << "\nTitle: " << out;
        cout << "\nDistance: " << dist << " meters\n";
    }
    return 0;
}
int client::peek(int opt){
    char out[100];
    int dist = 0;
    if(opt){
        myStack->peek(dist, out);
        cout << "\nStack";
    }
    else{
        myQue->peek(dist,out);
        cout << "\nQueue";
    }
    cout << " peek:\nTitle: " << out << "\nDistance: ";
    cout << dist << " meters";
    return 0;
}




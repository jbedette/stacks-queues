#include "head.h"
client::client(){
    myQue = NULL;
    myStack = NULL;
    count = 0;
}
client::~client(){
    myQue->~queue();
    delete myQue;
    delete myStack;
}
int client::init(){
    myQue = new queue;
    myStack = new stack;
    return 0;
}
int client::addDest(){
    char home[100];
    char dest[100];
    cout << "\n>Where are you leaving?\n";
    cin.get(home, 99 ,'\n');
    cin.clear();
    cin.ignore(100,'\n');
    cout << "\n>Where are you going?\n";
    cin.get(dest,99,'\n');
    cin.clear();
    cin.ignore(100,'\n');
    myQue->addHomeDest(home,dest);
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
    myQue->display();
    cout << "\nLeaving from: "<<myQue->dispHomeDest(0);
    for (int i = 0; i < count; ++i){
        myQue->dequeue(dist,out);
        cout << "\nStep #" << i+1;
        cout << "\nTitle: " << out;
        cout << "\nDistance: " << dist << " meters\n";
        myStack->push(dist,out);
    }
    cout << "\nArriving at: " <<myQue->dispHomeDest(1);
    return 0;
}
int client::stackPop(){
    char out[100];
    int dist = 0;
    cout << "\nLeaving from: "<<myQue->dispHomeDest(1);
    for (int i = 0; i < count; --count){
        myStack->pop(dist,out);
        cout << "\nStep #" << count;
        cout << "\nTitle: " << out;
        cout << "\nDistance: " << dist << " meters\n";
    }
    cout << "\nArriving at: " <<myQue->dispHomeDest(0);
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




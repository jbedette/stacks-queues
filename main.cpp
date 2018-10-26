#include "head.h"

int main(){
    client myClient;
    myClient.init();
    myClient.addDest();
    myClient.addSeg();
    myClient.addSeg();
    myClient.addSeg();
    myClient.addSeg();
    myClient.addSeg();
    myClient.addSeg();
    myClient.peek(0);
    cout << "\n\nNow we leave\n";
    myClient.queToStack();
    cout << "\n\nReady to come back?\n";
    if(confirm()){
        myClient.peek(1);
        myClient.stackPop();
    }

    return 0;
}


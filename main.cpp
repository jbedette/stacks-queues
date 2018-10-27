#include "head.h"

int main(){
    client myClient;
    myClient.init();
    myClient.addDest();
    myClient.addMeth();
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
    coutt << "\n\nGoodbye\n\n";

    return 0;
}


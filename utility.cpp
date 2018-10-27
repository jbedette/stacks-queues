#include "head.h"

bool topMod5(int top){
    return (top % 5 == 0) ? true : false;
}
bool confirm(){
    char y = ' ';
    cout << "\nEnter y to confirm: ";
    cin >> y;
    cin.clear();
    return (tolower(y)=='y') ? true : false;
}
    

#include "head.h"

int copyTo(char * & out,char in[]){
    int flag = 0;
    out = new char[strlen(in)+1];
    if(strcpy(out,in)) ++flag;
    return flag;
}
void charGet(char in[]){
    cin.get(in,99,'\n');
    cin.clear();
    cin.ignore(100,'\n');
}
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
    

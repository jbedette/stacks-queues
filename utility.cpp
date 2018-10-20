#include "head.h"

int copyTo(char * & out,char in[]){
    int flag = 0;
    out = new char[strlen(in)+1];
    if(strcpy(out,in)) ++flag;
    return flag;
}
void charGet(char in[]){
    cin.get(in,49,'\n');
    cin.clear();
    cin.ignore(50,'\n');
}
    

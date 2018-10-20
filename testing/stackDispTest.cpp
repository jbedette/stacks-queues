//#include "head.h"

int stack::display(){
    cerr << "--->display wrapper\n";
    return display(head, 0);
}
int stack::display(node * head, int i){
    cerr << "--->display recur\n";
    int flag = 0;
    if(!head){
        cerr << "--->display !head\n";
        return flag;
    }
    cout << "\nName: " << head->name << '\n';
    cout << "Data: " << head->data <<'\n';
    cout << "Count: " << i <<'\n';
    ++i;
    ++flag;
    display(head->next,i);
    return flag;
}

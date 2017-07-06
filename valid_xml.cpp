#include <iostream>
#include <string>
#include "linked_stack/stack.h"

using namespace std;
using namespace aedds;

int main(){
    Stack<char> tags;
    Stack<string> file;
    
    char elem;
    string tag = "";
    while(cin>>elem && !cin.eof()){
        cout<<elem<<endl;
        cout<<tags.front()<<endl;
        cout<<file.front()<<endl;
        if(elem=='<' && tags.getLength()==0){
            tags.push('<');
        }
        else if(elem=='>' && tags.getLength()>0){
            tags.pop();
            if(tag.size()>0){
                if(file.front()==tag) file.pop();
                else file.push(tag);
            }
            else{
                cout<<"Tag vazia."<<endl;
                cout<<"XML INVALIDO!!"<<endl;
                return 0;
            }
        }
        else if(elem!='<' && tags.getLength()>0){
            tag+=elem;
        }
        else{
            cout<<"Tag invalida."<<endl;
            cout<<"XML INVALIDO!!"<<endl;
            return 0;
        }
    }
    
    if(file.getLength()>0){
        cout<<"XML INVALIDO!!"<<endl;
        return 0;
    }
    else cout<<"XML VALIDO!!"<<endl;
}

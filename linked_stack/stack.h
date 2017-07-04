#ifndef STACK_H
#define STACK_H
#include <iostream>

#include <../linked_list/list.h>

using namespace std;
using namespace aedds;

namespace aedds{
template <class A>
class Stack: private List<A>{
    public:
        Stack(): List<A>::List();
        Stack(A _root): List<A>::List(A _root);
        
        A pop(){
            return List<A>::remove(List<A>::getLength()-1);
        }
        
        bool push(){
            return List<A>::insert(0);    
        }        
};
}

#endif //STACK_H

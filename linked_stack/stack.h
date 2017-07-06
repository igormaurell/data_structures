#ifndef STACK_H
#define STACK_H
#include <iostream>

#include "../linked_list/list.h"

using namespace std;
using namespace aedds;

namespace aedds{
template <class A>
class Stack: private List<A>{
    public:
        Stack(): List<A>::List(){}
        Stack(A _root): List<A>::List(_root){}
        
        A* pop(){
            return List<A>::remove(0);
        }
        
        bool push(A _elem){
            return List<A>::insert(0, _elem);    
        }

        Node<A> operator[](int _p){
            return *(List<A>::operator[](_p));
        }

        friend ostream& operator<<(ostream& _out, Stack<A> _stack){
            int i;
            _out<<"[";
            Node<A> *temp = _stack.List<A>::operator[](0);
            for(i = 0;i<_stack.getLength();i++){
                if(i!=_stack.getLength()-1) _out<<*temp<<", ";
                else _out<<*temp;
                temp = temp->getNext();    
            }
            _out<<"]";
            return _out;
        }        
};
}

#endif //STACK_H

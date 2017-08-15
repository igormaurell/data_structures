#ifndef STACK_H
#define STACK_H
#include <iostream>

#include "../list/list.h"

using namespace std;
using namespace aedds;

namespace aedds{
template <class A>
class Stack: private List<A>{
    private:
        A& operator[](int _p){
            return List<A>::operator[](_p);
        }

    public:
        Stack(): List<A>::List(){}
        Stack(A _root): List<A>::List(_root){}
        
        void pop(){
            List<A>::remove(0);
        }
        
        bool push(A _elem){
            return List<A>::insert(0, _elem);    
        }

        bool isEmpty(){
            return getSize()==0?true:false;
        }

        A& top(){
            return operator[](0);
        }

        int getSize(){
            return List<A>::getSize();
        }

        friend ostream& operator<<(ostream& _out, Stack<A> _stack){
            int i;
            _out<<"[";
            for(i = 0;i<_stack.getSize();i++){
                if(i!=_stack.getSize()-1) _out<<_stack[i]<<", ";
                else _out<<_stack[i];    
            }
            _out<<"]";
            return _out;
        }        
};
}

#endif //STACK_H

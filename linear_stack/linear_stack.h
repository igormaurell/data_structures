#ifndef LINEAR_STACK_H
#define LINEAR_STACK_H
#include <iostream>

#include "../vector/vector.h"

using namespace std;
using namespace aedds;

namespace aedds{
template <class A>
class LinearStack: private Vector<A>{
    private:
        A& operator[](int _p){
            return Vector<A>::operator[](_p);
        }

    public:
        LinearStack(): Vector<A>::Vector(){}
        LinearStack(int _len): Vector<A>::Vector(_len){}
        
        void pop(){
            Vector<A>::remove(0);
        }
        
        bool push(A _elem){
            return Vector<A>::insert(0, _elem);    
        }

        bool isEmpty(){
            return getSize()==0?true:false;
        }

        A& top(){
            return operator[](0);
        }

        int getSize(){
            return Vector<A>::getSize();
        }

        friend ostream& operator<<(ostream& _out, LinearStack<A> _linearStack){
            int i;
            _out<<"[";
            for(i = 0;i<_linearStack.getSize();i++){
                if(i!=_linearStack.getSize()-1) _out<<_linearStack[i]<<", ";
                else _out<<_linearStack[i];   
            }
            _out<<"]";
            return _out;
        }        
};
}

#endif //LINEAR_STACK_H

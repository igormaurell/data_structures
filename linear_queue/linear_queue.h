#ifndef LINEAR_QUEUE_H
#define LINEAR_QUEUE_H
#include <iostream>

#include "../vector/vector.h"

using namespace std;
using namespace aedds;

namespace aedds{
template <class A>
class LinearQueue: private Vector<A>{
    private:
        A& operator[](int _p){
            return Vector<A>::operator[](_p);
        }

    public:
        LinearQueue(): Vector<A>::Vector(){}
        LinearQueue(int _len): Vector<A>::Vector(_len){}
        
        void pop(){
            Vector<A>::remove(0);
        }
        
        bool push(A _elem){
            return Vector<A>::insert(getSize(), _elem);    
        }

        bool isEmpty(){
            return getSize()==0?true:false;
        }

        A& front(){
            return operator[](0);
        }

        A& back(){
            return operator[](getSize()-1);
        }        

        int getSize(){
            return Vector<A>::getSize();
        }

        friend ostream& operator<<(ostream& _out, LinearQueue<A> _linearQueue){
            int i;
            _out<<"[";
            for(i = 0;i<_linearQueue.getSize();i++){
                if(i!=_linearQueue.getSize()-1) _out<<_linearQueue[i]<<", ";
                else _out<<_linearQueue[i];    
            }
            _out<<"]";
            return _out;
        }        
};
}

#endif //LINEAR_QUEUE_H

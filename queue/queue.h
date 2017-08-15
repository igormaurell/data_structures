#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

#include "../list/list.h"

using namespace std;
using namespace aedds;

namespace aedds{
template <class A>
class Queue: private List<A>{
    private:
        A& operator[](int _p){
            return List<A>::operator[](_p);
        }

    public:
        Queue(): List<A>::List(){}
        Queue(A _root): List<A>::List(_root){}
        
        void pop(){
            List<A>::remove(0);
        }
        
        bool push(A _elem){
            return List<A>::insert(getSize(), _elem);    
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
            return List<A>::getSize();
        }

        friend ostream& operator<<(ostream& _out, Queue<A> _queue){
            int i;
            _out<<"[";
            for(i = 0;i<_queue.getSize();i++){
                if(i!=_queue.getSize()-1) _out<<_queue[i]<<", ";
                else _out<<_queue[i];    
            }
            _out<<"]";
            return _out;
        }        
};
}

#endif //QUEUE_H

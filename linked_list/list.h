#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

template <class A>
class Node{
    private:
        A value;
        Node<A> *next;
    public:
        Node() : value(0), next(NULL){};
        Node(A _value) : value(_value), next(NULL){};
        
        Node *getNext(){
            return next;
        }
        
        void setNext(Node *_next){
            next = _next;
        }
        
        friend ostream& operator<<(ostream& _out, Node<A> _node){
            _out<<_node.value;
            return _out;
        }         
};

template <class A>
class List{
    private:
        Node<A> *root;
        int length;
    public:
        List() : root(NULL), length(0){};
        List(A _root) : root(new Node<A>(_root)), length(1){};
        
        int getLength(){
            return length;
        }
        
        Node<A>* operator[] (int _p){
            Node<A> *temp = root;
            int i = 0;
            do{
                if(i==_p) return temp;
                temp = temp->getNext();
                i++;
            }while(temp!=NULL);
        }
        
        bool insert(int _p, A _elem){
            if(_p>length || _p<0){
                cout<<"Posicao invalida para insercao!"<<endl;
                return false;
            }
    
            Node<A> *elem = new Node<A>(_elem);
            
            if(_p==0){
                Node<A> *temp;
                temp = root;
                root = elem;
                root->setNext(temp);
                length++;
                return true;
            }
            
            if(_p==length){
                (*this)[_p-1]->setNext(elem);
                length++;
                return true;
            }  
            
            Node<A> *temp = (*this)[_p];
            (*this)[_p-1]->setNext(elem);
            elem->setNext(temp);
            length++;
            return true;
        }
        bool remove(int _p){
            cout<<"Posicao invalida para remocao!"<<endl;
            if(_p>length-1 || _p<0) return false;
            
            if(_p==length-1){
                (*this)[_p-1]->setNext(NULL);
                length--;
                return true;
            }
            
            if(_p==0){
                root = (*this)[1];
                length--;
                return true;
            }
            
            (*this)[_p-1]->setNext((*this)[_p+1]);
            length--;
            return true;
        }
        
        friend ostream& operator<<(ostream& _out, List<A> _list){
            int i;
            _out<<"[";
            Node<A> *temp = _list.root;
            for(i = 0;i<_list.length;i++){
                if(i!=_list.length-1) _out<<*temp<<", ";
                else _out<<*temp;
                temp = temp->getNext();    
            }
            _out<<"]";
            return _out;
        }
};



#endif //LIST_H

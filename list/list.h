#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;
namespace aedds{
template <class A>
class Node{
    private:
        A value;
        Node<A> *next;
    public:
        Node(): value(0, 0), next(NULL){}
        Node(A _value): value(_value), next(NULL){}
        
        Node *getNext(){
            return next;
        }
        
        A& getValue(){
            return value;
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
        int size;
                
        Node<A>* at(int _p){
            if(_p>=size || _p<0) return NULL;
            Node<A> *temp = root;
            int i = 0;
            do{
                if(i==_p) return temp;
                temp = temp->getNext();
                i++;
            }while(temp!=NULL);
        }
    public:
        List() : root(NULL), size(0){};
        List(A _root) : root(new Node<A>(_root)), size(1){};
        
        int getSize(){
            return size;
        }

        A& operator[] (int _p){
            A r;
            if(_p>=size || _p<0){
                cout<<"Posicao invalida. Objeto com valor qualquer retornado."<<endl;
                return r;
            }
            Node<A> *temp = root;
            int i = 0;
            do{
                if(i==_p) return temp->getValue();
                temp = temp->getNext();
                i++;
            }while(temp!=NULL);
        }
        
        bool insert(int _p, A _elem){
            if(_p>size || _p<0){
                cout<<"Posicao invalida para insercao."<<endl;
                return false;
            }
    
            Node<A> *elem = new Node<A>(_elem);
            
            if(_p==0){
                Node<A> *temp;
                temp = root;
                root = elem;
                root->setNext(temp);
                size++;
                return true;
            }
            
            if(_p==size){
                (*this).at(_p-1)->setNext(elem);
                size++;
                return true;
            }  
            
            Node<A> *temp = (*this).at(_p);
            (*this).at(_p-1)->setNext(elem);
            elem->setNext(temp);
            size++;
            return true;
        }

        void remove(int _p){
            A temp;
            if(_p>size-1 || _p<0){
                cout<<"Posicao invalida para remocao."<<endl;
                return;
            } 
            
            if(_p==size-1){
                (*this).at(_p-1)->setNext(NULL);
                size--;
                return;
            }
            
            if(_p==0){
                root = (*this).at(1);
                size--;
                return;
            }
            
            (*this).at(_p-1)->setNext((*this).at(_p+1));
            size--;
            return;
        }
        
        friend ostream& operator<<(ostream& _out, List<A> _list){
            int i;
            _out<<"[";
            Node<A> *temp = _list.root;
            for(i = 0;i<_list.size;i++){
                if(i!=_list.size-1) _out<<*temp<<", ";
                else _out<<*temp;
                temp = temp->getNext();    
            }
            _out<<"]";
            return _out;
        }
};
}

#endif //LIST_H

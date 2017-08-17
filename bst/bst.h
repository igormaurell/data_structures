#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

namespace aedds{
template <class A>
class Node{
    private:
        A key;
        Node<A>* left;
        Node<A>* right;
        
    public:
        Node(): key(0), left(NULL), right(NULL) {}
        Node(A _key): key(_key), left(NULL), right(NULL) {}
        
        Node<A>* getLeft(){
            return left;
        }
        Node<A>* getRight(){
            return right;
        }
        A getKey(){
            return key;
        }
        
        void setLeft(Node<A>* _left){
            left = _left;
        }
        void setLeft(A _keyleft){
            left = new Node<A>(_keyleft);
        }
        void setRight(Node<A>* _right){
            right = _right;
        }
        void setLeft(A _keyright){
            right = new Node<A>(_keyright);
        }
        
        friend ostream& operator<<(ostream& _out, Node<A> _node){
            _out<<_node.getKey();
            return _out;
        }
};

template <class A>
class Bst{
    private:
        Node<A>* root;
              
    public:
        Bst(): root(NULL) {}
        Bst(A _keyroot): root(new Node<A>(_keyroot)) {}
        void insertUtil(Node<A>* _node, A _key){
            if(_node==NULL){
                _node = Node<A>(_key);
                return;
            }        
        
            if(_key>root->getKey()) insertUtil(root->getRight(), _key);
            else if(_key<root->getKey()) insertUtil(root->getLeft(), _key);
            else{
                cout<<"Valor ja existe na Bst."<<endl;
                return;
            } 
        }
        void insert(A _key){
            insertUtil(root, _key);
        }       
};
}

#endif //BST_H

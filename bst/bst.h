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
        void setRight(Node<A>* _right){
            right = _right;
        }
        void setKey(A _key){
            key = _key;
        }
             
        friend ostream& operator<<(ostream& _out, Node<A> _node){
            if(_node.left==NULL)
                _out<<"(NULL)---(";
            else
                _out<<'('<<_node.left->getKey()<<")---(";
                
                _out<<_node.getKey();
                
            if(_node.right==NULL)
                _out<<")---(NULL)";
            else
                _out<<")---("<<_node.right->getKey()<<')';
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
            if(_key>_node->getKey()){
                if(_node->getRight()==NULL){
                    _node->setRight(new Node<A>(_key));
                }
                else insertUtil(_node->getRight(), _key);
            }
            else if(_key<_node->getKey()){
                if(_node->getLeft()==NULL){
                    _node->setLeft(new Node<A>(_key));
                }
                else insertUtil(_node->getLeft(), _key);
            }
            else{
                cout<<"Valor ja existe na Bst."<<endl;
                return;
            } 
        }
        void insert(A _key){
            if(root==NULL) root = new Node<A>(_key);
            else insertUtil(root, _key);
        }
        
        Node<A>* searchUtil(Node<A> *_node, A _key){
            if(_node==NULL) return NULL;
            if(_key>_node->getKey()){
                return searchUtil(_node->getRight(), _key);
            }
            else if(_key<_node->getKey()){
                return searchUtil(_node->getLeft(), _key);
            }
            else{
                return _node;
            }
        }
        Node<A>* search(A _key){
            return searchUtil(root, _key);
        }
        
        
        Node<A>* minValueNode(Node<A>* _root){
            if(_root==NULL) return NULL;
            
            Node<A>* temp;
            temp = minValueNode(_root->getLeft());
            if(temp==NULL) return _root;
            return temp;
        }
        void remove(A _key){
            Node<A> *del, *ch;
            del = search(_key);
            if(del==NULL) return;
            
            ch = del->getRight();
            ch = minValueNode(ch);
            if(ch==NULL){
                ch = del->getLeft();
                if(ch==NULL){
                    del = NULL;
                    return;
                }  
                del->setKey(ch->getKey());
                del->setLeft(NULL);                  
            }
            
            del->setKey(ch->getKey());
            del->setRight(NULL); 
        }
        void printByDfs(Node<A>* _node, ostream& _out) {
            _out<<*(_node)<<endl;
            if(_node->getLeft() != NULL) printByDfs(_node->getLeft(), _out);
            if(_node->getRight() != NULL) printByDfs(_node->getRight(), _out);
        }

        friend ostream& operator<< (ostream& _out, Bst<A> _tree) {
            _tree.printByDfs(_tree.root, _out);
            return _out;
        } 
};
}

#endif //BST_H

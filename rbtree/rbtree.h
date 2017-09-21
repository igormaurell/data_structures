#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>
using namespace std;

namespace aedds{

enum Color{
	BLACK, RED
};

template <class A>
class Node{
    private:
        A key;
        Node<A>* parent;
        Node<A>* left;
        Node<A>* right;
        Color color;
        
    public:
        Node(): key(0), left(NULL), right(NULL), color(BLACK) {}
        Node(A _key, Node<A>* _parent = NULL, Color _color = BLACK): key(_key), parent(_parent), left(NULL), right(NULL), color(_color) {}
        
        Node<A>* getLeft(){
            return left;
        }
        Node<A>* getRight(){
            return right;
        }
        Node<A>* getParent(){
        	return parent;
        }
        A getKey(){
            return key;
        }
        Color getColor(){
        	return color;
        }
        
        void setParent(Node<A>* _parent){
        	parent = _parent;
        }
        void setColor(Color _color){
        	color = _color;
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
class RBTree{         
    private:
        Node<A>* root;
        int blackHeight;
        
        void rightRotate(Node<A>* _root){
        	Node<A>* parent = _root->getParent();
        }
        void leftRotate(Node<A>* _root){
        	Node<A>* parent = _root->getParent();
        }
              
    public:
        RBTree(): root(NULL), blackHeigth(0) {}
        RBTree(A _keyroot): root(new Node<A>(_keyroot)), blackHeigth(1) {}
        
        void balance(Node<A>* _node){
        	Node<A>* parent = _node->getParent();
        	if(parent == root){
        		_node->setColor(BLACK);
        		blackHeight++;
        		return;
        	}
        	Node<A>* grandParent = parent->getParent();
        	Node<A>* uncle = (grandParent->getLeft() != parent) ? grandParent->getLeft() : grandParent->getRight();
        	
        	
        	if(parent.getColor() == RED){
        
        		if(uncle->getColor() == RED){
        			parent->setColor(BLACK);
        			uncle->setColor(BLACK);
        			grandParent->setColor(RED);
        			balance(grandParent);
        		}
        		
        		else if(uncle->getColor() == BLACK){
        			if(grandParent->getLeft() == parent && parent->getLeft() == _node) { //LLC
        				rightRotate(grandParent);
        			}
        			else if(grandParent->getLeft() == parent && parent->getRight() == _node) { //LRC
        				grandParent->setLeft(_node);
        				_node->setLeft(parent);
        				rightRotate(grandParent);
        			}
        			else if(grandParent->getRight() == parent && parent->getRight() == _node) { //RRC
        				leftRotate(grandParent);
        			}
        			else{ //RLC
        				grandParent->setRight(_node);
        				_node->setRight(parent);
        				leftRotate(grandParent);
        			}
        		}
        	}
        }
        
        void insertUtil(Node<A>* _node, A _key){
            if(_key>_node->getKey()){
                if(_node->getRight()==NULL){
                    _node->setRight(new Node<A>(_key, _node, RED));
                    balance(_node->getRight());
                }
                else insertUtil(_node->getRight(), _key);
            }
            else if(_key<_node->getKey()){
                if(_node->getLeft()==NULL){
                    _node->setLeft(new Node<A>(_key, _node, RED));
                    balance(_node->getLeft());
                }
                else insertUtil(_node->getLeft(), _key);
            }
            else{
                cout<<"Valor ja existe na RBTree."<<endl;
                return;
            } 
        }
        void insert(A _key){
            if(root==NULL) root = new Node<A>(_key);
            else insertUtil(root, _key);
        }
        
        
        /*Node<A>* searchUtil(Node<A> *_node, A _key){
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
        }*/
};
}

#endif //RBTREE_H

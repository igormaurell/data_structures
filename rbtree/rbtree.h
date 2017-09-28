#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>
using namespace std;

namespace aedds{

enum Color{
	BLACK, RED
};

template <class A>
class RBNode{
    private:
        A key;
        RBNode<A>* parent;
        RBNode<A>* left;
        RBNode<A>* right;
        Color color;
        
    public:
        RBNode(): key(0), left(NULL), right(NULL), color(BLACK) {}
        RBNode(A _key, RBNode<A>* _parent = NULL, Color _color = BLACK): key(_key), parent(_parent), left(NULL), right(NULL), color(_color) {}
        
        RBNode<A>* getLeft(){
            return left;
        }
        RBNode<A>* getRight(){
            return right;
        }
        RBNode<A>* getParent(){
        	return parent;
        }
        A getKey(){
            return key;
        }
        Color getColor(){
        	return color;
        }
        
        void setParent(RBNode<A>* _parent){
        	parent = _parent;
        }
        void setColor(Color _color){
        	color = _color;
        }
        void setLeft(RBNode<A>* _left){
            left = _left;
        }
        void setRight(RBNode<A>* _right){
            right = _right;
        }
        void setKey(A _key){
            key = _key;
        }
             
        friend ostream& operator<<(ostream& _out, RBNode<A> _rbnode){
            if(_rbnode.left==NULL) _out<<"(NULL, BLACK)---(";
            else _out<<'('<<_rbnode.left->getKey()<<", "<<(_rbnode.left->color?"RED":"BLACK")<<")---(";
                
            _out<<_rbnode.getKey()<<", "<<(_rbnode.color?"RED":"BLACK");
                
            if(_rbnode.right==NULL) _out<<")---(NULL, BLACK)";
            else _out<<")---("<<_rbnode.right->getKey()<<", "<<(_rbnode.right->color?"RED":"BLACK")<<')';
            
            return _out;
        }
};

template <class A>
class RBTree{         
    private:
        RBNode<A>* root;
        int blackHeight;
        
        void rightRotate(RBNode<A>* _node){
        	RBNode<A>* parent = _node->getParent();
        	RBNode<A>* newNode = _node->getLeft();
        	newNode->setRight(_node);
        	newNode->setColor(BLACK);
        	_node->setColor(RED);
        	newNode->getLeft()->setColor(RED);
        	if(parent->getLeft() == _node) parent->setLeft(newNode);
        	else parent->setRight(newNode);
        }
        void leftRotate(RBNode<A>* _node){
        	RBNode<A>* parent = _node->getParent();
        	RBNode<A>* newNode = _node->getRight();
        	newNode->setLeft(_node);
        	newNode->setColor(BLACK);
        	_node->setColor(RED);
        	newNode->getRight()->setColor(RED);
        	if(parent->getLeft() == _node) parent->setLeft(newNode);
        	else parent->setRight(newNode);
        }
              
    public:
        RBTree(): root(NULL), blackHeight(0) {}
        RBTree(A _keyroot): root(new RBNode<A>(_keyroot)), blackHeight(1) {}
        
        void balance(RBNode<A>* _rbnode){
            cout<<*(_rbnode)<<endl;
        	if(_rbnode == root){
        		_rbnode->setColor(BLACK);
        		blackHeight++;
        		return;
        	}
        	
        	RBNode<A>* parent = _rbnode->getParent();
            if(parent->getColor() == BLACK){
        	    return;
        	}
        	
        	RBNode<A>* grandParent = parent->getParent();
        	RBNode<A>* uncle = (grandParent->getLeft() != parent) ? grandParent->getLeft() : grandParent->getRight();
        	
    		if(uncle != NULL && uncle->getColor() == RED){
    			parent->setColor(BLACK);
    			uncle->setColor(BLACK);
    			grandParent->setColor(RED);
    			balance(grandParent);
    		}
    		
    		else if(uncle == NULL || uncle->getColor() == BLACK){
    			if(grandParent->getLeft() == parent && parent->getLeft() == _rbnode) { //LLC
    				rightRotate(grandParent);
    			}
    			else if(grandParent->getLeft() == parent && parent->getRight() == _rbnode) { //LRC
    				grandParent->setLeft(_rbnode);
    				_rbnode->setLeft(parent);
    				rightRotate(grandParent);
    			}
    			else if(grandParent->getRight() == parent && parent->getRight() == _rbnode) { //RRC
    				leftRotate(grandParent);
    			}
    			else{ //RLC
    				grandParent->setRight(_rbnode);
    				_rbnode->setRight(parent);
    				leftRotate(grandParent);
    			}
    		}
        	
        }
        
        void insertUtil(RBNode<A>* _rbnode, A _key){
            if(_key>_rbnode->getKey()){
                if(_rbnode->getRight()==NULL){
                    _rbnode->setRight(new RBNode<A>(_key, _rbnode, RED));
                    balance(_rbnode->getRight());
                }
                else insertUtil(_rbnode->getRight(), _key);
            }
            else if(_key<_rbnode->getKey()){
                if(_rbnode->getLeft()==NULL){
                    _rbnode->setLeft(new RBNode<A>(_key, _rbnode, RED));
                    balance(_rbnode->getLeft());
                }
                else insertUtil(_rbnode->getLeft(), _key);
            }
            else{
                cout<<"Valor ja existe na RBTree."<<endl;
                return;
            } 
        }
        void insert(A _key){
            if(root==NULL) root = new RBNode<A>(_key);
            else insertUtil(root, _key);
        }
        
        
        RBNode<A>* searchUtil(RBNode<A> *_rbnode, A _key){
            if(_rbnode==NULL) return NULL;
            if(_key>_rbnode->getKey()){
                return searchUtil(_rbnode->getRight(), _key);
            }
            else if(_key<_rbnode->getKey()){
                return searchUtil(_rbnode->getLeft(), _key);
            }
            else{
                return _rbnode;
            }
        }
        RBNode<A>* search(A _key){
            return searchUtil(root, _key);
        }
        
        void printByDfs(RBNode<A>* _node, ostream& _out) {
            _out<<*(_node)<<endl;
            if(_node->getLeft() != NULL) printByDfs(_node->getLeft(), _out);
            if(_node->getRight() != NULL) printByDfs(_node->getRight(), _out);
        }
        
        friend ostream& operator<< (ostream& _out, RBTree<A> _tree) {
            _tree.printByDfs(_tree.root, _out);
            return _out;
        }        
        
        /*RBNode<A>* minValueNode(RBNode<A>* _root){
            if(_root==NULL) return NULL;
            
            RBNode<A>* temp;
            temp = minValueNode(_root->getLeft());
            if(temp==NULL) return _root;
            return temp;
        }
        void remove(A _key){
            RBNode<A> *del, *ch;
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

#ifndef AVL_H
#define AVL_H

#include <iostream>
using namespace std;

namespace aedds{
template <class A>
class Node{
    private:
        A key;
        Node<A>* left;
        Node<A>* right;
        int height;
        
    public:
        Node(): key(0), left(NULL), right(NULL), height(1) {}
        Node(A _key): key(_key), left(NULL), right(NULL), height(1) {}
        
        Node<A>* getLeft(){
            return left;
        }
        Node<A>* getRight(){
            return right;
        }
        A getKey(){
            return key;
        }

        int getHeight(){
            return height;
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

        void setHeight(int _height){
            height = _height;
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
class Avl{         
    private:
        Node<A>* root;

        Node<A>* rightRotate(Node<A>* _node){
            Node<A>* left = _node->getLeft();
            Node<A>* left_right = left->getRight();

            _node->setLeft(left_right);
            left->setRight(_node);

            int h1 = 0, h2 = 0;
            if(_node->getLeft() != NULL) h1 = _node->getLeft()->getHeight();
            if(_node->getRight() != NULL) h2 = _node->getRight()->getHeight();
            _node->setHeight(1 + h1 > h2 ? h1 : h2);

            h1 = 0, h2 = 0;
            if(left->getLeft() != NULL) h1 = left->getLeft()->getHeight();
            if(left->getRight() != NULL) h2 = left->getRight()->getHeight();
            left->setHeight(1 + h1 > h2 ? h1 : h2);

            return left;
        }

        Node<A>* leftRotate(Node<A>* _node){
            Node<A>* right = _node->getRight();
            Node<A>* right_left = right->getLeft();

            _node->setRight(right_left);
            right->setLeft(_node);

            int h1 = 0, h2 = 0;
            if(_node->getLeft() != NULL) h1 = _node->getLeft()->getHeight();
            if(_node->getRight() != NULL) h2 = _node->getRight()->getHeight();
            _node->setHeight(1 + h1 > h2 ? h1 : h2);

            h1 = 0, h2 = 0;
            if(right->getLeft() != NULL) h1 = right->getLeft()->getHeight();
            if(right->getRight() != NULL) h2 = right->getRight()->getHeight();
            right->setHeight(1 + h1 > h2 ? h1 : h2);

            return right;
        }
              
    public:
        Avl(): root(NULL) {}
        Avl(A _keyroot): root(new Node<A>(_keyroot)) {}
        
        Node<A>* insertUtil(Node<A>* _node, A _key){
            if(_node == NULL)
                return (new Node<A>(_key));
            if(_key < _node->getKey())
                _node->setLeft(insertUtil(_node->getLeft(), _key));
            else if(_key > _node->getKey())
                _node->setRight(insertUtil(_node->getRight(), _key));
            else {
                cout<<"Valor ja existe na avl."<<endl;
                return _node;
            }

            int h1 = 0, h2 = 0;
            if(_node->getLeft() != NULL) h1 = _node->getLeft()->getHeight();
            if(_node->getRight() != NULL) h2 = _node->getRight()->getHeight();
            _node->setHeight(1 + h1 > h2 ? h1 : h2);

            int deltah = h1 - h2;

            if(deltah > 1 && _key < _node->getLeft()->getKey())
                return rightRotate(_node);
            
            if(deltah < -1 && _key > _node->getRight()->getKey())
                return leftRotate(_node);
            
            if(deltah > 1 && _key > _node->getLeft()->getKey()){
                _node->setLeft(leftRotate(_node->getLeft()));
                return rightRotate(_node);
            }
            
            if(deltah < -1 && _key < _node->getRight()->getKey()){
                _node->setRight(rightRotate(_node->getRight()));
                return leftRotate(_node);
            }
            return _node;
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

        friend ostream& operator<< (ostream& _out, Avl<A> _tree) {
            _tree.printByDfs(_tree.root, _out);
            return _out;
        } 
};
}

#endif //AVL_H

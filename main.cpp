#include "vector/vector.h"
#include "list/list.h"
#include "linear_stack/linear_stack.h"
#include "stack/stack.h"
#include "linear_queue/linear_queue.h"
#include "queue/queue.h"
//#include "bst/bst.h"
//#include "rbtree/rbtree.h"
#include "avl/avl.h"

#include "nodes/point2d.h"

using namespace aedds;
int main(){
    /*Point2D p1(0, 0), p2(10, 10), p3(10, 30), p4(31, 22);

    Vector<Point2D> vector(4);
    List<Point2D> list;
    LinearStack<Point2D> linear_stack;
    Stack<Point2D> stack;
    LinearQueue<Point2D> linear_queue;
    Queue<Point2D> queue;
    Bst<int> bst;*/
    //RBTree<int> tree;
    Avl<int> tree;
    
    /*vector.insert(0, p1);
    vector.insert(1, p2);
    vector.insert(2, p3);
    vector.insert(3, p4);
    cout<<vector<<endl;
    
    list.insert(0, p4);
    list.insert(1, p3);
    list.insert(2, p2);
    list.insert(3, p1);
    cout<<list<<endl;

    linear_stack.push(p3);
    linear_stack.push(p1);
    linear_stack.push(p4);
    linear_stack.push(p2);
    linear_stack.pop();
    cout<<linear_stack<<endl;

    stack.push(p4);
    stack.push(p2);
    stack.push(p1);
    stack.push(p3);
    cout<<stack<<endl;

    linear_queue.push(p2);
    linear_queue.push(p1);
    linear_queue.push(p4);
    linear_queue.push(p3);
    cout<<linear_queue<<endl;

    queue.push(p3);
    queue.push(p2);
    queue.push(p4);
    queue.push(p1);
    cout<<queue<<endl;
    
    bst.insert(10);
    bst.insert(15);
    bst.insert(6);
    bst.insert(14);
    bst.insert(21);
    bst.insert(13);
    bst.remove(15);
    bst.remove(14);
    
    cout<<*(bst.search(10))<<endl;
    cout<<*(bst.search(6))<<endl;
    cout<<*(bst.search(21))<<endl;
    cout<<*(bst.search(13))<<endl;*/
    
    tree.insert(20);
    tree.insert(15);
    tree.insert(5);
    tree.insert(17);
    tree.insert(16);
    tree.insert(25);
    tree.insert(10);
    tree.insert(30);
    tree.insert(13);
    cout<<tree<<endl;
    
}

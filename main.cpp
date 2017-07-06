#include "linear_list/vector.h"
#include "linked_list/list.h"
#include "linked_stack/stack.h"
#include "nodes/point2d.h"

using namespace aedds;
int main(){
    Point2D p1(0, 0), p2(10, 10), p3(10, 30), p4(31, 22);
    Vector<Point2D> vector(4);
    List<Point2D> list;
    Stack<Point2D> stack;
    
    vector.insert(0, p1);
    vector.insert(1, p2);
    vector.insert(2, p3);
    vector.insert(3, p4);
    cout<<vector<<endl;
    
    list.insert(0, p4);
    list.insert(1, p3);
    list.insert(2, p2);
    list.insert(3, p1);
    cout<<list<<endl;

    stack.push(p3);
    stack.push(p1);
    stack.push(p4);
    stack.push(p2);
    cout<<stack<<endl;
}

#include "linear_list/vector.h"
#include "linked_list/list.h"
#include "nodes/point2d.h"

using namespace aedds;
int main(){
    Point2D p1(0, 0), p2(10, 10), p3(10, 30), p4(31, 22);
    Vector<Point2D> vector(4);
    
    List<Point2D> list;
    
    vector.insert(0, p1);
    vector.insert(1, p2);
    vector.insert(2, p3);
    vector.insert(3, p4);
    
    cout<<vector<<endl;
    
    list.insert(0, p4);
    list.insert(1, p3);
    list.insert(2, p2);
    list.insert(3, p1);
    //Point2D p5 = list.remove(0);
    
    
    cout<<list<<endl;
}

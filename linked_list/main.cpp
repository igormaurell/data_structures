#include "list.h"
#include "point2d.h"
#include <iostream>

using namespace std;

int main(){
    Point2D p1(0, 0), p2(10, 10), p3(10, 30);
    List<Point2D> l;
    
    l.insert(0, p1);
    l.insert(1, p2);
    l.insert(2, p3);
    l.remove(-1);
    
    cout<<l<<endl;
}

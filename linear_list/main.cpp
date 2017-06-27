#include "list.h"
#include "point2d.h"

int main(){
    Point2D p1(0, 0), p2(10, 10), p3(10, 30);
    List<Point2D> list(4);
    
    list.insert(0, p1);
    list.insert(1, p2);
    list.insert(2, p3);
    list.remove(0);
    
    cout<<list<<endl;
}

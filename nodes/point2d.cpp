#include "point2d.h"
//Point2D
Point2D::Point2D(): x(0), y(0){}

Point2D::Point2D(int _x, int _y): x(_x), y(_y){}

Point2D::Point2D(Point2D &_p): x(_p.getX()), y(_p.getY()){}

int Point2D::getX(){
    return x;
}
int Point2D::getY(){
    return y;
}

ostream& operator<<(ostream& _out, Point2D _p){
	_out<<'('<<_p.getX()<<", "<<_p.getY()<<')';
	return _out;
}

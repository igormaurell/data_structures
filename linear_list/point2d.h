#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
using namespace std;

class Point2D{
	private:
		int x;
		int y;
	public:
		Point2D();
		Point2D(int _x, int _y);
		Point2D(Point2D &_n);
		
		int getX();
		int getY();
		
		friend ostream& operator<<(ostream& _out, Point2D _n);	
};

#endif //POINT2D_H

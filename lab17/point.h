#ifndef Point_H
#define Point_H
#include <iostream>
#include <stdexcept>

class Point {
private:
	int x;
	int y;
	int z;
public:
	Point() { x = 0; y = 0; z = 0; }
	Point(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	friend std::ostream& operator<<(std::ostream& out, const Point& point) {
		out << "( " << point.x << ", " << point.y << ", " << point.z << " )";
		return out;
	}
	friend Point operator+(const Point& p1, const Point& p2) {
		return Point(p1.x + p2.x, p1.y + p2.y, p1.z + p2.z);
	}
};

#endif
#ifndef MASSIVE_POINT_H_INCLUDED
#define MASSIVE_POINT_H_INCLUDED
class Point;
class Vector;
class Massive_Point : public Point
{
public:
	Massive_Point(Vector _speed, Vector _position) : Point(_speed, _position) {};

};
#endif
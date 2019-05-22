#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
class Vecotor;
class Ball
{
public:
	Vector speed;
	Vector position;
	double R;
	Ball(double x, double y, double vx, double vy, int r)
	{
		speed = Vector(vx, vy);
		position = Vector(x, y);
		R = r;
	}
	void move(double time)
	{
		Vector buff = position;
		position = buff + Vector(speed * time);
	}
};
#endif
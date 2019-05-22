#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
class Vector;
class Point
{
protected:
	Vector speed;
	Vector position;
	double radius;
	double mass;
public:
	Point(Vector _speed, Vector _position) : speed(_speed), position(_position) {};
	Vector get_speed()
	{
		return speed;
	};
	Vector get_position()
	{
		return position;
	};
	void set_speed(double X, double Y)
	{
		speed.setx(X);
		speed.sety(Y);
	};
	void set_speed(Vector & a)
	{
		speed = a;
	};
	void set_position(double X, double Y)
	{
		position.setx(X);
		position.sety(Y);
	};
	void move(double t)
	{
		double current_x = position.getx();
		double current_y = position.gety();
		current_x = current_x + speed.getx()*t;
		current_y = current_y + speed.gety()*t;
		position.setx(current_x);
		position.sety(current_y);
	};
	double getx()
	{
		return position.getx();
	}
	double gety()
	{
		return position.gety();
	}
	double get_speedx()
	{
		return speed.getx();
	}
	double get_speedy()
	{
		return speed.gety();
	}
	void reverse_speedx()
	{
		speed.inversex();
	}
	void reverse_speedy()
	{
		speed.inversey();
	}
	void collide(Point & b)
	{
		Vector centre = this->position - b.position;
		//std::cout << "centre: x = " << centre.getx() << " y = " << centre.gety() << std::endl;
		if (centre.getx() != 0 && centre.gety() != 0)
		{
			Vector v1 = centre.projection(this->speed);
			//std::cout << "v1: x = " << v1.getx() << " y = " << v1.gety() << std::endl;
			Vector v2 = this->speed - v1;
			//std::cout << "v2: x = " << v2.getx() << " y = " << v2.gety() << std::endl;
			Vector v3 = centre.projection(b.speed);
			//std::cout << "v3: x = " << v3.getx() << " y = " << v3.gety() << std::endl;
			Vector v4 = b.speed - v3;
			//std::cout << "v4: x = " << v4.getx() << " y = " << v4.gety() << std::endl;
			Vector tmp1 = v3 + v2;
			this->set_speed(tmp1);
			Vector tmp2 = v4 + v1;
			b.set_speed(tmp2);
		}
	}
};
#endif
#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
class Vector
{
private:
	double x;
	double y;
public:
	Vector(double _x =0, double _y = 0) : x(_x), y(_y) {};
	double get_length();
	void inversex();
	void inversey();
	void inverse();
	void setx(double k);
	void sety(double k);
	Vector operator+(Vector & b);
	Vector operator-(Vector & b);
	Vector operator*(double k);
	double operator*(Vector & b);
	Vector operator/(double k);
	Vector projection(Vector & b);
	double getx();
	double gety();
	friend Vector operator*(double k, Vector & b);
};



#endif
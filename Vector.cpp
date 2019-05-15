#include "Vector.h"
#include <math.h>

double Vector::get_length()
{
	return sqrt(x*x + y*y);
};
void Vector::inverse()
{
	x *= (-1);
	y *= (-1);
};
void Vector::inversex()
{
	x *= (-1);
};
void Vector::inversey()
{
	y *= (-1);
};
Vector Vector::operator+(Vector & b)
{
	return Vector(this->x + b.x, this->y + b.y);
};
Vector Vector::operator-(Vector & b)
{
	return Vector(this->x - b.x, this->y - b.y);
};
Vector Vector::operator*(double k)
{
	return Vector(this->x * k, this->y * k);
};
Vector Vector::operator/(double k)
{
	return Vector(this->x / k, this->y / k);
};
Vector operator*(double k, Vector & b)
{
	return (b * k);
};
double Vector::getx()
{
	return x;
};
double Vector::gety()
{
	return y;
};
void Vector::setx(double k)
{
	x = k;
};
void Vector::sety(double k)
{
	y = k;
};
double Vector::operator*(Vector & b)
{
	return (this->x * b.x + this->y * b.y);
};
Vector Vector::projection(Vector & b)
{
	Vector a = (*this);
	return a*(a*b) / (a.get_length() * a.get_length());
};

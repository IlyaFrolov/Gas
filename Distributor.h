#ifndef DISTRIBUTOR_H_INCLUDED
#define DISTRIBUTOR_H_INCLUDED
#include <math.h>
#include <vector>
#include <iostream>
class Vector;
class Point;
class Distributor
{
private:
	double mol_mass; //мол€рна€ масса
	double T; //тмепература
	const double R = 8.31; //no comments
	double A;
	int dir;
	int step;
	double r;
	double convert;
	double a;
	double get_part(double A, double a, double v)
	{
		double res = v * v * A * exp((-1) * a * v * v);
		return res;
	}
	void count_a()
	{
		a = mol_mass / (2 * R * T);
	}
	void count_A()
	{
		A = 4 * 3.1416 * pow(mol_mass / (2 * 3.1416 * R * T), 1.5);
	}
public:
	Distributor(double _convert)
	{ 
		T = 273; 
		mol_mass = 0.029; 
		dir = 10; 
		step = 10; 
		r = 0.03;
		convert = _convert; 
		count_A();
		count_a();
	};
	void set_mol_mass(double m)
	{
		if (m != 0)
		{
			mol_mass = m;
			count_A();
			count_a();
		}
	};
	void set_temperature(double t)
	{
		if (t != 0)
		{
			T = t;
			count_A();
			count_a();
		}
	};
	double get_mol_mass()
	{
		return mol_mass;
	};
	double get_temperature()
	{
		return T;
	};
	double set_num_of_directions(int n)
	{
		dir = n;
		return dir;
	};
	double set_step(int _step)
	{
		step = _step;
		return step;
	};
	double set_radius(double _r)
	{
		r = _r;
		return r;
	}
	std::vector<Point> & fill(std::vector<Point> & data, int number)
	{
		double V = sqrt(3 / a);
		std::cout << "V = " << V << std::endl;
		int current_number;
		double angle_step = 2 * 3.1416 / dir;
		int buff;
		for (int v = step; v < V; v += step)
		{
			current_number = (int)(number * step * get_part(A, a, v));
			std::cout <<v <<" "<< current_number << std::endl;
			buff = (int)(current_number / dir);
			for (int i = 0; i < dir; i++)
			{
				int add = data.size();
				for (int q = 0 + add; q < buff + add; q++)
				{
					data.push_back(Point(Vector(v * cos(i * angle_step + 0.1) / convert, v * sin(i * angle_step + 0.1) / convert), Vector(0, 0)));
				}
			}
		}
		std::cout << "filling finished" << std::endl;;
		return data;
	};


};




#endif
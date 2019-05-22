#include <glut.h>
#include <vector>
class Point;
class Distributor;
class Graphic
{
protected:
	int window;
	std::vector<int> tt1;
	std::vector<int> tt2;
	double b1, b2;
	unsigned int t1, t2;
public:
	std::vector<Point>* data;
	Graphic(std::vector<Point> * _data, int _window)
	{
		data = _data;
		window = _window;
		b1 = 0;
		b2 = 0;
	}
	void display_molecules()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0, 0, 0);
		glBegin(GL_POINTS);
		glVertex3f((*data)[0].getx(), (*data)[0].gety(), -1);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0, 1.0, 1.0);
		for (int i = 1; i < data->size(); i++) glVertex3f(((*data)[i].getx() / window), (*data)[i].gety(), -1);
		glEnd();
		if (window == 2)
		{
			glBegin(GL_POINTS);
			for (int i = 0; i < data->size(); i++) glVertex3f((((*data)[i].get_speedx() / 1000) / window) + 1 - 1.0 / (2 * window), (*data)[i].get_speedy() / 1000, -1);
			glEnd();
		}
	}
	void draw_rect(double x1, double y1, double x2, double y2, double c1, double c2, double c3)
	{
		glBegin(GL_POINTS);
		glColor3f(c1, c2, c3);
		for (int i = 1; i <= 10; ++i)
		{
			glVertex3f((x2 - x1)*0.1*i + x1, y1, -1);
			glVertex3f((x2 - x1)*0.1*i + x1, y2, -1);
			glVertex3f(x1, (y2 - y1)*0.1*i + y1, -1);
			glVertex3f(x2, (y2 - y1)*0.1*i + y1, -1);
		}
		glEnd();
	}
	void draw_graphic()
	{
		glBegin(GL_POINTS);
		glColor3f(0.5, 0.5, 0.1);
		for (int i = 0; i < 50; i++)glVertex3f(-1 + 0.01*i, 0, -1);
		glEnd();
		if (tt1.size() < 200)
		{
			tt1.push_back(t1);
			tt2.push_back(t2);
			if (tt1.size()>100)
			{
				glBegin(GL_POINTS);
				glColor3f(1.0, 0, 0);
				for (int i = 0; i < 20; ++i)glVertex3f(-1 + 0.005*i, b1 / 40.0, -1);
				glEnd();
				glBegin(GL_POINTS);
				glColor3f(1.0, 1.0, 1.0);
				for (int i = 0; i < 20; ++i)glVertex3f(-0.9 + 0.005*i, b2 / 40.0, -1);
				glEnd();
			}
		}
		else
		{
			b1 = this->average(tt1);
			std::cout << b1 << "   ";
			b2 = this->average(tt2);
			std::cout << b2 << std::endl;
			tt1.erase(tt1.begin(), tt1.begin() + 100);
			tt2.erase(tt2.begin(), tt2.begin() + 100);
		}
		t1 = 0;
		t2 = 0;
	}
	double average(std::vector<int> & d)
	{
		double buff = 0.0;
		for (int i = 0; i < d.size() / 2; i++) buff += d[i];
		return buff / d.size();
	}
	void update()
	{
		for (int i = 0; i < (*data).size(); i++)
		{
			if ((*data)[i].getx() >= 0 && (*data)[i].getx() <= 0.1)
			if ((*data)[i].gety() >= 0 && (*data)[i].gety() <= 0.1) ++t1;
			if ((*data)[i].getx() >= 0.2 && (*data)[i].getx() <= 0.3)
			if ((*data)[i].gety() >= 0.2 && (*data)[i].gety() <= 0.3) ++t2;
			if ((*data)[i].getx() >= 1 || (*data)[i].getx() <= -1)
			{
				(*data)[i].reverse_speedx();
			}
			if ((*data)[i].gety() >= 1 || (*data)[i].gety() <= -1 * window)
			{
				(*data)[i].reverse_speedy();
			}
			(*data)[i].move(0.00005);
		}
	}
	friend Distributor;
};
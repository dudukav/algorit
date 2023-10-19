#include <algorithm>
#include <iostream>
#include <cmath>

const double EPS = 1e-9;

struct	Point 
{
		double	x = 0;
		double	y = 0;
};

struct Line
{
		double a, b, c;
};

void	coeffitiens(double x1, double y1, double x2, double y2, Line& line)
{
		line.a = y2 - y1;
		line.b = x1 - x2;
		line.c = x2 * y1 - x1 * y2;
}

double	det(double x1, double y1, double x2, double y2)
{
		return x1 * y2 - x2 * y1;
}

bool	intersect(Line& line1, Line& line2, Point& point)
{
		double zn = det(line1.a, line1.b, line2.a, line2.b);
		if (abs(zn) < EPS)
		{
				return false;
		}
		point.x = -det(line1.c, line1.b, line2.c, line2.b) / zn;
		point.y = -det(line1.a, line1.c, line2.a, line2.c) / zn;
		return true;
}

bool	equivalent (Line& line1, Line& line2) 
{
		return abs(det(line1.a, line1.b, line2.a, line2.b)) < EPS
		&& abs(det(line1.a, line1.c, line2.a, line2.c)) < EPS
		&& abs(det(line1.b, line1.c, line2.b, line2.c)) < EPS;
}

int		main()
{
		Point	point;
		Line	line1;
		Line	line2;
		double x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		coeffitiens(x1, y1, x2, y2, line1);
		double x3, y3, x4, y4;
		std::cin >> x3 >> y3 >> x4 >> y4;
		coeffitiens(x3, y3, x4, y4, line2);

		if (intersect(line1, line2, point))
		{
				std::cout << 1 << ' ' << point.x << ' ' << point.y;
		}
		else if (equivalent(line1, line2))
		{
				std::cout << 2;
		}

		else 
		{
				std::cout << 0;
		}
		return 0;
}




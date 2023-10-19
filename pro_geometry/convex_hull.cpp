#include <iostream>
#include <vector>
#include <cmath>

struct Point 
{
    double x, y;
};

bool	comparator(Point a, Point b) 
{
		return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool	cw(Point a, Point b, Point c) 
{
		return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

bool	ccw(Point a, Point b, Point c)
{
		return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

void	convex_hull(std::vector<Point>& polygon) 
{
		if (polygon.size() == 1) 
		{
				return;
		}
		sort(polygon.begin(), polygon.end(), comparator);
		Point point1 = polygon[0];
		Point point2 = polygon.back();
		std::vector<Point> up, down;
		up.push_back(point1);
		down.push_back(point1);
		for (size_t i = 1; i < polygon.size(); ++i) 
		{
				if (i == polygon.size() - 1 || cw(point1, polygon[i], point2)) 
				{
						while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], polygon[i]))
						{
								up.pop_back();
						}	
						up.push_back(polygon[i]);
				}
				if (i == polygon.size() - 1 || ccw(point1, polygon[i], point2)) 
				{
						while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], polygon[i]))
						{
								down.pop_back();
						}
						down.push_back(polygon[i]);
				}
		}
		polygon.clear();
		for (size_t i = 0; i < up.size(); ++i)
		{
				polygon.push_back(up[i]);
		}
		for (size_t i = down.size() - 2; i > 0; --i)
		{
				polygon.push_back(down[i]);
		}
}

double	sq(const std::vector<Point>& polygon) 
{
		double res = 0;
		for (size_t i = 0; i < polygon.size(); ++i) 
		{
				Point p1 = i ? polygon[i - 1] : polygon.back();
				Point p2 = polygon[i];
				res += (p1.x - p2.x) * (p1.y + p2.y);
		}
		return fabs(res) / 2;
}

double	pr(const std::vector<Point>& polygon)
{
		double res = 0;
		for (size_t i = 0; i < polygon.size(); ++i)
		{
				Point p1 = polygon[i];
				Point p2 = polygon[(i + 1) % polygon.size()];
				res += sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
		}
		return res;
}

int		main()
{
		int n;
		std::cin >> n;
		std::vector<Point> polygon(n);

		for (size_t i = 0; i < n; ++i)
		{
				std::cin >> polygon[i].x >> polygon[i].y;
		}

		convex_hull(polygon);
		double per = pr(polygon);
		double square = sq(polygon);

		std::cout << per << " " << square;
		return 0;

}


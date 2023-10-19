#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

struct	Point 
{
		double x, y;
};

struct	Line 
{
		double a, b, c;
};

std::string	getSide(Point point, Line line) 
{
		double result = line.a * point.x + line.b * point.y + line.c;
		return result > 0 ? "1" : "0";
}

bool	Contains(std::unordered_set<std::string>& locations, std::string& point_position)	
{
		return locations.find(point_position) != locations.end();
}

int		main() 
{
		int n, m, r;
		std::cin >> n >> m >> r;

		std::vector<Point> points(n);
		std::vector<Line> lines(m);

		for (size_t i = 0; i < n; ++i) 
		{
				std::cin >> points[i].x >> points[i].y;
		}

		for (size_t i = 0; i < m; ++i) 
		{
				std::cin >> lines[i].a >> lines[i].b >> lines[i].c;
		}

		int counter = 0;
		std::unordered_set<std::string> point_position;
		for (size_t i = 0; i < n; ++i) 
		{
				std::string help;
				for (size_t j = 0; j < m; ++j) 
				{
						std::string pos = getSide(points[i], lines[j]);
						help += pos;
				}
				if (point_position.empty() || !Contains(point_position, help)) 
				{
						point_position.insert(help);
				} 
				else 
				{
						++counter;
				}
		}

		if (counter > 0) 
		{
					std::cout << "YES";
		} 
		else 
		{
				std::cout << "NO";
		}
		return 0;
}


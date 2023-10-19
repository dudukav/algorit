#include <iostream>
#include <vector>

struct	Point 
{
		double x, y;
};

struct Interval
{
		Point start;
		Point end;
};

bool	pointOninterval(Interval& interval, Point& point)
{
		double	dx = interval.end.x - interval.start.x;
		double	dy = interval.end.y - interval.start.y;
		double	dx_point = point.x - interval.start.x;
		double	dy_point = point.y - interval.start.y;
		return dx * dy_point == dx_point * dy && 
			   (std::max(interval.start.y, interval.end.y) >= point.y && 
			   std::min(interval.start.x, interval.end.x) <= point.x) &&
			   std::min(interval.start.y, interval.end.y) <= point.y &&
			   std::max(interval.start.x, interval.end.x) >= point.x;
}

bool	isInsidePolygon(Point point, const std::vector<Point> &polygon) {
		int n = polygon.size();
		int count = 0;
		for (int i = 0; i < n; i++) 
		{
				Point start = polygon[i];
				Point end = polygon[(i + 1) % n];
				Interval side = {start, end};
				if (pointOninterval(side, point)) 
				{
						return true;
				}
				if ((point.y < end.y && start.y <= point.y || point.y < start.y && end.y <= point.y) &&
					point.x < (end.x - start.x) * (point.y - start.y) / (end.y - start.y) + start.x) 
				{
						++count;
				}
		}
		return count % 2 == 1;
}

int		main() 
{
		int n;
		std::cin >> n;
		Point point;
		std::cin >> point.x >> point.y;
		std::vector<Point> polygon(n);

		for (int i = 0; i < n; ++i) 
		{
				std::cin >> polygon[i].x >> polygon[i].y;
		}

		if (isInsidePolygon(point, polygon)) 
		{
				std::cout << "YES";
		} 
		else 
		{
				std::cout << "NO";
		}
		return 0;
}

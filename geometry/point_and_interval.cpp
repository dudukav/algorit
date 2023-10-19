#include <algorithm>
#include <iostream>

struct	Point 
{
		double	x, y;
};

struct Interval 
{
		Point	start;
		Point	end;
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

int		main()
{
		Point point;
		Interval interval;

		std::cin >> point.x >> point.y;
		std::cin >> interval.start.x >> interval.start.y >> interval.end.x >> interval.end.y;
		if (pointOninterval(interval, point))
		{
				std::cout << "YES";
				return 0;
		}
		std::cout << "NO";
		return 0;
}





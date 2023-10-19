#include <iostream>

struct	Point 
{
		double	x, y;
};

struct Ray 
{
		Point	start;
		Point	end;
};

bool	pointOnRay(Ray& ray, Point& point)
{
		double	dx = ray.end.x - ray.start.x;
		double	dy = ray.end.y - ray.start.y;
		double	dx_point = point.x - ray.start.x;
		double	dy_point = point.y - ray.start.y;
		return dx * dy_point == dx_point * dy && dx * dx_point + dy * dy_point >= 0;
}

int		main()
{
		Point point;
		Ray ray;

		std::cin >> point.x >> point.y;
		std::cin >> ray.start.x >> ray.start.y >> ray.end.x >> ray.end.y;
		if (pointOnRay(ray, point))
		{
				std::cout << "YES";
				return 0;
		}
		std::cout << "NO";
		return 0;
}



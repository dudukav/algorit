#include <iostream>

int		main()
{
		double x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		double A = y2 - y1;
		double B = x1 - x2;
		double C = x2 * y1 - x1 * y2;
		std::cout << A << ' ' <<  B << ' ' << C << '\n';
		return 0;
}

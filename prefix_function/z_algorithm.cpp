#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

std::vector<size_t> ZFunction(const std::string& string)
{	
	size_t length = string.size();
	std::vector<size_t> z(length);
//	первый элемент - нулевое вхождение	
	z[0] = 0;

	for (size_t i = 1, l = 0, r = 0; i < length; ++i)
	{
//		если мы находимся внутри z-блока
		if (i <= r)
		{
			z[i] = std::min(r - i + 1, z[i - 1]);
		}

//		если мы не z-блоке, то мы идем до тех пор, пока не построим z-блок
//		(то есть, пока не встретиться символ, не входящий в префикс)
		while (i + z[i] - 1 < length && string[z[i]] == string[z[i] + i])
		{
			++z[i];
		}

//		проверка на то, выходим ли за границы z-блока	
		if (z[i] + i - 1 < r)
		{
			l = i;
			r = z[i] - 1;
			}
	}

		return z;
}

int main()
{
	std::string s;
	std::cin >> s;

	std::vector<size_t> z = ZFunction(s);
	for (size_t x : z)
	{
		std::cout << x << " ";
	}

	return 0;
}

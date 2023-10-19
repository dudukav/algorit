#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> ZFunction(const std::string& string)
{	
		int length = string.size();
		std::vector<int> z(length, 0);
	//	первый элемент - нулевое вхождение	
		z[0] = 0;
	
	//	0 1 2 3 4 5 6 7 8 9
	//	a b a b a b a c c a
		
		int l = 0, r = 0;
		for (int i = 1; i < length; ++i)
		{
	//			если мы находимся внутри z-блока
				z[i] = std::max(0, std::min(r - i - 1, z[i - l]));
	
	//			если мы не z-блоке, то мы идем до тех пор, пока не построим z-блок
	//			(то есть, пока не встретиться символ, не входящий в префикс)
				while (i + z[i] < length && string[z[i]] == string[z[i] + i])
				{
						++z[i];
				}
	
	//			проверка на то, выходим ли за границы z-блока	
				if (z[i] + i > r)
				{
						l = i;
						r = z[i] + i;
				}
		}
	
			return z;
}

int main()
{
		std::string substr, str;
		std::cin >> substr >> str;

		int	substr_size = substr.size();
		int	str_size = str.size();

		std::string concatenated_str;
		concatenated_str = substr + "#" + str;

		std::reverse(substr.begin(), substr.end());
		std::reverse(str.begin(), str.end());
		std::string reverse_concatenated = substr + "#" + str;


		std::vector<int> z = ZFunction(concatenated_str);
		std::vector<int> reverse_z = ZFunction(reverse_concatenated);

		int counter = 0;
		std::vector<int> position;
		for (int i = substr_size + 1; i + substr_size <= z.size(); ++i)
		{
				if (1 + z[i] + reverse_z[substr_size + str_size - i + 2] == substr_size||
					z[i] == substr_size)
				{
						++counter;
						position.push_back(i - substr_size);
				}
		}

		std::cout << counter << "\n";
		for (int i : position)
		{
				std::cout << i << " ";
		}

		return 0;
}


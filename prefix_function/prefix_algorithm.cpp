#include <iostream>
#include <string>
#include <vector>

std::vector<int64_t> PrefixFunction(const std::string& string)
{
	size_t length = string.size();
//	вектор из длин подсрок, совпадающих с префиксом
	std::vector<int64_t> pi(length);
//	первый элемент всегда нулевой по вхождению
	pi[0] = 0;

	for (size_t i = 1; i < length; ++i)
	{	
		int64_t max_prefix = pi[i - 1];
//		смотрим на совпадение с предыдущими символами, уменьшяаем до совпадения
		while (max_prefix > 0 && string[i] != string[max_prefix])
		{
			max_prefix = pi[max_prefix - 1];
		}
//		если совпадают, то прибавляем на 1 (соседние значения не могут
//		отличаться больше, чем на 1 )
		if (string[i] == string[max_prefix]) ++max_prefix;

//		значение в векторе становится равно счётчику	
		pi[i] = max_prefix;  
	}

	return pi;
}

int main()
{
	std::string s;
	std::cin >> s;

	std::vector<int64_t> pref = PrefixFunction(s);
	for (int64_t x : pref)
	{
		std::cout << x << " ";
	}

	return 0;
}

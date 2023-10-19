#include <iostream>
#include <vector>

struct Snowman 
{
		int mass = 0;
		int previous = 0;

		Snowman(int MASS, int PREVIOUS) 
		{
				mass = MASS;
				previous = PREVIOUS;
		}
};

int main()
{
		int n;
		std::cin >> n;
		std::vector<Snowman> snowmen_stack;
		snowmen_stack.reserve(n + 1);
		snowmen_stack.emplace_back(0, 0);
		int t, m;
		int64_t sum = 0;
		for (int i = 0; i < n; ++i) 
		{
				std::cin >> t >> m;
				if (m != 0)
				{
						snowmen_stack.emplace_back(snowmen_stack[t].mass + m, t);
				}
				else 
				{
						snowmen_stack.push_back(snowmen_stack[snowmen_stack[t].previous]);
				}
				sum += snowmen_stack[i + 1].mass;
		}
		std::cout << sum;
		return 0;
}

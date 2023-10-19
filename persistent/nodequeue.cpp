#include <cstdio>
#include <iostream>
#include <vector>
#include <deque>

struct NodeQueue {
    int				poisition;
	std::deque<int> data;
};

int main() 
{
		int		n;
		std::cin >> n;

		std::vector<NodeQueue> queues(1); 
		for (int i = 0; i < n; ++i) {
				int		cmd, t, m;
				std::cin >> cmd;

				if (cmd == 1) { 
						std::cin >> t >> m;

						NodeQueue new_queue = queues[t]; 
						new_queue.data.push_back(m); 
						new_queue.poisition = i + 1;
						queues.push_back(new_queue); 
				} 
				else
				{
						std::cin >> t;

						NodeQueue current_queue = queues[t]; 
						int		p = current_queue.data.front(); 
						current_queue.data.pop_front();
						std::cout << p << '\n';
						queues.push_back(current_queue); 
				}
		}

		return 0;
}

#include <iostream>
#include <string>
#include <vector>


// считаем контрольные позиции
int ControlBitsPosition(int n) 
{
    int r = 0;
    while ((1 << r) < n + r) 
        {
        ++r;
    }
    return r;
}

//вычисляем контрольные биты
void HammingCode(std::vector<int>& data) 
{
    int n = data.size();
    int r = ControlBitsPosition(n);

    for (int i = 0; i < r; i++) 
        {
        int control_bit_position = (1 << i);
        int control_bit_value = 0;

        for (int j = control_bit_position - 1; j < n; j += (2 * control_bit_position)) 
                {
            for (int k = 0; k < control_bit_position && j + k < n; k++) 
                        {
                control_bit_value ^= data[j + k];
            }
        }

        data[control_bit_position - 1] = control_bit_value;
    }
}

int main() 
{
        std::string bit_string;
        std::cin >> bit_string;

        std::vector<int> data;
		for (char bit : bit_string) {
        data.push_back(bit - '0');
		}

        int r = ControlBitsPosition(data.size());
        
        std::vector<int> new_data;
        int p = 0;
        
        for (int i = 0; i < data.size(); ++i) 
        {
                if (i != (1 << p) - 1)
                {
                        new_data.push_back(data[i]);
                } 
                else 
                {
                        new_data.push_back(0);
                        ++p;
                }
        }

		HammingCode(new_data);

        int error_pos = 0;
        for (int i = 0; i < data.size(); ++i)
        {
                if (new_data[i] != data[i])
                {
                        error_pos += (i + 1);
                }
        }

        if (error_pos != 0)
        {
			std::cout << error_pos - 1;
			return 0;
        }

    std::cout << -1;
    return 0;
}


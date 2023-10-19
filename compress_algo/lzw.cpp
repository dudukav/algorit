#include <iostream>
#include <string>
#include <vector>

std::string lzwDecompression(int K, std::vector<int>& codes) {
    std::vector<std::string> dictionary(128); // Инициализируем словарь со значениями ASCII-символов

    for (int i = 0; i < 128; i++) {
        dictionary[i] += char(i);
    }

    std::string result;
    std::string prevString = dictionary[codes[0]]; // Изначально предыдущая строка равняется первому кодированному фрагменту

    result += prevString; // Добавляем первую строку в результат

    int dictionarySize = 128; // Изначальный размер словаря равен 128

    for (int i = 1; i < K; i++) {
        int code = codes[i];

        std::string currentString;

        if (code < dictionarySize) {
            currentString = dictionary[code]; // Если код находится в словаре, берем соответствующую строку
        } else {
            currentString = prevString + prevString[0]; // Иначе создаем новую строку на основе предыдущей
        }

        result += currentString; // Добавляем текущую строку в результат

        dictionary.push_back(prevString + currentString[0]); // Добавляем новую строку в словарь

        prevString = currentString; // Обновляем предыдущую строку

        dictionarySize++; // Увеличиваем размер словаря
    }

    return result;
}

int main() {
    int K;
    std::cin >> K;

    std::vector<int> codes(K);

    for (int i = 0; i < K; i++) {
        std::cin >> codes[i];
    }

    std::string decompressedMessage = lzwDecompression(K, codes);

    std::cout << decompressedMessage << std::endl;

    return 0;
}


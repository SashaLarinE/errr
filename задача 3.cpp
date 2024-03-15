#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <cctype>

     // Функция для приведения слова к нижнему регистру
std::string toLowercase(const std::string& word) {
    std::string lowerWord = word;
    std::transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return lowerWord;
}

int main() {
    std::ifstream inputFile("f1.txt");
    std::ofstream outputFile("f2.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Failed to open files!" << std::endl;
        return 1;
    }

    std::map<std::string, int> wordFrequency;

    std::string word;
    while (inputFile >> word) {
       // Приводим слово к нижнему регистру
        word = toLowercase(word);
       // Удаляем знаки препинания
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
       // Увеличиваем счетчик частоты вхождения слова
        wordFrequency[word]++;
    }

       // Записываем результат в файл f2
    for (const auto& pair : wordFrequency) {
        outputFile << pair.first << " : " << pair.second << std::endl;
    }

    std::cout << "Word frequencies have been written to f2.txt" << std::endl;

    inputFile.close();
    outputFile.close();

    return 0;
}

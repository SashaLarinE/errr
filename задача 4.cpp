#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Employee {
    std::string name;
    std::string position;
};

struct Exhibit {
    std::string name;
    std::string description;
    int roomNumber;
};

struct MuseumActivity {
    std::vector<Employee> employees;
    std::vector<Exhibit> exhibits;
};

void saveDataToFile(const MuseumActivity& museum, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& employee : museum.employees) {
            file << "Employee: " << employee.name << " (" << employee.position << ")" << std::endl;
        }
        for (const auto& exhibit : museum.exhibits) {
            file << "Exhibit: " << exhibit.name << " - Room " << exhibit.roomNumber << std::endl;
            file << exhibit.description << std::endl;
        }
        file.close();
    }
    else {
        std::cerr << "Failed to open file for writing." << std::endl;
    }
}

int main() {
    MuseumActivity museum;

    // Добавляем некоторых сотрудников
    museum.employees.push_back({ "Alice", "Curator" });
    museum.employees.push_back({ "Denis", "Guide" });

    // Добавляем информацию о нескольких экспонатах
    museum.exhibits.push_back({ "Sculpture", "Ancient sculpture from Greece", 1 });
    museum.exhibits.push_back({ "Painting", "Famous painting by an artist", 2 });

    // Сохраняем данные в файл
    saveDataToFile(museum, "museum_data.txt");

    // Выводим информацию об экспонатах второго зала
    int roomNumberToDisplay = 2;
    std::cout << "Exhibits in Room " << roomNumberToDisplay << ":" << std::endl;
    for (const auto& exhibit : museum.exhibits) {
        if (exhibit.roomNumber == roomNumberToDisplay) {
            std::cout << exhibit.name << ": " << exhibit.description << std::endl;
        }
    }

    return 0;
}

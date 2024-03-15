#include <iostream>
#include <string>

// Абстрактный класс "Работник фирмы"
class Employee {
public:
    Employee(const std::string& name, double salary) : name(name), salary(salary) {}
    virtual void work() = 0; // Чисто виртуальная функция для работы

    void displayInfo() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Salary: $" << salary << std::endl;
    }

protected:
    std::string name;
    double salary;
};

// Класс "Менеджер", производный от "Работник фирмы"
class Manager : public Employee {
public:
    Manager(const std::string& name, double salary, int teamSize) : Employee(name, salary), teamSize(teamSize) {}

    void work() override {
        std::cout << name << " is managing a team of " << teamSize << " employees." << std::endl;
    }

private:
    int teamSize;
};

// Класс "Администратор", производный от "Работник фирмы"
class Administrator : public Employee {
public:
    Administrator(const std::string& name, double salary, std::string department) : Employee(name, salary), department(department) {}

    void work() override {
        std::cout << name << " is managing the administrative tasks of the " << department << " department." << std::endl;
    }

private:
    std::string department;
};

int main() {
    Manager manager("Lize", 5000.0, 5);
    Administrator admin("Denis", 4000.0, "HR");

    manager.displayInfo();
    manager.work();

    std::cout << std::endl;

    admin.displayInfo();
    admin.work();

    return 0;
}

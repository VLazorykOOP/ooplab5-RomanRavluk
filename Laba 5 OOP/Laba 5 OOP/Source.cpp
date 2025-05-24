#include <iostream>  
#include <string>    

using namespace std; 

// Базовий клас Person (Людина)
class Person {
protected:
    string fullName; // ПІБ людини
    int age; // Вік людини
    double weight; // Вага людини
public:
    // Конструктор класу Person з 3 параметрами
    Person(string name, int age, double weight)
        : fullName(name), age(age), weight(weight) {
    }  // Ініціалізація членів класу

// Конструктор класу Person з 2 параметрами
    Person(string name, int age)
        : fullName(name), age(age), weight(0.0) {
    }  // Вага встановлюється за замовчуванням

// Конструктор класу Person з 1 параметром
    Person(string name)
        : fullName(name), age(0), weight(0.0) {
    }  // Вік і вага встановлюються за замовчуванням

// Конструктор класу Person за замовчуванням
    Person() : fullName("Unknown"), age(0), weight(0.0) {}  // Встановлюємо значення за замовчуванням для всіх членів

    // Віртуальний деструктор
    virtual ~Person() {
        cout << "Destructor of Person called for " << fullName << endl;  // Повідомлення про виклик деструктора
    }

    // Віртуальна функція для друку інформації про людину
    virtual void print() const {
        cout << "Name: " << fullName << ", Age: " << age << ", Weight: " << weight << " kg" << endl;  // Виведення інформації про людину
    }

    // Функція для зміни віку
    void setAge(int newAge) {
        age = newAge;  // Зміна віку
    }
};

// Похідний клас Student (Школяр), який успадковує клас Person
class Student : public Person {
private:
    int grade; // Рік навчання (клас у школі)
public:
    // Конструктор класу Student з 4 параметрами
    Student(string name, int age, double weight, int grade)
        : Person(name, age, weight), grade(grade) {
    }  // Виклик конструктора базового класу та ініціалізація grade

// Конструктор класу Student з 3 параметрами
    Student(string name, int age, double weight)
        : Person(name, age, weight), grade(1) {
    }  // Виклик конструктора базового класу та встановлення grade за замовчуванням

// Конструктор класу Student з 2 параметрами
    Student(string name, int age)
        : Person(name, age), grade(1) {
    }  // Виклик конструктора базового класу та встановлення grade за замовчуванням

// Конструктор класу Student з 1 параметром
    Student(string name)
        : Person(name), grade(1) {
    }  // Виклик конструктора базового класу та встановлення grade за замовчуванням

// Конструктор класу Student за замовчуванням
    Student() : Person(), grade(1) {}  // Виклик конструктора за замовчуванням базового класу та встановлення grade за замовчуванням

    // Деструктор класу Student
    ~Student() {
        cout << "Destructor of Student called for " << fullName << endl;  // Повідомлення про виклик деструктора для студента
    }

    // Перевизначена функція друку інформації про школяра
    void print() const override {
        cout << "Student: " << fullName << ", Age: " << age << ", Weight: " << weight
            << " kg, Grade: " << grade << endl;  // Виведення інформації про студента, включаючи рік навчання
    }

    // Функція для зміни класу (року навчання)
    void setGrade(int newGrade) {
        grade = newGrade;  // Зміна класу
    }
};

int main() {
    // Створюємо об'єкти класу Person з різними конструкторами
    Person person1("Ihor Petrovich Ihorovych", 45, 80.5);  // Використовуємо конструктор з трьома параметрами
    Person person2("Anna Petriivna Ivanivna", 30);  // Використовуємо конструктор з двома параметрами
    Person person3("Oleh Vasulovich Mykolaiovych");  // Використовуємо конструктор з одним параметром
    Person person4;  // Використовуємо конструктор за замовчуванням

    person1.print();  // Друкуємо інформацію про person1
    person2.print();  // Друкуємо інформацію про person2
    person3.print();  // Друкуємо інформацію про person3
    person4.print();  // Друкуємо інформацію про person4

    // Створюємо об'єкти класу Student з різними конструкторами
    Student student1("Pavlo Andriyovych Petrenko", 15, 55.3, 9);  // Використовуємо конструктор з чотирма параметрами
    Student student2("Maria Olenivna Petrivna", 14, 50.0);  // Використовуємо конструктор з трьома параметрами
    Student student3("Taras Grugorovuch Shevchenko", 13);  // Використовуємо конструктор з двома параметрами
    Student student4("Artem Dmutrovuch Pavlenko");  // Використовуємо конструктор з одним параметром
    Student student5;  // Використовуємо конструктор за замовчуванням

    student1.print();  // Друкуємо інформацію про student1
    student2.print();  // Друкуємо інформацію про student2
    student3.print();  // Друкуємо інформацію про student3
    student4.print();  // Друкуємо інформацію про student4
    student5.print();  // Друкуємо інформацію про student5

    return 0;  // Завершуємо виконання програми
}
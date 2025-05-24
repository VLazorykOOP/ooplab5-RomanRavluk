#include <iostream>  
#include <string>    

using namespace std; 

// ������� ���� Person (������)
class Person {
protected:
    string fullName; // ϲ� ������
    int age; // ³� ������
    double weight; // ���� ������
public:
    // ����������� ����� Person � 3 �����������
    Person(string name, int age, double weight)
        : fullName(name), age(age), weight(weight) {
    }  // ����������� ����� �����

// ����������� ����� Person � 2 �����������
    Person(string name, int age)
        : fullName(name), age(age), weight(0.0) {
    }  // ���� �������������� �� �������������

// ����������� ����� Person � 1 ����������
    Person(string name)
        : fullName(name), age(0), weight(0.0) {
    }  // ³� � ���� �������������� �� �������������

// ����������� ����� Person �� �������������
    Person() : fullName("Unknown"), age(0), weight(0.0) {}  // ������������ �������� �� ������������� ��� ��� �����

    // ³��������� ����������
    virtual ~Person() {
        cout << "Destructor of Person called for " << fullName << endl;  // ����������� ��� ������ �����������
    }

    // ³�������� ������� ��� ����� ���������� ��� ������
    virtual void print() const {
        cout << "Name: " << fullName << ", Age: " << age << ", Weight: " << weight << " kg" << endl;  // ��������� ���������� ��� ������
    }

    // ������� ��� ���� ���
    void setAge(int newAge) {
        age = newAge;  // ���� ���
    }
};

// �������� ���� Student (������), ���� ��������� ���� Person
class Student : public Person {
private:
    int grade; // г� �������� (���� � ����)
public:
    // ����������� ����� Student � 4 �����������
    Student(string name, int age, double weight, int grade)
        : Person(name, age, weight), grade(grade) {
    }  // ������ ������������ �������� ����� �� ����������� grade

// ����������� ����� Student � 3 �����������
    Student(string name, int age, double weight)
        : Person(name, age, weight), grade(1) {
    }  // ������ ������������ �������� ����� �� ������������ grade �� �������������

// ����������� ����� Student � 2 �����������
    Student(string name, int age)
        : Person(name, age), grade(1) {
    }  // ������ ������������ �������� ����� �� ������������ grade �� �������������

// ����������� ����� Student � 1 ����������
    Student(string name)
        : Person(name), grade(1) {
    }  // ������ ������������ �������� ����� �� ������������ grade �� �������������

// ����������� ����� Student �� �������������
    Student() : Person(), grade(1) {}  // ������ ������������ �� ������������� �������� ����� �� ������������ grade �� �������������

    // ���������� ����� Student
    ~Student() {
        cout << "Destructor of Student called for " << fullName << endl;  // ����������� ��� ������ ����������� ��� ��������
    }

    // ������������� ������� ����� ���������� ��� �������
    void print() const override {
        cout << "Student: " << fullName << ", Age: " << age << ", Weight: " << weight
            << " kg, Grade: " << grade << endl;  // ��������� ���������� ��� ��������, ��������� �� ��������
    }

    // ������� ��� ���� ����� (���� ��������)
    void setGrade(int newGrade) {
        grade = newGrade;  // ���� �����
    }
};

int main() {
    // ��������� ��'���� ����� Person � ������ ��������������
    Person person1("Ihor Petrovich Ihorovych", 45, 80.5);  // ������������� ����������� � ������ �����������
    Person person2("Anna Petriivna Ivanivna", 30);  // ������������� ����������� � ����� �����������
    Person person3("Oleh Vasulovich Mykolaiovych");  // ������������� ����������� � ����� ����������
    Person person4;  // ������������� ����������� �� �������������

    person1.print();  // ������� ���������� ��� person1
    person2.print();  // ������� ���������� ��� person2
    person3.print();  // ������� ���������� ��� person3
    person4.print();  // ������� ���������� ��� person4

    // ��������� ��'���� ����� Student � ������ ��������������
    Student student1("Pavlo Andriyovych Petrenko", 15, 55.3, 9);  // ������������� ����������� � ������� �����������
    Student student2("Maria Olenivna Petrivna", 14, 50.0);  // ������������� ����������� � ������ �����������
    Student student3("Taras Grugorovuch Shevchenko", 13);  // ������������� ����������� � ����� �����������
    Student student4("Artem Dmutrovuch Pavlenko");  // ������������� ����������� � ����� ����������
    Student student5;  // ������������� ����������� �� �������������

    student1.print();  // ������� ���������� ��� student1
    student2.print();  // ������� ���������� ��� student2
    student3.print();  // ������� ���������� ��� student3
    student4.print();  // ������� ���������� ��� student4
    student5.print();  // ������� ���������� ��� student5

    return 0;  // ��������� ��������� ��������
}
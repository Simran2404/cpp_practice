#include <iostream>

struct Student
{
    char name[7];
    int id;
    int age;
};

struct Test
{
    char a = 0xAA;
    int b = 0xBBBBBBBB;
    short c = 0x9999;
};

struct Test2
{
    char a = 0xDD;
    short c = 0xEEEE;
    int b = 0xFFFFFFFF;
};

void print_student(Student st)
{
    std::cout << st.name << '\n';
    std::cout << st.id << '\n';
    std::cout << st.age << '\n';
}

int main()
{
    char student_name[] = "Simran";
    int student_id = 190906474;
    int student_age = 21;

    std::cout << student_name << '\n';
    std::cout << student_id << '\n';
    std::cout << student_age << '\n';

    Student s = {"Simran", 190906474, 21};
    print_student(&s);
}

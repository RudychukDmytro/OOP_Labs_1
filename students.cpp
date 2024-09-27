#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

struct Student
{
    std::string surname;
    std::string address;
    std::string phone;
};

void RW_students(const std::vector<Student> &students, const std::string &filename)
{
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open())
    {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    size_t numStudents = students.size();
    file.write(reinterpret_cast<const char *>(&numStudents), sizeof(numStudents));

    for (const auto &student : students)
    {
        size_t surnameSize = student.surname.size();
        file.write(reinterpret_cast<const char *>(&surnameSize), sizeof(surnameSize));
        file.write(student.surname.c_str(), surnameSize);

        size_t addressSize = student.address.size();
        file.write(reinterpret_cast<const char *>(&addressSize), sizeof(addressSize));
        file.write(student.address.c_str(), addressSize);

        size_t phoneSize = student.phone.size();
        file.write(reinterpret_cast<const char *>(&phoneSize), sizeof(phoneSize));
        file.write(student.phone.c_str(), phoneSize);
    }

    file.close();
}

void RD_students(const std::string &filename)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open())
    {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return;
    }

    size_t numStudents;
    file.read(reinterpret_cast<char *>(&numStudents), sizeof(numStudents));

    std::vector<Student> students;
    students.reserve(numStudents);

    for (size_t i = 0; i < numStudents; ++i)
    {
        Student student;

        size_t surnameSize;
        file.read(reinterpret_cast<char *>(&surnameSize), sizeof(surnameSize));
        student.surname.resize(surnameSize);
        file.read(&student.surname[0], surnameSize);

        size_t addressSize;
        file.read(reinterpret_cast<char *>(&addressSize), sizeof(addressSize));
        student.address.resize(addressSize);
        file.read(&student.address[0], addressSize);

        size_t phoneSize;
        file.read(reinterpret_cast<char *>(&phoneSize), sizeof(phoneSize));
        student.phone.resize(phoneSize);
        file.read(&student.phone[0], phoneSize);

        students.push_back(student);
    }

    file.close();

    std::sort(students.begin(), students.end(), [](const Student &a, const Student &b)
              { return a.address < b.address; });

    std::cout << "Students sorted by address:\n";
    for (const auto &s : students)
    {
        std::cout << s.surname << " - " << s.address << " ph.num:  " << s.phone << "\n";
    }
}

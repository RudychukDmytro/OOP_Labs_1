#include <iostream>
#include <vector>
#include <string>

struct Student
{
    std::string surname;
    std::string address;
    std::string phone;
};

struct Train
{
    int trainNumber;
    std::string destination;
    int departureHour;
    int departureMinute;
    int travelTime;
};

void RW_students(const std::vector<Student> &students, const std::string &filename);
void RD_students(const std::string &filename);
void RW_trains(const std::vector<Train> &trains, const std::string &filename);
void RD_trains(const std::string &filename);

int main()
{

    std::vector<Student> students = {
        {"Ivanov Ivan", "Khmelnytsky, Bohomoltsa str., 45 build", "0950011222"},
        {"Petrov Petro", "Kyiv, Hrushevskoho str., 12", "0932233445"},
        {"Sydorenko Sydor", "Poltava, Franka str., 56", "0975566778"},
        {"Kovalenko Andrii", "Dnipro, Shevchenka str., 24", "0503322114"},
        {"Shevchenko Taras", "Odessa, Deribasivska str., 11", "0731144777"},
        {"Bondarenko Oleg", "Vinnytsia, Soborna str., 29", "0965566778"},
        {"Tkachenko Ihor", "Poltava, Korolenka str., 5", "0669988776"},
        {"Mazurenko Olga", "Kharkiv, Gagarina str., 77", "0981122334"},
        {"Prykhodko Yulia", "Poltava, Pushkina str., 33", "0678899001"},
        {"Zubko Vasyl", "Cherkasy, Khreshchatyk str., 9", "0955544332"},
        {"Mazur Olena", "Kharkiv, Main str., 7", "0985555555"}};

    std::vector<Train> trains = {
        {101, "Ujhorod - Kyiv", 17, 45, 120},
        {102, "Vinnytsia - Lviv", 19, 20, 90},
        {103, "Lviv - Odessa", 16, 15, 180},
        {104, "Kyiv - Khmelnytsky", 13, 50, 130},
        {105, "Khmelnytsky - Kharkiv", 11, 10, 160},
        {106, "Khmelnytsky - Dnipro", 18, 0, 200},
        {107, "Lviv - Zhytomyr", 15, 30, 210},
        {108, "Khmelnytsky - Poltava", 20, 40, 180},
        {109, "Vinnytsia - Lviv", 17, 10, 140},
        {110, "Kyiv - Ujhorod", 12, 20, 70}};

    std::cout << "------------------STUDENTS------------------------" << std::endl;

    RW_students(students, "INFO.DAT");
    RW_trains(trains, "INFO.TXT");

    RD_students("INFO.DAT");
    std::cout << "------------------TRAINS------------------------" << std::endl;
    RD_trains("INFO.TXT");

    return 0;
}

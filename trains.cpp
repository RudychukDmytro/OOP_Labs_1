#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

struct Train
{
    int trainNumber;
    std::string destination;
    int departureHour;
    int departureMinute;
    int travelTime;
};

void RW_trains(const std::vector<Train> &trains, const std::string &filename)
{
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open())
    {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }
    for (const auto &train : trains)
    {

        file.write(reinterpret_cast<const char *>(&train.trainNumber), sizeof(train.trainNumber));
        size_t destinationSize = train.destination.size();
        file.write(reinterpret_cast<const char *>(&destinationSize), sizeof(destinationSize)); // Записуємо
        file.write(train.destination.c_str(), destinationSize);                                // Записуємо
        file.write(reinterpret_cast<const char *>(&train.departureHour), sizeof(train.departureHour));
        file.write(reinterpret_cast<const char *>(&train.departureMinute), sizeof(train.departureMinute));
        file.write(reinterpret_cast<const char *>(&train.travelTime), sizeof(train.travelTime));
    }
    file.close();
}

void RD_trains(const std::string &filename)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open())
    {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return;
    }

    Train train;
    std::vector<Train> trains;

    while (true)
    {

        file.read(reinterpret_cast<char *>(&train.trainNumber), sizeof(train.trainNumber));
        if (file.eof())
            break;

        size_t destinationSize;
        file.read(reinterpret_cast<char *>(&destinationSize), sizeof(destinationSize));

        train.destination.resize(destinationSize);
        file.read(&train.destination[0], destinationSize);

        file.read(reinterpret_cast<char *>(&train.departureHour), sizeof(train.departureHour));
        file.read(reinterpret_cast<char *>(&train.departureMinute), sizeof(train.departureMinute));
        file.read(reinterpret_cast<char *>(&train.travelTime), sizeof(train.travelTime));

        if (train.departureHour < 18 || (train.departureHour == 18 && train.departureMinute == 0))
        {
            trains.push_back(train);
        }
    }

    std::cout << "Trains departing before 18:00:\n";
    for (const auto &t : trains)
    {
        std::cout << "Train " << t.trainNumber << " " << t.destination
                  << " departs at " << t.departureHour << ":"
                  << (t.departureMinute < 10 ? "0" : "") << t.departureMinute
                  << ", travel time " << t.travelTime << " minutes.\n";
    }

    file.close();
}

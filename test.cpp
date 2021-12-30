#include <boost/date_time.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <conio.h>

const static std::string Days_Of_The_Week[] = {
    "Duminica",
    "Luni",
    "Marti",
    "Miercuri",
    "Joi",
    "Vineri",
    "Sambata"
};

int Date_To_Day(int day, int month, int year) {
    boost::gregorian::date date(year, month, day);
    return date.day_of_week();
}

int main()
{
    std::string input_string;
    std::cout << "Scrie data despartind-o prin spatii (ex. 30 12 2021)" << std::endl;
    std::cout << ">>  ";
    std::getline(std::cin, input_string);

    std::vector<std::string> date;
    std::stringstream input_stream(input_string);
    std::string buf;
    while (input_stream >> buf) {
        date.push_back(buf);
    }
    if ((int)date.size() > 3) {
        std::cout << "Mai mult de 3 numere au fost introduse\n";
        _getch();
        return EXIT_FAILURE;
    }
    if ((int)date.size() < 3) {
        std::cout << "Mai putin de 3 numere au fost introduse sau nu au fost despartite prin spatiu\n";
        _getch();
        return EXIT_FAILURE;
    }
    unsigned int arg_day;
    unsigned int arg_month;
    unsigned int arg_year;
    try {
        arg_day = stoi(date[0]);
        arg_month = stoi(date[1]);
        arg_year = stoi(date[2]);
    }
    catch (std::invalid_argument) {
        std::cout << "Argument invalid\n";
        _getch();
        return EXIT_FAILURE;
    }

    unsigned int index;
    try {
        index = Date_To_Day(arg_day, arg_month, arg_year);
    }
    catch(boost::gregorian::bad_day_of_month) {
        std::cout << "Data introdusa este invalida\n";
        _getch();
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cout << "Eroare nedefinita\n";
        _getch();
        return EXIT_FAILURE;
    }
    std::cout << "Ziua -> " + Days_Of_The_Week[index] << std::endl << std::endl;
    std::cout << "Press any key to continue . . .\n";
    _getch();
    return EXIT_SUCCESS;
}

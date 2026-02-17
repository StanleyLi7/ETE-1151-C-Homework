#include <iostream>
#include <iomanip>

bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    return false;
}

int getStartDay(int year, int month) {
    if (month < 3) {
        month += 12;
        year--;
    }

    int q = 1; 
    int m = month;
    int k = year % 100;
    int j = year / 100;

    int h = (q + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

    return (h + 6) % 7; 
}

int main() {
    int year;

    std::cout << "Enter a year  :  ";
    std::cin >> year;

    std::cout << "\nCalendar for " << year << "\n";

    std::string months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    int daysInMonth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    for (int month = 0; month < 12; month++) {

        std::cout << "\n--" << months[month] << " " << year << " --\n";
        std::cout << "  Mon   Tue   Wed   Thu   Fri   Sat   Sun\n";

        int startDay = getStartDay(year, month + 1);

        startDay = (startDay == 0) ? 6 : startDay - 1;

        for (int i = 0; i < startDay; i++) {
            std::cout << std::setw(6) << " ";
        }

        for (int day = 1; day <= daysInMonth[month]; day++) {
            std::cout << std::setw(6) << day;

            if ((day + startDay) % 7 == 0)
                std::cout << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}

#include <iostream>
#include <string>
#include <cmath>
#include "calendar.h"

//found this online because C++ needs to be indifferent for using negative modulus if my formula is to work
#define ma_mod(a,n) ((a % n) + n) % n //https://www.youtube.com/watch?v=gy3Ni-wFYR4&ab_channel=FastCodeDeveloper

using namespace std;

int calendar::calculate(int month, int day, int year){
    int day_of_the_week_number;
    //we need to pull the first two ints (century) and last two ints (year)
    int century = year / 100;

    if (month == 1 || month == 2) {
        month = month + 10;
        year = (year - year / 100 * 100) - 1;
    }

    else {
        month = month - 2;
        year = year - year / 100 * 100;
    }

    //formula below: https://cs.uwaterloo.ca/~alopez-o/math-faq/node73.html#:~:text=For%20a%20Gregorian%20date%2C%20add,7%20and%20take%20the%20remainder
    day_of_the_week_number = (day + (floor(2.6 * month - 0.2)) - (2 * century) + year + floor(year / 4) + (century / 4));
    day_of_the_week_number = ma_mod(day_of_the_week_number, 7);
    return day_of_the_week_number;
}

std::string calendar::day_to_string(int day_num){
    switch(day_num) {
        case (0):
            return "Sunday";

        case (1):
            return "Monday";

        case (2):
            return "Tuesday";

        case (3):
            return "Wednesday";

        case (4):
            return "Thursday";

        case (5):
            return "Friday";

        case (6):
            return "Saturday";
    }
}

std::string calendar::month_to_string(date date) {
    switch (date.month) {
        case (1):
            return "January";

        case (2):
            return "February";

        case (3):
            return "March";

        case (4):
            return "April";

        case (5):
            return "May";

        case (6):
            return "June";

        case (7):
            return "July";

        case (8):
            return "August";

        case (9):
            return "September";

        case (10):
            return "October";

        case (11):
            return "November";

        case (12):
            return "December";
    }
}

void calendar::calendar_print(date date, bool ly) {
    cout << "" << endl;
    cout << month_to_string(date) << endl;
    cout << date.year << endl;
    cout << "" << endl;
    //https://stackoverflow.com/questions/2485963/c-alignment-when-printing-cout
    cout.width(5); cout << left << "Su";
    cout.width(5); cout << left << "Mo";
    cout.width(5); cout << left << "Tu";
    cout.width(5); cout << left << "We";
    cout.width(5); cout << left << "Th";
    cout.width(5); cout << left << "Fr";
    cout.width(5); cout << left << "Sa" << endl;

    //we need to find the first of the month to simplify the printing process
    int first_day_of_the_month = calculate(date.month, 1, date.year);
    int month_length;

    if (date.month == 2) {
        if (ly == true) {
            month_length = 29;
        }
        else {
            month_length = 28;
        }
    }

    else if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) {
        month_length = 30;
    }

    else {
        month_length = 31;
    }

    //x is what we're using to hold our place, y is what we're counting up and printing
    int x = 1;
    int y = 1;

    while (x != -1) {
        //we need to start in the correct alignment
        if (x <= first_day_of_the_month) {
            cout.width(5); cout << left << "";
            x++;
        }

        //if we are past the month length then there's no reason to continue, we end the loop
        else if (x > month_length + first_day_of_the_month) {
            x = -1;
            cout.width(5); cout << left << "" << endl;
        }

        //if we reach saturday we need a new line after printing
        else if (x % 7 == 0) {
            cout.width(5); cout << left << y << endl;
            y++;
            x++;
        }

        //print normally
        else {
            cout.width(5); cout << left << y;
            y++;
            x++;
        }
    }
}

void calendar::holidays(date date) {
    //couldn't figure out how to do floating holidays such as Thanksgiving, could be a fun feature to add later
    cout << "" << endl;
    switch (date.month) {
        case (1):
            cout << day_to_string(calculate(1, 1, date.year)) << " " << date.month << "/" << 1 << "/" << date.year << " is New Years Day." << endl;
            cout << day_to_string(calculate(1, 7, date.year)) << " " << date.month << "/" << 7 << "/" << date.year << " is Orthodox Christmas." << endl;
            break;

        case (2):
            cout << day_to_string(calculate(2, 14, date.year)) << " " << date.month << "/" << 14 << "/" << date.year << " is Valentine's Day." << endl;
            break;

        case (3):
            cout << day_to_string(calculate(3, 17, date.year)) << " " << date.month << "/" << 17 << "/" << date.year << " is Saint Patrick's Day." << endl;
            break;

        case (4):
            cout << day_to_string(calculate(4, 1, date.year)) << " " << date.month << "/" << 1 << "/" << date.year << " is April Fools Day." << endl;
            break;

        case (5):
            break;

        case (6):
            break;

        case (7):
            cout << day_to_string(calculate(7, 4, date.year)) << " " << date.month << "/" << 4 << "/" << date.year << " is Independence Day." << endl;
            break;

        case (8):
            break;

        case (9):
            cout << day_to_string(calculate(9, 25, date.year)) << " " << date.month << "/" << 25 << "/" << date.year << " is Alex's Birthday." << endl;
            break;

        case (10):
            break;

        case (11):
            cout << day_to_string(calculate(11, 11, date.year)) << " " << date.month << "/" << 11 << "/" << date.year << " is Veteran's Day." << endl;
            break;

        case (12):
            cout << day_to_string(calculate(12, 24, date.year)) << " " << date.month << "/" << 24 << "/" << date.year << " is Christmas Eve." << endl;
            cout << day_to_string(calculate(12, 25, date.year)) << " " << date.month << "/" << 25 << "/" << date.year << " is Christmas Day." << endl;
            cout << day_to_string(calculate(12, 31, date.year)) << " " << date.month << "/" << 31 << "/" << date.year << " is New Years Eve." << endl;
            break;
    }
}
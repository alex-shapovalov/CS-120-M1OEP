/*
 * Alex Shapovalov
 * 1/24/2023 (Start Date)
 * M1OEP
 *
 * The purpose of this project is to create a complex calendar tool within the Gregorian Calendar.
 * The program is going to take in a specified date between 01/01/0001 and 12/31/9999 and print
 * out the day of the week of that date, the entire calendar for that month, and any holidays that are
 * in that month from a pre-programmed set of holidays. The calendar will function like any other calendar and
 * will include leap years.
 */

#ifndef M1OEP_ADSHAPOV_CALENDAR_H
#define M1OEP_ADSHAPOV_CALENDAR_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

typedef struct date {
    int day;
    int year;
    int month;
};

class calendar {
    public:
        /*
         * The calculate method is the backbone of the calendar application. It takes in a user inputted month, day,
         * and year and then calculates an integer (ex. 0-6 | 0 = Sunday, ... 6 = Saturday) which is passes back.
         *
         * int month - user inputted month
         * int day - user inputted day
         * int year - user inputted year
         * returns - 0-6 (corresponding to a day of the week)
         */
        int calculate(int month, int day, int year);

        /*
         * Day_to_string() is intended to take in a value from calculate() and return the name of that day (ex. 0 becomes
         * Sunday, 1 becomes Monday) I often used this method with calculate() at the same time.
         *
         * int day_num - an integer that represents which day of the week we want a string of
         * returns - the day in string form (ex. Monday, Tuesday)
         */
        std::string day_to_string(int day_num);

        /*
         * Month_to_string() is similar to day_to_string() but instead of taking in an int and printing the day,
         * we take in a date and print out a month using the date.month feature.
         *
         * date date - a structure which contains the user inputted date
         * returns - the month in string form (ex. January, February)
         */
        std::string month_to_string(date date);

        /*
         * Calendar_print() will be given a date structure along with a boolean which tells the function whether
         * it needs to consider a leap year for printing February. The method prints a header of all the days then
         * aligns the calendar and prints everyday day number until hitting the maximum days in the given month.
         *
         * date date - a structure which contains the user inputted date
         * bool ly - ly (leap year) tells the method whether it is a leap year or not
         * return - none
         */
        void calendar_print(date date, bool ly);

        /*
         * Holidays() is called at the very end in order to print out any holidays that happen to be contained
         * within a given month.
         *
         * date date - a structure which contains the user inputted date
         * return - none
         */
        void holidays(date date);
};

#endif //M1OEP_ADSHAPOV_CALENDAR_H

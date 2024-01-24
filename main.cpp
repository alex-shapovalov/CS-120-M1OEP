#include <iostream>
#include <string>
#include<limits>
#include "calendar.h"

using namespace std;

int main() {

    //ask for a month, day, and year
    int m; //month
    int d; //day
    int y; //year
    int input; //what the user inputs

    cout << "Hello. Welcome to Alex's Calendar Application." << endl;

    cout << "Enter a month (1-12): " << endl;
    cin >> input;
    while (input <= 0 || input >= 13) {
        cout << "Error: Invalid input." << endl;
        cout << "Enter a month (1-12): " << endl;
        cin.clear();                                                  //this code bit is from stack overflow (line 27-28)
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //https://stackoverflow.com/questions/19521320/why-do-i-get-an-infinite-loop-if-i-enter-a-letter-rather-than-a-number
        cin >> input;
    }
    m = input;

    //need to write out accurate instructions
    if (m == 2) { //february
        cout << "Enter a day (1-29): " << endl;
    }

    else if (m == 4 || m == 6 || m == 9 || m == 11) { //april, june, september, november
        cout << "Enter a day (1-30): " << endl;
    }

    else { //all other months
        cout << "Enter a day (1-31): " << endl;
    }
    cin >> input;

    while (input <= 0 || input >= 32) {
        cout << "Error: Invalid input." << endl;
        cout << "Enter a day (1-31): " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> input;
    }
    //making sure we're not exceeding month limits...
    while (m == 2 && (input <= 0 || input >= 30)) {
        cout << "Error: Invalid input. February cannot exceed 29 days." << endl;
        cout << "Enter a day (1-29): " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> input;
    }

    while (m == 4 && (input <= 0 || input >= 31)) {
        cout << "Error: Invalid input. April cannot exceed 30 days." << endl;
        cout << "Enter a day (1-30): " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> input;
    }

    while (m == 6 && (input <= 0 || input >= 31)) {
        cout << "Error: Invalid input. June cannot exceed 30 days." << endl;
        cout << "Enter a day (1-30): " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> input;
    }

    while (m == 9 && (input <= 0 || input >= 31)) {
        cout << "Error: Invalid input. September cannot exceed 30 days." << endl;
        cout << "Enter a day (1-30): " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> input;
    }

    while (m == 11 && (input <= 0 || input >= 31)) {
        cout << "Error: Invalid input. November cannot exceed 30 days." << endl;
        cout << "Enter a day (1-30): " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> input;
    }
    d = input;

    cout << "Enter a year (1-9999): " << endl;
    cin >> input;
    while (input <= 0 || input >= 10000) {
        cout << "Error: Invalid input." << endl;
        cout << "Enter a year (1-9999): " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> input;
    }
    //this boolean is handy for printing
    bool leapyear = false;
    //need to check if we have an invalid leap year entry
    if (m == 2) {
        if (d == 29) {
            if ((input % 100 == 0 && input % 400 != 0)) {
                while (input % 4 != 0 || (input % 100 == 0 && input % 400 != 0)) {
                    cout << "Error: Invalid input. A leap year where February has 29 days only occurs when a year is divisible by 4 but not by 100 (unless it is also divisible by 400)." << endl;
                    cout << "Enter a year that is divisible by 4 but not by 100 (unless it is also divisible by 400): " << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> input;
                    leapyear = true;
                }
            }
            else if (input % 4 != 0) {
                while (input % 4 != 0 || (input % 100 == 0 && input % 400 != 0)) {
                    cout << "Error: Invalid input. A leap year where February has 29 days only occurs when a year is divisible by 4 but not by 100 (unless it is also divisible by 400)." << endl;
                    cout << "Enter a year that is divisible by 4 but not by 100 (unless it is also divisible by 400): " << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> input;
                    leapyear = true;
                }
            }
        }
    }
    y = input;

    //pass to calculation method
    calendar calendar;

    //assign user_date
    date user_date;
    user_date.day = d;
    user_date.year = y;
    user_date.month = m;

    //pass to calculation method and print out day, using our day_to_string method
    cout << "" << endl;
    cout << m << "/" << d << "/" << y << " is a " << calendar.day_to_string(calendar.calculate(m, d, y)) << "" << endl;

    //call calender print
    calendar.calendar_print(user_date, leapyear);

    //call holidays to print out holidays for the month
    calendar.holidays(user_date);

    cout << "" << endl;
    cout << "Thanks you for using Alex's Calendar." << endl;

    return 0;
}

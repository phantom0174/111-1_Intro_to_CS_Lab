/*
Practice 9
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1003-B
*/

#include <iostream>

using namespace std;

// Gauss's algorithm
int which_date(int year, int month, int day) {
    // month offset
    int m = month - 2;
    if (m == -1 || m == 0) m += 12;

    // year offset
    if (month == 1 || month == 2) year -= 1;

    int c = year / 100;
    int y = year % 100;

    return (day + (int)(2.6 * m - 0.2) + 5 * (y % 4) + 3 * y + 5 * (c % 4)) % 7;
}

int main() {
    int year, month, day;
    cin >> year >> month >> day;
    int target_date = which_date(year, month, day);

    switch (target_date) {
        case 0:
            cout << "Sunday" << endl;
            break;
        case 1:
            cout << "Monday" << endl;
            break;
        case 2:
            cout << "Tuesday" << endl;
            break;
        case 3:
            cout << "Wednesday" << endl;
            break;
        case 4:
            cout << "Thursday" << endl;
            break;
        case 5:
            cout << "Friday" << endl;
            break;
        case 6:
            cout << "Saturday" << endl;
            break;
    }
}

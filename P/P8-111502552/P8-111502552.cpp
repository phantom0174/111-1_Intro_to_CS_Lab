/*
Practice 8
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1003-B
*/

# include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a = 0, b = 0;
    cin >> a >> b;

    cout << gcd(a, b) << endl;
    return 0;
}

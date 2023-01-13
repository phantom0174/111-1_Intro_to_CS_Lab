/*
Practice 14
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1003-B
*/

#include <fstream>
#include <iostream>

using namespace std;

// chinese, english, math, science
int SCORE_STANDARDS[4] = { 12, 12, 8, 12 };

ifstream input_file("./score.txt", ios::in);
ofstream output_file("./output.txt", ios::out);

void read_and_output_file() {
    string name;
    while (input_file >> name) {
        int score;

        bool pass = true;
        for (int i = 0; i < 4; i++) {
            input_file >> score;
            if (score < SCORE_STANDARDS[i]) pass = false;
        }

        if (pass) {
            output_file << "Hello " << name << ", welcome to NCU CSIE!" << endl;
        } else {
            output_file << "Sorry, " << name << " can't enter NCU CSIE." << endl;
        }
    }
}

int main() {
    read_and_output_file();

    input_file.close();
    output_file.close();
}

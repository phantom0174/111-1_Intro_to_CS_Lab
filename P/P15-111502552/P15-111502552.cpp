/*
Practice 15
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1003-B
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream input_file("./input.txt", ios::in);
ofstream output_file("./output.txt", ios::out);

// encoding
vector<char> DIRECTION_ENCODE = { 'S', 'W', 'N', 'E' };

int encode_dir(char c) {
    for (int i = 0; i < 4; i++) {
        if (DIRECTION_ENCODE[i] == c) return i;
    }
    return -1;
}
//

void deal_cards(string *p_card) {
    char dir;
    input_file >> dir;

    int curr_dir = (encode_dir(dir) + 1) % 4;
    string card_info;

    for (int i = 0; i < 52; i++) {
        input_file >> card_info;
        p_card[13 * curr_dir + int(i / 4)] = card_info;

        curr_dir = (curr_dir + 1) % 4;
    }
}

void show_card(string *p_card) {
    for (int i = 0; i < 4; i++) {
        output_file << DIRECTION_ENCODE[i] << ":";
        for (int j = 0; j < 13; j++) {
            output_file << " " << p_card[13 * i + j];
        }
        output_file << endl;
    }
}

int main() {
    string card[4][13];
    deal_cards(&card[0][0]);
    show_card(&card[0][0]);

    input_file.close();
    output_file.close();
}

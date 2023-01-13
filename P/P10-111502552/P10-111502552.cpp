/*
Practice 10
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1003-B
*/

#include <iostream>
#include <vector>

using namespace std;

// ========== Global Variables ==========

vector<string> g_token_list;  // Global token list

// identifier, num, special_symbol
int TYPES_COUNT[3] = {
    0, 0, 0
};

const vector<char> SPECIAL_SYMBOLS = {
    '+', '-', '*', '/', '>', '<', '=', '%', '&', '|',
    '^', '\"', '\'', '.', ',', '(', ')', '[', ']', '{',
    '}', '!', ':', ';'
};

// ========== Functions ==========

bool is_number(char c) {
    // given a character, return true if it is a number

    if ((int)c < 48 || (int)c > 57) return false;
    return true;
}

bool is_special_symbol(char c) {
    // given a character, return true if it is a special symbol or not

    for (char symbol : SPECIAL_SYMBOLS) {
        if (c == symbol) return true;
    }
    return false;
}

int get_token_type(string token) {
    // Given a token, return the type of the token.(Identifier, Number, or Special Symbol?)

    bool is_number_string = true;
    for (char c : token) {
        if (!is_number(c)) {
            is_number_string = false;
            break;
        }
    }
    if (is_number_string) return 1;

    bool is_special_symbol_string = true;
    for (char c : token) {
        if (!is_special_symbol(c)) {
            is_special_symbol_string = false;
            break;
        }
    }
    if (is_special_symbol_string) return 2;

    // the case left is identifier
    return 0;
}

void get_user_input() {
    // Get user input until END_OF_FILE appears, and store the tokens into g_token_list.

    string s;
    while (cin >> s) {
        if (s == "END_OF_FILE") return;
        g_token_list.push_back(s);
        TYPES_COUNT[get_token_type(s)]++;
    }
}

void print_token_sum(int sum) {
    cout << "Total number of tokens: " << sum << endl;
}

void print_token(string token) {
    cout << "[" << token << "]" << endl;
}

void print_types_info() {
    cout << "Identifier: " << TYPES_COUNT[0] << ", "
         << "Number: " << TYPES_COUNT[1] << ", "
         << "Special Symbol: " << TYPES_COUNT[2] << endl;
}

void print_invalid_command() {
    cout << "Invalid command." << endl;
}

void execute_command(int cmd) {
    // Given a command:
    // if command == 1, print token sum
    // if command == 2, print all tokens
    // if command == 3, token sum in each cases

    if (cmd == 1) {
        print_token_sum(g_token_list.size());
    } else if (cmd == 2) {
        for (string token : g_token_list) print_token(token);
    } else if (cmd == 3) {
        print_types_info();
    } else {
        print_invalid_command();
    }
}

// ========== Main Function ==========

int main() {
    // Get User Input form the input stream, and execute the command until command == 0.

    get_user_input();

    int cmd;
    while (cin >> cmd) {
        if (cmd == 0) break;
        execute_command(cmd);
    }
}

#include <fstream>
#include <iostream>

using namespace std;

ifstream input("./input.txt", ios::in);
ofstream output("./output.txt", ios::out);

string target = "";

void encode() {
    for (char c : target) {
        output << (char)(c + 10);
    }
}

void decode() {
    for (char c : target) {
        output << (char)(c - 10);
    }
}

void process_cmd() {
    int cmd;
    cin >> cmd;

    if (cmd == 1) {
        encode();
    } else if (cmd == 2) {
        decode();
    }
}

void get_input() {
    char c;
    char *p = &c;

    while (input.peek() != EOF) {
        input.read(p, 1);
        target += c;
    }
}

int main() {
    get_input();
    process_cmd();

    input.close();
    output.close();
}

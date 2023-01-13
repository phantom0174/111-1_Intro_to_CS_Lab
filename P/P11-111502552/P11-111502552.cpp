/*
Practice 11
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1003-B
*/

#include <iostream>
#include <map>

using namespace std;

map<int, short> get_input(map<int, short> doll_map) {
    int doll_count;
    cin >> doll_count;

    int doll_size;
    for (int i = 0; i < doll_count; i++) {
        cin >> doll_size;
        if (!doll_map[doll_size]) {
            doll_map[doll_size] = 1;
        } else {
            doll_map[doll_size]++;
        }
    }
    return doll_map;
}

short count_max_pieces(map<int, short>& pieces_count) {
    short max = 0;
    for (auto [key, value] : pieces_count) {
        if (value > max) max = value;
    }
    return max;
}

void calculate_doll(map<int, short>& doll_map) {
    cout << count_max_pieces(doll_map) << endl;
}

int main() {
    map<int, short> dolls;

    dolls = get_input(dolls);
    calculate_doll(dolls);
}

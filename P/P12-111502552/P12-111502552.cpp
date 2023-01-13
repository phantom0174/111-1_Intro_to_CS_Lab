/*
Practice 12
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1003-B
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> map;

// x and y is the dimension of the map
int x, y, land_count = 0;

void find_land(int pos_x, int pos_y) {
    map[pos_x][pos_y] = 0;  // the block has been stepped on

    if (pos_x - 1 >= 0 && map[pos_x - 1][pos_y]) {  // up
        find_land(pos_x - 1, pos_y);
    }
    if (pos_x + 1 < x && map[pos_x + 1][pos_y]) {  // down
        find_land(pos_x + 1, pos_y);
    }
    if (pos_y + 1 < y && map[pos_x][pos_y + 1]) {  // right
        find_land(pos_x, pos_y + 1);
    }
    if (pos_y - 1 >= 0 && map[pos_x][pos_y - 1]) {  // left
        find_land(pos_x, pos_y - 1);
    }
}

void traverse_map() {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (!map[i][j]) continue;

            land_count++;
            find_land(i, j);
        }
    }
}

void input_map() {
    cin >> x >> y;
    for (int i = 0; i < x; i++) {
        vector<bool> line;
        bool value;
        for (int j = 0; j < y; j++) {
            cin >> value;
            line.push_back(value);
        }
        map.push_back(line);
    }
}

int main() {
    input_map();
    traverse_map();

    cout << land_count << endl;
}

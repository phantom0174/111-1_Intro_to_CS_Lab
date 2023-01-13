#include <iostream>
#include <map>
#include <vector>

using namespace std;

// map: type, num
vector<map<int, map<int, bool>>> PLAYER_CARDS(4);
vector<vector<string>> UNSORTED_PLAYER_CARDS(4);

// 0, 1, 2, 3
vector<char> NUM_TO_TYPE = { 'C', 'D', 'S', 'H' };
int trans_type(char c) {
    for (int i = 0; i < NUM_TO_TYPE.size(); i++) {
        if (NUM_TO_TYPE[i] == c) return i;
    }
    return -1;
}

vector<char> NUM_TO_NUM = {
    '-', '-', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'
};
int trans_num(char c) {
    for (int i = 0; i < NUM_TO_NUM.size(); i++) {
        if (NUM_TO_NUM[i] == c) return i;
    }
    return -1;
}

vector<char> NUM_TO_DIR = { 'S', 'W', 'N', 'E' };
int dir_to_num(char c) {
    for (int i = 0; i < NUM_TO_DIR.size(); i++) {
        if (NUM_TO_DIR[i] == c) return i;
    }
    return -1;
}

void deal_cards() {
    char dir;
    cin >> dir;

    int curr_dir = (dir_to_num(dir) + 1) % 4;
    string card_info;

    for (int i = 0; i < 52; i++) {
        cin >> card_info;

        int card_type = trans_type(card_info[0]);
        int card_num = trans_num(card_info[1]);

        PLAYER_CARDS[curr_dir][card_type][card_num] = 1;
        UNSORTED_PLAYER_CARDS[curr_dir].push_back(card_info);
        curr_dir = (curr_dir + 1) % 4;
    }
}

int find_c3() {
    // avoid over-writing action
    // deprecated, no need to cin loop
    vector<map<int, map<int, bool>>> temp_player_cards = vector<map<int, map<int, bool>>>(PLAYER_CARDS);

    for (int i = 0; i < 4; i++) {
        if (temp_player_cards[i][0][3]) return i;
    }
    return -1;
}

void output_unsorted_card(int player_num) {
    for (int i = 0; i < UNSORTED_PLAYER_CARDS[player_num].size(); i++) {
        cout << " " << UNSORTED_PLAYER_CARDS[player_num][i];
    }
    cout << endl;
}

void output_sorted_card(int player_num) {
    for (auto [type, cards] : PLAYER_CARDS[player_num]) {
        for (auto [num, exists] : cards) {
            cout << " " << NUM_TO_TYPE[type];
            cout << NUM_TO_NUM[num];
        }
    }
    cout << endl;
}

void process_cmd() {
    cout << "Enter Number : ";

    int cmd;
    cin >> cmd;

    if (cmd == 1) {
        cout << NUM_TO_DIR[find_c3()] << endl;
    } else if (cmd == 2) {
        for (int i = 0; i < 4; i++) {
            cout << NUM_TO_DIR[i] << ":";
            output_unsorted_card(i);
        }
    } else if (cmd == 3) {
        for (int i = 0; i < 4; i++) {
            cout << NUM_TO_DIR[i] << ":";
            output_sorted_card(i);
        }
    }
}

int main() {
    deal_cards();
    process_cmd();
}

#include <iostream>
#include <vector>

using namespace std;

vector<int> WEIGHT = {
    1, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1
};

int alpha_to_num(char c) {
    if (c >= 'A' && c <= 'H') {
        return (c - 'A') + 10;
    } else if (c == 'I') {
        return 34;
    } else if (c >= 'J' && c <= 'N') {
        return (c - 'J') + 18;
    } else if (c == 'O') {
        return 35;
    } else if (c >= 'P' && c <= 'V') {
        return (c - 'P') + 23;
    } else if (c == 'W') {
        return 32;
    } else if (c >= 'X' && c <= 'Y') {
        return (c - 'X') + 30;
    } else if (c == 'Z') {
        return 33;
    }
    return -1;
}

int calculate_sum(string s) {
    int result = 0;

    for (int i = 0; i < s.length(); i++) {
        result += (s[i] - '0') * WEIGHT[i];
    }
    return result;
}

void process_cmd(string trans_id, int total) {
    int cmd;
    while (cin >> cmd) {
        if (cmd == 0) break;

        if (cmd == 1) {
            cout << trans_id << endl;
        } else if (cmd == 2) {
            cout << total << endl;
        } else if (cmd == 3) {
            if (total % 10 == 0) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
}

int main() {
    string id;
    cin >> id;

    int prefix = alpha_to_num(id[0]);

    string trans_id = to_string(prefix) + id.substr(1);
    int total = calculate_sum(trans_id);

    process_cmd(trans_id, total);
}

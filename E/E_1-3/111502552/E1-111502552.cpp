#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;

void get_input() {
    int N;
    cin >> N;

    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        nums.push_back(num);
    }
}

void iterate() {
    vector<int> new_nums;

    for (int i = 0; i < nums.size() - 1; i++) {
        new_nums.push_back(abs(nums[i + 1] - nums[i]));
    }
    new_nums.push_back(abs(nums[0] - nums[nums.size() - 1]));

    nums = new_nums;
}

void print_nums() {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << " ";
    }
    cout << endl;
}

// extra observed mathematical result (no matter the input):
// if N is a power of 2 (i.e. every prime factor of N is even) -> ZERO
// else -> LOOP
string is_finite_or_loop() {
    vector<vector<int>> all = { nums };

    while (true) {
        iterate();

        // exists same: LOOP
        for (auto list : all) {
            bool same = 1;
            for (int i = 0; i < list.size(); i++) {
                if (nums[i] != list[i]) same = 0;
            }

            if (same) return "LOOP";
        }

        // all zero: ZERO
        bool all_zero = 1;
        for (int i : nums) {
            if (i != 0) all_zero = 0;
        }
        if (all_zero) return "ZERO";

        all.push_back(nums);
    }
}

void process_cmd() {
    int cmd;
    cin >> cmd;

    if (cmd == 1) {
        iterate();
        print_nums();
    } else if (cmd == 2) {
        for (int i = 0; i < 3; i++) iterate();
        print_nums();
    } else if (cmd == 3) {
        cout << is_finite_or_loop() << endl;
    }
}

int main() {
    get_input();
    process_cmd();
}

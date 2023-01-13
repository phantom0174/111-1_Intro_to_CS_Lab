/*
Practice 13
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1003-B
*/

#include <iostream>

using namespace std;

void sortarray(int *arr, int length) {
    for (int i = 0; i < length - 1; i++) {
        // selection sort

        // find min index
        int min_index = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] < arr[min_index]) min_index = j;
        }

        // swap
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void mergesort(int *arr1, int *arr2, int length_arr1, int length_arr2) {
    int *result = new int[length_arr1 + length_arr2];

    int curr_pos = 0;
    for (int i = 0; i < length_arr1; i++) {
        result[curr_pos] = arr1[i];
        curr_pos++;
    }
    for (int i = 0; i < length_arr2; i++) {
        result[curr_pos] = arr2[i];
        curr_pos++;
    }

    sortarray(result, length_arr1 + length_arr2);

    for (int i = 0; i < length_arr1 + length_arr2; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    delete[] result;
}

int main() {
    int len1, len2;

    cin >> len1;
    int *A = new int[len1];
    for (int i = 0; i < len1; i++) cin >> A[i];

    cin >> len2;
    int *B = new int[len2];
    for (int i = 0; i < len2; i++) cin >> B[i];

    mergesort(A, B, len1, len2);

    // recycle memory
    delete[] A;
    delete[] B;
}

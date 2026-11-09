#if 1

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <map>
#include <cstdint> // INT32_MIN

#define R_C 5

using namespace::std;

/*
map: key - number, value: coord
diag_increase: bool[25 * 2 + 1]
diag_decrease: bool[25 * 2 + 1]
*/

int diag_increase[R_C * R_C + 1] = { 0, };
int diag_decrease[R_C * R_C + 1] = { 0, };

int row_count[R_C + 1] = { 0, };
int col_count[R_C + 1] = { 0, };

int line_count;

typedef pair<int, int> coordinate;

map<int, coordinate> coord_map;

void print_data(int* arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl << endl;
}

int main(void) {
    freopen("09_data.txt", "r", stdin);

    int number;

    for (int i = 0; i < R_C; i++) {
        for (int j = 0; j < R_C; j++) {
            cin >> number;
            coord_map.insert({ number,{ i, j } });
        }
    }

    for (int i = 0; i < R_C; i++) {
        for (int j = 0; j < R_C; j++) {
            cin >> number;
            //cout << "number: " << number << endl;

            coordinate coord = coord_map[number];
            int r = coord.first, c = coord.second;

            diag_increase[r + c]++;
            diag_decrease[R_C + r - c]++;

            row_count[r]++;
            col_count[c]++;

            //print_data(diag_increase, R_C * R_C + 1);
            //print_data(diag_decrease, R_C * R_C + 1);
            //print_data(row_count, R_C + 1);
            //print_data(col_count, R_C + 1);

            if (diag_increase[r + c] >= R_C) {
                line_count++;
                diag_increase[r + c] = INT32_MIN;
            }
            if (diag_decrease[R_C + r - c] >= R_C) {
                line_count++;
                diag_decrease[R_C + r - c] = INT32_MIN;
            }
            if (row_count[r] >= R_C) {
                line_count++;
                row_count[r] = INT32_MIN;
            }
            if (col_count[c] >= R_C) {
                line_count++;
                col_count[c] = INT32_MIN;
            }

            if (line_count >= 3) {
                cout << R_C * i + j + 1;
                return 0;
            }
        }
    }

    return 0;
}

#endif

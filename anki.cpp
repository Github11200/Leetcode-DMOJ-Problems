#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <numeric>
#include <math.h>
#include <set>

using namespace std;

template<typename T>
void displayVector(vector<T> arr) {
    for (auto x: arr)
        cout << x << endl;
}

template<typename T>
void display2DVector(vector<vector<T>> arr) {
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr[i].size(); ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

void setNumbersInOneDirection(vector<vector<int>> &coords, bool rowOrColumn, int index, int size) {
    // rowOrColumn == true -----> Row
    for (int i = 0; i < size; ++i) {
        if (rowOrColumn)
            coords.push_back({index, i});
        else
            coords.push_back({i, index});
    }
}

// https://leetcode.com/problems/set-matrix-zeroes/description/
void setMatrixZeroes(vector<vector<int>> &matrix) {
    vector<vector<int>> coords;

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] == 0) {
                setNumbersInOneDirection(coords, true, i, matrix[i].size());
                setNumbersInOneDirection(coords, false, j, matrix.size());
            }
        }
    }

    for (auto x: coords)
        matrix[x[0]][x[1]] = 0;
}

int main() {
    vector<vector<int>> matrix = {{1, 1, 1},
                                  {1, 0, 1},
                                  {1, 1, 1}};


    display2DVector(matrix);

    return 0;
}

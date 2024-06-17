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
void display2DVector(vector<vector<T> > arr) {
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr[i].size(); ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

void setMatrixZeroes(vector<vector<int> > &matrix) {
    bool rowZero = false;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] == 0) {
                if (i > 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                } else {
                    matrix[i][0] = 0;
                    rowZero = true;
                }
            }
        }
    }

    for (int i = 1; i < matrix.size(); ++i) {
        for (int j = 1; j < matrix[i].size(); ++j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    if (rowZero) {
        for (int i = 0; i < matrix[0].size(); ++i)
            matrix[0][i] = 0;
    }

    if (matrix[0][0] == 0) {
        for (int i = 0; i < matrix.size(); ++i)
            matrix[i][0] = 0;
    }
}

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<vector<int> > matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    setMatrixZeroes(matrix);
    display2DVector(matrix);

    return 0;
}

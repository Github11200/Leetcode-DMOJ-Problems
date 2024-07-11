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

void backtrack(int numberOfOpening, int numberOfClosing, string comb, int n, vector<string> &results) {
    if (numberOfOpening == n && numberOfClosing == n)
        results.push_back(comb);
    if (numberOfOpening < n)
        backtrack(numberOfOpening + 1, numberOfClosing, comb + "(", n, results);
    if (numberOfClosing < numberOfOpening)
        backtrack(numberOfOpening, numberOfClosing + 1, comb + ")", n, results);
}

vector<string> generateParentheses(int n) {
    vector<string> results;
    backtrack(0, 0, "", n, results);
    return results;
}

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

int main() {
    vector<int> nums1 = {1, -1, 0};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<vector<int> > matrix = {{1, 0}};

    displayVector(generateParentheses(3));

    return 0;
}

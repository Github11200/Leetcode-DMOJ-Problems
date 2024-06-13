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


int main() {
    vector<int> nums1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> nums2 = {3, 2, 3};

    cout << containerWithMostWater(nums1) << endl;

    return 0;
}

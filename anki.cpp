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
#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    int m = 0;

    while (l <= r) {
        m = (l + r) / 2;
        if (nums[m] < target)
            l = m + 1;
        else if (nums[m] > target)
            r = m - 1;
        else
            return m;
    }

    return -1;
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
    vector<int> nums1 = {3, 3, -2, -1};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<vector<int> > matrix = {{1, 0}};

    return 0;
}

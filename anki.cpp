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

int subarraySumEqualsK(vector<int> &nums, int k) {
    unordered_map<int, int> previousSums;
    previousSums[0] = 1;

    int sum = 0;
    int numberOfSubarrays = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        int diff = sum - k;
        if (previousSums.count(diff))
            numberOfSubarrays += previousSums[diff];
        if (previousSums.count(sum))
            ++previousSums[sum];
        else
            previousSums[sum] = 1;
    }

    return numberOfSubarrays;
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
    vector<int> nums1 = {1, 1, 1};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<vector<int> > matrix = {{1, 0}};

    cout << subarraySumEqualsK(nums1, 2) << endl;

    return 0;
}

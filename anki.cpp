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

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> nums1Hash;
    for (int i = 0; i < nums1.size(); ++i)
        nums1Hash[nums1[i]] = i;

    for (int i = 0; i < nums2.size(); ++i) {
        if (nums1Hash.count(nums2[i]) > 0) {
            stack<int> largerNums;
            largerNums.push(nums2[i]);

            int j = i + 1;
            for (; j < nums2.size(); ++j) {
                if (nums2[j] > nums2[i])
                    break;
                if (nums1Hash.count(nums2[j]) > 0)
                    largerNums.push(nums2[j]);
            }

            while (!largerNums.empty()) {
                int item = largerNums.top();
                largerNums.pop();
                nums1[nums1Hash[item]] = j < nums2.size() ? nums2[j] : -1;
            }
        }
    }

    return nums1;
}

int main() {
    vector<int> nums1 = {2, 4};
    vector<int> nums2 = {1, 2, 3, 4};

    displayVector(nextGreaterElement(nums1, nums2));

    return 0;
}

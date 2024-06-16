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

    stack<int> greaterElementsStack;
    vector<int> result(nums1.size(), -1);
    for (int i = 0; i < nums2.size(); ++i) {
        int currentElement = nums2[i];
        while (!greaterElementsStack.empty() && currentElement > greaterElementsStack.top()) {
            int element = greaterElementsStack.top();
            greaterElementsStack.pop();
            result[nums1Hash[element]] = currentElement;
        }
        if (nums1Hash.count(currentElement))
            greaterElementsStack.push(currentElement);
    }

    return result;
}

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    displayVector(nextGreaterElement(nums1, nums2));

    return 0;
}

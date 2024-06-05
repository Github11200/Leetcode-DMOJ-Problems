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
    for (auto x : arr)
        cout << x << endl;
}

int main() {
    vector nums = {1, 2, 0};
    int i = 0;
    int j = nums.size() - 1;
    int k = 0;

    while (i < j && k <= j) {
        if (nums[k] == 0) {
            swap(nums[i], nums[k]);
            ++i;
        } else if (nums[k] == 2) {
            swap(nums[j], nums[k]);
            if (nums[j] == 1)
                --k;
            if (nums[i] == 0)
                ++i;
            --j;
        }

        ++k;
    }

    displayVector(nums);

    return 0;
}

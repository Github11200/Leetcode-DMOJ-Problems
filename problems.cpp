#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

// https://leetcode.com/problems/contains-duplicate/
bool containsDuplicate(vector<int> &nums)
{
    unordered_map<int, int> duplicates;

    for (auto x : nums)
    {
        if (duplicates.find(x) != duplicates.end())
            return true;
        else
            duplicates[x] = 0;
    }

    return false;
}

// https://leetcode.com/problems/concatenation-of-array/description/
vector<int> concatenationOfArray(vector<int> &nums)
{
    vector<int> results;
    results.reserve(size(nums) * 2);
    results.insert(results.end(), nums.begin(), nums.end());
    results.insert(results.end(), nums.begin(), nums.end());
    return results;
}

// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/submissions/1218706537/
vector<int> replaceAlementsWithGreatestElementOnRightSide(vector<int> &arr)
{
    vector<int> outputArray(size(arr));
    int previousValue = -1;
    outputArray[size(arr) - 1] = -1;

    for (int i = size(arr) - 1; i > 0; --i)
    {
        if (arr[i] > previousValue)
        {
            outputArray[i - 1] = arr[i];
            previousValue = arr[i];
        }
        else
            outputArray[i - 1] = previousValue;
    }

    return outputArray;
}

bool isSubsequence(string s, string t)
{
}

template <typename T>
void displayVector(vector<T> arr)
{
    for (auto x : arr)
        cout << x << endl;
}

int main()
{
    vector<int> inputData({17, 18, 5, 4, 6, 1});
    // displayVector(replaceAlementsWithGreatestElementOnRightSide(inputData));
    cout << isSubsequence("acb", "ahbgdc") << endl;
    return 0;
}
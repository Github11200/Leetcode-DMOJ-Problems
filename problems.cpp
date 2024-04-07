#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <iostream>
#include <algorithm>

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

// https://leetcode.com/problems/is-subsequence/description/
bool isSubsequence(string s, string t)
{
    for (int i = 0; i < t.size(); ++i)
    {
        if (t[i] == s[0])
        {
            s.erase(0, 1);
        }

        if (s.size() == 0)
            return true;
    }

    return s.size() == 0;
}

// https://leetcode.com/problems/two-sum/description/
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> numberNeeded;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (numberNeeded.find(nums[i]) != numberNeeded.end())
            return vector<int>({numberNeeded[nums[i]], i});
        else
            numberNeeded[abs(nums[i] - target)] = i;
    }

    return vector<int>({0, 0});
}

string longestCommonPrefix(vector<string> &strs)
{
    if (strs.size() == 1)
        return strs[0];

    string longestCommonPrefix = strs[0];

    for (int i = 1; i < strs.size(); ++i)
    {
        int j = 0;
        while (j < strs[i].size() && j < longestCommonPrefix.size())
        {
            if (strs[i][j] != longestCommonPrefix[j])
            {
                longestCommonPrefix = longestCommonPrefix.substr(0, j);
                if (i == 0)
                    return "";
                else
                    break;
            }
            ++j;
        }

        longestCommonPrefix = longestCommonPrefix.substr(0, j);
    }

    return longestCommonPrefix;
}

// vector<vector<string>> groupAnagrams(vector<string> &strs)
// {
// }

template <typename T>
void displayVector(vector<T> arr)
{
    for (auto x : arr)
        cout << x << endl;
}

int main()
{
    string one = "eat";
    string two = "tea";

    if (one >= two)
        cout << "yep" << endl;
    else
        cout << "nope" << endl;

    // vector<string> inputData({"eat", "tea", "tan", "ate", "nat", "bat"});

    // for (auto x : groupAnagrams(inputData))
    // {
    //     displayVector(x);
    // }

    return 0;
}
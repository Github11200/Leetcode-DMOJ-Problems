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

// https://leetcode.com/problems/longest-common-prefix/description/
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

// https://leetcode.com/problems/group-anagrams/description/
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, int> anagrams;
    vector<vector<string>> anagramsVector;
    int i = 0;

    for (auto s : strs)
    {
        string x = s;
        sort(x.begin(), x.end());
        if (anagrams.count(x) == 0)
        {
            anagrams[x] = i;
            anagramsVector.push_back({s});
            ++i;
        }
        else
            anagramsVector[anagrams[x]].push_back(s);
    }

    return anagramsVector;
}

// https://leetcode.com/problems/pascals-triangle/description/
vector<vector<int>> pascalsTriangle(int numRows)
{
    vector<vector<int>> pascalsTriangleVector{{1}};

    if (numRows == 1)
        return pascalsTriangleVector;

    int j = 1;
    for (int i = 1; i < numRows; ++i)
    {
        vector<int> row;
        row.push_back(1);

        for (int k = 0; k < j - 1; ++k)
            row.push_back(pascalsTriangleVector[i - 1][k] + pascalsTriangleVector[i - 1][k + 1]);

        row.push_back(1);
        pascalsTriangleVector.push_back(row);
        ++j;
    }

    return pascalsTriangleVector;
}

// https://leetcode.com/problems/remove-element/description/
int removeElement(vector<int> &nums, int val)
{
    if (nums.size() == 1 && nums[0] == val)
        return 0;

    int i = 0;
    int j = nums.size() - 1;
    int k = j + 1;

    while (i <= j)
    {
        if (nums[i] == val && nums[j] == val)
        {
            --j;
            --k;
            continue;
        }
        else if (nums[i] == val)
        {
            nums[i] = nums[j];
            --j;
            --k;
            continue;
        }

        ++i;
    }

    return k;
}

// https://leetcode.com/problems/unique-email-addresses/description/
int uniqueEmailAddresses(vector<string> &emails)
{
    unordered_map<string, int> uniqueAddresses;
    int i = 0;

    for (auto email : emails)
    {
        string filteredEmail = "";
        bool ignoreLetters = false;

        for (int j = 0; j < email.size(); ++j)
        {
            if (email[j] == '+')
                ignoreLetters = true;
            else if (email[j] == '@')
                break;
            else if (email[j] != '.' && !ignoreLetters)
                filteredEmail += email[j];
        }

        int indexOfDomain = email.find("@");
        filteredEmail += email.substr(indexOfDomain, email.size() - indexOfDomain + 1);

        if (uniqueAddresses.count(filteredEmail) == 0)
        {
            uniqueAddresses[filteredEmail] = 0;
            ++i;
        }
    }

    return i;
}

template <typename T>
void displayVector(vector<T> arr)
{
    for (auto x : arr)
        cout << x << " ";
}

int main()
{
    vector<string> inputData({"test.email+alex@leetcode.com", "test.email@leetcode.com"});

    cout << uniqueEmailAddresses(inputData) << endl;

    return 0;
}
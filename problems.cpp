#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <numeric>
#include <math.h>

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

// https://leetcode.com/problems/isomorphic-strings/description/
bool isIsomorphic(string s, string t)
{
    unordered_map<char, char> inputToOutput;
    unordered_map<char, char> outputToInput;

    for (int i = 0; i < s.size(); ++i)
    {
        if (inputToOutput.count(s[i]) != 0 && inputToOutput[s[i]] != t[i])
            return false;
        else if (outputToInput.count(t[i]) != 0 && outputToInput[t[i]] != s[i])
            return false;
        else
        {
            inputToOutput[s[i]] = t[i];
            outputToInput[t[i]] = s[i];
        }
    }

    return true;
}

// https://leetcode.com/problems/can-place-flowers/description/
bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    if (n == 0)
        return true;
    if (flowerbed.size() == 1 && flowerbed[0] == 0)
        return n <= 1;

    int previous = 0;

    for (int i = 0; i < flowerbed.size() - 1 && n > 0; ++i)
    {
        if (previous == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0)
        {
            n -= 1;
            flowerbed[i] = 1;
            previous = flowerbed[i];
        }
        else
            previous = flowerbed[i];
    }

    if (previous == 0 && flowerbed[flowerbed.size() - 1] == 0)
        n -= 1;

    return n == 0;
}

// https://leetcode.com/problems/majority-element/description/
int majorityElement(vector<int> &nums)
{
    int count = 0;
    int maxElement = 0;

    for (auto x : nums)
    {
        if (count == 0)
        {
            maxElement = x;
        }

        if (x == maxElement)
            ++count;
        else
            --count;
    }

    return maxElement;
}

// https://leetcode.com/problems/valid-palindrome/description/
bool isPalindrome(string s)
{
    if (s.size() == 1)
        return true;

    string newString = "";

    for (auto x : s)
    {
        if (isalpha(x) || isdigit(x))
            newString += tolower(x);
    }

    int middle = newString.size() / 2;
    string secondPiece = newString.substr(newString.size() % 2 == 0 ? middle : middle + 1, newString.size());
    reverse(secondPiece.begin(), secondPiece.end());
    return newString.substr(0, middle) == secondPiece;
}

bool isPalindrome2(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        ++i;
        --j;
    }

    return true;
}

// https://leetcode.com/problems/valid-palindrome-ii/description/
bool validPalindrome(string s)
{
    int i = 0;
    int j = s.size() - 1;

    while (i < j)
    {
        if (s[i] != s[j])
            return isPalindrome2(s, i, j - 1) || isPalindrome2(s, i + 1, j);

        ++i;
        --j;
    }

    return true;
}

// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/
int minimumDifferenceBetweenHighestAndLowestOfKScores(vector<int> &nums, int k)
{
    if (nums.size() == 1)
        return 0;

    sort(nums.begin(), nums.end(), greater<int>());
    int smallestDifference = -1;

    for (int i = 0; i < nums.size() - k; ++i)
    {
        int difference = nums[i] - nums[i + k - 1];
        if (difference < smallestDifference || smallestDifference == -1)
            smallestDifference = difference;
    }

    return smallestDifference;
}

// https://leetcode.com/problems/reverse-string/description/
void reverseString(vector<char> &s)
{
    int i = 0;
    int j = s.size() - 1;

    while (i < j)
    {
        swap(s[i], s[j]);
        ++i;
        --j;
    }
}

// https://leetcode.com/problems/merge-sorted-array/description/
void mergeSortedArray(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m;
    for (auto x : nums2)
    {
        nums1[i] = x;
        ++i;
    }

    sort(nums1.begin(), nums1.end());
}

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
int removeDuplicatesFromSortedArray(vector<int> &nums)
{
    int j = 1;

    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[j] = nums[i];
            ++j;
        }
    }

    return j;
}

// https://leetcode.com/problems/next-greater-element-i/description/
vector<int> nextGreaterElementOne(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> nums1Hash;

    for (int i = 0; i < nums1.size(); ++i)
        nums1Hash[nums1[i]] = i;

    stack<int> numsStack;
    vector<int> result(nums1.size(), -1);
    for (int i = 0; i < nums2.size(); ++i)
    {
        int currentElement = nums2[i];
        while (!numsStack.empty() && currentElement > numsStack.top())
        {
            int element = numsStack.top();
            numsStack.pop();
            int index = nums1Hash[element];
            result[index] = currentElement;
        }
        if (nums1Hash.count(nums2[i]) > 0)
            numsStack.push(nums2[i]);
    }

    return result;
}

// https://leetcode.com/problems/find-pivot-index/description/
int pivotIndex(vector<int> &nums)
{
    int rightSum = 0;
    int leftSum = 0;
    for (int i = 1; i < nums.size(); ++i)
        leftSum += nums[i];

    for (int i = 0; i < nums.size(); ++i)
    {
        if (i > 0)
            leftSum -= nums[i];
        if (leftSum == rightSum)
            return i;
        rightSum += nums[i];
    }

    return -1;
}

// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
class NumArray
{
public:
    vector<int> numsArray;

    NumArray(vector<int> &nums)
    {
        int sum = 0;
        for (auto x : nums)
        {
            sum += x;
            this->numsArray.push_back(sum);
        }
    }

    int sumRange(int left, int right)
    {
        if (left > 0)
        {
            return this->numsArray[right] - this->numsArray[left - 1];
        }
        return this->numsArray[right];
    }
};

// https://leetcode.com/problems/maximum-number-of-balloons/description/
int maxNumberOfBalloons(string text)
{
    unordered_map<char, int> balloonHashMap = {{'b', 0}, {'a', 1}, {'l', 2}, {'o', 3}, {'n', 4}};
    vector<int> balloonWordArray({0, 0, 0, 0, 0});

    for (auto x : text)
    {
        if (balloonHashMap.count(x) > 0)
            balloonWordArray[balloonHashMap[x]] += 1;
    }

    balloonWordArray[2] /= 2;
    balloonWordArray[3] /= 2;
    auto smallestElement = min_element(balloonWordArray.begin(), balloonWordArray.end());
    if (*smallestElement == 0)
        return 0;
    return *smallestElement;
}

// https://leetcode.com/problems/word-pattern/description/
bool wordPattern(string pattern, string s)
{
    unordered_map<char, string> letterToWord;
    unordered_map<string, char> wordToLetter;

    int j = 0;
    int k = 0;
    for (int i = 0; i < s.size() + 1; ++i)
    {
        if (s[i] == ' ' || i == s.size())
        {
            string subString = s.substr(j, i - j);
            if ((letterToWord.count(pattern[k]) > 0 && letterToWord[pattern[k]] != subString) || (wordToLetter.count(subString) > 0 && wordToLetter[subString] != pattern[k]))
                return false;
            letterToWord[pattern[k]] = subString;
            wordToLetter[subString] = pattern[k];
            ++k;
            j = i + 1;
        }
    }

    return true ? k == pattern.size() : false;
}

// https://leetcode.com/problems/design-hashset/description/
class MyHashSet
{
public:
    vector<bool> booleanArray;

    MyHashSet()
    {
        booleanArray.push_back(false);
    }

    void add(int key)
    {
        if (key >= booleanArray.size())
        {
            for (int i = booleanArray.size(); i < key + 1; ++i)
                booleanArray.push_back(false);
        }
        booleanArray[key] = true;
    }

    void remove(int key)
    {
        if (key < booleanArray.size())
            booleanArray[key] = false;
    }

    bool contains(int key)
    {
        if (key < booleanArray.size())
            return booleanArray[key];
        return false;
    }
};

// https://leetcode.com/problems/design-hashmap/description/
class MyHashMap
{
public:
    vector<array<int, 2>> hashMap;

    MyHashMap()
    {
        for (int i = 0; i < pow(10, 4); ++i)
            this->hashMap.push_back({-1, -1});
    }

    void put(int key, int value)
    {
        if (key >= this->hashMap.size())
        {
            for (int i = 0; i <= key; ++i)
                this->hashMap.push_back({-1, -1});
        }
        this->hashMap[key] = {key, value};
    }

    int get(int key)
    {
        if (key > this->hashMap.size())
            return -1;
        return this->hashMap[key][1];
    }

    void remove(int key)
    {
        if (key <= this->hashMap.size())
            this->hashMap[key] = {-1, -1};
    }
};

// https://leetcode.com/problems/sort-an-array/description/
vector<int> sortArray(vector<int> &nums)
{
    if (nums.size() <= 2)
    {
        if (nums.size() == 2 && nums[0] > nums[1])
            swap(nums[0], nums[1]);
        return nums;
    }

    vector<int> leftPartition(nums.begin(), nums.begin() + nums.size() / 2);
    vector<int> rightPartition(nums.begin() + nums.size() / 2, nums.end());

    leftPartition = sortArray(leftPartition);
    rightPartition = sortArray(rightPartition);

    int i = 0;
    int j = 0;
    int k = 0;
    while (i < leftPartition.size() && j < rightPartition.size())
    {
        if (leftPartition[i] <= rightPartition[j])
        {
            nums[k] = leftPartition[i];
            ++i;
        }
        else
        {
            nums[k] = rightPartition[j];
            ++j;
        }
        ++k;
    }

    while (i < leftPartition.size() && k < nums.size())
    {
        nums[k] = leftPartition[i];
        i, k += 1;
    }

    while (j < rightPartition.size() && k < nums.size())
    {
        nums[k] = rightPartition[j];
        j, k += 1;
    }

    return nums;
}

// https://leetcode.com/problems/top-k-frequent-elements/description/
vector<int> topKFrequentElements(vector<int> &nums, int k)
{
    if (nums.size() == 1)
        return nums;

    unordered_map<int, int> count;
    vector<vector<int>> frequencies;
    frequencies.resize(nums.size());

    for (auto x : nums)
    {
        if (count.count(x) == 0)
            count[x] = 1;
        else
            count[x] += 1;
    }

    for (auto x : count)
        frequencies[x.second].push_back(x.first);

    vector<int> result;
    int i = frequencies.size() - 1;
    while (result.size() != k)
    {
        for (int j = 0; j < frequencies[i].size(); ++j)
        {
            if (result.size() != k)
                result.push_back(frequencies[i][j]);
            else
                break;
        }
        --i;
    }

    return result;
}

vector<int> productOfArrayExceptSelf(vector<int> &nums)
{
}

template <typename T>
void displayVector(vector<T> arr)
{
    for (auto x : arr)
        cout << x << " ";
}

int main()
{
    vector<int> nums({-1, -1});

    displayVector(topKFrequentElements(nums, 1));

    return 0;
}
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
  results.reserve(nums.size() * 2);
  results.insert(results.end(), nums.begin(), nums.end());
  results.insert(results.end(), nums.begin(), nums.end());
  return results;
}

// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/submissions/1218706537/
vector<int> replaceAlementsWithGreatestElementOnRightSide(vector<int> &arr)
{
  vector<int> outputArray(arr.size());
  int previousValue = -1;
  outputArray[arr.size() - 1] = -1;

  for (int i = arr.size() - 1; i > 0; --i)
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
  unordered_map<char, int> balloonHashMap = {
      {'b', 0},
      {'a', 1},
      {'l', 2},
      {'o', 3},
      {'n', 4}};
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
      if ((letterToWord.count(pattern[k]) > 0 && letterToWord[pattern[k]] != subString) ||
          (wordToLetter.count(subString) > 0 && wordToLetter[subString] != pattern[k]))
        return false;
      letterToWord[pattern[k]] = subString;
      wordToLetter[subString] = pattern[k];
      ++k;
      j = i + 1;
    }
  }

  return k == pattern.size();
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
// class MyHashMap {
// public:
//    vector<array<int, 2>> hashMap;
//
//    MyHashMap() {
//        for (int i = 0; i < pow(10, 4); ++i) {
//            int arr[2] = {-1, -1};
//            this->hashMap.push_back(arr);
//        }
//    }
//
//    void put(int key, int value) {
//        if (key >= this->hashMap.size()) {
//            for (int i = 0; i <= key; ++i)
//                this->hashMap.push_back({-1, -1});
//        }
//        this->hashMap[key] = {key, value};
//    }
//
//    int get(int key) {
//        if (key > this->hashMap.size())
//            return -1;
//        return this->hashMap[key][1];
//    }
//
//    void remove(int key) {
//        if (key <= this->hashMap.size())
//            this->hashMap[key] = {-1, -1};
//    }
//};

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
    ++k;
    ++i;
  }

  while (j < rightPartition.size() && k < nums.size())
  {
    nums[k] = rightPartition[j];
    k += 1;
    ++j;
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

// https://leetcode.com/problems/product-of-array-except-self/description/
vector<int> productOfArrayExceptSelf(vector<int> &nums)
{
  vector<int> result(nums.size(), 0);
  unordered_map<int, int> previousNumbers;

  for (int i = 0; i < nums.size(); ++i)
  {
    if (previousNumbers.count(nums[i]) == 0)
    {
      int product = 1;
      for (int j = 0; j < nums.size(); ++j)
      {
        if (j != i)
          product *= nums[j];
      }
      result[i] = product;
      previousNumbers[nums[i]] = product;
    }
    else
      result[i] = previousNumbers[nums[i]];
  }

  return result;
}

// https://leetcode.com/problems/valid-sudoku/description/
bool validSudoku(vector<vector<char>> &board)
{
  unordered_map<char, int> currentRow;
  unordered_map<string, int> boxes;
  vector<unordered_map<char, int>> columns;
  columns.resize(9);

  for (int i = 0; i < board.size(); ++i)
  {
    for (int j = 0; j < board.size(); ++j)
    {
      if (board[i][j] != '.')
      {
        string boxesString;
        boxesString += (char)(i / 3);
        boxesString += (char)(j / 3);
        if (currentRow.count(board[i][j]) != 0 || columns[j].count(board[i][j]) != 0 ||
            boxes.count(boxesString) != 0)
          return false;
        else
        {
          currentRow[board[i][j]] = 0;
          columns[j][board[i][j]] = 0;
          boxes[boxesString] = 0;
        }
      }
    }

    currentRow.clear();
  }

  return true;
}

// https://leetcode.com/problems/sort-colors/description/
int longestConsecutive(vector<int> &nums)
{
  if (nums.size() == 0)
    return 0;

  sort(nums.begin(), nums.end());
  int longestSequence = 1;
  int length = 1;

  for (int i = 1; i < nums.size(); ++i)
  {
    if (nums[i] - 1 == nums[i - 1])
      ++length;
    else if (nums[i] != nums[i - 1])
    {
      if (length > longestSequence)
        longestSequence = length;
      length = 1;
    }
  }

  if (length > longestSequence)
    return length;

  return longestSequence;
}

// https://leetcode.com/problems/sort-colors/description/
void sortColors(vector<int> &nums)
{
  if (nums.size() == 1)
    return;

  int left = 0;
  int right = nums.size() - 1;
  int mid = 0;

  while (mid < nums.size() && mid <= right)
  {
    if (nums[mid] == 0)
    {
      swap(nums[left], nums[mid]);
      ++left;
    }
    else if (nums[mid] == 2)
    {
      swap(nums[mid], nums[right]);
      --right;
      --mid;
    }
    ++mid;
  }
}

// https://leetcode.com/problems/encode-and-decode-tinyurl/description/
class EncodeAndDecodeTinyURL
{
public:
  string encode(string longUrl)
  {
    string newString;
    for (char s : longUrl)
    {
      int ascii = (int)s;
      ascii += 5;
      newString.push_back(char(ascii));
    }

    return newString;
  }

  string decode(string shortUrl)
  {
    string newString;
    for (char s : shortUrl)
    {
      int ascii = (int)s;
      ascii -= 5;
      newString.push_back(char(ascii));
    }

    return newString;
  }
};

// https://leetcode.com/problems/brick-wall/description/
int brickWall(vector<vector<int>> &wall)
{
  unordered_map<int, int> gaps;
  int max = 0;

  for (int i = 0; i < wall.size(); ++i)
  {
    int rowSum = wall[i][0];
    for (int j = 0; j < wall[i].size() - 1;)
    {
      if (gaps.count(rowSum) > 0)
        ++gaps[rowSum];
      else
        gaps[rowSum] = 1;
      if (gaps[rowSum] > max)
        max = gaps[rowSum];
      rowSum += wall[i][++j];
    }
  }

  return wall.size() - max;
}

// https://leetcode.com/problems/container-with-most-water/description/
int containerWithMostWater(vector<int> &height)
{
  int maxArea = 0;
  int i = 0;
  int j = height.size() - 1;

  while (i < j)
  {
    int area = (j - i) * (min(height[i], height[j]));
    if (area > maxArea)
      maxArea = area;

    height[i] > height[j] ? --j : ++i;
  }

  return maxArea;
}

// https://leetcode.com/problems/set-matrix-zeroes/description/
vector<int> spiralMatrix(vector<vector<int>> &matrix)
{
  vector<int> spiraled;

  int leftPointer = 0;
  int rightPointer = matrix[0].size() - 1;
  int topPointer = 1;
  int bottomPointer = matrix.size() - 1;

  int k = 0;
  int i = 0;
  int j = 0;
  int direction = 0; // 0 -> right, 1 -> down, 2 -> left, 3 -> up

  while (k < (matrix.size() * matrix[0].size()))
  {
    spiraled.push_back(matrix[i][j]);

    if (direction == 0 && j == rightPointer)
    {
      direction = 1;
      --rightPointer;
    }
    else if (direction == 1 && i == bottomPointer)
    {
      direction = 2;
      --bottomPointer;
    }
    else if (direction == 2 && j == leftPointer)
    {
      direction = 3;
      ++leftPointer;
    }
    else if (direction == 3 && i == topPointer)
    {
      direction = 0;
      ++topPointer;
    }

    if (direction == 0)
      ++j;
    else if (direction == 1)
      ++i;
    else if (direction == 2)
      --j;
    else if (direction == 3)
      --i;

    ++k;
  }

  return spiraled;
}

// https://leetcode.com/problems/set-matrix-zeroes/description/
void setMatrixZeroes(vector<vector<int>> &matrix)
{
  bool rowZero = false;

  for (int i = 0; i < matrix.size(); ++i)
  {
    for (int j = 0; j < matrix[i].size(); ++j)
    {
      if (matrix[i][j] == 0)
      {
        matrix[0][j] = 0;
        if (i > 0)
          matrix[i][0] = 0;
        else
          rowZero = true;
      }
    }
  }

  for (int i = 1; i < matrix.size(); ++i)
  {
    for (int j = 1; j < matrix[i].size(); ++j)
    {
      if (matrix[i][0] == 0 || matrix[0][j] == 0)
        matrix[i][j] = 0;
    }
  }

  if (rowZero)
  {
    for (int i = 0; i < matrix[0].size(); ++i)
      matrix[0][i] = 0;
  }

  if (matrix[0][0] == 0)
  {
    for (int i = 0; i < matrix.size(); ++i)
      matrix[i][0] = 0;
  }
}

// https://leetcode.com/problems/monotonic-array/description/
bool isMonotic(vector<int> &nums)
{
  int increasingOrDecreasing = 0; // 1 -> increasing, 2 -> decreasing

  for (int i = 1; i < nums.size(); ++i)
  {
    if (nums[i] == nums[i - 1])
      continue;
    else if (increasingOrDecreasing == 0)
      increasingOrDecreasing = nums[i] >= nums[i - 1] ? 1 : 2;
    if ((increasingOrDecreasing == 1 && nums[i] < nums[i - 1]) || (increasingOrDecreasing == 2 && nums[i] > nums[i - 1]))
      return false;
  }

  return true;
}

// https://leetcode.com/problems/number-of-good-pairs/description/
int numberOfGoodPairs(vector<int> &nums)
{
  unordered_map<int, int> counts;
  int result = 0;
  for (auto x : nums)
  {
    if (counts.count(x))
    {
      result += counts[x];
      counts[x] += 1;
    }
    else
      counts[x] = 1;
  }

  return result;
}

// https://leetcode.com/problems/pascals-triangle-ii/description/
vector<int> pascalsTriangle2(int rowIndex)
{
  vector<int> previous(rowIndex + 1, 1);
  vector<int> current(rowIndex + 1, 1);

  bool previousOrCurrent = true; // true -> current, false -> previous

  for (int i = 0; i < rowIndex + 1; ++i)
  {
    for (int j = 1; j < i; ++j)
    {
      if (previousOrCurrent)
        current[j] = previous[j - 1] + previous[j];
      else
        previous[j] = current[j - 1] + current[j];
    }
    previousOrCurrent = !previousOrCurrent;
  }

  return !previousOrCurrent ? current : previous;
}

// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/
int findWordsThatCanBeFormedByCharacters(vector<string> &words, string chars)
{
  unordered_map<char, int> charsHashMap;
  for (auto x : chars)
  {
    if (charsHashMap.count(x))
      ++charsHashMap[x];
    else
      charsHashMap[x] = 1;
  }

  int totalLength = 0;
  for (auto x : words)
  {
    unordered_map<char, int> lettersUsed;
    bool isGood = true;
    for (auto letter : x)
    {
      if (lettersUsed.count(letter))
        ++lettersUsed[letter];
      else
        lettersUsed[letter] = 1;

      if (charsHashMap.count(letter) == 0 || lettersUsed[letter] > charsHashMap[letter])
      {
        isGood = false;
        break;
      }
    }
    if (isGood)
      totalLength += x.size();
  }

  return totalLength;
}

// https://leetcode.com/problems/largest-3-same-digit-number-in-string/description/
string largestGoodInteger(string num)
{
  string largestNum = "";

  int startIndex = 0;
  for (int i = 1; i < num.size(); ++i)
  {
    if (num[i] != num[i - 1])
      startIndex = i;
    else if (i - startIndex == 2 && (largestNum == "" || (int)largestNum[0] < (int)num[i]))
      largestNum = string(3, num[i]);
  }

  return largestNum;
}

// https://leetcode.com/problems/destination-city/description/
string destinationCity(vector<vector<string>> &paths)
{
  unordered_map<string, string> startAndEndCities;
  for (auto x : paths)
    startAndEndCities[x[1]] = "";
  for (auto x : paths)
    startAndEndCities.erase(x[0]);

  return startAndEndCities.begin()->first;
}

// https://leetcode.com/problems/maximum-product-difference-between-two-pairs/description/
int maximumProductDifferenceBetweenTwoPairs(vector<int> &nums)
{
  sort(nums.begin(), nums.end(), greater<int>());
  return (nums[0] * nums[1]) - (nums[nums.size() - 1] * nums[nums.size() - 2]);
}

// https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/
int maximumScoreAfterSplittingAString(string s)
{
  int numberOfOnes = 0;
  for (int i = 1; i < s.size(); ++i)
    numberOfOnes += s[i] == '1' ? 1 : 0;

  int numberOfZeroes = 0;

  int maxScore = -1;
  for (int i = 1; i < s.size(); ++i)
  {
    if (s[i - 1] == '0')
      ++numberOfZeroes;
    if (numberOfZeroes + numberOfOnes > maxScore || maxScore == -1)
      maxScore = numberOfZeroes + numberOfOnes;
    if (s[i] == '1')
      --numberOfOnes;
  }

  return maxScore;
}

// https://leetcode.com/problems/path-crossing/description/
bool pathCrossing(string path)
{
  int x = 0;
  int y = 0;
  set<vector<int>> previousPoints;
  previousPoints.insert({0, 0});
  for (auto direction : path)
  {
    if (direction == 'N')
      ++y;
    else if (direction == 'S')
      --y;
    else if (direction == 'E')
      ++x;
    else
      --x;

    if (previousPoints.count({x, y}))
      return true;

    previousPoints.insert({x, y});
  }

  return false;
}

// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/
int minimumChangesToMakeAlternatingBinaryString(string s)
{
  int count = 0;
  for (int i = 0; i < s.size(); ++i)
  {
    if (i % 2) // Odd
      count += s[i] == '0' ? 1 : 0;
    else
      count += s[i] == '1' ? 1 : 0;
  }

  return count < (s.size() - count) ? count : s.size() - count;
}

// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/description/
bool redistributeChractersToMakeAllStringsEqual(vector<string> &words)
{
  unordered_map<char, int> frequencies;
  for (auto word : words)
  {
    for (auto letter : word)
    {
      if (frequencies.count(letter))
        ++frequencies[letter];
      else
        frequencies[letter] = 1;
    }
  }

  for (auto x : frequencies)
  {
    if (x.second % words.size() != 0)
      return false;
  }

  return true;
}

// https://leetcode.com/problems/largest-substring-between-two-equal-characters/description/
int largestSubstringBetweenTwoEqualCharacters(string s)
{
  unordered_map<char, int> letterPositions;
  int largestLength = -1;
  for (int i = 0; i < s.size(); ++i)
  {
    if (letterPositions.count(s[i]) && (i - letterPositions[s[i]] - 1) > largestLength)
      largestLength = (i - letterPositions[s[i]] - 1);
    else if (letterPositions.count(s[i]) == 0)
      letterPositions[s[i]] = i;
  }

  return largestLength;
}

// https://leetcode.com/problems/set-mismatch/description/
vector<int> setMismatch(vector<int> &nums)
{
  int actualSum = (nums.size() * (nums.size() + 1)) / 2;
  int currentSum = 0;
  int duplicatedNumber = -1;
  unordered_map<int, int> previousNumbers;
  for (auto x : nums)
  {
    if (previousNumbers.count(x) && duplicatedNumber == -1)
      duplicatedNumber = x;
    else
      previousNumbers[x] = 0;
    currentSum += x;
  }

  return vector<int>({duplicatedNumber, actualSum - (currentSum - duplicatedNumber)});
}

// https://leetcode.com/problems/first-unique-character-in-a-string/description/
int firstUniqueCharacterInAString(string s)
{
  unordered_map<char, int> letterCounts;
  for (auto x : s)
  {
    if (letterCounts.count(x))
      ++letterCounts[x];
    else
      letterCounts[x] = 1;
  }

  for (int i = 0; i < s.size(); ++i)
  {
    if (letterCounts[s[i]] == 1)
      return i;
  }

  return -1;
}

// https://leetcode.com/problems/intersection-of-two-arrays/description/
vector<int> intersectionOfTwoArrays(vector<int> &nums1, vector<int> &nums2)
{
  vector<int> intersection;
  unordered_map<int, int> nums1Hash;

  for (auto x : nums1)
    nums1Hash[x] = 0;

  for (auto x : nums2)
  {
    if (nums1Hash.count(x))
    {
      intersection.push_back(x);
      nums1Hash.erase(x);
    }
  }

  return intersection;
}

// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/
int numberOfStudentsUnableToEatLunch(vector<int> &students, vector<int> &sandwiches)
{
  queue<int> studentsQueue;
  queue<int> sandwichesQueue;
  for (auto x : students)
    studentsQueue.push(x);
  for (auto x : sandwiches)
    sandwichesQueue.push(x);

  int queueStartLength = studentsQueue.size();
  int i = 0;
  while (!studentsQueue.empty())
  {
    if (studentsQueue.front() == sandwichesQueue.front())
    {
      studentsQueue.pop();
      sandwichesQueue.pop();
      i = 0;
    }
    else
    {
      int temp = studentsQueue.front();
      studentsQueue.pop();
      studentsQueue.push(temp);
      ++i;
    }

    if (i == studentsQueue.size())
      return studentsQueue.size();
  }

  return 0;
}

// https://leetcode.com/problems/time-needed-to-buy-tickets/description/
int timeNeededToBuyTickets(vector<int> &tickets, int k)
{
  int seconds = 0;

  while (tickets[k] != 0)
  {
    for (int i = 0; i < tickets.size(); ++i)
    {
      if (tickets[i] != 0)
      {
        --tickets[i];
        ++seconds;
      }

      if (tickets[i] == 0 && i == k)
        return seconds;
    }
  }

  return seconds;
}

// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/
int specialArrayWithXElementsGreaterThanOrEqualToX(vector<int> &nums)
{
  unordered_map<int, int> previousNumbers;
  int maxElement = 0;
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); ++i)
  {
    if (nums[i] != 0 && nums[i] >= nums.size() - i && previousNumbers.count(nums.size() - i) == 0 &&
        nums.size() - i > maxElement)
      return nums.size() - i;
    previousNumbers[nums[i]] = i;
    if (nums[i] > maxElement)
      maxElement = nums[i];
  }

  return -1;
}

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
int bestTimeToBuyAndSellStock2(vector<int> &prices)
{
  int total = 0;
  for (int i = 0; i < prices.size() - 1; ++i)
  {
    if (prices[i + 1] > prices[i])
      total += prices[i + 1] - prices[i];
  }

  return total;
}

// https://leetcode.com/problems/subarray-sum-equals-k/description/
int subarraySumEqualsK(vector<int> &nums, int k)
{
  int numberOfSubArrays = 0;
  unordered_map<int, int> sumPrefixes;
  sumPrefixes[0] = 1;
  int total = 0;

  for (int i = 0; i < nums.size(); ++i)
  {
    total += nums[i];
    int diff = total - k;

    if (sumPrefixes.count(diff))
      numberOfSubArrays += sumPrefixes[diff];
    if (sumPrefixes.count(total))
      ++sumPrefixes[total];
    else
      sumPrefixes[total] = 1;
  }

  return numberOfSubArrays;
}

// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
vector<int> twoSum2InputArrayIsSorted(vector<int> &numbers, int target)
{
  int i = 0;
  int j = numbers.size() - 1;

  while (i < j)
  {
    int total = numbers[i] + numbers[j];
    if (total == target)
      return vector<int>({i + 1, j + 1});
    else if (total > target)
      numbers[j] > numbers[i] ? --j : ++i;
    else if (total < target)
      numbers[j] < numbers[i] ? --j : ++i;
  }

  return vector<int>({i + 1, j + 1});
}

// https://leetcode.com/problems/min-stack/description/
class MinStack
{
public:
  vector<int> vals;
  vector<int> smallestValues;

  MinStack()
  {
  }

  void push(int val)
  {
    vals.push_back(val);
    if (this->smallestValues.empty() || this->smallestValues[smallestValues.size() - 1] >= val)
      this->smallestValues.push_back(val);
  }

  void pop()
  {
    if (this->smallestValues[smallestValues.size() - 1] == vals[vals.size() - 1])
      this->smallestValues.pop_back();
    vals.pop_back();
  }

  int top()
  {
    return vals[vals.size() - 1];
  }

  int getMin()
  {
    return this->smallestValues[smallestValues.size() - 1];
  }
};

// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
int evaluateReversePolishNotation(vector<string> &tokens)
{
  stack<int> numsStack;

  for (int i = 0; i < tokens.size(); ++i)
  {
    if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
    {
      int first = numsStack.top();
      numsStack.pop();
      int second = numsStack.top();
      numsStack.pop();
      if (tokens[i] == "+")
        numsStack.push(first + second);
      else if (tokens[i] == "-")
        numsStack.push(second - first);
      else if (tokens[i] == "*")
        numsStack.push(first * second);
      else
        numsStack.push(second / first);
    }
    else
      numsStack.push(stoi(tokens[i]));
  }

  return numsStack.top();
}

void backtrack(int numberOfOpening, int numberOfClosing, string combination, vector<string> &res, int n)
{
  if (numberOfOpening == numberOfClosing && numberOfOpening == n)
    res.push_back(combination);

  if (numberOfOpening < n)
    backtrack(numberOfOpening + 1, numberOfClosing, combination + "(", res, n);
  if (numberOfClosing < numberOfOpening)
    backtrack(numberOfOpening, numberOfClosing + 1, combination + ")", res, n);
}

// https://leetcode.com/problems/generate-parentheses/description/
vector<string> generateParentheses(int n)
{
  vector<string> result;
  backtrack(0, 0, "", result, n);
  return result;
}

// https://leetcode.com/problems/3sum/description/
vector<vector<int>> threeSum(vector<int> &nums)
{
  vector<vector<int>> result;
  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size(); ++i)
  {
    if (i > 0 && nums[i] == nums[i - 1])
      continue;
    int left = i + 1, right = nums.size() - 1;
    while (left < right)
    {
      int total = nums[i] + nums[left] + nums[right];
      if (total > 0)
        --right;
      else if (total < 0)
        ++left;
      else
      {
        result.push_back(vector<int>({nums[i], nums[left], nums[right]}));
        ++left;
        while (nums[left] == nums[left - 1] && left < right)
          ++left;
      }
    }
  }

  return result;
}

// https://leetcode.com/problems/daily-temperatures/description/
vector<int> dailyTemperatures(vector<int> &temperatures)
{
  vector<int> offsets(temperatures.size(), 0);
  stack<int> smallerTemps;
  for (int i = 0; i < temperatures.size(); ++i)
  {
    while (!smallerTemps.empty() && temperatures[i] > temperatures[smallerTemps.top()])
    {
      offsets[smallerTemps.top()] = i - smallerTemps.top();
      smallerTemps.pop();
    }

    smallerTemps.push(i);
  }

  return offsets;
}

bool cmp(pair<int, int> a, pair<int, int> b) { return a.first > b.first; }

// https://leetcode.com/problems/car-fleet/description/
int carFleet(int target, vector<int> &position, vector<int> &speed)
{
  int numberOfFleets = position.size();

  pair<int, int> positionAndSpeed[position.size()];
  for (int i = 0; i < position.size(); ++i)
  {
    positionAndSpeed[i].first = position[i];
    positionAndSpeed[i].second = speed[i];
  }
  sort(positionAndSpeed, positionAndSpeed + position.size(), cmp);
  unordered_map<float, int> previousTimes;
  float maxTime = -1;

  for (int i = 0; i < position.size(); ++i)
  {
    float timeToReach = float(target - positionAndSpeed[i].first) / positionAndSpeed[i].second;
    if (previousTimes.count(timeToReach) || (maxTime != -1 && timeToReach <= maxTime))
      --numberOfFleets;
    else
    {
      previousTimes[timeToReach] = 1;
      if (timeToReach > maxTime)
        maxTime = timeToReach;
    }
  }

  return numberOfFleets;
}

// https://leetcode.com/problems/assign-cookies/description/
int assignCookies(vector<int> &g, vector<int> &s)
{
  sort(g.begin(), g.end());
  sort(s.begin(), s.end());

  int contentChildren = 0;
  int i = 0;
  int j = 0;
  while (i < g.size() && j < s.size())
  {
    if (s[j] >= g[i])
    {
      ++contentChildren;
      ++i;
    }

    ++j;
  }

  return contentChildren;
}

int uniqueLength3PalindromicSubsequences(string s)
{
  vector<int> first(26, -1);
  vector<int> last(26, -1);

  for (int i = 0; i < s.size(); ++i)
  {
    int letterIndex = s[i] - 'a';
    if (first[letterIndex] == -1)
      first[letterIndex] = i;
    last[letterIndex] = i;
  }

  int subsequences = 0;
  for (int i = 0; i < 26; ++i)
  {
    if (first[i] == -1)
      continue;
    unordered_map<char, int> combs;
    for (int j = first[i] + 1; j < last[i]; ++j)
    {
      combs[s[j]] = 1;
    }
    subsequences += combs.size();
  }

  return subsequences;
}

// https://leetcode.com/problems/binary-search/description/
int binarySearch(vector<int> &nums, int target)
{
  int l = 0;
  int r = nums.size() - 1;
  int m = 1;

  while (l <= r)
  {
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

// https://leetcode.com/problems/search-a-2d-matrix/description/
bool search2dMatrix(vector<vector<int>> &matrix, int target)
{
  for (int i = 0; i < matrix.size(); ++i)
  {
    if (target >= matrix[i][0] && target <= matrix[i][matrix[i].size() - 1])
    {
      int l = 0;
      int h = matrix[i].size() - 1;
      int m = 0;
      while (l <= h)
      {
        m = (l + h) / 2;
        if (target < matrix[i][m])
          l = m + 1;
        else if (target > matrix[i][m])
          h = m - 1;
        else
          return true;
      }
      return false;
    }
  }

  return false;
}

// https://leetcode.com/problems/koko-eating-bananas/description/
int kokoEatingBananas(vector<int> &piles, int h)
{
  sort(piles.begin(), piles.end());
  int m = 0;
  int l = 1;
  int r = piles[piles.size() - 1];
  int previousInput = 0;
  long long int numberOfHours = 0;

  while (l <= r)
  {
    numberOfHours = 0;
    m = (l + r) / 2;
    for (int i = 0; i < piles.size(); ++i)
      numberOfHours += piles[i] % m == 0 ? piles[i] / m : (piles[i] / m) + 1;
    if (numberOfHours > h)
      l = m + 1;
    else if (numberOfHours <= h)
    {
      r = m - 1;
      previousInput = m;
    }
  }

  if (numberOfHours > h)
    return previousInput;
  return m;
}

// https://dmoj.ca/problem/ccc00s1
void slotMachines()
{
  int numberOfQuarters = 0;
  vector<int> numberOfTimesMachinesPlayed({0, 0, 0});
  cin >> numberOfQuarters;
  cin >> numberOfTimesMachinesPlayed[0];
  cin >> numberOfTimesMachinesPlayed[1];
  cin >> numberOfTimesMachinesPlayed[2];

  int numberOfTimesPlayed = 0;
  int i = 0;
  while (numberOfQuarters > 0)
  {
    --numberOfQuarters;
    ++numberOfTimesMachinesPlayed[i];
    ++numberOfTimesPlayed;
    if (i == 0 && numberOfTimesMachinesPlayed[i] % 35 == 0)
      numberOfQuarters += 30;
    else if (i == 1 && numberOfTimesMachinesPlayed[i] % 100 == 0)
      numberOfQuarters += 60;
    else if (i == 2 && numberOfTimesMachinesPlayed[i] % 10 == 0)
      numberOfQuarters += 9;
    i += i == 2 ? -2 : 1;
  }

  cout << "Martha plays " << numberOfTimesPlayed << " times before going broke.";
}

// https://dmoj.ca/problem/ccc01s1
void keepingScore()
{
  string cardsAtHand;
  cin >> cardsAtHand;

  cout << "Cards Dealt " << "Points" << endl;

  int points = 0;
  int individualCardsPoints = 0;
  int numberOfCards = 0;
  for (auto card : cardsAtHand)
  {
    if (card == 'C' || card == 'D' || card == 'H' || card == 'S')
    {
      if (card != 'C')
      {
        if (numberOfCards == 0)
          individualCardsPoints += 3;
        else if (numberOfCards == 1)
          individualCardsPoints += 2;
        else if (numberOfCards == 2)
          ++individualCardsPoints;
        cout << individualCardsPoints << endl;
      }

      if (card == 'C')
        cout << "Clubs ";
      else if (card == 'D')
        cout << "Diamonds ";
      else if (card == 'H')
        cout << "Hearts ";
      else if (card == 'S')
        cout << "Spades ";
      points += individualCardsPoints;
      individualCardsPoints = 0;
      numberOfCards = 0;
      continue;
    }
    else
      cout << card << " ";

    switch (card)
    {
    case 'A':
      individualCardsPoints += 4;
      break;
    case 'K':
      individualCardsPoints += 3;
      break;
    case 'Q':
      individualCardsPoints += 2;
      break;
    case 'J':
      individualCardsPoints += 1;
      break;
    default:
      break;
    }
    ++numberOfCards;
  }

  if (numberOfCards == 0)
    individualCardsPoints += 3;
  else if (numberOfCards == 1)
    individualCardsPoints += 2;
  else if (numberOfCards == 2)
    ++individualCardsPoints;
  cout << individualCardsPoints << endl;
  points += individualCardsPoints;

  cout << "Total " << points;
}

int ticketPrices[4] = {0, 0, 0, 0};
int numberOfTicketsBought[4] = {0, 0, 0, 0};
int amountNeeded = 0;
int combinations = 0;
int minTickets = -1;

int computeMoneyRaised()
{
  int money = 0;
  for (int i = 0; i < 4; ++i)
    money += (ticketPrices[i] * numberOfTicketsBought[i]);
  return money;
}

void backtrack(int amountRaised, int currentLevel)
{
  int money = computeMoneyRaised();
  if (money == amountNeeded)
  {
    ++combinations;
    cout << "# of PINK is " << numberOfTicketsBought[0];
    cout << " # of GREEN is " << numberOfTicketsBought[1];
    cout << " # of RED is " << numberOfTicketsBought[2];
    cout << " # of ORANGE is " << numberOfTicketsBought[3] << endl;
    int numberOfTicketsUsed = 0;
    for (int i = 0; i < 4; ++i)
      numberOfTicketsUsed += numberOfTicketsBought[i];
    if (minTickets == -1 || numberOfTicketsUsed < minTickets)
      minTickets = numberOfTicketsUsed;
    amountRaised = 0;
    return;
  }
  else if (currentLevel == 4)
    return;

  while (money <= amountNeeded)
  {
    backtrack(amountRaised, currentLevel + 1);
    ++numberOfTicketsBought[currentLevel];
    money = computeMoneyRaised();
  }

  numberOfTicketsBought[currentLevel] = 0;
}

// https://dmoj.ca/problem/ccc02s1
void theStudentsCouncilBreakfast()
{
  for (int i = 0; i < 4; ++i)
    cin >> ticketPrices[i];
  cin >> amountNeeded;

  backtrack(0, 0);
  cout << "Total combinations is " << combinations << "." << endl;
  cout << "Minimum number of tickets to print is " << minTickets << "." << endl;
}

// https://dmoj.ca/problem/ccc03s1
void snakesAndLadders()
{
  int input = 1;
  int currentSquare = 1;

  unordered_map<int, int> ladders({{9, 34},
                                   {40, 64},
                                   {67, 86}});
  unordered_map<int, int> snakes({{54, 19},
                                  {90, 48},
                                  {99, 77}});

  while (input != 0 && currentSquare != 100)
  {
    cin >> input;
    if (input == 0)
    {
      cout << "You Quit!" << endl;
      return;
    }
    else if (currentSquare + input <= 100)
      currentSquare += input;
    if (ladders.count(currentSquare))
      currentSquare = ladders[currentSquare];
    else if (snakes.count(currentSquare))
      currentSquare = snakes[currentSquare];
    cout << "You are now on square " << currentSquare << endl;
  }

  cout << "You Win!" << endl;
}

// https://dmoj.ca/problem/ccc06s1
void maternity()
{
  string parent1, parent2 = "";
  cin >> parent1 >> parent2;

  vector<string> punnettSquareAnswers;
  for (int i = 1; i < parent1.size(); i += 2)
  {
    int parent1Sum = parent1[i] + parent1[i - 1], parent2Sum = parent2[i] + parent2[i - 1];
    if ((parent1Sum >= 130 && parent1Sum <= 138) || (parent2Sum >= 130 && parent2Sum <= 138))
      punnettSquareAnswers.push_back("D");
    else if ((parent1Sum >= 194 && parent1Sum <= 202) && (parent2Sum >= 194 && parent2Sum <= 202))
      punnettSquareAnswers.push_back("R");
    else
      punnettSquareAnswers.push_back("H");
  }

  vector<string> results;
  int x = 0;
  cin >> x;

  for (int i = 0; i < x; ++i)
  {
    string kid = "";
    cin >> kid;
    bool possiblyBaby = true;
    for (int j = 0; j < kid.size(); ++j)
    {
      if ((kid[j] < 90 && punnettSquareAnswers[j] != "D" && punnettSquareAnswers[j] != "H") ||
          (kid[j] >= 97 && punnettSquareAnswers[j] != "R" && punnettSquareAnswers[j] != "H"))
      {
        possiblyBaby = false;
        break;
      }
    }

    results.push_back(possiblyBaby ? "Possible baby." : "Not their baby!");
  }

  for (auto result : results)
    cout << result << endl;
}

// https://dmoj.ca/problem/ccc08s1
void itsColdHere()
{
  string city = "";
  int temperature = 0;
  string coldestCity = "";
  int coldestTemperature = 200;
  while (city != "Waterloo")
  {
    cin >> city >> temperature;
    if (temperature <= coldestTemperature)
    {
      coldestCity = city;
      coldestTemperature = temperature;
    }
  }
  cout << coldestCity;
}

// https://dmoj.ca/problem/ccc09s1
void coolNumbers()
{
  int num1, num2 = 0;
  scanf("%d", &num1);
  scanf("%d", &num2);
  int numberOfCoolNumbers = 0;

  for (long double i = num1; i <= num2; ++i)
  {
    long long int s = sqrt(i);
    long long int c = cbrt(i);
    if ((s * s) == i && (c * c * c) == i)
      ++numberOfCoolNumbers;
  }

  printf("%d", numberOfCoolNumbers);
}

struct Computer
{
  string name;
  int value;
};

// https://dmoj.ca/problem/ccc10s1
void computerPurchase()
{
  int n = 0;
  cin >> n;

  vector<Computer> computers;
  string name = "";
  int ram, cpu, disk = 0;
  for (int i = 0; i < n; ++i)
  {
    cin >> name >> ram >> cpu >> disk;
    computers.push_back({name, ((2 * ram) + (3 * cpu) + disk)});
  }

  if (computers.size() == 0)
    return;

  sort(computers.begin(), computers.end(), [](const Computer &a, const Computer &b)
       {
        if (a.value == b.value)
            return a.name > b.name;
        return a.value > b.value; });

  cout << computers[0].name;
  if (computers.size() >= 2)
  {
    cout << endl;
    cout << computers[1].name;
  }
}

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
int bestTimeToBuyAndSellAStock(vector<int> &prices)
{
  int currentLow = prices[0];
  int profit = 0;
  for (int i = 1; i < prices.size(); ++i)
  {
    if (prices[i] < currentLow)
      currentLow = prices[i];
    profit = max(profit, prices[i] - currentLow);
  }
  return profit;
}

// https://leetcode.com/problems/search-insert-position/description/
int searchInsertPosition(vector<int> &nums, int target)
{
  int h = nums.size() - 1;
  int l = 0;
  int m = 0;

  while (l <= h)
  {
    m = (l + h) / 2;
    if (nums[m] == target)
      return m;
    else if (nums[m] > target)
      h = m - 1;
    else
      l = m + 1;
  }

  return l;
}

// https://leetcode.com/problems/climbing-stairs/description/
int climbingStairs(int n)
{
  if (n == 1)
    return 1;
  int previous = 1;
  int current = 1;
  int s = 2;
  for (int i = 2; i <= n; ++i)
  {
    s = previous + current;
    previous = current;
    current = s;
  }
  return s;
}

void updateBits(vector<int> &bits, int n, int diff)
{
  for (int i = 0; i < 32; ++i)
    if (n & (1 << i))
      bits[i] += diff;
}

int bitsToInteger(vector<int> bits)
{
  int res = 0;
  for (int i = 0; i < 32; ++i)
    if (bits[i])
      res += (1 << i);
  return res;
}

// https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/description/
int shortestSubarrayWithORAtLeastK2(vector<int> &nums, int k)
{
  int res = INT_MAX;
  int left = 0;
  vector<int> bits(32, 0);
  int currentOr = 0;

  for (int right = 0; right < nums.size(); ++right)
  {
    updateBits(bits, nums[right], 1);
    currentOr = bitsToInteger(bits);
    while (left <= right && currentOr >= k)
    {
      res = min(res, right - left + 1);
      updateBits(bits, nums[left], -1);
      currentOr = bitsToInteger(bits);
      ++left;
    }
  }

  return res == INT_MAX ? -1 : res;
}

// https://leetcode.com/problems/find-the-difference-of-two-arrays/description/
vector<vector<int>> findTheDifferenceOfTwoArrays(vector<int> &nums1, vector<int> &nums2)
{
  unordered_map<int, int> nums1Hash;
  for (int i = 0; i < nums1.size(); ++i)
    nums1Hash[nums1[i]] = 1;

  unordered_map<int, int> nums2Hash;
  for (int i = 0; i < nums2.size(); ++i)
    nums2Hash[nums2[i]] = 1;

  vector<vector<int>> result(2, vector<int>());
  for (int i = 0; i < nums1.size(); ++i)
    if (nums2Hash.count(nums1[i]) == 0 && nums1Hash[nums1[i]] == 1)
    {
      result[0].push_back(nums1[i]);
      --nums1Hash[nums1[i]];
    }

  for (int i = 0; i < nums2.size(); ++i)
    if (nums1Hash.count(nums2[i]) == 0 && nums2Hash[nums2[i]] == 1)
    {
      result[1].push_back(nums2[i]);
      --nums2Hash[nums2[i]];
    }

  return result;
}

// https://leetcode.com/problems/largest-number/description/
string largestNumber(vector<int> &nums)
{
  auto compare = [&](int a, int b)
  {
    string aStr = to_string(a);
    string bStr = to_string(b);
    return aStr + bStr > bStr + aStr;
  };

  sort(nums.begin(), nums.end(), compare);
  string result = "";
  for (int i = 0; i < nums.size(); ++i)
    result += to_string(nums[i]);

  return stoll(result) == 0 ? "0" : result;
}

// https://leetcode.com/problems/backspace-string-compare/description/
bool backspaceCompare(string s, string t)
{
  string a = "";
  string b = "";

  for (int i = 0; i < s.size(); ++i)
  {
    if (s[i] == '#' && !a.empty())
      a.pop_back();
    else if (s[i] != '#')
      a.push_back(s[i]);
  }

  for (int i = 0; i < t.size(); ++i)
  {
    if (t[i] == '#' && !b.empty())
      b.pop_back();
    else if (t[i] != '#')
      b.push_back(t[i]);
  }

  return a == b;
}

// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
bool checkIfTwoStringArraysAreEquivalent(vector<string> &word1, vector<string> &word2)
{
  string a = "";
  string b = "";
  for (auto s : word1)
    a += s;
  for (auto s : word2)
    b += s;
  return a == b;
}

// https://leetcode.com/problems/contains-duplicate-ii/
bool containsDuplicate2(vector<int> &nums, int k)
{
  unordered_map<int, int> previousNums;
  for (int i = 0; i < nums.size(); ++i)
  {
    if (previousNums.count(nums[i]) && i - previousNums[nums[i]] <= k)
      return true;
    else
      previousNums[nums[i]] = i;
  }
  return false;
}

// https://leetcode.com/problems/make-the-string-great/
string makeTheStringGreat(string s)
{
  stack<char> letters;
  for (int i = 0; i < s.size(); ++i)
  {
    if (letters.empty() || abs(int(letters.top()) - int(s[i])) != 32)
      letters.push(s[i]);
    else
      letters.pop();
  }
  string res = "";
  while (!letters.empty())
  {
    res += letters.top();
    letters.pop();
  }
  reverse(res.begin(), res.end());
  return res;
}

// https://leetcode.com/problems/jump-game-ii/description/
int jumpGame2(vector<int> &nums)
{
  int r = 0;
  int l = 0;
  int res = 0;

  while (r < nums.size() - 1)
  {
    int farthest = 0;
    for (int i = l; i <= r; ++i)
      farthest = max(farthest, i + nums[i]);
    l = r + 1;
    r = farthest;
    ++res;
  }

  return res;
}

// https://dmoj.ca/problem/ccc16s1
void ragaman()
{
  string s1 = "";
  string s2 = "";

  cin >> s1;
  cin >> s2;

  if (s1.size() != s2.size())
  {
    cout << "N" << endl;
    return;
  }

  unordered_map<char, int> s1Hash;

  for (int i = 0; i < s1.size(); ++i)
    ++s1Hash[s1[i]];

  int numberOfAsterixes = 0;

  for (int i = 0; i < s2.size(); ++i)
  {
    if (s2[i] == '*')
      ++numberOfAsterixes;
    else if (s1Hash.count(s2[i]))
    {
      --s1Hash[s2[i]];
      if (s1Hash[s2[i]] == 0)
        s1Hash.erase(s2[i]);
    }
  }

  int charactersRemaining = 0;
  for (auto x : s1Hash)
    charactersRemaining += x.second;

  cout << (charactersRemaining <= numberOfAsterixes ? "A" : "N") << endl;
}

// https://dmoj.ca/problem/ccc17s1
void sumGame()
{
  int numberOfDays = 0;

  scanf("%d", &numberOfDays);

  vector<int> sums(numberOfDays);

  int prefixSum = 0;
  string input;
  for (int i = 0; i < numberOfDays; ++i)
  {
    cin >> input;
    sums[i] = prefixSum + stoi(input);
    prefixSum += stoi(input);
  }

  prefixSum = 0;
  pair<int, int> maxRunsAndIndex = pair<int, int>(0, 0);
  for (int i = 0; i < numberOfDays; ++i)
  {
    cin >> input;
    prefixSum += stoi(input);
    if (prefixSum == sums[i] && prefixSum >= maxRunsAndIndex.first)
    {
      maxRunsAndIndex.first = prefixSum;
      maxRunsAndIndex.second = i + 1;
    }
  }

  printf("%d", maxRunsAndIndex.second);
}

// https://dmoj.ca/problem/ccc18s1
void voronoiVillages()
{
  int N;
  scanf("%d", &N);

  vector<int> villages(N);
  for (int i = 0; i < N; ++i)
    scanf("%d", &villages[i]);

  sort(villages.begin(), villages.end());
  double minimumDistance = INT_MAX;
  double distance = 0;
  for (int i = 1; i < N - 1; ++i)
  {
    distance = ((villages[i] - villages[i - 1]) / (double)2) + (((villages[i + 1] - villages[i]) / (double)2));
    minimumDistance = min(minimumDistance, distance);
  }

  printf("%.1f", minimumDistance);
}

// https://dmoj.ca/problem/ccc19s1
void flipper()
{
  string steps;
  cin >> steps;

  int grid[4] = {1, 2, 3, 4};
  for (int i = 0; i < steps.size(); ++i)
  {
    if (steps[i] == 'H')
    {
      swap(grid[0], grid[2]);
      swap(grid[1], grid[3]);
    }
    else
    {
      swap(grid[0], grid[1]);
      swap(grid[2], grid[3]);
    }
  }

  printf("%d %d\n%d %d", grid[0], grid[1], grid[2], grid[3]);
}

// https://dmoj.ca/problem/ccc20s1
void surmisingASprintersSpeed()
{
  int N;
  scanf("%d", &N);

  vector<pair<int, int>> measurements(N);
  for (int i = 0; i < N; ++i)
    scanf("%d %d", &measurements[i].first, &measurements[i].second);
  sort(measurements.begin(), measurements.end());

  double maxSpeed = -1;
  for (int i = 1; i < measurements.size(); ++i)
  {
    double speed = abs((measurements[i].second - measurements[i - 1].second) / (double)(measurements[i].first - measurements[i - 1].first));
    maxSpeed = max(maxSpeed, speed);
  }

  printf("%.1f", maxSpeed);
}

// https://dmoj.ca/problem/ccc21s1
void crazyFencing()
{
  int N;
  scanf("%d", &N);

  int leftWidth;
  int rightWidth;
  scanf("%d", &leftWidth);
  scanf("%d", &rightWidth);
  vector<int> sums(N);
  for (int i = 0; i < N; ++i)
  {
    sums[i] = leftWidth + rightWidth;
    leftWidth = rightWidth;
    scanf("%d", &rightWidth);
  }

  int width = rightWidth;
  double area = 0;
  for (int i = 0; i < N; ++i)
  {
    area += width * (sums[i] / (double)2);
    if (i < N - 1)
      scanf("%d", &width);
  }

  printf("%.1f", area);
}

// https://dmoj.ca/problem/ccc12s1
void dontPassMeTheBall()
{
  int J;
  scanf("%d", &J);

  if (J < 4)
  {
    printf("0");
    return;
  }

  int n = J - 1;
  int r = 3;
  int rFactorial = 6;
  int maxNumbersToMultiply = n - r;
  int nFactorialProduct = 1;
  for (int i = n; i > maxNumbersToMultiply; --i)
    nFactorialProduct *= i;

  printf("%d", nFactorialProduct / rFactorial);
}

// https://dmoj.ca/problem/ccc00s2
void babblingBrooks()
{
  int N;
  scanf("%d", &N);

  vector<int> streams(N);
  for (int i = 0; i < N; ++i)
    scanf("%d", &streams[i]);

  int input = -1;
  while (input != 77)
  {
    scanf("%d", &input);
    if (input == 99)
    {
      int splitStreamIndex;
      int percentage;
      scanf("%d", &splitStreamIndex);
      scanf("%d", &percentage);

      int leftSplitValue = percentage * streams[splitStreamIndex - 1] / 100;
      int rightSplitValue = streams[splitStreamIndex - 1] - leftSplitValue;

      streams[splitStreamIndex - 1] = leftSplitValue;
      streams.insert(streams.begin() + splitStreamIndex, rightSplitValue);
    }
    else if (input == 88)
    {
      int joinedStreamIndex;
      scanf("%d", &joinedStreamIndex);
      streams[joinedStreamIndex - 1] += streams[joinedStreamIndex];
      streams.erase(streams.begin() + joinedStreamIndex);
    }
  }

  for (int i = 0; i < streams.size(); ++i)
    printf("%d ", streams[i]);
}

string reduce(int numerator, int denominator)
{
  for (int i = numerator; i >= 1; --i)
    if (numerator % i == 0 && denominator % i == 0)
      return to_string(numerator / i) + "/" + to_string(denominator / i);
}

// https://dmoj.ca/problem/ccc02s2
void fractionAction()
{
  int numerator, denominator;
  scanf("%d", &numerator);
  scanf("%d", &denominator);

  if (numerator == 0)
  {
    printf("0");
    return;
  }
  else if (numerator % denominator == 0)
  {
    printf("%d", numerator / denominator);
    return;
  }

  if (numerator > denominator)
    printf("%d %s", numerator / denominator, reduce(numerator % denominator, denominator).c_str());
  else
    printf("%s", reduce(numerator, denominator).c_str());
}

// https://dmoj.ca/problem/ccc05s2
void mouseMove()
{
  int c, r;
  scanf("%d", &c);
  scanf("%d", &r);

  int a, b;

  vector<pair<int, int>> result;
  pair<int, int> position = pair<int, int>(0, 0);
  while (true)
  {
    scanf("%d %d", &a, &b);
    if (a == 0 && b == 0)
      break;

    position.first += a;
    position.second += b;

    if (position.first < 0)
      position.first = 0;
    else if (position.first > c)
      position.first = c;

    if (position.second < 0)
      position.second = 0;
    else if (position.second > r)
      position.second = r;

    result.push_back(position);
  }

  for (int i = 0; i < result.size(); ++i)
    printf("%d %d\n", result[i].first, result[i].second);
}

// https://dmoj.ca/problem/ccc11s2
void multipleChoice()
{
  int N;
  scanf("%d", &N);

  vector<string> answers(N);
  for (int i = 0; i < N; ++i)
    cin >> answers[i];

  int numberCorrect = 0;
  string s;
  for (int i = 0; i < N; ++i)
  {
    cin >> s;
    if (s == answers[i])
      ++numberCorrect;
  }

  printf("%d", numberCorrect);
}

// https://dmoj.ca/problem/ccc13s2
void bridgeTransport()
{
  int maxWeight;
  scanf("%d", &maxWeight);

  int numberOfTrainCars;
  scanf("%d", &numberOfTrainCars);

  vector<int> weights(numberOfTrainCars, 0);
  for (int i = 0; i < numberOfTrainCars; ++i)
    scanf("%d", &weights[i]);

  int weight = 0;
  int numberOfCarsCrossed = 0;
  for (int i = 0; i < numberOfTrainCars; ++i)
  {
    weight += weights[i];
    if (i > 3)
      weight -= weights[i - 4];
    if (weight > maxWeight)
    {
      printf("%d", numberOfCarsCrossed);
      return;
    }
    ++numberOfCarsCrossed;
  }

  printf("%d", numberOfCarsCrossed);
}

// https://dmoj.ca/problem/ccc17s2
void highTideLowTide()
{
  int N;
  scanf("%d", &N);

  vector<int> measurements(N, 0);
  for (int i = 0; i < N; ++i)
    scanf("%d", &measurements[i]);

  sort(measurements.begin(), measurements.end());

  int middle = N / 2;
  vector<int> highs;
  vector<int> lows;
  int i = 0;
  for (i = 0; i < middle; ++i)
    lows.push_back(measurements[i]);
  if (N % 2 != 0)
    lows.push_back(measurements[i++]);
  for (; i < measurements.size(); ++i)
    highs.push_back(measurements[i]);

  sort(lows.rbegin(), lows.rend());

  for (i = 0; i < middle; ++i)
    printf("%d %d ", lows[i], highs[i]);
  if (N % 2 != 0)
    printf("%d", lows[i]);
}

template <typename T>
void display2DVector(vector<vector<T>> arr)
{
  for (int i = 0; i < arr.size(); ++i)
  {
    for (int j = 0; j < arr[i].size(); ++j)
      cout << arr[i][j] << " ";
    cout << endl;
  }
}

template <typename T>
void displayVector(vector<T> arr)
{
  for (auto x : arr)
    cout << x << " ";
}

int main()
{
  vector<int> nums1({2, 3, 1, 1, 4});
  vector<int> nums2({1, 1, 2, 2});
  vector<vector<int>> nums2d({{4, 3, 1}, {6, 5, 2}, {9, 7, 3}});

  return 0;
}

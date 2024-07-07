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

// https://leetcode.com/problems/contains-duplicate/
bool containsDuplicate(vector<int> &nums) {
    unordered_map<int, int> duplicates;

    for (auto x: nums) {
        if (duplicates.find(x) != duplicates.end())
            return true;
        else
            duplicates[x] = 0;
    }

    return false;
}

// https://leetcode.com/problems/concatenation-of-array/description/
vector<int> concatenationOfArray(vector<int> &nums) {
    vector<int> results;
    results.reserve(nums.size() * 2);
    results.insert(results.end(), nums.begin(), nums.end());
    results.insert(results.end(), nums.begin(), nums.end());
    return results;
}

// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/submissions/1218706537/
vector<int> replaceAlementsWithGreatestElementOnRightSide(vector<int> &arr) {
    vector<int> outputArray(arr.size());
    int previousValue = -1;
    outputArray[arr.size() - 1] = -1;

    for (int i = arr.size() - 1; i > 0; --i) {
        if (arr[i] > previousValue) {
            outputArray[i - 1] = arr[i];
            previousValue = arr[i];
        } else
            outputArray[i - 1] = previousValue;
    }

    return outputArray;
}

// https://leetcode.com/problems/is-subsequence/description/
bool isSubsequence(string s, string t) {
    for (int i = 0; i < t.size(); ++i) {
        if (t[i] == s[0]) {
            s.erase(0, 1);
        }

        if (s.size() == 0)
            return true;
    }

    return s.size() == 0;
}

// https://leetcode.com/problems/two-sum/description/
vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> numberNeeded;

    for (int i = 0; i < nums.size(); ++i) {
        if (numberNeeded.find(nums[i]) != numberNeeded.end())
            return vector<int>({numberNeeded[nums[i]], i});
        else
            numberNeeded[abs(nums[i] - target)] = i;
    }

    return vector<int>({0, 0});
}

// https://leetcode.com/problems/longest-common-prefix/description/
string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 1)
        return strs[0];

    string longestCommonPrefix = strs[0];

    for (int i = 1; i < strs.size(); ++i) {
        int j = 0;
        while (j < strs[i].size() && j < longestCommonPrefix.size()) {
            if (strs[i][j] != longestCommonPrefix[j]) {
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
vector<vector<string> > groupAnagrams(vector<string> &strs) {
    unordered_map<string, int> anagrams;
    vector<vector<string> > anagramsVector;
    int i = 0;

    for (auto s: strs) {
        string x = s;
        sort(x.begin(), x.end());
        if (anagrams.count(x) == 0) {
            anagrams[x] = i;
            anagramsVector.push_back({s});
            ++i;
        } else
            anagramsVector[anagrams[x]].push_back(s);
    }

    return anagramsVector;
}

// https://leetcode.com/problems/pascals-triangle/description/
vector<vector<int> > pascalsTriangle(int numRows) {
    vector<vector<int> > pascalsTriangleVector{{1}};

    if (numRows == 1)
        return pascalsTriangleVector;

    int j = 1;
    for (int i = 1; i < numRows; ++i) {
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
int removeElement(vector<int> &nums, int val) {
    if (nums.size() == 1 && nums[0] == val)
        return 0;

    int i = 0;
    int j = nums.size() - 1;
    int k = j + 1;

    while (i <= j) {
        if (nums[i] == val && nums[j] == val) {
            --j;
            --k;
            continue;
        } else if (nums[i] == val) {
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
int uniqueEmailAddresses(vector<string> &emails) {
    unordered_map<string, int> uniqueAddresses;
    int i = 0;

    for (auto email: emails) {
        string filteredEmail = "";
        bool ignoreLetters = false;

        for (int j = 0; j < email.size(); ++j) {
            if (email[j] == '+')
                ignoreLetters = true;
            else if (email[j] == '@')
                break;
            else if (email[j] != '.' && !ignoreLetters)
                filteredEmail += email[j];
        }

        int indexOfDomain = email.find("@");
        filteredEmail += email.substr(indexOfDomain, email.size() - indexOfDomain + 1);

        if (uniqueAddresses.count(filteredEmail) == 0) {
            uniqueAddresses[filteredEmail] = 0;
            ++i;
        }
    }

    return i;
}

// https://leetcode.com/problems/isomorphic-strings/description/
bool isIsomorphic(string s, string t) {
    unordered_map<char, char> inputToOutput;
    unordered_map<char, char> outputToInput;

    for (int i = 0; i < s.size(); ++i) {
        if (inputToOutput.count(s[i]) != 0 && inputToOutput[s[i]] != t[i])
            return false;
        else if (outputToInput.count(t[i]) != 0 && outputToInput[t[i]] != s[i])
            return false;
        else {
            inputToOutput[s[i]] = t[i];
            outputToInput[t[i]] = s[i];
        }
    }

    return true;
}

// https://leetcode.com/problems/can-place-flowers/description/
bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    if (n == 0)
        return true;
    if (flowerbed.size() == 1 && flowerbed[0] == 0)
        return n <= 1;

    int previous = 0;

    for (int i = 0; i < flowerbed.size() - 1 && n > 0; ++i) {
        if (previous == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
            n -= 1;
            flowerbed[i] = 1;
            previous = flowerbed[i];
        } else
            previous = flowerbed[i];
    }

    if (previous == 0 && flowerbed[flowerbed.size() - 1] == 0)
        n -= 1;

    return n == 0;
}

// https://leetcode.com/problems/majority-element/description/
int majorityElement(vector<int> &nums) {
    int count = 0;
    int maxElement = 0;

    for (auto x: nums) {
        if (count == 0) {
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
bool isPalindrome(string s) {
    if (s.size() == 1)
        return true;

    string newString = "";

    for (auto x: s) {
        if (isalpha(x) || isdigit(x))
            newString += tolower(x);
    }

    int middle = newString.size() / 2;
    string secondPiece = newString.substr(newString.size() % 2 == 0 ? middle : middle + 1, newString.size());
    reverse(secondPiece.begin(), secondPiece.end());
    return newString.substr(0, middle) == secondPiece;
}

bool isPalindrome2(string s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j])
            return false;
        ++i;
        --j;
    }

    return true;
}

// https://leetcode.com/problems/valid-palindrome-ii/description/
bool validPalindrome(string s) {
    int i = 0;
    int j = s.size() - 1;

    while (i < j) {
        if (s[i] != s[j])
            return isPalindrome2(s, i, j - 1) || isPalindrome2(s, i + 1, j);

        ++i;
        --j;
    }

    return true;
}

// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/
int minimumDifferenceBetweenHighestAndLowestOfKScores(vector<int> &nums, int k) {
    if (nums.size() == 1)
        return 0;

    sort(nums.begin(), nums.end(), greater<int>());
    int smallestDifference = -1;

    for (int i = 0; i < nums.size() - k; ++i) {
        int difference = nums[i] - nums[i + k - 1];
        if (difference < smallestDifference || smallestDifference == -1)
            smallestDifference = difference;
    }

    return smallestDifference;
}

// https://leetcode.com/problems/reverse-string/description/
void reverseString(vector<char> &s) {
    int i = 0;
    int j = s.size() - 1;

    while (i < j) {
        swap(s[i], s[j]);
        ++i;
        --j;
    }
}

// https://leetcode.com/problems/merge-sorted-array/description/
void mergeSortedArray(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int i = m;
    for (auto x: nums2) {
        nums1[i] = x;
        ++i;
    }

    sort(nums1.begin(), nums1.end());
}

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
int removeDuplicatesFromSortedArray(vector<int> &nums) {
    int j = 1;

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[i - 1]) {
            nums[j] = nums[i];
            ++j;
        }
    }

    return j;
}

// https://leetcode.com/problems/next-greater-element-i/description/
vector<int> nextGreaterElementOne(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> nums1Hash;

    for (int i = 0; i < nums1.size(); ++i)
        nums1Hash[nums1[i]] = i;

    stack<int> numsStack;
    vector<int> result(nums1.size(), -1);
    for (int i = 0; i < nums2.size(); ++i) {
        int currentElement = nums2[i];
        while (!numsStack.empty() && currentElement > numsStack.top()) {
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
int pivotIndex(vector<int> &nums) {
    int rightSum = 0;
    int leftSum = 0;
    for (int i = 1; i < nums.size(); ++i)
        leftSum += nums[i];

    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0)
            leftSum -= nums[i];
        if (leftSum == rightSum)
            return i;
        rightSum += nums[i];
    }

    return -1;
}

// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
class NumArray {
public:
    vector<int> numsArray;

    NumArray(vector<int> &nums) {
        int sum = 0;
        for (auto x: nums) {
            sum += x;
            this->numsArray.push_back(sum);
        }
    }

    int sumRange(int left, int right) {
        if (left > 0) {
            return this->numsArray[right] - this->numsArray[left - 1];
        }
        return this->numsArray[right];
    }
};

// https://leetcode.com/problems/maximum-number-of-balloons/description/
int maxNumberOfBalloons(string text) {
    unordered_map<char, int> balloonHashMap = {
            {'b', 0},
            {'a', 1},
            {'l', 2},
            {'o', 3},
            {'n', 4}
    };
    vector<int> balloonWordArray({0, 0, 0, 0, 0});

    for (auto x: text) {
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
bool wordPattern(string pattern, string s) {
    unordered_map<char, string> letterToWord;
    unordered_map<string, char> wordToLetter;

    int j = 0;
    int k = 0;
    for (int i = 0; i < s.size() + 1; ++i) {
        if (s[i] == ' ' || i == s.size()) {
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
class MyHashSet {
public:
    vector<bool> booleanArray;

    MyHashSet() {
        booleanArray.push_back(false);
    }

    void add(int key) {
        if (key >= booleanArray.size()) {
            for (int i = booleanArray.size(); i < key + 1; ++i)
                booleanArray.push_back(false);
        }
        booleanArray[key] = true;
    }

    void remove(int key) {
        if (key < booleanArray.size())
            booleanArray[key] = false;
    }

    bool contains(int key) {
        if (key < booleanArray.size())
            return booleanArray[key];
        return false;
    }
};

// https://leetcode.com/problems/design-hashmap/description/
//class MyHashMap {
//public:
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
vector<int> sortArray(vector<int> &nums) {
    if (nums.size() <= 2) {
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
    while (i < leftPartition.size() && j < rightPartition.size()) {
        if (leftPartition[i] <= rightPartition[j]) {
            nums[k] = leftPartition[i];
            ++i;
        } else {
            nums[k] = rightPartition[j];
            ++j;
        }
        ++k;
    }

    while (i < leftPartition.size() && k < nums.size()) {
        nums[k] = leftPartition[i];
        ++k;
        ++i;
    }

    while (j < rightPartition.size() && k < nums.size()) {
        nums[k] = rightPartition[j];
        k += 1;
        ++j;
    }

    return nums;
}

// https://leetcode.com/problems/top-k-frequent-elements/description/
vector<int> topKFrequentElements(vector<int> &nums, int k) {
    if (nums.size() == 1)
        return nums;

    unordered_map<int, int> count;
    vector<vector<int> > frequencies;
    frequencies.resize(nums.size());

    for (auto x: nums) {
        if (count.count(x) == 0)
            count[x] = 1;
        else
            count[x] += 1;
    }

    for (auto x: count)
        frequencies[x.second].push_back(x.first);

    vector<int> result;
    int i = frequencies.size() - 1;
    while (result.size() != k) {
        for (int j = 0; j < frequencies[i].size(); ++j) {
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
vector<int> productOfArrayExceptSelf(vector<int> &nums) {
    vector<int> result(nums.size(), 0);
    unordered_map<int, int> previousNumbers;

    for (int i = 0; i < nums.size(); ++i) {
        if (previousNumbers.count(nums[i]) == 0) {
            int product = 1;
            for (int j = 0; j < nums.size(); ++j) {
                if (j != i)
                    product *= nums[j];
            }
            result[i] = product;
            previousNumbers[nums[i]] = product;
        } else
            result[i] = previousNumbers[nums[i]];
    }

    return result;
}

// https://leetcode.com/problems/valid-sudoku/description/
bool validSudoku(vector<vector<char> > &board) {
    unordered_map<char, int> currentRow;
    unordered_map<string, int> boxes;
    vector<unordered_map<char, int> > columns;
    columns.resize(9);

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            if (board[i][j] != '.') {
                string boxesString;
                boxesString += (char) (i / 3);
                boxesString += (char) (j / 3);
                if (currentRow.count(board[i][j]) != 0 || columns[j].count(board[i][j]) != 0 ||
                    boxes.count(boxesString) != 0)
                    return false;
                else {
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
int longestConsecutive(vector<int> &nums) {
    if (nums.size() == 0)
        return 0;

    sort(nums.begin(), nums.end());
    int longestSequence = 1;
    int length = 1;

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] - 1 == nums[i - 1])
            ++length;
        else if (nums[i] != nums[i - 1]) {
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
void sortColors(vector<int> &nums) {
    if (nums.size() == 1)
        return;

    int left = 0;
    int right = nums.size() - 1;
    int mid = 0;

    while (mid < nums.size() && mid <= right) {
        if (nums[mid] == 0) {
            swap(nums[left], nums[mid]);
            ++left;
        } else if (nums[mid] == 2) {
            swap(nums[mid], nums[right]);
            --right;
            --mid;
        }
        ++mid;
    }
}

// https://leetcode.com/problems/encode-and-decode-tinyurl/description/
class EncodeAndDecodeTinyURL {
public:
    string encode(string longUrl) {
        string newString;
        for (char s: longUrl) {
            int ascii = (int) s;
            ascii += 5;
            newString.push_back(char(ascii));
        }

        return newString;
    }

    string decode(string shortUrl) {
        string newString;
        for (char s: shortUrl) {
            int ascii = (int) s;
            ascii -= 5;
            newString.push_back(char(ascii));
        }

        return newString;
    }
};

// https://leetcode.com/problems/brick-wall/description/
int brickWall(vector<vector<int> > &wall) {
    unordered_map<int, int> gaps;
    int max = 0;

    for (int i = 0; i < wall.size(); ++i) {
        int rowSum = wall[i][0];
        for (int j = 0; j < wall[i].size() - 1;) {
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

// https://leetcode.com/problems/sort-colors/description/
int ContainerWithMostWater(vector<int> &height) {
    int maxArea = 0;
    int i = 0;
    int j = height.size() - 1;

    while (i < j) {
        int area = (j - i) * (min(height[i], height[j]));
        if (area > maxArea)
            maxArea = area;

        height[i] > height[j] ? --j : ++i;
    }

    return maxArea;
}

// https://leetcode.com/problems/set-matrix-zeroes/description/
vector<int> spiralMatrix(vector<vector<int> > &matrix) {
    vector<int> spiraled;

    int leftPointer = 0;
    int rightPointer = matrix[0].size() - 1;
    int topPointer = 1;
    int bottomPointer = matrix.size() - 1;

    int k = 0;
    int i = 0;
    int j = 0;
    int direction = 0; // 0 -> right, 1 -> down, 2 -> left, 3 -> up

    while (k < (matrix.size() * matrix[0].size())) {
        spiraled.push_back(matrix[i][j]);

        if (direction == 0 && j == rightPointer) {
            direction = 1;
            --rightPointer;
        } else if (direction == 1 && i == bottomPointer) {
            direction = 2;
            --bottomPointer;
        } else if (direction == 2 && j == leftPointer) {
            direction = 3;
            ++leftPointer;
        } else if (direction == 3 && i == topPointer) {
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
void setMatrixZeroes(vector<vector<int> > &matrix) {
    bool rowZero = false;

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;
                if (i > 0)
                    matrix[i][0] = 0;
                else
                    rowZero = true;
            }
        }
    }

    for (int i = 1; i < matrix.size(); ++i) {
        for (int j = 1; j < matrix[i].size(); ++j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    if (rowZero) {
        for (int i = 0; i < matrix[0].size(); ++i)
            matrix[0][i] = 0;
    }

    if (matrix[0][0] == 0) {
        for (int i = 0; i < matrix.size(); ++i)
            matrix[i][0] = 0;
    }
}

// https://leetcode.com/problems/monotonic-array/description/
bool isMonotic(vector<int> &nums) {
    int increasingOrDecreasing = 0; // 1 -> increasing, 2 -> decreasing

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] == nums[i - 1])
            continue;
        else if (increasingOrDecreasing == 0)
            increasingOrDecreasing = nums[i] >= nums[i - 1] ? 1 : 2;
        if ((increasingOrDecreasing == 1 && nums[i] < nums[i - 1]) || (
                increasingOrDecreasing == 2 && nums[i] > nums[i - 1]))
            return false;
    }

    return true;
}

// https://leetcode.com/problems/number-of-good-pairs/description/
int numberOfGoodPairs(vector<int> &nums) {
    unordered_map<int, int> counts;
    int result = 0;
    for (auto x: nums) {
        if (counts.count(x)) {
            result += counts[x];
            counts[x] += 1;
        } else
            counts[x] = 1;
    }

    return result;
}

// https://leetcode.com/problems/pascals-triangle-ii/description/
vector<int> pascalsTriangle2(int rowIndex) {
    vector<int> previous(rowIndex + 1, 1);
    vector<int> current(rowIndex + 1, 1);

    bool previousOrCurrent = true; // true -> current, false -> previous

    for (int i = 0; i < rowIndex + 1; ++i) {
        for (int j = 1; j < i; ++j) {
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
int findWordsThatCanBeFormedByCharacters(vector<string> &words, string chars) {
    unordered_map<char, int> charsHashMap;
    for (auto x: chars) {
        if (charsHashMap.count(x))
            ++charsHashMap[x];
        else
            charsHashMap[x] = 1;
    }

    int totalLength = 0;
    for (auto x: words) {
        unordered_map<char, int> lettersUsed;
        bool isGood = true;
        for (auto letter: x) {
            if (lettersUsed.count(letter))
                ++lettersUsed[letter];
            else
                lettersUsed[letter] = 1;

            if (charsHashMap.count(letter) == 0 || lettersUsed[letter] > charsHashMap[letter]) {
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
string largestGoodInteger(string num) {
    string largestNum = "";

    int startIndex = 0;
    for (int i = 1; i < num.size(); ++i) {
        if (num[i] != num[i - 1])
            startIndex = i;
        else if (i - startIndex == 2 && (largestNum == "" || (int) largestNum[0] < (int) num[i]))
            largestNum = string(3, num[i]);
    }

    return largestNum;
}

// https://leetcode.com/problems/destination-city/description/
string destinationCity(vector<vector<string>> &paths) {
    unordered_map<string, string> startAndEndCities;
    for (auto x: paths)
        startAndEndCities[x[1]] = "";
    for (auto x: paths)
        startAndEndCities.erase(x[0]);

    return startAndEndCities.begin()->first;
}

// https://leetcode.com/problems/maximum-product-difference-between-two-pairs/description/
int maximumProductDifferenceBetweenTwoPairs(vector<int> &nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    return (nums[0] * nums[1]) - (nums[nums.size() - 1] * nums[nums.size() - 2]);
}

// https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/
int maximumScoreAfterSplittingAString(string s) {
    int numberOfOnes = 0;
    for (int i = 1; i < s.size(); ++i)
        numberOfOnes += s[i] == '1' ? 1 : 0;

    int numberOfZeroes = 0;

    int maxScore = -1;
    for (int i = 1; i < s.size(); ++i) {
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
bool pathCrossing(string path) {
    int x = 0;
    int y = 0;
    set<vector<int>> previousPoints;
    previousPoints.insert({0, 0});
    for (auto direction: path) {
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
int minimumChangesToMakeAlternatingBinaryString(string s) {
    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i % 2) // Odd
            count += s[i] == '0' ? 1 : 0;
        else
            count += s[i] == '1' ? 1 : 0;
    }

    return count < (s.size() - count) ? count : s.size() - count;
}

// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/description/
bool redistributeChractersToMakeAllStringsEqual(vector<string> &words) {
    unordered_map<char, int> frequencies;
    for (auto word: words) {
        for (auto letter: word) {
            if (frequencies.count(letter))
                ++frequencies[letter];
            else
                frequencies[letter] = 1;
        }
    }

    for (auto x: frequencies) {
        if (x.second % words.size() != 0)
            return false;
    }

    return true;
}

// https://leetcode.com/problems/largest-substring-between-two-equal-characters/description/
int largestSubstringBetweenTwoEqualCharacters(string s) {
    unordered_map<char, int> letterPositions;
    int largestLength = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (letterPositions.count(s[i]) && (i - letterPositions[s[i]] - 1) > largestLength)
            largestLength = (i - letterPositions[s[i]] - 1);
        else if (letterPositions.count(s[i]) == 0)
            letterPositions[s[i]] = i;
    }

    return largestLength;
}

// https://leetcode.com/problems/set-mismatch/description/
vector<int> setMismatch(vector<int> &nums) {
    int actualSum = (nums.size() * (nums.size() + 1)) / 2;
    int currentSum = 0;
    int duplicatedNumber = -1;
    unordered_map<int, int> previousNumbers;
    for (auto x: nums) {
        if (previousNumbers.count(x) && duplicatedNumber == -1)
            duplicatedNumber = x;
        else
            previousNumbers[x] = 0;
        currentSum += x;
    }

    return vector<int>({duplicatedNumber, actualSum - (currentSum - duplicatedNumber)});
}

// https://leetcode.com/problems/first-unique-character-in-a-string/description/
int firstUniqueCharacterInAString(string s) {
    unordered_map<char, int> letterCounts;
    for (auto x: s) {
        if (letterCounts.count(x))
            ++letterCounts[x];
        else
            letterCounts[x] = 1;
    }

    for (int i = 0; i < s.size(); ++i) {
        if (letterCounts[s[i]] == 1)
            return i;
    }

    return -1;
}

// https://leetcode.com/problems/intersection-of-two-arrays/description/
vector<int> intersectionOfTwoArrays(vector<int> &nums1, vector<int> &nums2) {
    vector<int> intersection;
    unordered_map<int, int> nums1Hash;

    for (auto x: nums1)
        nums1Hash[x] = 0;

    for (auto x: nums2) {
        if (nums1Hash.count(x)) {
            intersection.push_back(x);
            nums1Hash.erase(x);
        }
    }

    return intersection;
}

// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/
int numberOfStudentsUnableToEatLunch(vector<int> &students, vector<int> &sandwiches) {
    queue<int> studentsQueue;
    queue<int> sandwichesQueue;
    for (auto x: students)
        studentsQueue.push(x);
    for (auto x: sandwiches)
        sandwichesQueue.push(x);

    int queueStartLength = studentsQueue.size();
    int i = 0;
    while (!studentsQueue.empty()) {
        if (studentsQueue.front() == sandwichesQueue.front()) {
            studentsQueue.pop();
            sandwichesQueue.pop();
            i = 0;
        } else {
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
int timeNeededToBuyTickets(vector<int> &tickets, int k) {
    int seconds = 0;

    while (tickets[k] != 0) {
        for (int i = 0; i < tickets.size(); ++i) {
            if (tickets[i] != 0) {
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
int specialArrayWithXElementsGreaterThanOrEqualToX(vector<int> &nums) {
    unordered_map<int, int> previousNumbers;
    int maxElement = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
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
int bestTimeToBuyAndSellStock2(vector<int> &prices) {
    int total = 0;
    for (int i = 0; i < prices.size() - 1; ++i) {
        if (prices[i + 1] > prices[i])
            total += prices[i + 1] - prices[i];
    }

    return total;
}

// https://leetcode.com/problems/subarray-sum-equals-k/description/
int subarraySumEqualsK(vector<int> &nums, int k) {
    int numberOfSubArrays = 0;
    unordered_map<int, int> sumPrefixes;
    sumPrefixes[0] = 1;
    int total = 0;

    for (int i = 0; i < nums.size(); ++i) {
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
vector<int> twoSum2InputArrayIsSorted(vector<int> &numbers, int target) {
    int i = 0;
    int j = numbers.size() - 1;

    while (i < j) {
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
class MinStack {
public:
    vector<int> vals;
    vector<int> smallestValues;

    MinStack() {
    }

    void push(int val) {
        vals.push_back(val);
        if (this->smallestValues.empty() || this->smallestValues[smallestValues.size() - 1] >= val)
            this->smallestValues.push_back(val);
    }

    void pop() {
        if (this->smallestValues[smallestValues.size() - 1] == vals[vals.size() - 1])
            this->smallestValues.pop_back();
        vals.pop_back();
    }

    int top() {
        return vals[vals.size() - 1];
    }

    int getMin() {
        return this->smallestValues[smallestValues.size() - 1];
    }
};

vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> triplets;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 1; ++i) {
        int j = i + 1;
        int k = nums.size() - 1;
        int target = -nums[i];
        while (j < k && (j == i + 1 || nums[j] != nums[j - 1]) ||
               (k == nums.size() - 1 || nums[k] != nums[k + 1])) {
            if (nums[j] + nums[k] == target) {
                triplets.push_back({nums[i], nums[j], nums[k]});
                break;
            } else if (nums[j] + nums[k] > target)
                --k;
            else
                ++j;
        }
    }

    return triplets;
}

int evaluateReversePolishNotation(vector<string> &tokens) {
    stack<int> numsStack;

    for (int i = 0; i < tokens.size(); ++i) {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
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
        } else
            numsStack.push(stoi(tokens[i]));
    }

    return numsStack.top();
}

template<typename T>
void displayVector(vector<T> arr) {
    for (auto x: arr)
        cout << x << " ";
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
    vector<int> nums(
            {-1, 0, 1, 2, -1, -4});

    vector<string> operations({"2", "1", "+", "3", "*"});


    cout << evaluateReversePolishNotation(operations) << endl;

    return 0;
}

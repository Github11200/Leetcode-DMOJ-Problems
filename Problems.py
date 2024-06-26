from pickle import TRUE
import sys
import math
from tabnanny import check
from xmlrpc.client import Boolean

# https://dmoj.ca/problem/cheerio1j3


def Festival():
    # Get the user input
    numberOfRowsAndColumns = int(input())

    # This holds each string tat the user inputs
    rowValues = []
    # This array stores the number of empty spots in each column so you know when to print "S"
    numberOfEmptySpotsInEachColumn = [0] * numberOfRowsAndColumns

    # Loop through for the number of rows and columns there are and get the string for each row
    for x in range(numberOfRowsAndColumns):
        letters = str(input())
        rowValues.append(letters)
        # Loop through the string that the user inputs, for example ".S"
        for i, letter in enumerate(letters):
            # If the letter is a "." then increase that in the array
            if letter == ".":
                numberOfEmptySpotsInEachColumn[i] += 1

    # Loop through every string and print out the new values
    for row in rowValues:
        for i, value in enumerate(row):
            # If there are still dots to be printed out then print a dot and subtract one from that array
            if numberOfEmptySpotsInEachColumn[i] != 0:
                print(".", end="")
                numberOfEmptySpotsInEachColumn[i] -= 1
            else:  # If all the dots have been printed out in a column then print a "S"
                print("S", end="")
        print("\n")


# https://leetcode.com/problems/roman-to-integer/editorial/
def RomanToInteger():
    class RomanNumerals:
        def __init__(self) -> None:
            self.I = 1
            self.V = 5
            self.X = 10
            self.L = 50
            self.C = 100
            self.D = 500
            self.M = 1000

    romanNumerals = RomanNumerals()
    stringInput = str(input())
    previousNumber = None
    total = 0

    for letter in stringInput:
        number = getattr(romanNumerals, letter)
        if previousNumber and number > previousNumber:
            total = abs((total - previousNumber) + (number - previousNumber))
        else:
            total += number
        previousNumber = number

    print(total)

# https://leetcode.com/problems/plus-one/


def PlusOne():
    digits = [1, 2, 3]
    length = len(digits) - 1
    number = 0

    for digit in digits:
        number += digit * pow(10, length)
        length -= 1

    del length
    number += 1
    stringNumber = str(number)
    del number
    outputDigits = []
    for letter in stringNumber:
        outputDigits.append(int(letter))

    print(outputDigits)

    temps = []
    numberOfDays = int(input("How many day's temperature? "))
    average = 0

    for i in range(numberOfDays):
        temp = int(input(f"Day {i + 1}'s high temp: "))
        temps.append(temp)
        average += temp
        i += 1

    average /= numberOfDays
    print(average)

    numberOfNumbersMoreThanAverage = 0
    for ele in temps:
        if ele > average:
            numberOfNumbersMoreThanAverage += 1

    print(f"{numberOfNumbersMoreThanAverage} day(s) above average")

# https://leetcode.com/problems/single-number/description/


def SingleNumber():
    inputList = [4, 1, 2, 1, 2]
    numsDict = {}
    for item in inputList:
        print(item)
        if item in numsDict.keys():
            del numsDict[item]
        else:
            numsDict[item] = item
    return list(numsDict.keys())

# https://leetcode.com/problems/container-with-most-water/description/


def ContainerWithMostWater():
    height = [1, 1]

    i = 0
    j = len(height) - 1

    largestArea = 0

    while i != j:
        area = 0
        if height[j] < height[i] or height[j] == height[i]:
            area = height[j] * (j - i)
        else:
            area = height[i] * (j - i)

        if area > largestArea:
            largestArea = area

        if height[i] < height[j] or height[i] == height[j]:
            i += 1
        else:
            j -= 1

    return largestArea

# https://leetcode.com/problems/valid-parentheses/description/?source=submission-ac


def ValidParentheses():
    s = "()[]{}"

    customStack = []

    for bracket in s:
        if bracket in ["(", "[", "{"]:
            customStack.append(bracket)
            continue

        if len(customStack) == 0:
            return False

        top = ord(customStack[len(customStack) - 1])

        if not ord(bracket) - 1 == top and not ord(bracket) - 2 == top:
            return False
        else:
            customStack.pop()

    if len(customStack) == 0:
        return True
    else:
        return False

# https://leetcode.com/problems/find-the-difference/?envType=study-plan-v2&envId=programming-skills


def MergeStringsAlternately():
    word1 = "abc"
    word2 = "pqr"

    i = 0
    j = 0

    while i < len(word1) + len(word2) and j < len(word2):
        word1 = word1[:i + 1] + word2[j] + word1[i + 1:]
        i += 2
        j += 1

    word1 += word2[j:]

    return word1


# https://leetcode.com/problems/find-the-difference/description/?envType=study-plan-v2&envId=programming-skills
def FindTheDifference():
    s = "abc"
    t = "abce"

    return chr(sum([ord(letter) for letter in t]) - sum([ord(letter) for letter in s]))

# https://leetcode.com/problems/valid-anagram/description/?envType=study-plan-v2&envId=programming-skills


def ValidAnagram():
    s = "ab"
    t = "a"

    lettersDict = {}

    for letter in s:
        if letter in lettersDict:
            lettersDict[letter] += 1
            continue
        lettersDict[letter] = 1

    for letter in t:
        if not letter in lettersDict:
            return False
        if lettersDict[letter] > 1:
            lettersDict[letter] -= 1
            continue
        lettersDict.pop(letter)

    return True if len(lettersDict.keys()) == 0 else False

# https://leetcode.com/problems/repeated-substring-pattern/description/?envType=study-plan-v2&envId=programming-skills


def RepeatedSubstringPattern():
    s = "ababa"

    return s in (s + s)[1:-1]

# https://leetcode.com/problems/sign-of-the-product-of-an-array/description/?envType=study-plan-v2&envId=programming-skills


def SignOfTheProductOfAnArray():
    nums = [-1, -2, -3, -4, 3, 2, 1]
    numberOfNegatives = 0
    for item in nums:
        if item == 0:
            return 0
        elif item < 0:
            numberOfNegatives += 1

    return 1 if numberOfNegatives % 2 == 0 else 0

# https://leetcode.com/problems/monotonic-array/description/?envType=study-plan-v2&envId=programming-skills


def MonoticArray():
    nums = [1, 3, 2]
    previousNum = 0
    monotoneIncreasing = None

    for num in range(1, len(nums)):
        if nums[num] == nums[previousNum]:
            previousNum += 1
            continue

        if monotoneIncreasing is None:
            monotoneIncreasing = True if nums[num] > nums[previousNum] else False

        if nums[num] > nums[previousNum] and monotoneIncreasing is False or nums[num] < nums[previousNum] and monotoneIncreasing is True:
            return False

        previousNum += 1

    return True

# https://leetcode.com/problems/length-of-last-word/description/?envType=study-plan-v2&envId=programming-skills


def LengthOfLastWord():
    s = "   fly me   to   the moon  "
    lengthOfLastWord = 0
    startedWord = False

    for i in range(len(s) - 1, -1, -1):
        if s[i] == " " and startedWord == True:
            return lengthOfLastWord

        if s[i] != " ":
            startedWord = True
            lengthOfLastWord += 1

    return lengthOfLastWord

# https://leetcode.com/problems/to-lower-case/description/?envType=study-plan-v2&envId=programming-skills


def ToLowerCase():
    s = "Hello"
    return "".join([char.lower() for char in s])

# https://leetcode.com/problems/baseball-game/description/?envType=study-plan-v2&envId=programming-skills


def BaseballGame():
    ops = ["5", "-2", "4", "C", "D", "9", "+", "+"]
    record = []

    for i in range(len(ops)):
        if (ops[i][1:] if ops[i][0] == "-" else ops[i]).isnumeric():
            record.append(int(ops[i]))
        elif ops[i] == "+":
            record.append(record[len(record) - 1] + record[len(record) - 2])
        elif ops[i] == "D":
            record.append(record[len(record) - 1] * 2)
        else:
            record.pop()

    return sum(record)

# https://leetcode.com/problems/robot-return-to-origin/description/?envType=study-plan-v2&envId=programming-skills


def RobotReturnToOrigin():
    moves = "UD"

    return moves.count("L") == moves.count("R") and moves.count("D") == moves.count("U")


# https://leetcode.com/problems/robot-bounded-in-circle/description/?envType=study-plan-v2&envId=programming-skills
def RobotBoundedInCircle():
    instructions = "GL"
    position = [0, 0]
    direction = 0

    for i in range(4):
        for instruction in instructions:
            if instruction == "L":
                direction = 3 if direction == 0 else direction - 1
                continue
            if instruction == "R":
                direction = 0 if direction == 3 else direction + 1
                continue

            if instruction == "G":
                if direction == 0:
                    position[1] += 1
                elif direction == 1:
                    position[0] += 1
                elif direction == 2:
                    position[1] -= 1
                elif direction == 3:
                    position[0] -= 1

    return position == [0, 0]

# https://leetcode.com/problems/richest-customer-wealth/description/?envType=study-plan-v2&envId=programming-skills


def RichestCustomerWealth():
    accounts = [[1, 2, 3], [3, 2, 1]]
    maxWealth = -1

    for account in accounts:
        maxWealth = max(sum(account), maxWealth)

    return maxWealth

# https://leetcode.com/problems/matrix-diagonal-sum/description/?envType=study-plan-v2&envId=programming-skills


def MatrixDiagonalSum():
    mat = [[1, 1, 1, 1],
           [1, 1, 1, 1],
           [1, 1, 1, 1],
           [1, 1, 1, 1]]

    n = len(mat)
    sum = 0
    for i in range(n):
        sum += mat[i][i]
        sum += mat[i][n - i - 1]

    if n % 2 != 0:
        sum -= mat[n // 2][n // 2]

    return sum

    currentNode = firstNode
    while firstNode != None:
        currentNode = currentNode.next
        if currentNode == firstNode:
            return True

    return False


# https://leetcode.com/problems/move-zeroes/description/?envType=study-plan-v2&envId=programming-skills
def MoveZeroes(nums):
    zeroPointer = 0
    nonZeroPointer = 0

    while zeroPointer < len(nums) and nonZeroPointer < len(nums):
        if nums[zeroPointer] == 0 and nums[nonZeroPointer] > 0:
            if zeroPointer > nonZeroPointer:
                nonZeroPointer += 1
                continue
            nums[zeroPointer], nums[nonZeroPointer] = nums[nonZeroPointer], nums[zeroPointer]
        elif nums[zeroPointer] != 0:
            zeroPointer += 1
        elif nums[nonZeroPointer] == 0:
            nonZeroPointer += 1

# https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/description/?envType=study-plan-v2&envId=programming-skills


def CanMakeArithmeticProgressionFromSequence():
    arr = [3, 5, 1]

    newArr = sorted(arr)
    if len(arr) <= 2:
        return True
    difference = newArr[1] - newArr[0]
    for i in range(2, len(newArr)):
        if newArr[i] - newArr[i - 1] != difference:
            return False

    return True

# https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/description/?envType=study-plan-v2&envId=programming-skills


def FindWInnerOnATicTacToeGame():
    moves = [[2, 2], [0, 1], [2, 1], [0, 0], [0, 2]]

    if len(moves) < 5:
        return "Pending"

    plottedMoves = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]

    for i in range(len(moves)):
        plottedMoves[moves[i][0]][moves[i][1]] = "A" if i % 2 == 0 else "B"

    for i in range(3):
        previous = plottedMoves[i][0]
        if previous == 0:
            continue
        inRow = True
        for j in range(1, 3):
            if plottedMoves[i][j] != previous:
                inRow = False
                break
        if inRow == True:
            return previous

    for i in range(3):
        previous = plottedMoves[i][i]
        if previous == 0:
            continue
        inColumn = True
        for j in range(3):
            if plottedMoves[j][i] != previous:
                inColumn = False
                break
        if inColumn == True:
            return previous

    if plottedMoves[0][0] == plottedMoves[1][1] == plottedMoves[2][2] == "A" or plottedMoves[0][2] == plottedMoves[1][1] == plottedMoves[2][0] == "A":
        return "A"
    elif plottedMoves[0][0] == plottedMoves[1][1] == plottedMoves[2][2] == "B" or plottedMoves[0][2] == plottedMoves[1][1] == plottedMoves[2][0] == "B":
        return "B"
    elif len(moves) != 9:
        return "Pending"
    else:
        return "Draw"

# https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/?envType=study-plan-v2&envId=programming-skills


def CountOddNumbersInAnIntervalRange():
    low = 3
    high = 7
    return len(range(low if low % 2 != 0 else low + 1,
                     high + 1 if high % 2 != 0 else high, 2))


# https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/?envType=study-plan-v2&envId=programming-skills
def AverageSalaryExcludingTheMinimumAndMaximumSalary():
    salary = [4000, 3000, 1000, 2000]

    return (sum(salary) - max(salary) - min(salary)) / (len(salary) - 2)

# https://leetcode.com/problems/spiral-matrix/description/?envType=study-plan-v2&envId=programming-skills


def SpiralMatrix():
    matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    newList = []

    n = 0

    startX = 0
    startY = 0
    endX = len(matrix[0]) - 1
    endY = len(matrix) - 1
    i = 0
    j = 0

    direction = 1  # 1 -> Right, 2 -> Down, 3 -> Left, 4 -> Up

    matrixLength = len(matrix) * len(matrix[0])

    while n < matrixLength:
        newList.append(matrix[i][j])

        if direction == 1 and j == endX:
            direction = 2
            endX -= 1
        elif direction == 2 and i == endY:
            direction = 3
            startY += 1
        elif direction == 3 and j == startX:
            direction = 4
            startX += 1
        elif direction == 4 and i == startY:
            direction = 1
            endY -= 1

        if direction == 1:
            j += 1
        elif direction == 2:
            i += 1
        elif direction == 3:
            j -= 1
        elif direction == 4:
            i -= 1

        n += 1

    return newList


# Definition for singly-linked list.


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# https://leetcode.com/problems/merge-two-sorted-lists/description/?envType=study-plan-v2&envId=programming-skills


def MergeTwoSortedLists(list1: ListNode, list2: ListNode) -> ListNode:
    if not hasattr(list1, "next"):
        return list2
    elif not hasattr(list2, "next"):
        return list1

    currentList1 = list1
    currentList2 = list2
    currentNode = ListNode()
    head = ListNode()

    while currentList1 and currentList2:
        smallerNode = currentList1 if currentList1.val <= currentList2.val else currentList2
        newNode = ListNode(val=smallerNode.val)
        if head.next is None:
            head.next = newNode
            currentNode = newNode
        else:
            currentNode.next = newNode
            currentNode = currentNode.next
        if smallerNode == currentList1:
            currentList1 = currentList1.next
        else:
            currentList2 = currentList2.next

    if currentList1:
        currentNode.next = currentList1

    if currentList2:
        currentNode.next = currentList2

    return head.next


listOne = ListNode(1)
listOneNodeOne = ListNode(2)
listOneNodeTwo = ListNode(4)

listOneNodeOne.next = listOneNodeTwo
listOne.next = listOneNodeOne

listTwo = ListNode(1)
listTwoNodeOne = ListNode(3)
listTwoNodeTwo = ListNode(4)

listTwoNodeOne.next = listTwoNodeTwo
listTwo.next = listTwoNodeOne

merged = MergeTwoSortedLists(listOne, listTwo)


# https://leetcode.com/problems/set-matrix-zeroes/description/?envType=study-plan-v2&envId=programming-skills

def setZeroes(start, stop, matrix, i, horizontally):
    if horizontally:
        for j in range(start, stop):
            if matrix[i][j] == 0:
                continue
            matrix[i][j] = ""
    else:
        for j in range(start, stop):
            if matrix[j][i] == 0:
                continue
            matrix[j][i] = ""


def SetMatrixZeroes():
    matrix = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if matrix[i][j] == 0:
                setZeroes(start=0,
                          stop=len(matrix[0]),
                          matrix=matrix,
                          i=i,
                          horizontally=True)

                setZeroes(start=0,
                          stop=len(matrix),
                          matrix=matrix,
                          i=j,
                          horizontally=False)

    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if matrix[i][j] == "":
                matrix[i][j] = 0

    return matrix

# https://leetcode.com/problems/lemonade-change/?envType=study-plan-v2&envId=programming-skills


def LemonadeChange():
    bills = [5, 5, 10, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 20, 5, 20, 5]

    fiveDollars = 0
    tenDollars = 0
    twentyDollars = 0

    for bill in bills:
        if bill == 5:
            fiveDollars += 1
        elif bill == 10:
            if fiveDollars == 0:
                return False
            else:
                fiveDollars -= 1
                tenDollars += 1
        elif bill == 20:
            if fiveDollars > 0 and tenDollars > 0:
                fiveDollars -= 1
                tenDollars -= 1
            elif fiveDollars >= 3:
                fiveDollars -= 3
            elif twentyDollars > 0:
                continue
            else:
                return False

    return True

# https://leetcode.com/problems/largest-perimeter-triangle/?envType=study-plan-v2&envId=programming-skills


def LargestPerimeterTriangle():
    nums = [3, 4, 15, 2, 9, 4]
    nums.sort()
    for i in range(len(nums) - 1, 1, -1):
        if nums[i - 1] + nums[i - 2] > nums[i]:
            return nums[i - 1] + nums[i - 2] + nums[i]
    return 0


# https://leetcode.com/problems/check-if-it-is-a-straight-line/?envType=study-plan-v2&envId=programming-skills
def CheckIfItIsAStraightLine():
    coordinates = [[0, 0], [0, 5], [5, 5], [5, 0]]
    for i in range(0, len(coordinates) - 2):
        if (coordinates[i + 1][1] - coordinates[i][1]) * (coordinates[i + 2][0] - coordinates[i + 1][0]) != (coordinates[i + 2][1] - coordinates[i + 1][1]) * (coordinates[i + 1][0] - coordinates[i][0]):
            return False
    return True


# https://leetcode.com/problems/add-binary/description/?envType=study-plan-v2&envId=programming-skills
def AddBinary():
    a = "11"
    b = "1"

    power = 0
    aSum = 0
    bSum = 0
    i = len(a) - 1
    j = len(b) - 1
    while i > -1 or j > -1:
        if i > -1:
            aSum += pow(2, power) if a[i] == "1" else 0
        if j > -1:
            bSum += pow(2, power) if b[j] == "1" else 0
        power += 1
        i -= 1
        j -= 1

    c = ""
    dividedNumber = aSum + bSum
    if dividedNumber == 0:
        return "0"
    while dividedNumber >= 1:
        binary = f"{dividedNumber % 2}"
        c = binary + c
        dividedNumber //= 2

    return c


def isPalindrome(string):
    i = 0
    j = len(string) - 1
    while i <= j:
        if string[i] != string[j]:
            return False
        i += 1
        j -= 1
    return True

# https://dmoj.ca/problem/ccc16j3


def HiddenPalindrome():
    # str(sys.stdin.readline())
    string = str(sys.stdin.readline())
    spliceMax = len(string)

    while spliceMax > 1:
        i = 0
        while i + spliceMax <= len(string):
            if isPalindrome(string[i:i + spliceMax]):
                return len(string[i:i + spliceMax])
            i += 1
        spliceMax -= 1
    return 1


# https://dmoj.ca/problem/ccc04j4
def simple_encryption():
    keyword = str(sys.stdin.readline())
    message = str(sys.stdin.readline())

    j = 0
    for i in range(len(message)):
        if ord(message[i]) >= 65 and ord(message[i]) <= 90:
            index = j % (len(keyword) - 1)
            new_letter = ord(message[i]) + ord(keyword[index]) - 65
            if new_letter > 90:
                new_letter = (new_letter % 90) + 64
            new_letter = chr(new_letter)
            print(new_letter, end="")
            j += 1


# https://dmoj.ca/problem/ccc12j4
def big_bang_secrets():
    k = int(sys.stdin.readline())
    message = str(sys.stdin.readline())

    for i in range(len(message) - 1):
        new_letter = ord(message[i]) - (3 * (i + 1) + k)
        if new_letter < 65:
            new_letter = 91 - (65 - new_letter)
        print(chr(new_letter), end="")


# https://dmoj.ca/problem/ccc20j4

def check_shifts(shifts, text):
    for shift in shifts:
        if shift in text:
            return True
    return False


def cyclic_shifts():
    text = sys.stdin.readline().strip()
    string = sys.stdin.readline().strip()
    string_cyclic_shifts = []
    for i in range(len(string)):
        string_cyclic_shifts.append(string)
        string = string[1:] + string[0]

    for j in range((len(text) - len(string)) + 1):
        if check_shifts(shifts=string_cyclic_shifts, text=text[j:j + len(string)]):
            print("yes")
            return None
    print("no")


# https://dmoj.ca/problem/ccc07j4
def anagram_checker():
    phrase_one = str(sys.stdin.readline()).strip()
    phrase_two = str(sys.stdin.readline()).strip()

    phrases_dict = {}

    for letter in phrase_one:
        if letter != " ":
            if letter in phrases_dict:
                phrases_dict[letter] += 1
            else:
                phrases_dict[letter] = 1

    for letter in phrase_two:
        if letter != " ":
            if not letter in phrases_dict:
                print("Is not an anagram.")
                return
            elif phrases_dict[letter] > 1:
                phrases_dict[letter] -= 1
            else:
                phrases_dict.pop(letter)

    if len(phrases_dict.keys()) > 0:
        print("Is not an anagram.")
    else:
        print("Is an anagram.")


# https://dmoj.ca/problem/ccc11j4
def boring_business():
    instructions = [["d", 2], ["r", 3], ["d", 2], ["r", 2],
                    ["u", 2], ["r", 2], ["d", 4], ["l", 8], ["u", 2]]

    user_input = ""

    while user_input != "q 0":
        user_input = str(sys.stdin.readline()).strip()
        instructions.append([f"{user_input[0]}", int(user_input[2:])])

    instructions.pop()

    current_x = 0
    current_y = -1

    previous_positions = {"0-1": ""}

    for i, instruction in enumerate(instructions):
        direction = instruction[0]
        is_danger = False

        for j in range(instruction[1]):
            if direction == "l":
                current_x -= 1
            elif direction == "r":
                current_x += 1
            elif direction == "u":
                current_y += 1
            else:
                current_y -= 1
            if f"{current_x}{current_y}" in previous_positions:
                is_danger = True
            else:
                previous_positions[f"{current_x}{current_y}"] = ""

        if is_danger:
            print(f"{current_x} {current_y} DANGER")
            return

        if i > 8:
            print(f"{current_x} {current_y} safe")

# https://dmoj.ca/problem/ccc13j4


def time_on_task():
    total_number_of_minutes = int(sys.stdin.readline().strip())
    total_number_of_chores = int(sys.stdin.readline().strip())

    chore_times = []
    for i in range(total_number_of_chores):
        amount_of_time_to_complete_chore = int(sys.stdin.readline().strip())
        chore_times.append(amount_of_time_to_complete_chore)

    chore_times.sort()
    number_of_chores_that_you_can_complete = 0
    sum_of_times = 0
    for time in chore_times:
        sum_of_times += time
        if sum_of_times <= total_number_of_minutes:
            number_of_chores_that_you_can_complete += 1
        else:
            print(number_of_chores_that_you_can_complete)
            return


# https://dmoj.ca/problem/ccc17j4
def favourite_times():
    duration = int(sys.stdin.readline())

    time = 1200
    number_of_arithmetic_sequences = 0

    if duration >= 720:
        number_of_arithmetic_sequences += 31 * (duration // 720)
        duration -= 720 * (duration // 720)

    for i in range(duration + 1):
        str_time = list(str(time))

        difference = int(str_time[1]) - int(str_time[0])
        is_sequence = True

        for j in range(2, len(str_time)):
            if int(str_time[j]) - int(str_time[j - 1]) != difference:
                is_sequence = False
                break

        if is_sequence:
            number_of_arithmetic_sequences += 1

        time += 1
        if time % 100 == 60:
            time += 100
            time -= 60

        if time == 1300:
            time = 100

    print(number_of_arithmetic_sequences)


# https://dmoj.ca/problem/ccc10j4
def global_warming():
    cycles = []
    user_input = "1"

    while user_input[0] != "0":
        user_input = sys.stdin.readline().strip().split(" ")
        if int(user_input[0]) > 1:
            cycles.append([int(user_input[i]) - int(user_input[i - 1])
                          for i in range(2, len(user_input))])
        elif user_input[0] != "0":
            cycles.append([False])

    for i, cycle in enumerate(cycles):
        if cycle[0] == False:
            print("0")
            continue
        for k in range(len(cycle)):
            subset = cycle[:k + 1]
            if len(subset) == len(cycle):
                print(len(subset))
                break
            is_subset = True
            if len(subset) > len(cycle) // 2:
                second_subset = cycle[k + 1:]
                for j in range(len(second_subset)):
                    if subset[j] != second_subset[j]:
                        is_subset = False
                        break
            else:
                j = k + 1
                while j < len(cycle):
                    second_subset = cycle[j:] if len(cycle[j:]) < len(
                        subset) else cycle[j:j + len(subset)]
                    for k in range(len(second_subset)):
                        if subset[k] != second_subset[k]:
                            is_subset = False
                            break
                    if is_subset == False:
                        break
                    j += len(subset)

            if is_subset:
                print(len(subset))
                break


def boring_business():
    user_input = ""
    instructions = [("d", 2), ("r", 3), ("d", 2), ("r", 2),
                    ("u", 2), ("r", 2), ("d", 4), ("l", 8), ("u", 2)]
    while True:
        user_input = str(sys.stdin.readline().strip())
        if user_input == "q 0":
            break
        instructions.append((user_input[0], int(user_input[2:])))

    current_x = 0
    current_y = -1

    previous_positions = {}

    for i, instruction in enumerate(instructions):
        direction = instruction[0]
        is_danger = False
        for j in range(instruction[1]):
            if direction == "d":
                current_y -= 1
            elif direction == "r":
                current_x += 1
            elif direction == "l":
                current_x -= 1
            else:
                current_y += 1

            if f"{current_x} {current_y}" in previous_positions:
                is_danger = True
            else:
                previous_positions[f"{current_x} {current_y}"] = 1

        if i > 8:
            if not is_danger:
                print(f"{current_x} {current_y} safe")
            else:
                print(f"{current_x} {current_y} DANGER")
                return


boring_business()

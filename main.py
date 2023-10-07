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


def Waiting():
    timeGriffyArrives = [00] * 3
    timeSchoolStarts = [00] * 3

    tempArrivalTime = input()
    tempStartTime = input()

    timeGriffyArrives[0] = int(tempArrivalTime[:2])
    timeGriffyArrives[1] = int(tempArrivalTime[3:-3])
    timeGriffyArrives[2] = int(tempArrivalTime[6:])

    timeSchoolStarts[0] = int(tempStartTime[:2])
    timeSchoolStarts[1] = int(tempStartTime[3:-3])
    timeSchoolStarts[2] = int(tempStartTime[6:])

    numberOfHoursMinutesAndSeconds = [timeSchoolStarts[0] - timeGriffyArrives[0],
                                      timeSchoolStarts[1] - timeGriffyArrives[1], timeSchoolStarts[2] - timeGriffyArrives[2]]
    numberOfSeconds = (numberOfHoursMinutesAndSeconds[0] * 360) + (
        numberOfHoursMinutesAndSeconds[1] * 60) + numberOfHoursMinutesAndSeconds[2]

    print(numberOfHoursMinutesAndSeconds)
    print(numberOfSeconds)


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


PlusOne()

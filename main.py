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


Festival()

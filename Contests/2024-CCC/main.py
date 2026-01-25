import sys
import queue

number_of_rows = int(sys.stdin.readline().strip())
number_of_columns = int(sys.stdin.readline().strip())

farm = []

for i in range(number_of_rows):
    farm.append([x for x in str(sys.stdin.readline().strip())])

start_row = int(sys.stdin.readline().strip()) - 1
start_column = int(sys.stdin.readline().strip()) - 1

current_row = start_row
current_column = start_column

total_money = 0

next_position = queue.Queue()


def add_money(start, end, step, vertical):
    money = 0
    if vertical:
        for i in range(start, end, step):
            if farm[i][current_column] != "-" and farm[i][current_column] != "*":
                if farm[i][current_column] == "S":
                    money += 1
                elif farm[i][current_column] == "M":
                    money += 5
                else:
                    money += 10
                farm[i][current_column] = "-"
                if i != current_row:
                    next_position.put([i, current_column])
            else:
                break
    else:
        for i in range(start, end, step):
            if farm[current_row][i] != "-" and farm[current_row][i] != "*":
                if farm[current_row][i] == "S":
                    money += 1
                elif farm[current_row][i] == "M":
                    money += 5
                else:
                    money += 10
                farm[current_row][i] = "-"
                if i != current_column:
                    next_position.put([current_row, i])
            else:
                break
    return money


while True:
    # Go up
    if farm[current_row][current_column] == "-":
        total_money += add_money(current_row - 1, -1, -1, True)
    else:
        total_money += add_money(current_row, -1, -1, True)
    # Go right
    total_money += add_money(current_column + 1, number_of_columns, 1, False)
    # Go down
    total_money += add_money(current_row + 1, number_of_rows, 1, True)
    # rows_completed[current_row] = 1
    # Go left
    total_money += add_money(current_column - 1, -1, -1, False)
    # columns_completed[current_column] = 1

    if next_position.empty():
        break
    else:
        new_position = next_position.get()
        current_row = new_position[0]
        current_column = new_position[1]

print(total_money)

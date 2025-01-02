def apple_redistribution_into_boxes():
    apple = [5, 5, 5]
    capacity = [2, 4, 2, 7]

    number_of_apples = sum(apple)

    number_of_boxes = 0
    current_capacity = 0

    while current_capacity < number_of_apples:
        biggest_box = max(capacity)
        capacity.remove(biggest_box)
        number_of_boxes += 1
        current_capacity += biggest_box

    return number_of_boxes


def maximize_happiness_of_selected_children():
    happiness = [1, 2, 3]
    k = 2
    total_happiness = 0
    happiness.sort()

    j = len(happiness) - 1
    for i in range(k):
        if happiness[j] - i > 0:
            total_happiness += happiness[j] - i
        else:
            break
        j -= 1

    return total_happiness


def get_all_substrings(string):
    i = 1
    substrings = []
    while i <= len(string):
        for j in range(0, len(string) - i + 1):
            substrings.append(string[j:j + i])
            # if i > 1:
            #     substrings.append(string[j:j + i][::-1])
        i += 1
    return substrings


def check_substring(target_string, substring):
    return substring in target_string


def shortest_uncommon_substring_in_an_array():
    arr = ["fhi", "ct", "s", "o", "o"]
    answer = []

    for j, item in enumerate(arr):
        substrings = get_all_substrings(item)
        answers = []
        for substring in substrings:
            is_substring = True
            for k, itemTwo in enumerate(arr):
                if j != k:
                    if substring in itemTwo:
                        is_substring = False
                        break
            if is_substring:
                answers.append(substring)

        if len(answers) == 0:
            answer.append("")
        elif len(answers) == 1:
            answer.append(answers[0])
        else:
            smallest = ""
            for ans in answers:
                if smallest == "":
                    smallest = ans
                    continue
                i = 0
                while i < len(smallest if len(smallest) < len(ans) else ans):
                    if ord(ans[i]) < ord(smallest[i]) and len(ans) <= len(smallest):
                        smallest = ans
                        break
                    elif ord(ans[i]) > ord(smallest[i]):
                        break
                    i += 1

            answer.append(smallest)

    return answer


print(shortest_uncommon_substring_in_an_array())

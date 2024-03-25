def existence_of_a_substring_in_a_string_and_its_reverse():
    s = "ausoee"
    reversed_string = s[::-1]

    i = 2
    while i <= len(s):
        j = 0
        while j + i <= len(s):
            substring = s[j:j + i]
            if substring in reversed_string:
                return True
            j += 1
        i += 1

    return False


def count_substring_starting_and_ending_with_given_character():
    s = "zzz"
    c = "z"

    number_of_substrings = 0
    for letter in s:
        if letter == c:
            number_of_substrings += 1
    i = number_of_substrings - 1
    while i > 0:
        number_of_substrings += i
        i -= 1

    return number_of_substrings

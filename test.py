def DigitSum(n):
    if n < 10:
        return n
    return DigitSum(int(n / 10)) + (n % 10)


print(DigitSum(2))

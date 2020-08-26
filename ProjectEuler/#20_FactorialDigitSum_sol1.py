def factorial(n):
    p = 1
    for i in range(2, n + 1):
        p *= i
    return p

N = 100
N_FACTORIAL = factorial(N)

digits = [int(digit) for digit in str(N_FACTORIAL)]
digits_sum = sum(digits)

# 648
print(digits_sum)
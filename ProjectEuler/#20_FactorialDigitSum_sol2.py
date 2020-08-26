import math

N = 100
N_FACTORIAL = math.factorial(N)

digits = [int(digit) for digit in str(N_FACTORIAL)]
digits_sum = sum(digits)

# 648
print(digits_sum)
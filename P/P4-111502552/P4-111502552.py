"""
Practice 4
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1003-B
"""

import math


def find_factor(num: int) -> list[int]:
    factors: list[int] = []
    for i in range(1, math.floor(math.sqrt(num)) + 1):
        if num % i == 0:
            # find two factors at once
            f0 = i
            f1 = int(num / i)
            
            factors.append(f0)
            if f0 != f1:
                factors.append(f1)

    factors.sort()
    return factors


# redefined: whether num is a prime
def find_prime(num: int) -> str:
    if num == 1:
        return 'F'
    if num == 2 or num == 3:
        return 'T'
    
    # even numbers are not primes
    if num % 2 == 0:
        return 'F'
    
    # sieve of Eratosthenes
    for i in range(3, math.floor(math.sqrt(num)) + 1, 2):
        if num % i == 0:
            return 'F'

    return 'T'


with open('./Input.txt', 'r', encoding='utf-8') as file:
    data = file.read().split()
    data: list[int] = list(map(int, data))

output: list[str] = [] # text to be outputted into Output.txt

# push text into output
for (ord, num) in enumerate(data):
    output.append(f'Number_{ord + 1}: {num}')

    for factor in find_factor(num):
        output.append(f'{factor} {find_prime(factor)}')

# output to file
with open('./Output.txt', 'w+', encoding='utf-8') as file:
    file.write('\n'.join(output))
    file.write('\n')

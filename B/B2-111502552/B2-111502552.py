"""
Bonus 2
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1003-B
"""


import math


HEXI_CHART = {
    10: 'a',
    11: 'b',
    12: 'c',
    13: 'd',
    14: 'e',
    15: 'f'
}

def is_binary(s: str) -> bool:
    if not s.isnumeric():
        return False

    for c in s:
        if int(c) >= 2:
            return False

    return True

def bin_to_deci(num: str) -> int:
    num = num[::-1]

    value = 0
    for i, c in enumerate(num):
        value += int(c) * pow(2, i)
    return value

def add_one(s: str) -> str:
    s = s[::-1]

    result = ''
    carry = 1
    for c in s:
        value = int(c) + carry
        carry = value // 2
        result += str(value % 2)
    return result[::-1]

def not_gate(s: str) -> str:
    result = ''
    for c in s:
        result += str((int(c) + 1) % 2)
    return result

def to_hex(s: str) -> str:
    segment_count = math.ceil(len(s) / 4)
    add_zero_count = 4 * segment_count - len(s)

    s = '0' * add_zero_count + s

    hex = ''
    for i in range(segment_count):
        deci = bin_to_deci(s[i*4 : (i+1)*4])

        if deci <= 9:
            hex += str(deci)
        else:
            hex += HEXI_CHART[deci]
    
    return ('0' if (hex.isdecimal() and int(hex) == 0) else hex.lstrip('0'))

def Output(decimal, decimal_reverse, heximal):
    print("Decimal: ", decimal)
    print("Decimal reverse: ", decimal_reverse)
    print("Heximal: ", heximal)

while True:
    num = input('Please input the binary : ')

    if num == '-1':
        break

    if not is_binary(num):
        print('Input number is not binary')
        continue

    if num[0] == '1':
        num = add_one(not_gate(num))
    
    deci = bin_to_deci(num)

    flip_deci = str(deci)[::-1]
    flip_deci = '0' if flip_deci == '0' else flip_deci.lstrip('0')

    hex = to_hex(num)

    Output(deci, flip_deci, hex)

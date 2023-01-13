"""
Practice 6
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1003-B
"""


def to_deci(base: int, num: str):
    if not num.isnumeric():
        return False
    
    num = num[::-1]

    value = 0
    for i, c in enumerate(num):
        if (int(c) >= base):
            return False

        value += int(c) * pow(base, i)
    return value


num = str(input('NUM(BIN) : '))

# base 2 to 10
deci = to_deci(2, num)

if not deci:
    print('Not Binary Number!')
else:
    print(f'NUM(DEC) : {deci}')

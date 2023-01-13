"""
Exam 1
Name: 蕭登鴻
Student Number: 111502552
Course: 2022-CE1003-B
"""

def open_file(file_name: str):
    with open(f'./test_data/{file_name}', 'r', encoding='utf-8') as file:
        return file.read()


def check_number(num: str):
    if len(num) != 4:
        return False
    
    if not num.isdigit():
        return False

    for i, c in enumerate(num):
        if c in num[i+1:]:
            return False

    if '0' in num:
        return False

    return True

def cmp_numbers(ans_num: str, guess_num: str):
    A = 0
    B = 0
    for i, char in enumerate(guess_num):
        if char in ans_num and ans_num[i] == char:
            A += 1
        elif char in ans_num:
            B += 1
    return (A, B)


ans_num = open_file('E4_input.txt')

if not check_number(ans_num):
    print('invalid ans_num!')
else:
    while True:
        guess_num = input()

        if not check_number(guess_num):
            print('wrong format!')
            continue

        A, B = cmp_numbers(ans_num, guess_num)

        if A == 4 and B == 0:
            print('correct')
            break

        print(f'{A}A{B}B')

"""
Exam 1
Name: 蕭登鴻
Student Number: 111502552
Course: 2022-CE1003-B
"""


def open_file(file_name):
    with open(f'./test_data/{file_name}', 'r', encoding='utf-8') as file:
        return list(map(int, file.read().split()))

data = open_file('E1_input3.txt')

result = []

total = 0
for datum in data:
    total += datum
    result.append(total)

print(result)

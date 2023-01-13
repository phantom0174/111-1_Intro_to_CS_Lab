"""
Exam 1
Name: 蕭登鴻
Student Number: 111502552
Course: 2022-CE1003-B
"""

def open_file(file_name: str):
    with open(f'./test_data/{file_name}', 'r', encoding='utf-8') as file:
        return file.read().split('\n')


def search_index(target_list, target_char):
    if target_char in target_list:
        return target_list.index(target_char)
    
    for i, c in enumerate(target_list):
        if target_char.isdigit():
            if int(target_char) <= int(c):
                return i
        else:
            if target_char <= c:
                return i
    
    return len(target_list)


data = open_file('E2_input.txt')

char = input()

if char.isdigit():
    index = 1
else:
    index = 0

result = search_index(data[index].split(), char)

print(f'Search list: {index + 1}')
print(f'Index: {result}')


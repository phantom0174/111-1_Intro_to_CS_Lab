"""
Exam 1
Name: 蕭登鴻
Student Number: 111502552
Course: 2022-CE1003-B
"""

def open_file(file_name: str):
    with open(f'./test_data/{file_name}', 'r', encoding='utf-8') as file:
        return file.read().split('\n')


def bool_finish(data_list: list):
    start = int(data_list[0]) * 60 + int(data_list[1])
    end = int(data_list[2]) * 60 + int(data_list[3])

    if int(data_list[4]) <= end - start:
        return True
    
    return False


data = open_file('E3_input5.txt')

del data[0]

for datum in data:
    result = bool_finish(datum.split())

    if result:
        print('Yes')
    else:
        print('No')

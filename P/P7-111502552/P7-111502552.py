"""
Practice 7
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1003-B
"""

with open('./input.txt', 'r', encoding='utf-8') as file:
    maze = [line.split() for line in file.read().split('\n')]
    if maze[-1] == []:
        del maze[-1]

def find_path(x, y):
    if x == 5 and y == 5:
        return True
    
    right = False
    down = False
    if maze[y][x+1] == '1':
        right = find_path(x+1, y)
    if maze[y+1][x] == '1':
        down = find_path(x, y+1)
    return (right or down)

result = find_path(1, 1)
print(int(result))

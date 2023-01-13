"""
Practice 8
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1003-B
"""

with open('./input.txt', 'r', encoding='utf-8') as file:
    nums = list(map(int, file.read().split()))

def bubble_sort(l: list[int]) -> None:
    for times in range(1, len(l)):
        sorted = True
        for i in range(len(l) - 1):
            if l[i+1] < l[i]:
                sorted = False
                t = l[i]
                l[i] = l[i+1]
                l[i+1] = t

        if sorted:
            break


bubble_sort(nums)
print(nums)

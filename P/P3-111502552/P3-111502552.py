"""
Practice 3
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1003-B
"""


def CreatePyramid():
    layer: int = 0

    # read total layer from file
    with open('./input.txt', 'r', encoding='utf-8') as file:
        layer = int(file.read())

    
    pyramid = [] # string list of each layer
    
    for l in range(1, layer + 1):
        white_count = layer - l
        num_count = 2 * l - 1

        layer_text = ' ' * white_count + '*' * num_count # a temp string to be pushed into var: pyramid
        pyramid.append(layer_text)

    with open('./output.txt', 'w+', encoding='utf-8') as file:
        file.write('\n'.join(pyramid))


CreatePyramid()

"""
Practice 2
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1003-B
"""

ERROR_TEMPLATE = 'try again or type "exit" to leave.'


while True:
    pw = input('Please enter your password: ')
    if pw == 'exit':
        break
    
    if len(pw) < 6 or len(pw) > 10:
        print(f'Password should contain 6 to 10 characters, {ERROR_TEMPLATE}')
        continue

    has_upper = False
    has_num = False
    for char in pw:
        if char.isupper():
            has_upper = True
        elif char.isdecimal():
            has_num = True

    if not has_upper:
        print(f'Password should contain at least one upper-case alphabetical character, {ERROR_TEMPLATE}')
    elif not has_num:
        print(f'Password should contain at least one number, {ERROR_TEMPLATE}')
    else:
        print('Password is valid.')
        break

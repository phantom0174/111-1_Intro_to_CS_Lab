"""
Practice 1
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1003-B
"""

# chinese, english, math, science
SCORE_NAMES = ['Chinese', 'English', 'Math', 'Science']
SCORE_STANDARDS = [12, 12, 8, 12]

scores = []

for i in range(4):
    score = float(input(f'Please enter your {SCORE_NAMES[i]} score: '))
    scores.append(score)

fail_any_standards = False
for i in range(4):
    if scores[i] < SCORE_STANDARDS[i]:
        fail_any_standards = True
        break

if fail_any_standards:
    print("Sorry, you can't enter NCU CSIE.")
else:
    print('Welcome to NCU CSIE!')

"""
Bonus 1
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1003-B
"""


# 特別獎 特獎 頭獎 二獎 三獎 四獎 五獎 六獎 沒中獎
REWARD_COUNT = [0] * 9

with open('./invoice.txt', 'r', encoding='utf-8') as file:
    invoices = file.read().split('\n')

with open('./num.txt', 'r', encoding='utf-8') as file:
    num = file.read().split('\n')


def scan_invoice(invoice: str):
    if invoice == num[0]:
        REWARD_COUNT[0] += 1
    elif invoice == num[1]:
        REWARD_COUNT[1] += 1
    
    # 頭獎
    elif invoice in num[2:5]:
        REWARD_COUNT[2] += 1

    # 2
    elif invoice[1:] in list(map(lambda a: a[1:], num[2:5])):
        REWARD_COUNT[3] += 1

    # 3
    elif invoice[2:] in list(map(lambda a: a[2:], num[2:5])):
        REWARD_COUNT[4] += 1
    
    # 4
    elif invoice[3:] in list(map(lambda a: a[3:], num[2:5])):
        REWARD_COUNT[5] += 1

    # 5
    elif invoice[4:] in list(map(lambda a: a[4:], num[2:5])):
        REWARD_COUNT[6] += 1

    # 6
    elif invoice[5:] in list(map(lambda a: a[5:], num[2:5])):
        REWARD_COUNT[7] += 1

    # 6 extra
    elif invoice[-3:] in num[5:]:
        REWARD_COUNT[7] += 1

    else:
        REWARD_COUNT[8] += 1

def Output(count, total):
    print('特別獎：', count[0])
    print('特獎：', count[1])
    print('頭獎：', count[2])
    print('二獎：', count[3])
    print('三獎：', count[4])
    print('四獎：', count[5])
    print('五獎：', count[6])
    print('六獎：', count[7])
    print('沒中獎：', count[8])
    print(total)

for invoice in invoices:
    scan_invoice(invoice)

total = REWARD_COUNT[0] * 10000000 \
        + REWARD_COUNT[1] * 2000000 \
        + REWARD_COUNT[2] * 200000 \
        + REWARD_COUNT[3] * 40000 \
        + REWARD_COUNT[4] * 10000 \
        + REWARD_COUNT[5] * 4000 \
        + REWARD_COUNT[6] * 1000 \
        + REWARD_COUNT[7] * 200

Output(REWARD_COUNT, total)

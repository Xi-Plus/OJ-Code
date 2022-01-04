# coding: utf-8

BET = 400


def clac_sum(card):
    ans = 0
    count_A = 0
    for num in card:
        ans += num
        if num == 1:
            count_A += 1
            ans += 10
    while ans > 21 and count_A > 0:
        ans -= 10
        count_A -= 1
    return ans


line_1 = input()  # line 1
round = int(input())  # line 2
win_streak = int(input())  # line 3

my_card = list(map(int, line_1.split(' ')))

if my_card[0] == 0:
    print(BET)
else:
    max_bet = int(input())  # line 4
    line_5 = input()  # line 5
    other_card = list(map(int, line_5.split(' ')))

    my_sum = clac_sum(my_card)
    other_sum = clac_sum(other_card)
    if other_sum > 21:
        print('STAND')
    elif my_sum <= 17 or my_sum < other_sum:
        print('HIT')
    else:
        print('STAND')

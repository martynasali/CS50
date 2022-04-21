from cs50 import get_int
import re


def ask():
    card = get_int("Number: ")
    length = int(len(str(card)))
    # Check visa
    if length == 13:
        two = int(str(card)[:2])
        if two >= 40 and two < 50:
            if check(length, card):
                print("VISA")
        else:
            print("INVALID")

    # Check American Express
    elif length == 15:
        two = int(str(card)[:2])
        if two == 34 or two == 37:
            if check(length, card):
                print("AMEX")
        else:
            print("INVALID")

    # Check MasterCard, Visa uses 16
    elif length == 16:
        two = int(str(card)[:2])
        if two >= 51 and two <= 55:
            if check(length, card):
                print("MASTERCARD")
            else:
                print("INVALID")
            # mastercard : 51, 52, 53, 54, or 55 visa 4
        elif two >= 40 and two < 50:
            if check(length, card):
                print("VISA")
        else:
            print("INVALID")

    else:
         print("INVALID")

# Check if numbers are valid


def check(length, card):
    card1 = card
    card2 = card
    sum1 = 0
    sum2 = 0
    for i in range(length):
        num = card1 % 10
        card1 = int((card1 - num)/10)
        if (i+1) % 2 == 0:
            # print(num, i)
            var = (num * 2) % 10
            sum1 += (((num * 2)-var)/10)+var
            # print("sum1:", sum1)
        elif(i+1) % 2 != 0:
            sum2 += num
            # print("sum2:", sum2)


    if int(sum2+sum1) % 10 == 0:
        return True
    else:
        return False


ask()

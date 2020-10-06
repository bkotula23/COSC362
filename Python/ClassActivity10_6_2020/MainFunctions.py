import sys
import os
import math
from string import whitespace

"""
      This is the document string for this file.
      This will serve as the library of functions that are needed by the letter writing main script.
"""

dinosours = [6, 10, 8, 9, 10, 11]

def sum(dinosours):
    total = 0
    for x in dinosours:
        total += x
    return total
print(sum(dinosours))

def numberFun():
    num1 = input('Enter first numnber: ')
    num2 = input('Enter second number: ')
    gummyworm = input('Enter A or S: ')
    if gummyworm == 'S':
        sub = int(num1) - int(num2)
        return(sub)
        print('This subtracted')
    else:
        sum = int(num1) + int(num2)
        return(sum)

print (numberFun())

class AddSub:
    def newAdd (x, y, flag = 'add'):
        if flag == 'add':
            return x + y
        else:
            return x - y
            print('this subtracted')

    print(newAdd(10,14, 'sub')



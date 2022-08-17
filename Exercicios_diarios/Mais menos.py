import sys
import re
import random
import os
import math


def plusMinus(arr):
    cont_positivo = 0
    cont_negativo = 0
    cont_neutro = 0

    for num in arr:
        if (num > 0):
            cont_positivo += 1
        elif (num < 0):
            cont_negativo += 1
        else:
            cont_neutro += 1

    print(cont_positivo/len(arr))
    print(cont_negativo/len(arr))
    print(cont_neutro/len(arr))


if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)

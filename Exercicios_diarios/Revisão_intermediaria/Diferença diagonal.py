import math
import os
import random
import re
import sys


def diagonalDifference(arr):
    primaria = 0
    secundario = 0
    cont = 1
    for i in range(len(arr)):
        primaria += arr[i][i]
        secundario += arr[i][len(arr) - cont]
        cont += 1
    return abs(primaria - secundario)


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = []

    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split())))

    result = diagonalDifference(arr)

    fptr.write(str(result) + '\n')

    fptr.close()

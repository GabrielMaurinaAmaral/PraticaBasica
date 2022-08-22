import math
import os
import random
import re
import sys


def superDigit(n,  k):
    if len(n) == 1 and k <= 1:
        return int(n)

    x = 0
    for i in n:
        x += int(i)
    x *= k

    return superDigit(str(x), 1)


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = first_multiple_input[0]

    k = int(first_multiple_input[1])

    result = superDigit(n, k)

    fptr.write(str(result) + '\n')

    fptr.close()

import math
import os
import random
import re
import sys


def solve(string):
    for s in string.split():
        string = string.replace(s, s.capitalize())
    return string


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = solve(s)

    fptr.write(result + '\n')

    fptr.close()

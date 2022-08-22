import math
import os
import random
import re
import sys


def countingSort(arr):
    vetor = []
    
    for i in range(len(arr)):
        if i < 100 and i >= 0:
            vetor.append(arr.count(i))
        
    return vetor

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = countingSort(arr)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()

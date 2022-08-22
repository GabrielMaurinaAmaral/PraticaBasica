import math
import os
import random
import re
import sys


def palindromeIndex(s):
    esquerda = 0
    direita = len(s) - 1

    while esquerda < direita:
        if s[esquerda] != s[direita]:
            if s[esquerda+1] == s[direita]:
                return esquerda
            elif s[esquerda] == s[direita - 1]:
                return direita
            
        esquerda += 1
        direita -= 1
        
    return -1


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        s = input()

        result = palindromeIndex(s)

        fptr.write(str(result) + '\n')

    fptr.close()

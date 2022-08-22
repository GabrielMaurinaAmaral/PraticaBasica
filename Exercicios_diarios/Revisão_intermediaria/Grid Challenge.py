import math
import os
import random
import re
import sys

if __name__ == '__main__':
    casos = int(input())
    for _ in range(casos):
        len = int(input())
        strings = [list(sorted(input())) for i in range(len)]

        result = 'YES'
        for str in list(zip(*strings)):
            if(list(str) != sorted(str)):
                result = 'NO'
                break
        print(result)

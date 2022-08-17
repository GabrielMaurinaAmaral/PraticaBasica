import math
import os
import random
import re
import sys


def timeConversion(s):
    hora = int(s[:2])

    if s[-2:] == 'PM':
        if hora != 12:
            hora = 12 + hora
        else:
            hora = hora
        return(str(hora) + s[2:8])
    else:
        if hora == 12:
            return("00" + s[2:8])
        else:
            return(s[:8])


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    fptr.write(result + '\n')

    fptr.close()

import math
import os
import random
import re
import sys


def caesarCipher(str, k):
    str_aux = ''
    k = k % 26
    for i in str:
        if i.isalpha():#verificar se caracter é alfabetico
            if i.isupper() and ord(i)+k > 90:
                str_aux += chr(64+k-(90-ord(i)))  #ord converte char em num
            elif i.islower() and ord(i)+k > 122:  #char converte num e char
                str_aux += chr(96+k-(122-ord(i)))
            else:
                str_aux += chr(ord(i)+k)
        else:
            str_aux += i
    return str_aux


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    s = input()

    k = int(input().strip())

    result = caesarCipher(s, k)

    fptr.write(result + '\n')

    fptr.close()

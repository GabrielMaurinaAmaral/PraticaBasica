import math
import os
import random
import re
import sys


def minimumBribes(q):
    lastItem = len(q)
    bribe = 0
    result = ""
    while(len(q) != 0):
        count = 0
        for i in range(len(q)-1, -1, -1):
            if(result == "Too chaotic"):
                break
            if(q[i] == lastItem):
                bribe += count
                q.pop(i)
                result = str(bribe)
                break
            elif(count == 2):
                result = "Too chaotic"
            else:
                count += 1
        lastItem = len(q)
        if(result == "Too chaotic"):
            break
    print(result)


if __name__ == '__main__':
    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        q = list(map(int, input().rstrip().split()))

        minimumBribes(q)

from itertools import permutations

s, k = input().split()

words = list(permutations(s, int(k)))
words = sorted(words, reverse=False)

for word in words:
    print(*word, sep='')

from itertools import combinations_with_replacement

s, k = input().split()

words = list(combinations_with_replacement(s, int(k)))
words = sorted(words, reverse=False)

for word in words:
    print(*word, sep='')

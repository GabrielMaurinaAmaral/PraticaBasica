from itertools import combinations
n = int(input())
lista = input().split()
k = int(input())

cont = 0
total = 0

for c in combinations(lista, k):
    print(c)
    if "a" in c:
        cont += 1
    total += 1
print(cont/total)

from itertools import product

A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(product(A, B))

for c in C:
    print(c, end=" ")

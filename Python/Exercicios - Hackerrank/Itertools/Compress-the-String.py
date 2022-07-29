from itertools import *

lista = input()
for i, j in groupby(map(int, list(lista))):
    print(tuple([len(list(j)), i]), end=" ")

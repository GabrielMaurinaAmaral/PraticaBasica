tam_1 = int(input())
set_1 = set(map(int, input().split()))
tam_2 = int(input())
set_2 = set(map(int, input().split()))

diferenca_1 = set_1.difference(set_2)
diferenca_2 = set_2.difference(set_1)

set_3 = diferenca_1.union(diferenca_2)
print(len(set_3))

tam_1 = int(input())
set_1 = set(map(int, input().split()))
tam_2 = int(input())
set_2 = set(map(int, input().split()))
print(type(set_1))

diferenca_1 = set_1.difference(set_2)
diferenca_2 = set_2.difference(set_1)
print(type(diferenca_1))


result = diferenca_1.union(diferenca_2)
result = sorted(result)
print(type(result))

for r in result:
    print(r)

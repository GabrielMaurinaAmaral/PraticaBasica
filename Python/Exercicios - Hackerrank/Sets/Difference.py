tam_1 = int(input())
set_1 = set(map(int, input().split()))
tam_2 = int(input())
set_2 = set(map(int, input().split()))

set_3 = set_1.difference(set_2)
print(len(set_3))

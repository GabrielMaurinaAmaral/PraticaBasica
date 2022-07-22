casos = int(input())

for i in range(casos):
    len_A = int(input())
    set_A = set(map(int, input().split()))
    len_B = int(input())
    set_B = set(map(int, input().split()))

    print(set_A.issubset(set_B))

size_1 = int(input())
set_1 = set(map(int, input().split()))
size_op = int(input())

for i in range(size_op):
    funcao = input().split()
    set_2 = set(map(int, input().split()))

    if funcao[0] == 'intersection_update':
        set_1.intersection_update(set_2)
    elif funcao[0] == 'update':
        set_1.update(set_2)
    elif funcao[0] == 'symmetric_difference_update':
        set_1.symmetric_difference_update(set_2)
    elif funcao[0] == 'difference_update':
        set_1.difference_update(set_2)
    else:
        assert False

print(sum(set_1))

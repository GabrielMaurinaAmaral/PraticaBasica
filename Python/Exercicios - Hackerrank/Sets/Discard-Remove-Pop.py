n = int(input())
s = set(map(int, input().split()))
tam = int(input())

for i in range(tam):
    funcao = input().split()

    if funcao[0] == 'pop':
        s.pop()
    elif funcao[0] == 'remove':
        s.remove(int(funcao[1]))
    elif funcao[0] == 'discard':
        s.discard(int(funcao[1]))
print(sum(s))

N = int(input())
lista = list()

for i in range(N):
    funcao, *l = input().split()
    variaveis = list(map(int, l))

    if funcao == 'insert':
        lista.insert(variaveis[0], variaveis[1])
    elif funcao == 'print':
        print(lista)
    elif funcao == 'remove':
        lista.remove(variaveis[0])
    elif funcao == 'append':
        lista.append(variaveis[0])
    elif funcao == 'sort':
        lista.sort()
    elif funcao == 'pop':
        lista.pop()
    elif funcao == 'reverse':
        lista.reverse()

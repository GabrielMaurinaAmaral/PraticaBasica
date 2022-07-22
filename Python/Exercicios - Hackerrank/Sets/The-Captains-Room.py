k = int(input())
lista = sorted(map(int, input().split()))

for i in range(len(lista)):

    if(i != len(lista)-1):
        if(lista[i] != lista[i-1] and lista[i] != lista[i+1]):
            print(lista[i])
            break
    else:
        print(lista[i])

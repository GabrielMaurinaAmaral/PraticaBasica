a = input()
lista = list(map(int, input().split()))
tam = int(input())

cont = 0
for i in range(tam):
    num, din = map(int, input().split())

    if num in lista:
        lista.remove(num)
        cont += din
print(cont)

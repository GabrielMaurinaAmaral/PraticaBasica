tamanho = int(input())
letra = 'H'

for i in range(tamanho):
    print((letra*i).rjust(tamanho-1) + letra + (letra*i).ljust(tamanho-1))

for i in range(tamanho+1):
    print((letra*tamanho).center(tamanho*2)+(letra*tamanho).center(tamanho*6))

for i in range((tamanho+1)//2):
    print((letra*tamanho*5).center(tamanho*6))

for i in range(tamanho+1):
    print((letra*tamanho).center(tamanho*2)+(letra*tamanho).center(tamanho*6))

for i in range(tamanho):
    print(((letra*(tamanho-i-1)).rjust(tamanho)+letra + (letra*(tamanho-i-1)).ljust(tamanho)).rjust(tamanho*6))

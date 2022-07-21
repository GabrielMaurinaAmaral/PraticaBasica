matriz = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
soma = 0
for i in range(0, 3):
    for j in range(0, 3):
        matriz[i][j] = int(input("enter a number: "))

        if matriz[i][j] % 2 == 0:
            soma += matriz[i][j]

print("="*20)
for i in range(0, 3):
    for j in range(0, 3):
        print('[{}]'.format(matriz[i][j]), end='')
    print()

print("soma par: {}".format(soma))

somaColuna = 0
for i in range(0, 3):
    somaColuna += matriz[i][2]
print("soma ultima coluna: {}".format(somaColuna))

maior = 0
for l in range(0, 3):
    if l == 0:
        maior = matriz[1][l]
    elif matriz[1][l] > maior:
        maior = matriz[1][l]
print("maior da segunda coluna: {}".format(maior))

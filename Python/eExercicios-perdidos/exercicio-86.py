matriz = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]

for i in range(0, 3):
    for j in range(0, 3):
        matriz[i][j] = int(input("enter a number: "))

print("="*20)
for i in range(0, 3):
    for j in range(0, 3):
        print('[{}]'.format(matriz[i][j]), end='')
    print()

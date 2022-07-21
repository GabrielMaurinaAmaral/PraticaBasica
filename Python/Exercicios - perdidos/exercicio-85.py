matriz = [[], []]
for m in range(0, 7):
    num = int(input("enter a number: "))

    if num % 2 == 0:
        matriz[0].append(num)

    else:
        matriz[1].append(num)

matriz[0].sort()
matriz[1].sort()
print("="*20)
print(matriz)

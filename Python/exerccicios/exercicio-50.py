soma = 0

for a in range(1, 7):
    i = int(input("number {}: ".format(a)))
    if i % 2 == 0:
        soma += i

print("result: {}".format(soma))

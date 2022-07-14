saque = int(input("voce quer sacar R$"))
result = 0
cont50 = 0
cont20 = 0
cont10 = 0
cont5 = 0
cont2 = 0
cont1 = 0

while result == 0:
    if saque >= 50:
        cont50 += 1
        saque -= 50

    elif saque < 50 and saque >= 20:
        cont20 += 1
        saque -= 20

    elif saque < 20 and saque >= 10:
        cont10 += 1
        saque -= 10

    elif saque < 10 and saque >= 5:
        cont5 += 1
        saque -= 5

    elif saque < 5 and saque >= 2:
        cont2 += 1
        saque -= 2

    elif saque < 2 and saque >= 1:
        cont1 += 1
        saque -= 1

    else:
        result = 1

print(" {} nota de 50".format(cont50))
print(" {} nota de 20".format(cont20))
print(" {} nota de 10".format(cont10))
print(" {} nota de 5".format(cont5))
print(" {} nota de 2".format(cont2))
print(" {} nota de 1".format(cont1))

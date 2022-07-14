def vetorMaior(*num):
    cont = 0
    for n in num:
        print(f'{n} ', end='',)
        if cont == 0:
            maior = n
            cont = 1
        else:
            if n > maior:
                maior = n

    print(maior)

while True:
    num = []
    n = (int(input('enter a number: ')))

    num.append(n)

    opc = str(input('continue? '))
    if opc in 'Nn':
        break

vetorMaior(num)

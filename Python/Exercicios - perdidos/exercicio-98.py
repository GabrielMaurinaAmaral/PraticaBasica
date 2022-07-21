def cont(inicio, fim, passo):
    aux = inicio
    if inicio < fim:
        while aux <= fim:
            print(aux , end='')
            aux += passo

    elif inicio > fim:
        while aux >= fim:
            print(aux , end='')
            aux -= passo

    print('FIM!')


while True:
    i = int(input('INICIO: '))
    p = int(input('PASSO: '))
    f = int(input('FIM: '))

    cont(i, f, p)

    opc = str(input('continue? '))
    if opc in 'Nn':
        break

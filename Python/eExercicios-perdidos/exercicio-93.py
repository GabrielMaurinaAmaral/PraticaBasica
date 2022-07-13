

lista = list()
pessoa = dict()
while True:
    pessoa['nome'] = str(input("Nome: "))
    pessoa['ano de nacimento'] = int(input("Ano de nacimento: "))
    pessoa['carteira de trabalho'] = int(input('carteira de trabalho'))

    if pessoa['carteira de trabalho'] != 0:
        pessoa['ano de contratação'] = int(input("ano de contratação: "))
        pessoa['salario'] = float(input('salariol'))
        pessoa['aposentadoria'] = (
            2022-pessoa['ano de nacimento']) + pessoa['ano de contratação'] + 35

    lista.append(pessoa.copy())
    pessoa.clear()

    opc = str(input("continue: "))
    if opc in 'Nn':
        break

for i in lista:
    for k, v in pessoa.items():
        print("{} e igual a {}".format(k, v))
    print("")

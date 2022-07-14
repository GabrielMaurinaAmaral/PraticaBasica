estado = dict()
brasil = list()

for c in range(0, 3):
    estado["uf"] = str(input("Unidade federativa: "))
    estado["sigla"] = str(input("Sigra do estado: "))
    brasil.append(estado.copy())

for i in brasil:
    for j in i.values():
        print([j], end=' ')
    print()

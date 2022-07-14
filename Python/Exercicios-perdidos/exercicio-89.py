turma = list()

while True:
    nome = (str(input("nome: ")))
    n1 = float(input("nota 1: "))
    n2 = float(input("nota 2: "))
    media = (n1+n2)/2
    turma.append([nome, [n1, n2], media])

    opc = str(input("continue? "))
    if opc in "Nn":
        break

print("="*20)
for i, l in enumerate(turma):
    print("{}-----{}-----{}".format(i, l[0], l[2]))

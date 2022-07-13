teste = list()
teste.append("gustavo")
teste.append("40")
galera = list()
galera.append(teste[:])
teste[0] = "maria"
teste[1] = 22
galera.append(teste[:])
print(galera)


matriz = [["joao", 29], ["Ana", 32], ['Joaquim', 45], ["maria", 24]]
for m in matriz:
    print("{} tem {} anos de idade".format(m[0], m[1]))


vetor=list()
dado=list()
for c in range(0,3):
    dado.append(str(input("nome: ")))
    dado.append(int(input("idade: ")))
    vetor.append(dado[:])
    dado.clear()##limpa o vetor
print(vetor)
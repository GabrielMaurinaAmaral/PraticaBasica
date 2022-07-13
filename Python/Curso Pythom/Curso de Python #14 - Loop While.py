op = "s"
vetor = []

while op != "n":
    vetor.append(input("digite um numero: "))
    op = input("deseja continuar(s/n? ")
print(vetor)

i = 0
while i < 10:
    print(i)
    i += 1
    if i > 5:
        break

carros = []
carro = input("digite um carro: ")
while carro != "-1":
    carros.append(carro)
    carro = input("digite um carro: ")
print(carros)

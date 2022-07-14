from random import randint
listas = list()
jogos = list()

x = int(input("quantas veze: "))

for i in range(0, x):
    for l in range(0, 6):
        num = randint(0, 60)
        listas.append(num)

    listas.sort()
    jogos.append(listas[:])
    listas.clear()

for i, l in enumerate(jogos):
    print("jogo {}: {}".format(i+1, l))

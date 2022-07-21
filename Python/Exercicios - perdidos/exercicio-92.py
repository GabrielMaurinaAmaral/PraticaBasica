from random import randint
from operator import itemgetter

jogo = {'jogador 1': randint(1, 6), 'jogador 2': randint(
    1, 6), 'jogador 3': randint(1, 6), 'jogador 4': randint(1, 6)}

for i, j in jogo.items():
    print("{} tirou {}".format(i, j))

maior = list()
maior = sorted(jogo.items(), key=itemgetter(1), reverse=True)

for i, j in enumerate(maior):
    print("{} lugar {} com {} ".format(i+1, j[0], j[1]))

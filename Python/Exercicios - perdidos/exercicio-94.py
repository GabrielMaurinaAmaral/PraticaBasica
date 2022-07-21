from ast import Num


jogador = dict()
partidas=list

print("="*20)
jogador['nome'] = str(input('nome: '))
num = int(input('quantas partidas {} jogou: '.format(jogador['nome'])))

for i in range(0,num):
    partidas.append(int(input('gols feitos na {} partida: '.format(i+1))))

jogador['gols']=partidas[:]
jogador['total']=sum(partidas)

print("="*20)
for i,j in jogador.items():
    print('o jogagor {}, fez {} gols'.format(i,j))

for i,j in enumerate(jogador['gols']):
    print(" na partida {} fez {} gols".format(i,j))


    
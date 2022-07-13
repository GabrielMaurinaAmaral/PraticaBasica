from os import system
from random import randrange

# variaveis globais
jogarNovamente = "s"
jogadas = 0
quemJoga = 2
maximoJoagadas = 9
vitoria = False
velha = [
    [" ", " ", " "],
    [" ", " ", " "],
    [" ", " ", " "],
]


def tela():
    system("cls")
    global velha, jogadas

    print("    0   1   2")
    print(f"0:  {velha[0][0]} | {velha[0][1]} | {velha[0][2]}")
    print(15*"-")
    print(f"1:  {velha[1][0]} | {velha[1][1]} | {velha[1][2]}")
    print(15*"-")
    print(f"2:  {velha[2][0]} | {velha[2][1]} | {velha[2][2]}")
    print(f"\njogadas: {jogadas}")


def jogadorJoga():
    global jogadas, quemJoga, maximoJoagadas, velha

    if quemJoga == 2 and jogadas < maximoJoagadas:
        linha = int(input("Linha: "))
        coluna = int(input("Coluna: "))

        try:
            while velha[linha][coluna] != " ":
                linha = int(input("Linha: "))
                coluna = int(input("Coluna: "))

            velha[linha][coluna] = "X"
            quemJoga = 1
            jogadas += 1
        except:
            print("linha e ou coluna invalida")
            system("pause")


def cpuJoga():
    global jogadas, quemJoga, maximoJoagadas, velha

    if quemJoga == 1 and jogadas < maximoJoagadas:
        linha = randrange(0, 3)
        coluna = randrange(0, 3)

        while velha[linha][coluna] != " ":
            linha = randrange(0, 3)
            coluna = randrange(0, 3)

        velha[linha][coluna] = "O"
        quemJoga = 2
        jogadas += 1


def verificarVitoria():
    global velha, vitoria
    simbolos = ["X", "O"]

    for s in simbolos:
        vitoria = False
        indiceLinha = indiceColuna = 0
        #verificar linhas
        while indiceLinha < 3:
            soma = 0
            indiceColuna = 0

            while indiceColuna < 3:
                if(velha[indiceLinha][indiceColuna] == s):
                    soma += 1

                indiceColuna += 1

            indiceLinha += 1

            if (soma == 3):
                vitoria = True
                break
        if(vitoria != False):
            break

        indiceLinha = indiceColuna = 0
        #verificar colunas
        while indiceColuna < 3:
            soma = 0
            indiceLinha = 0

            while indiceLinha < 3:
                if(velha[indiceLinha][indiceColuna] == s):
                    soma += 1
                indiceLinha += 1
            indiceColuna += 1

            if (soma == 3):
                vitoria = True
                break
        if(vitoria != False):
            break

        #verificar diagonais 1
        diagonal = 0
        soma = 0
        while diagonal < 3:
            if(velha[diagonal][diagonal] == s):
                soma += 1
            diagonal += 1

        if (soma == 3):
            vitoria = True
            break

        #verificar diagonais 2
        soma = 0
        indiceLinha = 0
        indiceColuna = 2
        while indiceLinha < 3:
            if(velha[indiceLinha][indiceColuna] == s):
                soma += 1
            indiceLinha += 1
            indiceColuna -= 1

        if (soma == 3):
            vitoria = True
            break


def redefinir():
    global jogadas, quemJoga, maximoJoagadas, vitoria, velha
    jogadas = 0
    quemJoga = 2
    maximoJoagadas = 9
    vitoria = False
    velha = [
        [" ", " ", " "],
        [" ", " ", " "],
        [" ", " ", " "], ]


while True:
    tela()
    jogadorJoga()
    cpuJoga()
    tela()

    verificarVitoria()
    if(vitoria):
        print("jogador ganhou")
        break

    verificarVitoria()
    if(vitoria):
        print("computador ganhou")
        break

    if(jogadas == maximoJoagadas):
        print("deu velha")

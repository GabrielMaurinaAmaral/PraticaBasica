import os

carros = []


class Carro:
    nome = ""
    potencia = 0
    velocidadeMaxima = 0
    ligado = False

    def __init__(self, nome, potencia):  # contrututor no objeto
        self.nome = nome
        self.potencia = potencia
        self.velocidadeMaxima = int(potencia)*2
        self.ligado = False

    def ligar(self):
        self.ligado = True

    def desligar(self):
        self.ligado = False

    def imprimir(self):
        print(
            f"nome: {self.nome}\npotencai: {self.potencia}\nvelocidade maxima: {self.velocidadeMaxima}\nligador: {self.ligado}")  # "sim" if self.ligado=True else "nao"


def Menu():
    os.system("cls") or None  # limpar a tela/terminal

    print("1 - novo carro")
    print("2 - informacao do carro")
    print("3 - excluir carro")
    print("4 - ligar carro")
    print("5 - desligar carro")
    print("6 - listar carro")
    print("7 - sair")
    print("quantidades de carros: ", len(carros))

    opcao = int(input("\nDigite uma opcao: "))

    return opcao


def novo_Carro():
    os.system("cls") or None

    nom = input("Nome  do carro: ")
    pot = input("potencia: ")
    car = Carro(nom, pot)
    carros.append(car)
    print(f"{car.nome} foi adicionado")
    os.system("pause")


def informacao_Carro():
    os.system("cls") or None

    n = int(input("informe o numero do carro que dejesa ver as informacao: "))

    try:
        carros[n].imprimir()
    except:
        print("carro nap existe na lista")
    os.system("pause")


def excluir_Carro():
    os.system("cls") or None

    n = int(input("informe o numero que quer excluir: "))

    try:
        del carros[n]
    except:
        print("carro nao existe na lista")
    os.system("pause")


def ligar_Carro():
    os.system("cls") or None

    n = int(input("informe o numero que quer ligar: "))

    try:
        carros[n].ligar()
        print("carro ligado")
    except:
        print("carro nao existe na lista")
    os.system("pause")


def desligar_Carro():
    os.system("cls") or None

    n = int(input("informe o numero que quer desligar: "))

    try:
        carros[n].desligar()
        print(f"carro desligado")

    except:
        print("carro nao existe na lista")
    os.system("pause")


def listar_Carros():
    os.system("cls") or None

    p = 0
    for c in carros:
        print(f"{p} - {c.nome}")
        p += 1
    os.system("pause")


resposta = Menu()

while resposta < 7:
    if resposta == 1:
        novo_Carro()
    elif resposta == 2:
        informacao_Carro()
    elif resposta == 3:
        excluir_Carro()
    elif resposta == 4:
        ligar_Carro()
    elif resposta == 5:
        desligar_Carro()
    else:
        listar_Carros()
    resposta = Menu()

os.system("cls") or None
print("fim do programa")

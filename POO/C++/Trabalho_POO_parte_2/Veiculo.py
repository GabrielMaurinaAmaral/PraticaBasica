import Rodas
import random

class Veiculo:
    quantidade_rodas = 4

    def __init__(self):
        self.existe = False

    def __init__(self, ID):
        self.existe = True
        self.id = ID
        self.distancia_percorrida = 0
        self.desenho = "    ____\n __/ |_ \\._\n|  _     _``-.\n-(_)---(_)--\n"
        self.combustivel = 1
        self.valor_venda = 100
        self.ipva = bool(random.randint(0, 1))
        # AVISO PRECISA DE AJUSTE
        # self.rodas = Rodas() for _ in range(self.quantidade_rodas)
        # 
        print(f"Veiculo com ID {self.id} foi inicializado na pista")

    def get_existe(self):
        return self.existe

    def get_quantidade_rodas(self):
        return self.quantidade_rodas

    def mover(self):
        if self.combustivel >= 0.55 and self.ipva and self.verificar_todos_pneus():
            self.consumir(0.55)
            self.distancia_percorrida += 1
        else:
            if self.combustivel < 0.55:
                print(f"Veiculo ID {self.id} nao possui combustivel suficiente")
            if self.ipva:
                print(f"Veiculo ID {self.id} nao possui o ipva pago")
            if self.verificar_todos_pneus():
                print(f"Veiculo ID {self.id} nao possui todos os pneus calibrados")

    def abastecer(self, abastecer):
        self.combustivel += abastecer
        print(f"Tanque de combustivel esta agora com {self.combustivel} de combustivel")

    def consumir(self, consumir):
        if self.combustivel > 0:
            self.combustivel -= consumir
            print(f"Tanque de combustivel esta agora com {self.combustivel} de combustivel")
        else:
            print("Sem gasolina para consumir")
        if self.combustivel < 0:
            self.combustivel = 0

    def verificar_todos_pneus(self):
        result = True
        for roda in self.rodas:
            if not roda.get_calibragem():
                result = False
        return result

    def calibrar(self, id_pneu):
        self.rodas[id_pneu].set_calibragem(True)
        print(f"Pneu: {id_pneu} -> calibrado")

    def esvaziar(self, id_pneu):
        self.rodas[id_pneu].set_calibragem(False)
        print(f"Pneu: {id_pneu} -> esvaziado")

    def imprimir_veiculo(self):
        for _ in range(self.distancia_percorrida):
            print("     ", end="")
        print("    ____")
        for _ in range(self.distancia_percorrida):
            print("     ", end="")
        print(" __/ |_ \\._")
        for _ in range(self.distancia_percorrida):
            print("     ", end="")
        print("|  _     _``-.")
        for _ in range(self.distancia_percorrida):
            print("     ", end="")
        print("-(_)---(_)--\n")

    def mostrar_dados(self):
        print(f"\nID: {self.id}")
        print("IPVA: ", end="")
        if self.ipva:
            print("Sim")
        else:
            print("Nao")
        print(f"Combustivel: {self.combustivel}")
        print(f"Valor de venda: {self.valor_venda}")
        print(f"Distancia percorrida: {self.distancia_percorrida}")
        print(f"Quantidade de rodas: {self.quantidade_rodas}")
        for i in range(self.quantidade_rodas):
            print(f"Roda {i}: ", end="")
            if self.rodas[i].get_calibragem():
                print("calibrada")
            else:
                print("decalibrada")

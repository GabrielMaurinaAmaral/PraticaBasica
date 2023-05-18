import random
import Veiculo

class Simulador:
    def __init__(self):
        self.capacidade_veiculos = 20
        self.quantidade_veiculos = 0
        # AVISO SE ESTA CERTO
        #self.garagem = [Veiculo() for _ in range(self.capacidade_veiculos)]
        #
    def get_capacidade_veiculos(self):
        return self.capacidade_veiculos

    def incluir_veiculo(self):
        if self.capacidade_veiculos == self.quantidade_veiculos:
            print("Capacidade de veiculo está cheia")
        elif self.quantidade_veiculos == 0:
            id = random.randint(0, 19)
            self.garagem[id] = Veiculo(id)
            self.quantidade_veiculos += 1
        else:
            id = random.randint(0, self.capacidade_veiculos - 1)
            while self.garagem[id].get_existe():
                id = random.randint(0, self.capacidade_veiculos - 1)
            self.garagem[id] = Veiculo(id)
            self.quantidade_veiculos += 1
            print(f"Quantdade de garagem na pista agora é {self.quantidade_veiculos}")

    def remover_veiculo(self, id):
        if self.garagem[id].get_existe():
            self.garagem[id] = Veiculo()
            self.quantidade_veiculos -= 1
            print(f"Veiculo com id {id} foi excluido da pista")
            print(f"Quantdade de garagem na pista agora é {self.quantidade_veiculos}")
        else:
            print(f"Não existe nenhum veiculo com ID {id} na pista para que seja excluido")

    def abastecer_veiculo(self, id, quantidade_gasosa):
        if self.garagem[id].get_existe():
            self.garagem[id].abastecer(quantidade_gasosa)
        else:
            print(f"Não existe nenhum veiculo com ID {id} na pista para que possa abastecer")

    def mover_veiculo(self, id):
        if self.garagem[id].get_existe():
            self.garagem[id].mover()
        else:
            print(f"Não existe nenhum veiculo com ID {id} na pista para que possa movelo")

    def mover_todos_veiculos(self):
        for i in range(self.capacidade_veiculos):
            if self.garagem[i].get_existe():
                self.garagem[i].mover()

    def mostrar_dados_veiculo(self, id):
        if self.garagem[id].get_existe():
            self.garagem[id].mostrar_dados()
        else:
            print(f"Não existe nenhum veiculo com ID {id} na pista para que possa mostrar as informações")

    def mostrar_dados_todos_veiculos(self):
        for i in range(self.capacidade_veiculos):
            if self.garagem[i].get_existe():
                self.garagem[i].mostrar_dados()

    def veiculo_mexer_pneu(self, id, id_pneu):
        if self.garagem[id].get_existe():
            opcao = int(input("esvaziar(1) ou encher(2): "))
            if id_pneu < self.garagem[id].get_quantidade_rodas():
                if opcao == 1:
                    self.garagem[id].esvaziar(id_pneu)
                else:
                    self.garagem[id].calibrar(id_pneu)
            else:
                print(f"Não existe esse pneu no veiculo com ID {id}")
        else:
            print(f"Não existe nenhum veiculo com ID {id} na pista para que possa mexer no pneu dele")

    def veiculo_mexer_todos_pneus(self, id):
        if self.garagem[id].get_existe():
            opcao = int(input("esvaziar(1) ou encher(2) todos os pneus: "))
            if opcao == 1:
                for i in range(self.garagem[id].get_quantidade_rodas()):
                    self.garagem[id].esvaziar(i)
            else:
                for i in range(self.garagem[id].get_quantidade_rodas()):
                    self.garagem[id].calibrar(i)
        else:
            print(f"Não existe nenhum veiculo com ID {id} na pista para que possa mexer nos pneus dele")

    def imprimir_pista(self):
        print()
        for i in range(self.capacidade_veiculos):
            if self.garagem[i].get_existe():
                self.garagem[i].imprimir_veiculo()
        print()

    def gravar_arquivo(self):
        with open("veiculos.dat", "wb") as arquivo_gravar:
            for i in range(self.capacidade_veiculos):
                arquivo_gravar.write(self.garagem[i])

    def ler_arquivo(self):
        with open("veiculos.dat", "rb") as arquivo_leitura:
            for i in range(self.capacidade_veiculos):
                self.garagem[i] = arquivo_leitura.read()

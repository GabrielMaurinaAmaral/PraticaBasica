# classes
from Veiculo import *
from Veiculo_Motorizado import *
from Bicicleta import Bicicleta
from Motocicleta import Motocicleta
from Carro_Passeio import Carro_Passeio
from Carro_Esportivo import Carro_Esportivo

# biblioteca
from random import randint
import pickle
import os


class Simulador:

    def __init__(self, capacidade: int) -> None:
        self.__capacidade_veiculos = capacidade
        self.__quantidade_veiculos = 0
        self.__garagem = []
        print("\n SIMULAÇÃO COMEÇOU \n")

    def incluir_veiculo(self, tipo: str) -> None:
            if self.__capacidade_veiculos == self.__quantidade_veiculos:
                print("Capacidade de veiculo está cheia")
            else:
                ids_existentes = set(veiculo.get_id() for veiculo in self.__garagem)
                id = None
                while id is None or id in ids_existentes:
                    id = int(randint(0, 1000))
                if tipo == 'B':
                    veiculo = Bicicleta(id, 2)
                elif tipo == 'M':
                    veiculo = Motocicleta(id, 2)
                elif tipo == 'C':
                    veiculo = Carro_Passeio(id, 4)
                elif tipo == 'E':
                    veiculo = Carro_Esportivo(id, 4)  
                self.__garagem.append(veiculo)
                self.__quantidade_veiculos += 1
                print(f"Quantidade de veiculos na pista agora é {self.__quantidade_veiculos}")

    def remover_veiculo(self, id: int) -> None:
        for i in range(len(self.__garagem)):
            if self.__garagem[i].get_id() == id:
                del self.__garagem[i]
                self.__quantidade_veiculos -= 1
                print(f"Veiculo com id {id} foi excluido da pista")
                print(f"Quantdade de __garagem na pista agora é {self.__quantidade_veiculos}")
                return
        print(
            f"Não existe nenhum veiculo com ID {id} na pista para que seja excluido")

    def abastecer_veiculo(self, id, quantidade_gasosa) -> None:
        for veiculo in self.__garagem:
            if veiculo.get_id() == id:
                if isinstance(self.veiculo, Veiculo_Motorizado):
                    veiculo.abastecer(quantidade_gasosa)
                    return
                else:
                    print("Bicicleta não pode ser abastecida")
        print(f"Não existe nenhum veiculo com ID {id} na pista para que possa abastecer")

    def mover_veiculo(self, id) -> None:
        for veiculo in self.__garagem:
            if veiculo.get_id() == id:
                veiculo.mover()
                return
        print(
            f"Não existe nenhum veiculo com ID {id} na pista para que possa movelo")

    def mover_veiculos_tipo(self, tipo) -> None:
        if tipo in ["E", "B", "M", "C"]:
            for veiculo in self.__garagem:
                if veiculo.get_tipo() == tipo:
                    veiculo.mover()
                    return
        else:
            print(f"Não existe nenhum veiculo com ID {id} na pista para que possa movelo")

    def mover_todos_veiculos(self) -> None:
        for veiculo in self.__garagem:
            veiculo.mover()

    def mostrar_dados_veiculos_tipo(self, tipo) ->None:
        if tipo in ["E", "B", "M", "C"]:
            for veiculo in self.__garagem:
                if veiculo.get_tipo() == tipo:
                    print(veiculo)
        else:    
            print(f"Não existe nenhum tipo {tipo} nesse Simulador")

    def mostrar_dados_todos_veiculos(self) -> None:
        for veiculo in self.__garagem:
            print(veiculo)

    def veiculo_mexer_pneu(self, id) -> None:
        for veiculo in self.__garagem:
            if veiculo.get_id() == id:
                id_pneu = 0 
                for roda in veiculo.get_rodas(): 
                    print(f"pneu {id_pneu} esta {roda}")   
                    id_pneu +=1
                id_pneu = input("qual pneu vc quer mexer")
                
                if 0 < id_pneu and id_pneu < veiculo._quantidade_rodas:
                    opcao = 0
                    while opcao != 1 and opcao != 2:
                        try:
                            opcao = int(input("esvaziar(1) ou encher(2): "))
                        except ValueError:
                            print(
                                "Opção inválida. Digite 1 para esvaziar ou 2 para encher.")
                    if opcao == 1:
                        self.veiculo.esvaziar(id_pneu)
                    else:
                        self.veiculo.calibrar(id_pneu)
                    return
                else:
                    print(f"Não existe esse pneu no veiculo com ID {id}")
                    return
        print(
            f"Não existe nenhum veiculo com ID {id} na pista para que possa mexer no pneu dele")

    def veiculo_mexer_todos_pneus(self, id) -> None:
        for veiculo in self.__garagem:
            if veiculo.get_id() == id:
                opcao = 0
                while opcao != 1 and opcao != 2:
                    try:
                        opcao = int(input("esvaziar(1) ou encher(2): "))
                    except ValueError:
                        print(
                            "Opção inválida. Digite 1 para esvaziar ou 2 para encher.")
                if opcao == 1:
                    for i in range(veiculo._quantidade_rodas()):
                        veiculo.esvaziar(i)
                else:
                    for i in range(veiculo._quantidade_rodas()):
                        veiculo.calibrar(i)
                return
        print(
            f"Não existe nenhum veiculo com ID {id} na pista para que possa mexer nos pneus dele")

    def imprimir_pista(self) -> None:
        for veiculo in self.__garagem:
            veiculo.desenhar()

    def gravar_arquivo(self) -> None:
        if len(self.__garagem) != 0:
            if os.path.isfile('veiculos.txt'):
                mode: str = 'ab'
            else:
                mode: str = 'wb'
            with open('veiculos.txt', mode=mode) as file:
                pickle.dump(len(self.__garagem), file)
                for veiculo in self.__garagem:
                    pickle.dump(veiculo, file)
            print("veiculos gravados com sucesso")
        else:
            print('Não há veículos para serem gravados')

    def ler_arquivo(self) -> None:
        if os.path.isfile('veiculos.txt'):
            with open('veiculos.txt', "rb") as file:
                for _ in range(pickle.load(file)):
                    self.__garagem.append(pickle.load(file))
            print('veiculos lidos com sucesso')
        else:
            print("Nenhum arquivo encontrado")

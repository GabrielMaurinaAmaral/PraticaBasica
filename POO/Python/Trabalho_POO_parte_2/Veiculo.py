# classe
from Roda import *

# biblioteca
from abc import ABC, abstractclassmethod, abstractmethod

# classe abstrata
class Veiculo(ABC):
    # construtor abstrato
    @abstractclassmethod
    def __init__(self, ID: int, rodas: int):
        self.__id: int = ID
        self.__distancia_percorrida: int = 0
        self.__quantidade_rodas: int = rodas
        self.__rodas: list = [Roda() for _ in range(self.__quantidade_rodas)]

    # metodos get
    def get_id(self) -> int:
        return self.__id

    def get_distancia_percorrida(self) -> int:
        return self.__distancia_percorrida

    def get_quantidade_rodas(self) -> int:
        return self.__quantidade_rodas

    def get_rodas(self) -> list:
        return self.__rodas

    def set_distancia_percorrida(self, new: int) -> int:
        self.__distancia_percorrida = new

    # funções abstratas
    @abstractmethod
    def mover(self) -> None:
        pass

    @abstractmethod
    def desenhar(self) -> None:
        pass

    # funções herdadas
    def verificar_pneu(self) -> bool:
        result = True
        for roda in self.__rodas:
            if not roda.get_calibragem():
                result = False
        return result

    def calibrar_pneu(self, id_pneu: int) -> None:
        self.__rodas[id_pneu].set_calibragem(True)
        print(f"Pneu: {id_pneu} -> calibrado")

    def esvaziar_pneu(self, id_pneu: int) -> None:
        self.__rodas[id_pneu].set_calibragem(False)
        print(f"Pneu: {id_pneu} -> esvaziado")

    def __str__(self) -> str:
        dados = []
        dados.append(f"\nID: {self.__id}")
        dados.append(f"Distancia percorrida: {self.__distancia_percorrida}")
        dados.append(f"Quantidade de rodas: {self.__quantidade_rodas}")
        for roda in self.__rodas:
            dados.append(str(roda))
        return "\n".join(dados)

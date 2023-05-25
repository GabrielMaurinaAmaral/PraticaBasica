# classe
from Veiculo import Veiculo

# biblioteca
from random import choice
from abc import ABC, abstractclassmethod

#classe abstrata


class Veiculo_Motorizado(Veiculo):
    # construtor abstrato
    @abstractclassmethod
    def __init__(self, id: int, rodas: int):
        super().__init__(id, rodas)
        self.__gasto_motocicleta: float = 0.25
        self.__gasto_carro_passeio: float = 0.75
        self.__gasto_carro_esportivo: float = 2.3
        self.__combustivel: float = 0
        self.__ipva = bool(choice([True, False]))

    # metodo get
    def get_combustivel(self) -> float:
        return self.__combustivel

    def get_ipva(self) -> bool:
        return self.__ipva

    # funções herdadas
    def abastecer(self, abastecer: float) -> None:
        self.__combustivel += abastecer
        print(
            f"Tanque de combustivel esta agora com {self.__combustivel} de combustivel")

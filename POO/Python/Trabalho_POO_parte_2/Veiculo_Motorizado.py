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
        # self.__ipva = bool(choice([True, False]))
        self.__ipva = True

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
    
    def consumir(self, consome:float ) ->None:
        self.__combustivel -= consome
        print(
            f"Tanque de combustivel esta agora com {self.__combustivel} de combustivel")
    
    def __str__(self) -> str:
        dados = []
        dados.append(f"\nID: {self.get_id()}")
        dados.append(f"Distancia percorrida: {self.get_distancia_percorrida()}")
        dados.append(f"Quantidade de rodas: {self.get_quantidade_rodas()}")
        for roda in self.get_rodas():
            dados.append(str(roda))
        dados.append(f"Combustivel no tanque: {self.__combustivel}")
        dados.append(f"IPVA: {self.__ipva}")
        return "\n".join(dados)
        
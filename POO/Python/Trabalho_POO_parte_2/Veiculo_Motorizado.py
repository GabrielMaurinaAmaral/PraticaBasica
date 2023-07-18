# classe
from Veiculo import *

# biblioteca
from random import choice
from abc import ABC, abstractclassmethod

#classe abstrata e herda a classe abstrata veiculo
class Veiculo_Motorizado(Veiculo, ABC):
    # construtor abstrato
    @abstractclassmethod
    def __init__(self, id: int, rodas: int):
        super().__init__(id, rodas)
        self.__combustivel: float = 0
        self.__ipva = bool(choice([True, False]))
        self.__valor_ipva: float = 0
    # metodo get
    def get_combustivel(self) -> float:
        return self.__combustivel

    def get_ipva(self) -> bool:
        return self.__ipva
    
    def get_valor_ipva(self) -> float:
        return self.__valor_ipva
   
    def set_valor_ipva(self, valor_ipva:float) -> None:
        self.__valor_ipva = valor_ipva


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
        dados.append(f"Valor IPVA: {self.__valor_ipva}")
        return "\n".join(dados)
    
    
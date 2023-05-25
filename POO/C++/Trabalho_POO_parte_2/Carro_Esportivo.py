from Veiculo_Motorizado import Veiculo_Motorizado
from Veiculo import *


class Carro_Esportivo(Veiculo_Motorizado):
    # constructor
    def __init__(self, id: int, rodas: int):
        super().__init__(id, rodas)
        self.__tipo = "E"
        print(f"Carro Esportivo com ID {self._id} foi construida")

    # metodo get
    def get_tipo(self) -> int:
        return self.__tipo

    # funções abstrata herdada pelo pai veiculo
    def mover(self):
        if self._ipva:
            if self._combustivel >= self.__gasto_carro_esportivo:
                if self.verificar_pneu():
                    self._combustivel -= self.__gasto_carro_esportivo
                    self._distancia_percorrida += 10
                    print(
                        f"Carro Esportivo - ID:{self.id} andou  bloco +5 e está com {self._combustivel:.2f}litro_ de gasolina")
                else:
                    print(
                        f"Carro Esportivo com ID {self.id} não possui todos os pneus calibrados")
            else:
                print(
                    f"Carro Esportivo com ID {self.id} não possui _combustivel suficient_")
        else:
            print(f"Carro Esportivo com ID {self.id} não está com ipva em dia")

    def desenhar(self) -> None:
        print(" "*self._distancia_percorrida + "    ____")
        print(" "*self._distancia_percorrida + " __/  |_ \_")
        print(" "*self._distancia_percorrida + "|  _     _``-.")
        print(" "*self._distancia_percorrida + "'-(_)---(_)--'")

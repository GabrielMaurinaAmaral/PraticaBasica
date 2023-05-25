from Veiculo_Motorizado import Veiculo_Motorizado
from Veiculo import *


class Motocicleta(Veiculo_Motorizado):
    def __init__(self, id: int, rodas: int):
        super().__init__(id, rodas)
        self.__tipo = "M"
        print(f"Motocicleta com ID {self._id} foi construida")

    # metodo get
    def get_tipo(self) -> int:
        return self.__tipo

    # funções abstrata herdada pelo pai veiculo
    def mover(self):
        if self._ipva:
            if self._combustivel >= self.__gasto_motocicleta:
                for roda in self._rodas:
                    if roda.verificar_pneu():
                        self._combustivel -= self.__gasto_motocicleta
                        self._distanciaPercorrida += 3
                        print(
                            f"Motocicleta - ID:{self.id} andou  bloco +3 e está com {self.combustivel:.2f}litros de gasolina")
                        return
                print(
                    f"Motocicleta com ID {self.id} não possui todos os pneus calibrados")
            else:
                print(
                    f"Motocicleta com ID {self.id} não possui combustivel suficiente")
        else:
            print(f"Motocicleta com ID {self.id} não está com ipva em dia")

    def desenhar(self):
        print(" "*self._distancia_percorrida + "  , _oo")
        print(" "*self._distancia_percorrida + ".-/c-//: :")
        print(" "*self._distancia_percorrida + "(_)'=='(_)")

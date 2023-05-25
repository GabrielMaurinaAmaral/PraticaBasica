from Veiculo import *


class Bicicleta(Veiculo):
    def __init__(self, id: int, rodas: int):
        super().__init__(id, rodas)
        self.__tipo = "B"
        print(f"Bicicleta com ID {self._id} foi construida")

    # metodo get
    def get_tipo(self) -> int:
        return self.__tipo

    # funções abstrata herdada pelo pai veiculo
    def mover(self):
        for roda in self._rodas:
            if roda.verificar_pneu():
                self._distancia_percorrida += 2
                return
        print(f"Bicicleta - ID:{self.id} andou +2 blocos")

    def desenhar(self):
        print(" "*self._distancia_percorrida + "   __o")
        print(" "*self._distancia_percorrida + " _`\<,_:")
        print(" "*self._distancia_percorrida + "(*)/ (*)")

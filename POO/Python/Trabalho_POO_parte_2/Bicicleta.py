from Veiculo import *


class Bicicleta(Veiculo):
    def __init__(self, id: int, rodas: int):
        super().__init__(id, rodas)
        self.__tipo = "B"
        print(f"Bicicleta com ID {self.get_id()} foi construida")

    # metodo get
    def get_tipo(self) -> int:
        return self.__tipo

    # funções abstrata herdada pelo pai veiculo
    def mover(self):
        if self.verificar_pneu():
            new_distancia = self.get_distancia_percorrida() + 2
            self.set_distancia_percorrida(new_distancia)
            print(f"Bicicleta - ID:{self.get_id()} andou +2 blocos")
        else: 
            print(f"Bicicleta com ID {self.get_id()} não possui todos os pneus calibrados")

    def desenhar(self):
        print(" "*self.get_distancia_percorrida() + "   __o")
        print(" "*self.get_distancia_percorrida() + " _`\<,_:")
        print(" "*self.get_distancia_percorrida() + "(*)/ (*)")

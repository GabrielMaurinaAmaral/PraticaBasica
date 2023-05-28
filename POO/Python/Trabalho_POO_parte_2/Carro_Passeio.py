from Veiculo_Motorizado import Veiculo_Motorizado
from Veiculo import *


class Carro_Passeio(Veiculo_Motorizado):
    def __init__(self, id: int, rodas: int):
        super().__init__(id, rodas)
        self.__tipo = "C"
        print(f"Carro de Passeio com ID {self.get_id()} foi construida")

    # metodo get
    def get_tipo(self) -> int:
        return self.__tipo

    # funções abstrata herdada pelo pai veiculo
    def mover(self):
        if self.get_ipva():
            if self.get_combustivel() >= self.__gasto_carro_passeio:
                for roda in self.get_rodas():
                    if roda.verificar_pneu():
                        self.consumir(self.__gasto_carro_passeio)
                        new_distancia = self.get_distancia_percorrida() + 2
                        self.set_distancia_percorrida(new_distancia)
                        print(
                            f"Carro de passeio - ID:{self.get_id()} andou  bloco +5 e está com {self.get_combustivel():.2f}litros de gasolina")
                        return
                print(
                    f"Carro de passeio com ID {self.get_id()} não possui todos os pneus calibrados")
            else:
                print(
                    f"Carro de passeio com ID {self.get_id()} não possui combustivel suficiente")
        else:
            print(
                f"Carro de passeio com ID {self.get_id()} não está com ipva em dia")

    def desenhar(self) -> None:
        print(" "*self.get_distancia_percorrida() + "    ____")
        print(" "*self.get_distancia_percorrida() + " __/  |_ \_")
        print(" "*self.get_distancia_percorrida() + "|  _     _``-.")
        print(" "*self.get_distancia_percorrida() + "'-(_)---(_)--'")

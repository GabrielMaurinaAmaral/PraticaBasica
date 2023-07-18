from Veiculo_Motorizado import *
from Veiculo import *
from Interface_IPVA import *


class Carro_Esportivo(Veiculo_Motorizado, Interface_IPVA):
    __gasto_carro_esportivo: float = 2.3
    # constructor
    def __init__(self, id: int, rodas: int):
        super().__init__(id, rodas)
        super().set_valor_ipva(self.calcular_ipva())
        self.__tipo = "E"
        print(f"Carro Esportivo com ID {self.get_id()} foi construida")

    # metodo get
    def get_tipo(self) -> int:
        return self.__tipo

    # funções abstrata herdada pelo pai veiculo
    def mover(self):
        if self.get_ipva():
            if self.get_combustivel() >= self.__gasto_carro_esportivo:
                if self.verificar_pneu():
                    self.consumir(self.__gasto_carro_esportivo)
                    new_distancia = self.get_distancia_percorrida() + 2
                    self.set_distancia_percorrida(new_distancia)
                    print(f"Carro Esportivo - ID:{self.get_id()} andou  bloco +10 e está com {self.get_combustivel():.2f}litros de gasolina")
                else:
                    print(f"Carro Esportivo com ID {self.get_id()} não possui todos os pneus calibrados")
            else:
                print(f"Carro Esportivo com ID {self.get_id()} não possui combustivel suficiente")
        else:
            print(f"Carro Esportivo com ID {self.get_id()} não está com ipva em dia")

    def desenhar(self):
        print(" "*self.get_distancia_percorrida() + "        __")
        print(" "*self.get_distancia_percorrida() + "      ~( @\ \ ")
        print(" "*self.get_distancia_percorrida() + "   _____]_[_/_>__")
        print(" "*self.get_distancia_percorrida() + "  / __ \\<> |  __ \\")
        print(" "*self.get_distancia_percorrida() + "=\\_/__\\_\\__|_/__\\")
        print(" "*self.get_distancia_percorrida() + "   (__)      (__)")

    def calcular_ipva(self):
        return self.VALOR_BASE * self.CARRO_ESPORTIVO
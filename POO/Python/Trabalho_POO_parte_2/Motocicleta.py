from Veiculo_Motorizado import *
from Veiculo import *
from Interface_IPVA import *

class Motocicleta(Veiculo_Motorizado, Interface_IPVA):
    # metodo final(isso é feito implicitaente, linguagem ja interpleta que é uma variavel que não pode ser alterada)
    __gasto_motocicleta: float = 0.25
    #contrut
    def __init__(self, id: int, rodas: int):
        super().__init__(id, rodas)
        super().set_valor_ipva(self.calcular_ipva())
        self.__tipo = "M"
        print(f"Motocicleta com ID {self.get_id()} foi construida")

    # metodo get
    def get_tipo(self) -> int:
        return self.__tipo

    # funções abstrata herdada pelo pai veiculo 
    def mover(self):
        if self.get_ipva():
            if self.get_combustivel() >= self.__gasto_motocicleta:
                for roda in self.get_rodas():
                    if roda.verificar_pneu():
                        self.consumir(self.__gasto_motocicleta)
                        new_distancia = self.get_distancia_percorrida() + 2
                        self.set_distancia_percorrida(new_distancia)
                        print(
                            f"Motocicleta - ID:{self.get_id()} andou  bloco +3 e está com {self.get_combustivel():.2f}litros de gasolina")
                        return
                print(
                    f"Motocicleta com ID {self.get_id()} não possui todos os pneus calibrados")
            else:
                print(
                    f"Motocicleta com ID {self.get_id()} não possui combustivel suficiente")
        else:
            print(f"Motocicleta com ID {self.get_id()} não está com ipva em dia")

    def desenhar(self):
        print(" "*self.get_distancia_percorrida() + "  , _oo")
        print(" "*self.get_distancia_percorrida() + ".-/c-//: :")
        print(" "*self.get_distancia_percorrida() + "(_)'=='(_)")
    
    def calcular_ipva(self):
        self.valor =  self.VALOR_BASE * self.MOTOCICLETA
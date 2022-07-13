class Carro:
    velMax = 0
    ligado = False
    cor = ""

    def __init__(self, v, l, c):
        self.velMax = v
        self.ligado = l
        self.cor = c

    def mostrar(self):
        print(f"velocidade maxima: {self.velMax}")
        print(f"cor..............: {self.cor}")
        print(f"ligado...........: {self.ligado}")
        print("-------------------")

    def ligar(self):
        if (self.ligado == False):
            self.ligado = True
        else:
            self.ligado = False


c1 = Carro(200, True, "preto")
c2 = Carro(225, False, "branco")

c2.ligar()
c1.mostrar()
c1.mostrar()

class Complexo:
    def __init__(self, real=1, imaginario=1):
        self.real = real
        self.imaginario = imaginario

    def inicializarComplexo(self, real, imaginario):
        self.real = real
        self.imaginario = imaginario

    def imprimirComplexo(self):
        if (self.imaginario > 0):
            print(f"Complexo: {self.real} + {self.imaginario}i")
        elif (self.imaginario == 0):
            print(f"Complexo: {self.real}")
        else:
            print(f"Complexo: {self.real} {self.imaginario}i")

    def elgual(self, complexo):
        return (complexo.real == self.real and complexo.imaginario == self.imaginario)

    def soma(self, c):
        self.real += c.real
        self.imaginario += c.imaginario

    def subtrai(self, c):
        self.real -= c.real
        self.imaginario -= c.imaginario

    def multiplica(self, c):
        aux_r = (self.real * c.real) - (self.imaginario * c.imaginario)
        aux_i = (self.real * c.imaginario) + (self.imaginario * c.real)
        self.real = aux_r
        self.imaginario = aux_i

    def divide(self, c):
        aux_r = ((self.real * c.real) + (self.imaginario * c.imaginario)) / ((c.real * c.real) + (c.imaginario * c.imaginario))
        aux_i = ((self.imaginario * c.real) - (self.real * c.imaginario)) / ((c.real * c.real) + (c.imaginario * c.imaginario))
        self.real = aux_r
        self.imaginario = aux_i

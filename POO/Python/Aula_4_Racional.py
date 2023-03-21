class Fracao:
    def __init__(self, numerador=1, demoninador=1):
        self.numerador = numerador
        self.denominador = demoninador
        self.simplificar()

    def simplificar(self):
        a = self.numerador
        b = self.denominador

        while (b != 0):
            resto = a % b
            a = b
            b = resto

        self.numerador = self.numerador / a
        self.denominador = self.denominador / a

    def somar(self, fracao):
        if (self.denominador == fracao.denominador):
            self.numerador += fracao.numerador
        else:
            aux_1 = self.numerador
            aux_2 = self.denominador
            aux_3 = fracao.numerador
            aux_4 = fracao.denominador

            self.numerador = aux_1 * aux_4

            self.numerador += aux_3 * aux_2
            self.denominador = aux_2 * aux_4
            self.simplificar()

    def subtrair(self, fracao):
        if (self.denominador == fracao.denominador):
            self.numerador -= fracao.numerador
        else:
            aux_1 = self.numerador
            aux_2 = self.denominador
            aux_3 = fracao.numerador
            aux_4 = fracao.denominador

            self.numerador = aux_1 * aux_4
            fracao.numerador = aux_3 * aux_2

            self.numerador -= fracao.numerador
            self.denominador = aux_2 * aux_4
            self.simplificar()

    def multiplicar(self, fracao):
        aux_1 = self.numerador
        aux_2 = self.denominador

        self.numerador = aux_1 * fracao.numerador
        self.denominador = aux_2 * fracao.denominador
        self.simplificar()

    def dividir(self, fracao):
        aux_1 = self.numerador
        aux_2 = self.denominador

        self.numerador = aux_1 * fracao.denominador
        self.denominador = aux_2 * fracao.numerador
        self.simplificar()

    def imprimirFracao(self):
        print(
            f"Numero em Fração: {int(self.numerador)}/{int(self.denominador)}")

    def imprimirNumerico(self, casas):
        print(f"Numero em Float: {(self.numerador/self.denominador):,.2f}")

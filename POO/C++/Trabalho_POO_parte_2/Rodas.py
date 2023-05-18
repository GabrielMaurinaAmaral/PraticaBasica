import random

class Rodas:
    def __init__(self):
        self.calibragem_pneu = random.randint(0, 1)

    def set_calibragem(self, c_p):
        self.calibragem_pneu = c_p

    def get_calibragem(self):
        return self.calibragem_pneu

    def imprimir(self):
        print(f"\nCalibragem do Pneu: {self.calibragem_pneu}")

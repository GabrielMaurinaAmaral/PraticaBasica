class Carro:
    def __init__(self, nome="", velocidade=0):
        self.nome = nome
        self.estado = False
        self.velocidade = velocidade

    def info(self):
        print(f'\nnome......: {self.nome}')
        print(f'estado....: {self.estado}')
        print(f'velocidade: {self.velocidade}')

    def set_nome(self, nome):
        self.nome = nome

    def ligar_desligar(self):
        if (self.estado == False):
            self.estado = True
        else:
            self.estado = False

    def acelerar(self, a):
        if ((self.velocidade + a) <= 200):
            self.velocidade += a
        else:
            self.velocidade = 200


c1 = Carro()
c2 = Carro("Cu")
c3 = Carro("Gol", 100)

c1.set_nome("Uno")
c2.acelerar(300)
c3.ligar_desligar()

c1.info()
c2.info()
c3.info()

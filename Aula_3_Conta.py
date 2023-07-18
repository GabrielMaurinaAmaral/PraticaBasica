class Conta:
    def __init__(self, nome="", saldo=0.0):
        self.nome = nome
        self.saldo = saldo
    def setSaldo(self, s):
        self.saldo = s
    def setNome(self, n):
        self.nome = n
    def getSaldo(self):
        return saldo
    def getNome(self):
        return nome
    def depositar(self, quantia):
        self.saldo += quantia
    def retirar(self, quantia):
        if (quantia <= self.saldo):
            self.saldo -= quantia
        else:
            print("\nnão é possivel")
    def mostrar(self):
        print(f'\nNome: {self.nome}')
        print(f'Saldo: {self.saldo}')


c1 = Conta()
c2 = Conta('Joao')
c3 = Conta('Marcos', 2200)

c1.setSaldo(200)
c1.depositar(345)
c3.retirar(200)

c1.mostrar()
c2.mostrar()
c3.mostrar()

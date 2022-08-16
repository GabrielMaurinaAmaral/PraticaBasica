class Funcao:
    num = 0
    den = 0

    def __init__(self, n, d):
        self.num = n
        self.den = d

    def printf(self):
        print(f"{self.num} {self.den}")


num, den = input().split()
a = Funcao(num, den)

num, den = input().split()
b = Funcao(num, den)

num = int(a.num)*int(b.den)
den = int(b.num)*int(a.den)
c = Funcao(num, den)

c.printf()

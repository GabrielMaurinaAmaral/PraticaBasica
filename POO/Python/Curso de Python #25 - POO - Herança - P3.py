class NPC:
    def __init__(self, nome, time, forca, municao):
        self.nome = nome
        self.time = time
        self.forca = forca
        self.municao = municao
        self.vivo = True
        self.energia = 100

    def info(self):
        print(f'Nome.....: {self.nome}')
        print(f'Time.....: {self.time}')
        print(f'Forca....: {self.forca}')
        print(f'Municao..: {self.municao}')
        print(f'Vivo.....: {self.vivo}')
        print(f'Energia..: {self.energia}')
        print('-' * 20)


class Soldado(NPC):
    def __init__(self, nome, time):
        self.forca = 200
        self.municao = 200
        super().__init__(nome, time, self.forca, self.municao)


class Guarda(NPC):
    def __init__(self, nome, time):
        self.forca = 175
        self.municao = 100
        super().__init__(nome, time, self.forca, self.municao)


class Elite(NPC):
    def __init__(self, nome, time):
        self.forca = 400
        self.municao = 300
        super().__init__(nome, time, self.forca, self.municao)

    def inf(self):
        super().info()


s1 = Guarda('Olho Vivo', 1)
s2 = Soldado('Come Coração', 1)
s3 = Elite('Super Atento', 1)
s4 = Guarda('Olho Vivo 2', 2)
s5 = Soldado('Maldoso', 2)
s6 = Elite('Super Atento 2', 2)

print('\n\033[31mClasse Guarda\033[m')
s1.info()
print('\n\033[31mClasse Soldado\033[m')
s2.info()
print('\n\033[31mClasse Elite\033[m')
s3.inf()
print('\n\033[31mClasse Guarda\033[m')
s4.info()
print('\n\033[31mClasse Soldado\033[m')
s5.info()
print('\n\033[31mClasse Elite\033[m')
s6.inf()

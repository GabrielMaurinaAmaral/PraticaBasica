class Pessoa:
    def __init__(self, nome="-", cpf="-", anoNascimento=0, peso=0.0, altura=0.0):
        self.nome = nome
        self.cpf = cpf
        self.anoNascimento = anoNascimento
        self.peso = peso
        self.altura = altura
        self.vivo = True
        if 100 >= (2023 - anoNascimento) and (2023 - anoNascimento) >= 0:
            self.idade = 2023 - anoNascimento
        else:
            self.idade = 0

    def set_nome(self, n):
        self.nome = n

    def set_cpf(self, c):
        self.cpf = c

    def get_peso(self):
        return self.peso

    def get_idade(self):
        return self.idade

    def matar(self):
        self.vivo = False

    def mostrar(self):
        print(f'\nNome: {self.nome}')
        print(f'CPF: {self.cpf}')
        print(f'Idade: {self.idade}')
        print(f'Vivo: {self.vivo}')
        print(f'Peso: {self.peso}')
        print(f'Altura: {self.altura}')


p1 = Pessoa()
p2 = Pessoa('Paulo', '222.333.444-55')
p3 = Pessoa('Ana', '111.222.333-44', 2000, 67.34, 1.83)
 
p1.set_nome('Gabriel')
p2.set_cpf('333.444.555-66')
p3.matar()
 
print(p2.get_peso)
p1.mostrar()
p2.mostrar()
p3.mostrar()

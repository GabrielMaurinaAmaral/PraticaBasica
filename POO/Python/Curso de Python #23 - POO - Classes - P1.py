class Carro:
    velMax = 0
    ligado = False
    cor = ""


c1 = Carro()
c2 = Carro()

c1.velMax = 200
c1.cor = "preto"
c1.ligado = False
print(f"velocidade maxima: {c1.velMax}")
print(f"cor: {c1.cor}")
estado="sim" if c1.ligado else "nao"
print(f"ligado: {estado}")

print(f"velocidade maxima: {c2.velMax}")
print(f"cor: {c2.cor}")
estado="sim" if c2.ligado else "nao"
print(f"ligado: {estado}")
carros = ["gabreil", "erisom", "sara", "marcoooo"]
nomes = carros
print(carros)
print(carros[0])
print(carros[1])

carros.append("alexandro")
print(carros[-1])

print(str(len(carros)) + " carros na lista")

carros.remove("sara")
print(carros)

del carros[2]
print(carros)

juntar = carros + nomes
print(juntar)

carros.clear()
print(carros)


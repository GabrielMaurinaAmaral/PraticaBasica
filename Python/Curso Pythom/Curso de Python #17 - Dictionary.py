carro = {
    "fabrica": "Honda",
    "Modelo": "HRV",
    "Ano": "2016",
    "Cor": "preto"
}

carro["Cambio"] = "Automatico"
fab = carro["fabrica"]  # fab=carro.get("fabrica")
carro["Cor"] = "branco"
del carro["fabrica"]  # carro.pop("frabrica")

print(carro)
print(fab)

for l, c in carro.items():
    print(l+": "+c)

if "Ano" in carro:
    print("Ano e uma chave")

print("tamanho do carro: " + str(len(carro)))

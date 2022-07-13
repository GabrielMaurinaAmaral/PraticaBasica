carros = ["HB20", "GOL", "PALIO", "FERRARI"]

itCarros = iter(carros)

for c in carros:
    print(c)

i = 0
while i < 4:
    print(carros[i])

while itCarros:
    try:
        print(next(itCarros))
    except StopIteration:
        print("fim da lista")
        break
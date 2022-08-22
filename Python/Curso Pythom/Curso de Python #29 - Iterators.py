carros = ["HB20", "GOL", "PALIO", "FERRARI"]

itCarros = iter(carros)



while itCarros:
    try:
        print(next(itCarros))
    except StopIteration:
        print("fim da lista")
        break
number = (int(input("1°: ")), int(input("2°: ")), int(
    input("3°: ")), int(input("4°: ")), int(input("5°: ")))

print("NUMEROS DIGITADOS: {}".format(number))
print("apareceu o 9: {} vezes".format(number.count(9)))
print("apareceu o 3: {} vezes".format(number.index(3)))

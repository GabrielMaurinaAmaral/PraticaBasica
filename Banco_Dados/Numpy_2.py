import numpy as np

array = np.arange(1, 10, dtype=int)
print(array)
print(array[4])
print(array[2:6])
print(array[:4])
print(array[5:])

aleatorio = np.random.randint(0, 100, size=(5, 5, 5))
print(aleatorio)
print(aleatorio[1])
print(aleatorio[1][2])
print(aleatorio[1][2][3])  # maneira 1
print(aleatorio[1, 2, 3])  # maneira 2
print(aleatorio[1:2, 3:, :4])

a = 40
b = 60
print(a > b)

cadastro = np.random.randint(1, 51, size=(50, 10))
print(cadastro)

array_1 = cadastro > 18
print((array_1))

array_2 = cadastro[array_1]
print(array_2)

array_3 = cadastro > 25
print(array_3)

print(len(cadastro))
print(len(array_1))
print(len(array_2))
print(len(array_3))


import matplotlib.pyplot as plt
import numpy
from time import process_time
from numpy.random import default_rng

# import numpy as np
A = numpy.array([1, 2, 3, 4, 5, 6, 7, 8, 9])
print("\n", A)
print(type(A))

B = numpy.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
print("\n", B)
print(B.shape)
print(B.size)
print(B.ndim)
print(type(B))

A_zero = numpy.zeros(shape=(2, 3, 4))
print("\n", A_zero)

zero_a_nove = numpy.arange(10)
print(zero_a_nove)

# criando array porum parametro
dois_dez_par = numpy.arange(2, 10, 2)
print("\n", dois_dez_par)

# linarizando
Array_linear = numpy.linspace(0.0, 100.0, num=20, endpoint=False, retstep=True)
print("\n", (Array_linear))

# mudando dimenções
C = numpy.array([1, 2, 3])
print("\n", C.shape)
print(C.ndim)
print(C)

C2 = C[numpy.newaxis, :]
print("\n", C2.shape)
print(C2.ndim)
print(C2)

C3 = C[:, numpy.newaxis]
print("\n", C3.shape)
print(C3.ndim)
print(C3)

print(B[1][2], "\n")

for i in B:
    print(i)

for i in B:
    for j in range(3):
        print(i[j])

# juntando arrays
a = numpy.array([1, 2, 3])
b = numpy.array([4, 5, 6])
D = numpy.concatenate((a, b))
E = numpy.concatenate((b, a))
print("\n", D)
print("\n", E)
print(numpy.concatenate((C, A)))

# oprerações
print("\n", B > 6)
maior_5 = B[B > 5]
print("\n", maior_5)

print("\n", B.sum())
print(B.max())
print(B.min())
print(B.mean())

# gerando um array aleatoria
rng = default_rng()
aleatorio = rng.integers(10, size=(4, 3, 2))
print(aleatorio)

# diferança de array e lista
print("===================================")
print(A)
print(type(A))
print("===================================")
lista_A = [1, 2, 3, 4, 5, 6, 7, 8, 9]
print(lista_A)
print(type(lista_A))
print("===================================")
print(B)
print(type(B))
print("===================================")
lista_B = [[1, "Gabriel", 3], [4, 5, 6], [7, 8, 9]]
print(lista_B)
print(type(lista_B))
print("===================================")


lista_a = list(rng.integers(10, 100, 100000))
lista_b = list(rng.integers(10, 100, 100000))
# print(lista_a)
# print(lista_b)

lista_c = []
tempo_1 = float(process_time())
for i in range(len(lista_a)):
    lista_c.append(lista_a[i]*lista_b[i])
tempo_2 = float(process_time())

print('\n', lista_c)
print((type((lista_c))))
print(tempo_2-tempo_1)

array_a = rng.integers(10, 100, 1000000)
array_b = rng.integers(10, 100, 1000000)

tempo_1 = float(process_time())
array_c = array_a*array_b
tempo_2 = float(process_time())

print("\n", array_c)
print((type(array_c)))
print(tempo_2-tempo_1)

# interface grafica para gerar grafico de dados
dados_x = rng.integers(50, size=100)
dados_y = rng.integers(30, size=100)
plt.scatter(x=dados_x, y=dados_y)
plt.show()

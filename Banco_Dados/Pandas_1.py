import pandas as pd
import numpy as np

s = pd.Series([1, 2, 3, 'oi', np.nan, 6.8])
print(s)
print(type(s))

lista = [10, 20, 30, 40, 50]
print("\n", lista)
serie_lista = pd.Series(lista)
print(serie_lista)
print(serie_lista[0])

dicionario = {'telefone': '889977766', 'nome': 'gabriel', 'idade': '18'}
print("\n", dicionario)
serie_dicionario = pd.Series(dicionario)
print(serie_dicionario)
print(serie_dicionario[2])
print(serie_dicionario['nome'])

array = np.array([10, 20, 30, 40, 50])
print('\n', array)
serie_array = pd.Series(array)
print(serie_array)

serie_alterada1 = pd.Series(array, index=['A', 'B', 'C', 'D', 'E'])
print(serie_alterada1)

serie_alterada2 = pd.Series([50, 60, 70, 80, 90], index=['Z', 'B', 'C', 'D', 'F'])
print(serie_alterada2)

print(serie_alterada1+serie_alterada2)


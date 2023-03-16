import numpy as np
import pandas as pd

data = {'Sede': ['SP', 'SP', 'MG', 'MG', 'RJ', 'RJ', 'ES', 'ES'],
        'Vendedor': ['Jorge', 'Ana', 'Tiago', 'Pedro', 'Raphaela', 'Guto', 'Maria', 'Carolina'],
        'Vendas': [2000, 2500, 3100, 1200, 1500, 3900, 2900, 3900]}
df = pd.DataFrame(data)


arrays = [['São Paulo', 'São Paulo', 'Rio de Janeiro', 'Rio de Janeiro', 'Minas Gerais', 'Minas Gerais'],
          ['Garrafas', 'Copos', 'Garrafas', 'Copos', 'Garrafas', 'Copos']]
index = pd.MultiIndex.from_arrays(arrays, names=('Estado', 'Produto'))
df1 = pd.DataFrame(
    {'Total Vendido R$': [10000, 35000, 22400, 12890, 10880, 13900]}, index=index)

by_sede = df.groupby('Sede')
print(by_sede)

print('\n', by_sede.max())
print('\n', by_sede.describe())
print('\n', by_sede.describe().transpose())
print('\n', by_sede.describe().transpose()['SP'])
print('\n', df)
print('\n', df1)

mult_bysede = df1.groupby('Estado', level=0)
print('\n', mult_bysede)
print('\n', mult_bysede.mean())
print('\n', mult_bysede.max())

mult_bysede = df1.groupby('Produto', level=1)
print('\n', mult_bysede)
print('\n', mult_bysede.mean())
print('\n', mult_bysede.max())

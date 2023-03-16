import numpy as np
import pandas as pd

# left  merge / join uni pela esquerda
# right merge / join uni pela direita
# outer merge / join uni todos
# inner merge / join uni apenas aqules que tem nos dois datas fremes

df1 = pd.DataFrame({'A': ['A0', 'A1', 'A2', 'A3'],
                    'B': ['B0', 'B1', 'B2', 'B3'],
                    'C': ['C0', 'C1', 'C2', 'C3'],
                    'D': ['D0', 'D1', 'D2', 'D3']},
                   index=[0, 1, 2, 3])

df2 = pd.DataFrame({'A': ['A4', 'A5', 'A6', 'A7'],
                    'B': ['B4', 'B5', 'B6', 'B7'],
                    'C': ['C4', 'C5', 'C6', 'C7'],
                    'D': ['D4', 'D5', 'D6', 'D7']},
                   index=[4, 5, 6, 7])

df3 = pd.DataFrame({'A': ['A8', 'A9', 'A10', 'A11'],
                    'B': ['B8', 'B9', 'B10', 'B11'],
                    'C': ['C8', 'C9', 'C10', 'C11'],
                    'D': ['D8', 'D9', 'D10', 'D11']},
                   index=[8, 9, 10, 11])

dicionario = {'ID': [10, 11, 12, 13, 14,], 'NOME': ['Mario', 'Joana', 'Claudia', 'Lucas', 'Gabriel'],
              'CIDADE': ['SÃO PAULO', 'RIO DE JANEIRO', 'SÃO PAULO', 'CAMPINAS', 'PORTO ALEGRE']}

dicionario2 = {'ID': [16, 11, 12, 13, 18,], 'Experiência': [
    'Junior', 'Senior', 'Pleno', 'Estagiário', 'Analista']}

df4 = pd.DataFrame(data=dicionario)
df5 = pd.DataFrame(data=dicionario2)

dicionario = {'NOME': ['Mario', 'Joana', 'Claudia', 'Lucas', 'Gabriel'],
              'CIDADE': ['SÃO PAULO', 'RIO DE JANEIRO', 'SÃO PAULO', 'CAMPINAS', 'PORTO ALEGRE']}

dicionario2 = {'Experiência': [
    'Junior', 'Senior', 'Pleno', 'Estagiário', 'Analista']}

df7 = pd.DataFrame(data=dicionario)
df8 = pd.DataFrame(data=dicionario2)

df_concatenar = pd.concat([df1, df2, df3])
print("\n", df_concatenar)

df_merge = pd.merge(df4, df5, how='outer')
print("\n", df_merge)

df_join_esquerda = df4.join(df5, lsuffix='_X', rsuffix='_Y')
print("\n", df_join_esquerda)



import pandas as pd
import numpy as np

# DAT fremes
array = np.random.randint(5, 55, size=(5, 5))
print(array)

df_1 = pd.DataFrame(data=array, index=['A', 'B', 'C', 'D', 'E'], columns=[
                    'idade', 'cp', 'rg', 'telefone', 'outro'])
print(df_1)

dados = {'PRODUTOS': ['videogame', 'pc', 'teclado', 'mouse',
                      'microfone'], 'PRECOS': [2600, 2455.0, 99.9, 64, 126.8]}
print(dados)
df_2 = pd.DataFrame(data=dados)
print(df_2)
df_2['CUSTO'] = [1900, 2000.1, 40.05, 50, 1]
print("\n", df_2)


print("\n\n\n")
# Indexação
indices = ['Janeiro', 'Março', 'Maio',
           'Julho', 'Agosto', 'Outubro', 'Novembro']
print(indices)
colunas = np.arange(1, 32)
print(colunas)
dados = np.random.randint(491, 2050, size=(7, 31))
print(dados)

data_frame = pd.DataFrame(data=dados, index=indices, columns=colunas)
print(data_frame)
print(data_frame[2])
print(data_frame[[2, 3, 4]])
print(data_frame[3]['Março'])
print(data_frame[3][1])
print(data_frame[2:6])
##
print("\nQuanto vendeu no dia 11?")
print(data_frame[11])
print("\nQuanto vendeu no dia 10,20 e 30?")
print(data_frame[[10, 20, 30]])
print("\nQuanto vendeu no dia 16 de Julho?")
print(data_frame[16]['Julho'])
print("\nQuanto vendeu nos meses Janeiro, Março e Maio?")
print(data_frame[:3])
print("\nQuanto vendeu nos meses  Março, Julho e Novembro do dias 25 e 31?")
print(data_frame.loc[['Março', 'Julho', 'Novembro'], [25, 31]])
print(data_frame.rename({'Novembro': 'Dezemvro'}))

print(data_frame > 1000)
data_maior_1000 = data_frame[data_frame > 1000]
print(data_maior_1000.fillna('-'))

print(data_frame.loc[["Março"], [3]])  # procula pelo nome
print(data_frame.iloc[[1], [2]])  # procura pelo index
print(data_frame.rename({'Janeiro': 'Gabriel'}))

print("\n", data_maior_1000[2])
print(data_frame[data_frame < 1000][:][[1, 2, 3, 4, 5]].fillna('-'))
#print(data_frame[((data_frame[10]>500) or (data_frame[5] < 1000))])
